#ifndef OBJ_FUN_H
#define OBJ_FUN_H
#include "element_types.h"
#include <memory>
using elem_ptr = std::shared_ptr<element>;
class obj_fun
{
public:
    obj_fun(double* var):m_var(var) {}
    double operator() (double cum, const elem_ptr element); //functor function
private:
    double m_obj_val;
    double*  m_var;
};

#endif // OBJ_FUN_H
