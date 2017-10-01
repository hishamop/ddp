#include "material.h"

material::material()
{

}

material::~material()
{

}
/*........................
 * .............................................*/

steel::steel()
{

}


const std::vector<double> steel:: get_strain(const std::vector<double>& sts)
{
    std::vector<double> strain(3);
    strain[0]  =  (sts[0] - sts[1]*_n)/_E;
    strain[1]  =  (sts[1] - sts[0]*_n)/_E;
    strain[2]  =  2*sts[2]*(1+_n)/_E;
    return strain;
}


