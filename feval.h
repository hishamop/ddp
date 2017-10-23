#ifndef FEVAL_H
#define FEVAL_H
#include "common.h"
#include "element.h"



class FEval
{
public:
    FEval();
    FEval(element_type type):m_type{type},m_qpts{10}{}
    FEval( element_type type ,int quad_pts):m_type{type},m_qpts{quad_pts}{}
    void compute();
    std::vector<Eigen::MatrixXd>& get_bsmat()
    {
        return m_bsmat;
    }



private:
    element_type m_type;
    int m_qpts;
    std::vector<Eigen::MatrixXd> m_bsmat;
    std::vector<Eigen::MatrixXd> m_bdmat;

    void cps4_bsmat();
    void cps4_bdmat();
};

#endif // FEVAL_H
