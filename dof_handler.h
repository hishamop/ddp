#ifndef DOF_HANDLER_H
#define DOF_HANDLER_H
#include "cmodel.h"
#include "boundary.h"
#include "boundary_cps4.h"
#include "cps4.h"
#include<vector>
#include"element.h"
class CModel;
class dof_handler
{
public:
    dof_handler(CModel*);
    void assign_dof();

    CModel*             m_model;
    int                 m_Nvar;
    std::vector<double> m_variables;
    std::vector<double> m_airys_dof;
    std::vector<double> m_disp_dof;
    std::vector<double> m_traction_dof;
private:
    dof_handler(const dof_handler&);
};

#endif // DOF_HANDLER_H
