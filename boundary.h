#ifndef BOUNDARY_H
#define BOUNDARY_H
#include <vector>
#include <list>
#include <utility>
#include <map>
#include <tuple>
#include "element_types.h"
#include "element.h"
#include "load.h"
using load_ptr = std::shared_ptr<load>;
using elem_ptr = std::shared_ptr<element>;
typedef unsigned int            side;
typedef unsigned int            orientation;
typedef double                  traction;
typedef unsigned int            node_No;

class boundary
{
public:
    boundary();
    unsigned int get_index();
    void       set_load(load_ptr);
    elem_ptr   get_elem_ptr() const;
    virtual void       set_boundary_faces()                                                   =0;
    virtual unsigned int        getindex()                                             const  =0;
    virtual void       assign_traction(side)                                                  =0;
    virtual void       assign_traction(unsigned int , orientation,traction,traction )         =0;
    virtual void       set_normal_pressure_on_face(side,traction)                             =0;
    virtual void       set_ForceBoundary()                                                    =0;
    virtual void       set_ForceBoundary_values()                                             =0;

protected:
    elem_ptr                                                m_boundary_element_ptr;     // pointer to boundary element.
    std::map <node_No, std::array<traction,2>>              m_traction{};
    std::map<side, double>                                  m_pressure_on_face;
    std::map <node_No, std::array<traction,2>>              m_unknown_traction{};
 //   std::map <node_No, std::vector<unsigned int>>           m_fixity;
    std::vector <side>                                      m_boundary_faces{};
 //   std::vector<double>                                     m_dload{};
    std::vector<load_ptr>                                   m_loads{};
    std::vector<double>                                     m_ForceBoundary;
    std::vector<double>                                     m_FB_val;

    //virtual void get_face_nodes(unsigned int,unsigned int&, unsigned int&)                            =0;

};


#endif // BOUNDARY_H
