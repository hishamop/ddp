#include "load.h"

load::load()
{

}

load::~load()
{

}

//.........................................................................................//
//.........................................................................................//
Dload::Dload(unsigned int side, double pressure)
{
    m_face =side;
    m_pressure_load = pressure;
}
