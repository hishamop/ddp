#include "element.h"
#include <iomanip>
element::element()
{

}
element::element(int id, std::vector<node_ptr> nodes)
{
    m_elem_id =id;
    m_ENode_ptrs = nodes;
}
element::~element()
{

}

void element::print_element() const
{
    std::cout<<std::setw(10)<< std::left <<m_elem_id;
    for (auto &iter:m_ENode_ptrs)
    {
        std::cout << std::setw(10) << std::left << iter->getindex();
    }
    std::cout<<"\n";
}


unsigned int element::getindex() const
{
    return m_elem_id;
}

node_ptr element::getnode(int i) const
{
    return m_ENode_ptrs.at(i-1);
}




