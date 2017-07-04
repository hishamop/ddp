#include "nlp.h"
#include "element.h"
#include "boundary.h"
using elem_ptr = std::shared_ptr<element>;

nlp::nlp(CModel* m)
{
    m_model =m;
}

nlp::~nlp()
{
}



void nlp::set_constraint_info()
{
    for(auto &iter:m_model->m_boundary)
    {


    }
}

