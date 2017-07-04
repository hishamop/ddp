#include "cmodel.h"
#include <cassert>
#include <memory>
CModel::CModel()
{

}

void CModel::add_node(node_ptr t)    // Add node as push back
{
    m_nodes.push_back(t);
}

void CModel::add_element(elem_ptr t)
{
    m_elements.push_back(t);
}

node_ptr CModel::get_node_ptr(int id)
{
    assert(m_nodes.at(id-1)->getindex() == id);      // Make sure that correct node is returned.
    return m_nodes.at(id-1);
}

node_ptr CModel::get_node_ptr_with_count(int id)
{
    assert(m_nodes.at(id-1)->getindex() == id);      // Make sure that correct node is returned.
    return m_nodes.at(id-1);
}

elem_ptr CModel::get_elem_ptr(unsigned int id)
{

    assert(m_elements.at(id-1)->getindex() == id);    //Make sure correct element is returned.
    return m_elements.at(id-1);
}


//void CModel::print_elems() const
//{
//    std::cout<<"...............ELEMENTS DATA................\n";
//    for (auto iter=m_elements.begin(); iter != m_elements.end(); ++iter)
//    {
//        iter->print_element();
//    }
//}

void CModel::print_elems() const
{
    std::cout<<"...............ELEMENTS DATA................\n";
    for (auto &iter:m_elements)
    {
        iter->print_element();
    }
}

// public function for printing node data
void CModel::print_nodes() const
{
    if(m_nodes.empty())
    {
        std::cout<<"node empty\n";
        return;
    }

    std::cout<<".............NODE DATA.................\n";
    for( const auto  &iter:m_nodes)
    {
        iter->printnode();
    }
}

//void CModel::print_nodeset() const
//{
//    if(m_nset.empty())
//    {
//        std::cout<<"No nodesets \n";
//        return;
//    }

//    for (auto &iter:m_nset)
//    {
//        iter->print_nodeset();
//    }
//}

void CModel::print_node_count() const
{
    std::cout<<"Count of nodes :    "<<m_nodes.size()<<std::endl;
}

void CModel::print_elem_count() const
{
    std::cout<<"Count of elements :    "<<m_elements.size()<<std::endl;
}

//void CModel::print_elset() const
//{
//    if(m_elemset.empty())
//    {
//        std::cout<<"No element sets \n";
//        return;
//    }

//    for (auto &iter:m_elemset)
//    {
//        iter->print_elset();
//    }
//}

void CModel::add_boundary_element(boundary_ptr elem)
{

    m_boundary.push_back(elem);
}


//void CModel::print_boundary_elements() const
//{
//    int i =1;
//    std::cout<<"...............BOUNDARY ELEMENTS................\n";
//    for(auto &iter:m_boundary)
//    {
//        if(i%5==0)
//            std::cout<<"\n";
//        std::cout<<iter->get_element_id()<<"\t";
//        i++;
//    }

//    std::cout<<"\n\n";
//}
