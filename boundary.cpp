#include "boundary.h"
#include <cassert>
#include <iterator>
boundary::boundary()
{

    //m_traction.second.fill(0);    // Tractions initialised to zeros.
}


//void boundary::set_load(load_ptr temp)
//{
  //  m_loads.push_back(temp);
//}


/*......................................................................................................
 .......................................................................................................*/








//BOUNDARY_CPS4 CLASS

boundary_cps4::boundary_cps4(elem_ptr elem)
{
    m_boundary_element_ptr = elem;
}



void boundary_cps4::set_boundary_faces()
{
    for(unsigned int i=0; i<4; i++)
    {
        if(m_boundary_element_ptr->elements_shared_by_face(i) == 1)
        {
            m_boundary_faces.push_back(i);
            assign_traction(i);
        }

    }
}

//unsigned int boundary_cps4::getindex() const
//{
//    return m_boundary_element_ptr->getindex();
//}


void boundary_cps4::assign_traction(side s)
{
    unsigned int node_1,node_2;
    node_1 = s;
    if(s == 3)
        node_2 = 0;
    else
        node_2 = s+1;

    std::array<double,2> node_1_traction{0,0};
    std::array<double,2> node_2_traction{0,0};

    m_traction[node_1] = node_1_traction;
    m_traction[node_2] = node_2_traction;
}

void boundary_cps4::assign_traction(side s,  orientation orient, traction tract_1, traction tract_2)
{
    unsigned int node_1,node_2;
    node_1 = s;
    if(s == 3)
        node_2 = 0;
    else
        node_2 = s+1;

   assert(m_traction.count(node_1) != 0 and m_traction.count(node_2) != 0);  // the nodes should be previously identified.
   enum direction {x_dir =0 ,y_dir};
   auto n1 = m_traction.find(node_1);
   auto n2 = m_traction.find(node_2);
   switch (orient)
    {
    case 1:
       n1->second.at(x_dir) = tract_1;
       n2->second.at(x_dir) = tract_2;
       break;
    case 2:
       n1->second.at(y_dir) = tract_1;
       n2->second.at(y_dir) = tract_2;
       break;
    default:
       std::cerr<<"Error at orientation";
       break;
    }
}

bool is_id_equal(boundary_cps4 b,int id)
{
    if( b.getindex() == id)
        return true;
    else
        return false;
}

void boundary_cps4::set_normal_pressure_on_face(side s, traction tr)
{
    m_pressure_on_face[s] =tr;
}

