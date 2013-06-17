#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include <string>
#include <vector>
#include "expressionnode.h"
#include "../../symbol.h"
#include "../../scope.h"
#include "../../iloc.h"

class IdentifierNode : public ExpressionNode {

public:
	IdentifierNode(Symbol* symbol);
	IdentifierNode(Symbol* symbol, std::vector<Node*>* expressionList);
	void printSourceCode(const std::string& end);
	void generateILOCCode();
	void printILOC();

private:
	Symbol* symbol;
};

#endif // IDENTIFIERNODE_H
