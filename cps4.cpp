#include "cps4.h"
#include <cassert>
#include<material.h>
#include <algorithm>
#include<eigen3/Eigen/Dense>
using namespace Eigen;
using quad_ptr = std::shared_ptr<quadrature>;
using material_ptr = std::shared_ptr<material>;
cps4::cps4(int id, std::vector<node_ptr> nodes)
{
    m_type =CPS4;
    m_elem_id=id;
    m_ENode_ptrs.reserve(4);
    m_ENode_ptrs=nodes;

    for(auto& iter:m_ENode_ptrs)
    {
        iter->set_dof(24,8);
    }
}

cps4::~cps4()
{

}

int cps4::get_dof_count() const
{
    return 32;
}

void cps4::set_node_dof()
{
    for(auto& iter:m_ENode_ptrs)
    {
        iter->set_dof(24,8);
    }
}

std::vector<node_ptr> cps4::get_face(unsigned int i) const
{
    std::vector<node_ptr> temp;
    if(i !=3)
    {
        temp.push_back(m_ENode_ptrs.at(i));
        temp.push_back(m_ENode_ptrs.at(i+1));
    }
    else
    {
        temp.push_back(m_ENode_ptrs.at(3));
        temp.push_back(m_ENode_ptrs.at(0));
    }

    return temp;
}

int cps4::elements_shared_by_face(unsigned int i) const
{
    std::vector<node_ptr> face = get_face(i);
    std::vector<unsigned int> v1 = face.at(0)->get_shared_elements_id() ; std::sort(v1.begin(),v1.end());
    std::vector<unsigned int> v2 = face.at(1)->get_shared_elements_id() ; std::sort(v2.begin(),v2.end());
    std::vector<unsigned int> intersection ;
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(intersection,intersection.begin()));
    return intersection.size();
}

element_type cps4::get_element_type() const
{
    return m_type;
}



int cps4::faces_count() const
{
    return 4;
}

bool cps4::is_boundary( ) const
{
    bool flag =false;
    for(int i=0; i<4; i++)
    {
        if(elements_shared_by_face(i) == 1)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

unsigned int cps4::getindex() const
{
    return m_elem_id;
}



//std::vector<double>    cps4::get_stress_vector(double sval, double tval, std::vector<double> dof,
//                                                     cell_type = m_type
//                                                     )                   const
//{


//    std::vector<double> stress_vec(3);
//    std::vector<double> sxx_coeff(24,0.0);
//    std::vector<double> syy_coeff(24,0.0);
//    std::vector<double> sxy_coeff(24,0.0);

//    sxx_coeff[0]=  (3*tval*(sval - 1)*(sval^2 + sval + 5*tval^2 - 5))/8;
//    sxx_coeff[1]= 3*tval*(sval - 1)^2*(sval + 1)/8;
//    sxx_coeff[2] = (sval - 1)*(3*sval^2*tval - sval^2 + 3*sval*tval - sval + 15*tval^3 - 3*tval^2 - 15*tval + 3)/8;
//    sxx_coeff[4] = (sval - 1)*(tval - 1)*(5*tval^2 + 2*tval - 1)/8;
//    sxx_coeff[5] = (3*tval - 1)*(sval - 1)^2*(sval + 1)/8;
//    sxx_coeff[6]= 3*tval*(sval + 1)*(- sval^2 + sval - 5*tval^2 + 5)/8;
//    sxx_coeff[7] = 3*tval*(sval - 1)*(sval + 1)^2/8;
//    sxx_coeff[8] = -(sval + 1)*(3*sval^2*tval - sval^2 - 3*sval*tval + sval + 15*tval^3 - 3*tval^2 - 15*tval + 3)/8;
//    sxx_coeff[10]= -(sval + 1)*(tval - 1)*(5*tval^2 + 2*tval - 1)/8;
//    sxx_coeff[11] = (3*tval - 1)*(sval - 1)*(sval + 1)^2/8;
//    sxx_coeff[12] = 3*tval*(sval + 1)*(sval^2 - sval + 5*tval^2 - 5)/8;
//    sxx_coeff[13] = -3*tval*(sval - 1)*(sval + 1)^2/8;
//    sxx_coeff[14] = (sval + 1)*(-3*sval^2*tval - sval^2 + 3*sval*tval + sval - 15*tval^3 - 3*tval^2 + 15*tval + 3)/8;
//    sxx_coeff[16] = (sval + 1)*(tval + 1)*(5*tval^2 - 2*tval - 1)/8;
//    sxx_coeff[17] = (3*tval + 1)*(sval - 1)*(sval + 1)^2/8;
//    sxx_coeff[18] = -(3*tval*(sval - 1)*(sval^2 + sval + 5*tval^2 - 5))/8;
//    sxx_coeff[19] = -3*tval*(sval - 1)^2*(sval + 1)/8;
//    sxx_coeff[20]= (sval - 1)*(3*sval^2*tval + sval^2 + 3*sval*tval + sval + 15*tval^3 + 3*tval^2 - 15*tval - 3)/8;
//    sxx_coeff[22] = (sval - 1)*(tval + 1)*(- 5*tval^2 + 2*tval + 1)/8;
//    sxx_coeff[23] = (3*tval + 1)*(sval - 1)^2*(sval + 1)/8;


//    syy_coeff[0] = (3*sval*(tval - 1)*(5*sval^2 + tval^2 + tval - 5))/8;
//    syy_coeff[1] = (tval - 1)*(15*sval^3 - 3*sval^2 + 3*sval*tval^2 + 3*sval*tval - 15*sval - tval^2 - tval + 3)/8;
//    syy_coeff[2] = 3*sval*(tval - 1)^2*(tval + 1)/8;
//    syy_coeff[3] = (sval - 1)*(tval - 1)*(5*sval^2 + 2*sval - 1)/8;
//    syy_coeff[5] = (3*sval - 1)*(tval - 1)^2*(tval + 1)/8;
//    syy_coeff[6] = -3*sval*(tval - 1)*(5*sval^2 + tval^2 + tval - 5)/8;
//    syy_coeff[7]= (tval - 1)*(15*sval^3 + 3*sval^2 + 3*sval*tval^2 + 3*sval*tval - 15*sval + tval^2 + tval - 3)/8;
//    syy_coeff[8]= -3*sval*(tval - 1)^2*(tval + 1)/8;
//    syy_coeff[9]= ((sval + 1)*(tval - 1)*(- 5*sval^2 + 2*sval + 1))/8;
//    syy_coeff[11] = (3*sval + 1)*(tval - 1)^2*(tval + 1)/8;
//    syy_coeff[12] = 3*sval*(tval + 1)*(5*sval^2 + tval^2 - tval - 5)/8;
//    syy_coeff[13] = (tval + 1)*(-15*sval^3 - 3*sval^2 - 3*sval*tval^2 + 3*sval*tval + 15*sval - tval^2 + tval + 3)/8;
//    syy_coeff[14]= -3*sval*(tval - 1)*(tval + 1)^2/8;
//    syy_coeff[15] = (sval + 1)*(tval + 1)*(5*sval^2 - 2*sval - 1)/8;
//    syy_coeff[17]= (3*sval + 1)*(tval - 1)*(tval + 1)^2/8;
//    syy_coeff[18] = (3*sval*(tval + 1)*(-5*sval^2 - tval^2 + tval + 5))/8;
//    syy_coeff[19] = (tval + 1)*(-15*sval^3 + 3*sval^2 - 3*sval*tval^2 + 3*sval*tval + 15*sval + tval^2 - tval - 3)/8;
//    syy_coeff[20] = 3*sval*(tval - 1)*(tval + 1)^2/8;
//    syy_coeff[21] = -(sval - 1)*(tval + 1)*(5*sval^2 + 2*sval - 1)/8;
//    syy_coeff[23] = (3*sval - 1)*(tval - 1)*(tval + 1)^2/8;

//    sxy_coeff[0] = -(15*sval^4 + 18*sval^2*tval^2 - 36*sval^2 + 15*tval^4 - 36*tval^2 + 24)/32;
//    sxy_coeff[1]= -(3*sval + 1)*(sval - 1)*(5*sval^2 + 2*sval + 6*tval^2 - 9)/32;
//    sxy_coeff[2] = -(3*tval + 1)*(tval - 1)*(6*sval^2 + 5*tval^2 + 2*tval - 9)/32;
//    sxy_coeff[3] = -(5*sval + 1)*(sval - 1)^2*(sval + 1)/32;
//    sxy_coeff[4] = -(5*tval + 1)*(tval - 1)^2*(tval + 1)/32;
//    sxy_coeff[5] = -(3*sval + 1)*(3*tval + 1)*(sval - 1)*(tval - 1)/16;
//    sxy_coeff[6] = (15*sval^4 + 18*sval^2*tval^2 - 36*sval^2 + 15*tval^4 - 36*tval^2 + 24)/32;
//    sxy_coeff[7] = (3*sval - 1)*(sval + 1)*(- 5*sval^2 + 2*sval - 6*tval^2 + 9)/32;
//    sxy_coeff[8] = (3*tval + 1)*(tval - 1)*(6*sval^2 + 5*tval^2 + 2*tval - 9)/32;
//    sxy_coeff[9] = (5*sval - 1)*(sval - 1)*(sval + 1)^2/32;
//    sxy_coeff[10]= (5*tval + 1)*(tval - 1)^2*(tval + 1)/32;
//    sxy_coeff[11] = -(3*sval - 1)*(3*tval + 1)*(sval + 1)*(tval - 1)/16;
//    sxy_coeff[12]= -(15*sval^4 + 18*sval^2*tval^2 - 36*sval^2 + 15*tval^4 - 36*tval^2 + 24)/32;
//    sxy_coeff[13] = (3*sval - 1)*(sval + 1)*(5*sval^2 - 2*sval + 6*tval^2 - 9)/32;
//    sxy_coeff[14]= (3*tval - 1)*(tval + 1)*(6*sval^2 + 5*tval^2 - 2*tval - 9)/32;
//    sxy_coeff[15] = -(5*sval - 1)*(sval - 1)*(sval + 1)^2/32;
//    sxy_coeff[16]= -(5*tval - 1)*(tval - 1)*(tval + 1)^2/32;
//    sxy_coeff[17] = -(3*sval - 1)*(3*tval - 1)*(sval + 1)*(tval + 1)/16;
//    sxy_coeff[18] = (15*sval^4 + 18*sval^2*tval^2 - 36*sval^2 + 15*tval^4 - 36*tval^2 + 24)/32;
//    sxy_coeff[19] = (3*sval + 1)*(sval - 1)*(5*sval^2 + 2*sval + 6*tval^2 - 9)/32;
//    sxy_coeff[20] = (3*tval - 1)*(tval + 1)*(-6*sval^2 - 5*tval^2 + 2*tval + 9)/32;
//    sxy_coeff[21] = (5*sval + 1)*(sval - 1)^2*(sval + 1)/32;
//    sxy_coeff[22] = (5*tval - 1)*(tval - 1)*(tval + 1)^2/32;
//    sxy_coeff[23] = -(3*sval + 1)*(3*tval - 1)*(sval - 1)*(tval + 1)/16;


//    return stress_vec;

//}

//double cps4::get_objval(const double *x, material_ptr material,quad_ptr quad) const
//{
//    double objval;
//    Matrix<double,24,3> _bsmat;
//    _pts = quad->get_degree();
//    for (auto& sval:m_quad->get_nodes())
//    {
//        for(auto& tval:mquad->get_nodes())
//        {

//            std::vector<double> stress_vec =this->get_stress_vector();
//            std::vector<double> strain=material->get_strain(stress_vec);

//        }
//    }





//    return objval;

//}






