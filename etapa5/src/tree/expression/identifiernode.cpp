#include "identifiernode.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

IdentifierNode::IdentifierNode(Symbol* symbol):
	ExpressionNode("Expressao idenficador", Common::EX_IDENTIFIER), symbol(symbol) {
	// TODO check the data type
	Symbol* sym = Scope::getSymbol(symbol->getText());
	this->dataType = sym->getDataType();
}

IdentifierNode::IdentifierNode(Symbol* symbol, std::vector<Node*>* expressionList):
	ExpressionNode("Expressao idenficador", Common::EX_IDENTIFIER), symbol(symbol) {
	// TODO check the data type
	this->addChildren(expressionList);
	Symbol* sym = Scope::getSymbol(symbol->getText());
	this->dataType = sym->getDataType();
}

void IdentifierNode::printSourceCode(const std::string& end) {
	if (this->children->size() == 0)
		fprintf(this->flexOut, "%s", symbol->getText().c_str());
	else {
		fprintf(this->flexOut, "%s", symbol->getText().c_str());
		for (unsigned int i = 0; i < this->children->size(); i++) {
			fprintf(this->flexOut, "%s", "[");
			this->children->at(i)->printSourceCode("");
			fprintf(this->flexOut, "%s", "]");
		}
	}
}

void IdentifierNode::generateILOCCode(Node* context) {
	if (this->children->size() == 0) { // Variable
		Symbol* symbol = Scope::getSymbol(this->symbol->getText());
		Node* symbolScope = Scope::getScope(this->symbol->getText());
		std::string* varAddressRegisterName = ILOC::getRegister(symbol->getText());
		std::string registerBaseAddress = (symbolScope->getNodeType() == Common::NT_PROGRAM) ? "bss" : "fp";
		std::stringstream symbolOffsetStr;
		symbolOffsetStr << symbol->getOffset();
		ILOC* instruction = new ILOC(Common::ILOC_LOADAI, registerBaseAddress, symbolOffsetStr.str(), *varAddressRegisterName, "");
		this->addInstruction(instruction);
		this->setLastRegister(*varAddressRegisterName);
	} else { // vector
		Symbol* symbol = Scope::getSymbol(this->symbol->getText());
		Node* symbolScope = Scope::getScope(this->symbol->getText());
		std::string* vectorAddressRegisterName = ILOC::getRegister(symbol->getText());
		std::string registerBaseAddress = (symbolScope->getNodeType() == Common::NT_PROGRAM) ? "bss" : "fp";
		std::stringstream symbolOffsetStr;
		symbolOffsetStr << symbol->getOffset();
		ILOC* instruction = new ILOC(Common::ILOC_ADDI, registerBaseAddress, symbolOffsetStr.str(), *vectorAddressRegisterName, "");
		ILOC::addInstruction(instruction);
		std::string lastBaseRegister = *vectorAddressRegisterName;
		std::string* indexRegisterName;
		for (unsigned int i = 0; i < this->children->size(); i++) {
			ExpressionNode* expression = dynamic_cast<ExpressionNode*>(this->children->at(i));
			expression->generateILOCCode(this);
			std::stringstream indexStream;
			indexStream << i;
			std::string* multResultRegisterName = ILOC::getRegister("INST_MULT_VEC_RESULT_" + indexStream.str());
			indexRegisterName = ILOC::getRegister("INDEX_REGISTER_NAME_" + indexStream.str());
			ILOC* instructionMult = new ILOC(Common::ILOC_MULTI, expression->getLastRegister(), "4", *multResultRegisterName, "");
			ILOC* instructionLoadAO = new ILOC(Common::ILOC_LOADA0, lastBaseRegister, *multResultRegisterName, *indexRegisterName, "");
			lastBaseRegister = *indexRegisterName;
			ILOC::addInstruction(instructionMult);
			ILOC::addInstruction(instructionLoadAO);
		}
		this->setLastRegister(*indexRegisterName);
	}
}
