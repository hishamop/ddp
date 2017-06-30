#include "nodeset.h"

nodeset::nodeset(std::string name)
{
    m_name=name;
}

void nodeset::add_nset_node(node_ptr n)
{
    m_nset_nodes.push_back(n);
}

std::string nodeset::getname()
{
    return m_name;
}

void nodeset::print_nodeset()
{
    std::cout<<"\n.................NSET == "<<m_name<<".....................\n\n";
    int i=1;
    for(auto &iter:m_nset_nodes)
    {
        if(i%5==0)
            std::cout<<"\n";
        std::cout<<iter->getindex()<<"\t";
        i++;
    }
    std::cout<<"\n\n";
}
