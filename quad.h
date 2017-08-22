#ifndef QUAD_H
#define QUAD_H
#include<vector>
#include<iostream>

class quadrature
{
public:
    quadrature(int);
    const std::vector<double>& get_nodes() const
    {
        return m_nodes;
    }
    const std::vector<double>& get_weight() const
    {
        return m_weight;
    }

private:
    int                  m_pts;
    std::vector<double>  m_nodes;
    std::vector<double>  m_weight;
    void set_gauss_val(const double*,const double*);
};

#endif // QUAD_H
