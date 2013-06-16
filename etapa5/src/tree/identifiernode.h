#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include <string>
#include "expressionnode.h"
#include "../symbol.h"
#include "../iloc.h"

class IdentifierNode : public ExpressionNode {

public:
	IdentifierNode(Symbol* symbol);
	IdentifierNode(Symbol* symbol, Node* expression);
	void printSourceCode(const std::string& end);
    Symbol * generateILOCCode();

private:
	Symbol* symbol;
};

#endif // IDENTIFIERNODE_H
