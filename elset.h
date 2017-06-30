#ifndef ELSET_H
#define ELSET_H

#include <string>
#include <vector>
#include "element.h"

//using elem_ptr = element*;
using elem_ptr = std::shared_ptr<element>;

class elset
{
public:
    elset(std::string);
    void add_elset_elem(elem_ptr);
    void print_elset();

private:
    std::vector <elem_ptr> m_elset_elems;
    std::string m_name;
    std::vector<node_ptr> m_nodes;
};

#endif // ELSET_H
