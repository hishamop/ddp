#ifndef SYSTEM_H
#define SYSTEM_H

#include "../../Ipopt/CoinIpopt/Ipopt/src/Interfaces/IpTNLP.hpp"
#include "cmodel.h"
using namespace Ipopt;

class system
{
public:
    system();
    ~system();

protected:
    void initialise_variables();
    int get_Nvar();
    int get_Nconstr();
    int get_Nnz_jacobian();
    int get_Nnz_hess_lagrangian();
    double get_obj_value();


protected:
    double* m_x = nullptr;   // initial values of variables.
    int     m_Nvar;         //No of variables
    int     m_Nconstr;
    int     m_Nnz_jacobian;          //No of nonzero in jacobian
    int m_Nnz_hess_lagrangian;   //No of nonzero in hessian of lagrgangian
    double m_obj_val;            //obj. function value
    std::vector<double> m_xi_lower_bound;
    std::vector<double> m_xi_upper_bound;
    std::vector<double> m_g;       //Constraint equations
    std::vector<double> m_g_val;   //Constraint value
    std::vector<double> m_grad_fun; //gradient of function variables

};

#endif // SYSTEM_H
