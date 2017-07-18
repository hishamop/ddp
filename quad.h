#ifndef QUAD_H
#define QUAD_H
#include<vector>
#include<iostream>
template<int pts>
class quadrature
{
public:
    quadrature();

private:
    std::vector<double>  m_nodes[pts];
    std::vector<double>  m_weight[pts];

};

#endif // QUAD_H
