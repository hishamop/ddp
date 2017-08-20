#ifndef OBJ_FUN_H
#define OBJ_FUN_H
#include "element_types.h"
#include <memory>
#include "quad.h"
using elem_ptr = std::shared_ptr<element>;
using quad_ptr = quadrature*;
class objval
{
public:
    objval(double* var,quad_ptr q):m_var(var),m_quad(q) {}
    double operator() (double cum, const elem_ptr element); //functor function
    double obj_val() (const elem_ptr element)
    {
        unsigned int elem_id =element->getindex();
        // (elem_id x 32,elem_id x 32+23)  stress_dof.
        //  (elem_id*32+24,elem_id*32+31)  disp_dof.

        return 0.0;







    }

private:
    double m_obj_val;
    double*  m_var;
    quad_ptr m_quad;
};

#endif // OBJ_FUN_H
