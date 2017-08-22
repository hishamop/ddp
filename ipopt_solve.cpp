#include "ipopt_solve.h"


Ipopt_solve::~Ipopt_solve()
{

}

bool Ipopt_solve::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                             Index& nnz_h_lag, IndexStyleEnum& index_style)
{
    // No of  variables,
    n = get_Nvar();

    // No. of  equality constraint,
    m = get_Nconstr();

    //  nonzeros in the jacobian,
    nnz_jac_g = get_Nnz_jacobian();

    // nonzeros in the hessian of the lagrangian
    // (the hessian of the objective +
    //  the hessian of the constraints)
    nnz_h_lag = get_Nnz_hess_lagrangian();

    // We use the standard fortran index style for row/col entries
    index_style = C_STYLE;

    return true;

}

bool Ipopt_solve::get_bounds_info(Index n, Number* x_l, Number* x_u,
                                 Index m, Number* g_l, Number* g_u)
{

    //Copying the constraints values.
    std::copy(m_xi_lower_bound.begin(),m_xi_lower_bound.end(),x_l);
    std::copy(m_xi_upper_bound.begin(),m_xi_upper_bound.end(),x_u);

    //we only have equality constrints.
    std::copy(m_g_val.begin(),m_g_val.end(),g_l);
    std::copy(m_g_val.begin(),m_g_val.end(),g_u);

    return true;

}

bool Ipopt_solve::get_starting_point(Index n, bool init_x, Number* x,
                                   bool init_z, Number* z_L, Number* z_U,
                                   Index m, bool init_lambda,
                                   Number* lambda)
{
    // Here, we assume we only have starting values for x, if you code
    // your own NLP, you can provide starting values for the others if
    // you wish.
    assert(init_x == true);
    assert(init_z == false);
    assert(init_lambda == false);


    // we initialize x in bounds, in the upper right quadrant
    std::copy(m_xi.begin(),m_xi.end(),x);

    return true;

}

bool Ipopt_solve::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    obj_value = get_obj_val(x);

    return true;
}


bool Ipopt_solve::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    std::vector<double>temp = get_grad_fun(x);
    std::copy(temp.begin(),temp.end(),grad_f);

    return true;
}

bool Ipopt_solve::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{

    std::vector<double> temp = get_constraints(x);
    std::copy(temp.begin(),temp.end(), g);

    return true;
}



bool Ipopt_solve::eval_jac_g(Index n, const Number* x, bool new_x,
                            Index m, Index nele_jac, Index* iRow, Index *jCol,
                            Number* values)
{
    return true;

}

bool Ipopt_solve::eval_h(Index n, const Number* x, bool new_x,
                        Number obj_factor, Index m, const Number* lambda,
                        bool new_lambda, Index nele_hess, Index* iRow,
                        Index* jCol, Number* values)
{
    return true;
}

void Ipopt_solve::finalize_solution(SolverReturn status,
                                   Index n, const Number* x, const Number* z_L, const Number* z_U,
                                   Index m, const Number* g, const Number* lambda,
                                   Number obj_value,
                   const IpoptData* ip_data,
                   IpoptCalculatedQuantities* ip_cq)
{
}
