#include "cps4.h"
#include <cassert>
#include <algorithm>

cps4::cps4(int id, std::vector<node_ptr> nodes)
{
    m_type =CPS4;
    m_elem_id=id;
    m_ENode_ptrs.reserve(4);
    m_ENode_ptrs=nodes;

    for(auto& iter:m_ENode_ptrs)
    {
        iter->set_dof(24,8);
    }
}

cps4::~cps4()
{

}

int cps4::get_dof_count() const
{
    return 32;
}

void cps4::set_node_dof()
{
    for(auto& iter:m_ENode_ptrs)
    {
        iter->set_dof(24,8);
    }
}

std::vector<node_ptr> cps4::get_face(unsigned int i) const
{
    std::vector<node_ptr> temp;
    if(i !=3)
    {
        temp.push_back(m_ENode_ptrs.at(i));
        temp.push_back(m_ENode_ptrs.at(i+1));
    }
    else
    {
        temp.push_back(m_ENode_ptrs.at(3));
        temp.push_back(m_ENode_ptrs.at(0));
    }

    return temp;
}

int cps4::elements_shared_by_face(unsigned int i) const
{
    std::vector<node_ptr> face = get_face(i);
    std::vector<unsigned int> v1 = face.at(0)->get_shared_elements_id() ; std::sort(v1.begin(),v1.end());
    std::vector<unsigned int> v2 = face.at(1)->get_shared_elements_id() ; std::sort(v2.begin(),v2.end());
    std::vector<unsigned int> intersection ;
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(intersection,intersection.begin()));
    return intersection.size();
}

element_type cps4::get_element_type() const
{
    return m_type;
}



int cps4::faces_count() const
{
    return 4;
}

bool cps4::is_boundary( ) const
{
    bool flag =false;
    for(int i=0; i<4; i++)
    {
        if(elements_shared_by_face(i) == 1)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

unsigned int cps4::getindex() const
{
    return m_elem_id;
}













