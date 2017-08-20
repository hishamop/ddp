#ifndef NLP_H
#define NLP_H
#include <vector>
#include "cmodel.h"
#include "dof_handler.h"
#include "data_store.h"
class nlp
{
public:
    nlp(CModel*);
    ~nlp();
    void initialise_dof();
    void set_constraint_info(double* vars);   // variables are passed to make expressions of const.
    int get_Nvar();
    int get_Nconstr();
    int get_Nnz_jacobian();
    int get_Nnz_hess_lagrangian();
    double get_obj_val(const double*);
    std::vector<double> get_grad_fun(const double*);
    std::vector<double> get_constraints(const double*);
    std::vector<double>& get_lower_bound();
    std::vector<double>& get_upper_bound();
    std::vector<double>& get_constraints_value();
    std::vector<double>& get_initial_values();



protected:
    nlp (nlp&);
    void initialize_elements_dofs();

    CModel*      m_model;
    data_store*  m_data = NULL;    //to store intermediate data_values;
  //  std::vector<double>     m_var;   //total variables
    int m_Nconstr;               //No of constraints
    int m_Nvar;                  //No of variables
    int m_Nnz_jacobian;          //No of nonzero in jacobian
    int m_Nnz_hess_lagrangian;   //No of nonzero in hessian of lagrgangian
    double m_obj_val;            //obj. function value
    std::vector<double> m_xi;     //initial values
    std::vector<double> m_xi_lower_bound;
    std::vector<double> m_xi_upper_bound;
    //std::vector<double> m_g;       //Constraint equations
    std::vector<double> m_g_val;   //Constraint value
   // std::vector<double> m_grad_fun; //gradient of function variables

private:
    void set_info();
};

#endif // NLP_H
