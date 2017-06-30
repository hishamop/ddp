#ifndef NLP_H
#define NLP_H
#include <vector>
#include "cmodel.h"
class nlp
{
public:
    nlp(CModel*);
    ~nlp();
    void initialise_dof();
    void set_constraint_info();
    
private:
    nlp (nlp&);

    CModel*      m_model;
    int m_Nconstr;               //No of constraints
    int m_Nvar;                  //No of variables
    int m_Nnz_jacobian;          //No of nonzero in jacobian
    int m_Nnz_hess_lagrangian;   //No of nonzero in hessian of lagrgangian
    double m_obj_val;            //obj. function value
//    std::vector<double> m_xi;     //initial values
    std::vector<double> m_g;       //Constraint equations
    std::vector<double> m_g_val;   //Constraint value
    std::vector<double> m_grad_fun; //gradient of function variables
};

#endif // NLP_H
