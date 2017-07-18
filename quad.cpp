#include "quad.h"

template<int pts>
quadrature<pts>::quadrature()
{
    switch(pts)
    {
    case 10:
    {
        m_nodes.push_back(-0.1488743389816312);
        m_nodes.push_back( 0.1488743389816312);
        m_nodes.push_back(-0.4333953941292472);
        m_nodes.push_back( 0.4333953941292472);
        m_nodes.push_back(-0.6794095682990244);
        m_nodes.push_back( 0.6794095682990244);
        m_nodes.push_back(-0.8650633666889845);
        m_nodes.push_back( 0.8650633666889845);
        m_nodes.push_back(-0.9739065285171717);
        m_nodes.push_back( 0.9739065285171717);

        m_weight.push_back(0.2955242247147529);
        m_weight.push_back(0.2955242247147529);
        m_weight.push_back(0.2692667193099963);
        m_weight.push_back(0.2692667193099963);
        m_weight.push_back(0.2190863625159820);
        m_weight.push_back(0.2190863625159820);
        m_weight.push_back(0.1494513491505806);
        m_weight.push_back(0.1494513491505806);
        m_weight.push_back(0.0666713443086881);
        m_weight.push_back(0.0666713443086881);


    }
    default:
        std::cerr<<"This quadrature rule isn't implemented yet";
    }


}
