#ifndef SHAPEFN_H
#define SHAPEFN_H
#include "element.h"
#include "memory"

using elem_ptr = std::shared_ptr<element>;
class ShapeFN
{
public:
    ShapeFN();
};


class Quad4
{
public:
    Quad4(const elem_ptr elem );

protected:

};

#endif // SHAPEFN_H
