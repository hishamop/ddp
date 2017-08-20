#ifndef SHAPEFN_H
#define SHAPEFN_H
#include "element.h"

using elem_ptr = std::shared<element>;
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
