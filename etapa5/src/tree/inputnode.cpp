#include "inputnode.h"
#include <stdio.h>

InputNode::InputNode(const std::string& varName): Node("Entrada", Common::NT_INPUT), varName(varName) {}

void InputNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "entrada ");
	fprintf(this->flexOut, "%s", this->varName.c_str());
	fprintf(this->flexOut, "%s", ";\n");
}

void InputNode::generateILOCCode() {}

void InputNode::printILOC() {}