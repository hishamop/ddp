#include<iostream>
#include <iomanip>
#include "node.h"
node::node()
{
    m_id=0;
    m_xcord=0.0;
    m_ycord=0.0;
    m_zcord=0.0;
}

node::node(int id,float x, float y)
{
    m_id=id;
    m_xcord=x;
    m_ycord=y;
    m_zcord=0;
}

node::node(int id, float x, float y, float z)
{
    m_id   =id;
    m_xcord=x;
    m_ycord=y;
    m_zcord=z;

}

node::~node()
{
}

node::node(node & other)
{

}

void node ::set_dof(int nStsDof, int nDispDof)
{
    m_stressDof.resize(nStsDof);
    m_dispDof.resize( nDispDof);

    m_Nddof =nDispDof;
    m_Nsdof =nStsDof;



}

void node::printnode() const
{
    std::cout<<std::setw(10)<< std::left <<m_id<<std::setw(10)<<std::left<<m_xcord<<std::setw(10)<<std::left<<m_ycord<<"\n";
}



int node::getindex() const
{
    return m_id;
}



std::vector<unsigned int> node::get_shared_elements_id() const
{
    return m_incident_elements;
}

void node::add_incident_elem_id(unsigned int  id)
{
    m_incident_elements.push_back(id);
}

std::vector<double>& node::get_disp_dof_reference()
{
    return m_ddof;
}

std::vector<double> &node::get_stress_dof_reference()
{
    return m_sdof;
}

int node::get_Nddof()
{
    return m_Nddof;
}

int node::get_Nsdof()
{
    return m_Nsdof;
}
