#include "vardeclarationnode.h"
#include <stdio.h>

VarDeclarationNode::VarDeclarationNode(const std::string &varName, Common::DataType dataType):
	Node("Declaracao de variavel"), varName(varName), dataType(dataType) {
	Node* parentWithScope = this->getParentWithScope();
	int i = 0;
}

void VarDeclarationNode::printSourceCode(const std::string& end) {
  fprintf(this->flexOut, "%s", this->varName.c_str());
  fprintf(this->flexOut, "%s", ": ");
  fprintf(this->flexOut, "%s", this->dataTypeToString(this->dataType).c_str());
  fprintf(this->flexOut, "%s", end.c_str());
}
