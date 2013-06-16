#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include <string>
#include "../node.h"
#include "../common.h"
#include "../../symbol.h"

class ExpressionNode : public Node {

public:
	ExpressionNode();
	ExpressionNode(const std::string& name);
	ExpressionNode(const std::string& name, const Common::DataType& dataType);
	Common::DataType getDataType() const;
	void setDataType(const Common::DataType &value);
	virtual void printSourceCode(const std::string& end) = 0;	

protected:
	Common::DataType dataType;
};

#endif // EXPRESSIONNODE_H
