#ifndef NODESET_H
#define NODESET_H

#include <iostream>
#include <string>
#include <vector>
#include "node.h"

using node_ptr=node*;

class nodeset
{
public:
    nodeset(std::string);
    void add_nset_node(node_ptr);
    void print_nodeset();
    std::string getname();


private:
    std::string m_name;
    std::vector<node_ptr> m_nset_nodes;
};

#endif // NODESET_H
