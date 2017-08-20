#ifndef MATERIAL_H
#define MATERIAL_H
#include <vector>
#include<string>

class material
{
public:
    material();
    virtual const std::vector<double>& get_strain_refernce()=0;
protected:
    std::string m_name;
};

class steel:public material
{
public:
    steel();
    const std::vector<double>& get_strain_refernce();

protected:
    double _elasticity{2e+05};
    double _poisson{0.3};

};

#endif // MATERIAL_H
