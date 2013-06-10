#ifndef IFNODE_H
#define IFNODE_H

#include "node.h"

class IfNode : public Node {

public:
  IfNode(Node* expression, Node* commandThen);
  IfNode(Node* expression, Node* commandThen, Node* commandElse);
  void printSourceCode();
};

#endif // IFNODE_H
