#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include <list>
#include "node.h"

class OutputNode : public Node {

public:
  OutputNode(std::vector<Node*>* children);
  void printSourceCode(const std::string& end);
  void generateILOCCode();
};

#endif // OUTPUTNODE_H
