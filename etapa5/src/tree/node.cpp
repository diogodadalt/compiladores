#include "node.h"
#include <iostream>

Node::Node(): parent(NULL), flexOut(yyout), isNewScope(false), hashTable(NULL) {
	this->children = new std::vector<Node*>();
	this->instructions = new std::vector<ILOC*>();
}

Node::Node(const std::string& name): name(name), parent(NULL), flexOut(yyout), isNewScope(false), hashTable(NULL) {
	this->children = new std::vector<Node*>();
	this->instructions = new std::vector<ILOC*>();
}

Node::Node(const std::string& name, std::vector<Node*>* children): name(name), children(children), parent(NULL), flexOut(yyout), isNewScope(false), hashTable(NULL) {
	this->instructions = new std::vector<ILOC*>();
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->setParent(this);
}

void Node::addChild(Node* child) {
	this->children->push_back(child);
	child->setParent(this);
}

void Node::addChildren(std::vector<Node*>* children) {
	for (std::vector<Node*>::iterator it = children->begin(); it != children->end(); it++) {
		this->children->push_back((*it));
		(*it)->setParent(this);
	}
}

Node* Node::getParent() const {
	return this->parent;
}

void Node::setParent(Node* parent) {
	this->parent = parent;
}

bool Node::getIsNewScope() const {
	return isNewScope;
}

void Node::setIsNewScope(bool value) {
	isNewScope = value;
}

Node* Node::getParentWithScope() const {
	if (parent->getIsNewScope())
		return parent;
	else
		return parent->getParentWithScope();
}

void Node::print(int level) {
	this->printSpaces(level);
	std::cout << this->name << "\n";
	for (std::vector<Node*>::iterator it = children->begin(); it != children->end(); it++)
		(*it)->print(level+1);
}

std::string Node::dataTypeToString(const Common::DataType& dataType) {
	switch (dataType) {
	case Common::BOOL:
		return "booleano";
	case Common::INT:
		return "inteiro";
	case Common::FLOAT:
		return "flutuante";
	case Common::CHAR:
		return "caractere";
	case Common::STRING:
		return "cadeia";
	default:
		break;
	}

	return "ERROR!";
}

std::string Node::operationTypeToString(const Common::OperationType& operationType) {
	switch (operationType) {
	case Common::OP_SUM:
		return "+";
	case Common::OP_SUB:
		return "-";
	case Common::OP_MULT:
		return "*";
	case Common::OP_DIV:
		return "/";
	case Common::OP_AND:
		return "&&";
	case Common::OP_OR:
		return "||";
	case Common::OP_LESS:
		return "<";
	case Common::OP_GREATER:
		return ">";
	case Common::OP_LE:
		return "<=";
	case Common::OP_GE:
		return ">=";
	case Common::OP_EQUAL:
		return "==";
	case Common::OP_NEQUAL:
		return "!=";
	default:
		break;
	}

	return "ERROR!";
}

void Node::printSpaces(int level) {
	for (int i = 0; i < level; i++)
		std::cout << "  ";
}

std::string Node::getName() {
	return this->name;
}

Common::HashTable* Node::getHashTable() {
	return this->hashTable;
}

int Node::getBaseAddr() {
	return this->baseAddr;
}

int Node::getCurrentOffset() {
	return this->currentOffset;
}

void Node::setCurrentOffset(int co) {
	this->currentOffset = co;
}
