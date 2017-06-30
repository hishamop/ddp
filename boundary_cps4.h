#ifndef BOUNDARY_CPS4_H
#define BOUNDARY_CPS4_H

#include "boundary.h"
#include <iostream>

class boundary_cps4 : public boundary
{
public:
    boundary_cps4(elem_ptr);
    void              set_ForceBoundary();
    void              set_ForceBoundary_values();
    void              set_boundary_faces();
    unsigned int      getindex() const;
    void              assign_traction(side);
    void              set_normal_pressure_on_face(side,traction);
    void              assign_traction(unsigned int, orientation, traction, traction);
//    void              assign_fixity(unsigned int, orientation);
    friend bool       is_id_equal(int);
};

#endif // BOUNDARY_CPS4_H
