#ifndef QUAD_H
#define QUAD_H
#include<vector>
#include<iostream>
template<int pts>
class quadrature
{
public:
    quadrature();
    const std::vector<double>& get_nodes() const
    {
        return m_nodes;
    }
    const std::vector<double>& get_weight() const
    {
        return m_weight;
    }

private:
    int m_pts{pts};
    std::vector<double>  m_nodes[pts];
    std::vector<double>  m_weight[pts];
    void set_gauss_val(const double*,const double*);
};

#endif // QUAD_H
