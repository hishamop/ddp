#include "nlp.h"
#include "element.h"
#include "boundary.h"
#include "quad.h"
#include "feval.h"
#include "material.h"
#include <algorithm>
using elem_ptr = std::shared_ptr<element>;
using material_ptr =std::shared_ptr<material>;

nlp::nlp(CModel* m)
{
    m_model =m;
    set_info();
}

nlp::~nlp()
{
}

void nlp::set_info()
{
    // count no of variables in the problem and set initial variables.

    m_Nvar = 32*m_model->m_elements.size();

    //Initial variables
    m_xi.resize(m_Nvar);     //every variable is initialised to zero.


}

double nlp::get_obj_val(const double* x )
{
    std::vector<double> _var(m_Nvar);
    for(int i=0; i<m_Nvar; i++)
    {
        _var.push_back(x[i]);
    }
    double obj_val=0.0;
    FEval precomputed(CPS4,m_gauss_degree);
    material_ptr matrl =std::make_shared<steel>();
    //obj_fun at each element is calculated and accumulated. used functor obj_fun.
    for(auto const & iter: m_model->m_elements)
    {
        std::vector<double> stress_dof = iter->get_standard_stress_dof(_var);
        obj_val += iter->get_objval(_var,matrl,precomputed);
    }
    return obj_val;
}

void nlp::set_constraint_info(double *x)
{

 //   initialize_elements_dof();
    for(auto &iter:m_model->m_boundary)
    {


    }
}

int nlp::get_Nvar()
{
    return m_Nvar;
}

int nlp::get_Nconstr()
{
    return m_Nconstr;
}

int nlp::get_Nnz_jacobian()
{
    return m_Nnz_jacobian;
}

std::vector<double>& nlp::get_lower_bound()
{
    return m_xi_lower_bound;
}

std::vector<double>& nlp::get_upper_bound()
{
    return m_xi_upper_bound;
}


int nlp::get_Nnz_hess_lagrangian()
{
    return 1;
}

std::vector<double> nlp::get_grad_fun(const double*)
{
    std::vector<double> grad_fun;


    return grad_fun;
}


std::vector<double> nlp::get_constraints(const double*)
{
    std::vector<double> constraints;
    return constraints;
}

