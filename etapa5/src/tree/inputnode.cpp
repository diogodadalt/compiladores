#include "inputnode.h"

InputNode::InputNode(const std::string &varName): Node("Entrada"), varName(varName) {}

void InputNode::printSourceCode(const std::string& end) {}

void InputNode::generateILOCCode() {
    // ...
}
