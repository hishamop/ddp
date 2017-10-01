#ifndef MATERIAL_H
#define MATERIAL_H
#include <vector>
#include<string>

class material
{
public:
    material();
    ~material();
    virtual const std::vector<double> get_strain(const std::vector<double>&)=0;
protected:
    std::string m_name;
};

class steel:public material
{
public:
    steel();
    const std::vector<double> get_strain(const std::vector<double>& stress);


protected:
    double _E{2e+05};   //elasticity
    double _n{0.3};     //poisson

};

#endif // MATERIAL_H
