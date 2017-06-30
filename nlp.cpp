#include "nlp.h"
#include "element.h"
#include "boundary.h"
using elem_ptr = std::shared_ptr<element>;

nlp::nlp(CModel* m)
{
    m_model =m;
    initialise_dof();
}

nlp::~nlp()
{
}

void nlp::initialise_dof()
{
    int count =0;
    for(auto &iter:m_model->m_elements)
    {
       count+= iter->get_dof_count();
    }

    m_Nvar =count;

    for(auto &elem:m_model->m_elements)
    {
        int index =0;
        for(auto &nodes:elem->get_nodes())
        {
            int sdof_count,ddof_count;
            sdof_count = nodes->get_Nsdof();
            ddof_count = nodes->get_Nddof();
            double* disp_dof;
            double* stress_dof;
            int id = nodes->getindex();
          //  disp_dof =nodes->get_disp_dof_ptr();
          //  stress_dof =nodes->get_stress_dof_ptr();
            for(int i=0; i<sdof_count;i++)
            {

            }


        }
    }
}

void nlp::set_constraint_info()
{
    for(auto &iter:m_model->m_boundary)
    {


    }
}

