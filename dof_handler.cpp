#include "dof_handler.h"
#include "cmodel.h"
#include <iostream>


dof_handler::dof_handler(CModel *model)
{
    m_model =model;
    int count =0;
    for(auto &iter:m_model->m_elements)
    {
       count+= iter->get_dof_count();
    }

    m_Nvar =count;
    m_variables.resize(count);

//    for(auto &elem:m_model->m_elements)
//    {
//        int index =0;
//        for(auto &nodes:elem->get_nodes())
//        {
//            int sdof_count,ddof_count;
//            sdof_count = nodes->get_Nsdof();
//            ddof_count = nodes->get_Nddof();

//            int id = nodes->getindex();
//            auto disp_dof =nodes->get_disp_dof_reference();
//            auto stress_dof =nodes->get_stress_dof_reference();
//        }
//    }
}

void dof_handler::assign_dof()
{


}
