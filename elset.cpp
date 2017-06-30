#include "elset.h"

elset::elset(std::string name)
{
    m_name =name;
}

void elset::add_elset_elem(elem_ptr n)
{
    m_elset_elems.push_back(n);
}

void elset::print_elset()
{
    std::cout<<"\n.................ELSET == "<<m_name<<".....................\n\n";
    int i=1;
    for(auto iter=m_elset_elems.begin(); iter != m_elset_elems.end(); ++iter)
    {
        if(i%5==0)
            std::cout<<"\n";
        std::cout<<(*iter)->getindex()<<"\t";
        i++;
    }
    std::cout<<"\n\n";
}
