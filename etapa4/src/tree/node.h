#ifndef NODE_H
#define NODE_H

#include <vector>
#include <tr1/unordered_map>
#include <string>
#include "common.h"
#include "symbol.h"

extern FILE* yyout;

class Node {

public:
	Node();
  Node(const std::string& name);	
  Node(const std::string& name, std::vector<Node*>* children);
	void addChild(Node* child);
  void addChildren(std::vector<Node*>* children);
	Node* getParent() const;
	void setParent(Node* parent);
	bool getIsNewScope() const;
	void setIsNewScope(bool value);
	Node* getParentWithScope() const;
	void print(int level);
  virtual void printSourceCode(const std::string& end) = 0;

protected:
	std::string dataTypeToString(const Common::DataType& dataType);
	std::string operationTypeToString(const Common::OperationType& operationType);	
  std::string name;
  std::vector<Node*>* children;
	Node* parent;
  FILE* flexOut;
	bool isNewScope;
	std::tr1::unordered_map<std::string, Symbol*>* hashTable;

private:
  void printSpaces(int level);
};

#endif // NODE_H
