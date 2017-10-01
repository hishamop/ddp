#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <utility>
#include <iostream>
#include "node.h"
#include "material.h"
#include <memory>
#include <quad.h>
#include<eigen3/Eigen/Dense>
using namespace Eigen;

enum element_type {CPS4=1,CPS8};   //Element types are equated into numbers.
enum cell_type {unit_cell=1,actual_cell};
using node_ptr=std::shared_ptr<node>;
using face = std::vector<node_ptr> ;

class element
{
public:
    class unit_stress   //Stress coefficients in unit cell i.e Bsmat.
    {
    public:
        unit_stress(double sval,double tval):_sval(sval),_tval(tval){}

        double _sval;
        double _tval;
    };

    element();
    element(int, std::vector<node_ptr>);
    virtual ~element();

    //INTERFACE FUNCTIONS
    unsigned int                   getindex()       const;
    void                           print_element()  const;
    node_ptr                       getnode(int)     const;         //return nth node_ptr.
    const std::vector<node_ptr>&   get_nodes()      const
    {
        return m_ENode_ptrs;
        }
    //get reference of nodelist.
    void                           assign_var_vector();            //

    //Interface functions


    // VIRTUAL FUNCTIONS

    virtual std::vector<node_ptr>  get_face(unsigned int)                const =0;    // return node_ptrs of nth face of element.
    virtual element_type           get_element_type()                    const =0;
    virtual int                    faces_count()                         const =0;
    virtual bool                   is_boundary()                         const =0;
    virtual int                    elements_shared_by_face(unsigned int) const =0;
    virtual int                    get_dof_count()                       const =0;
    virtual void                   set_node_dof()                       =0;
//    virtual std::vector<double>    get_stress_vector(std::vector<double> dof
 //                                                    )                   const =0;
 //   virtual double                 get_objval(const double* x,
  //                                            quadrature quad)           const =0;


protected:
    int                            m_elem_id;
    std::vector<node_ptr>          m_ENode_ptrs;
    element_type                   m_type;
    std::vector<double>*           m_variable_ptr;
    //PROTECTED
    //FUNCTIONS RELATED TO MAPPING.

private:
    element (element&);
    element& operator=(const element&);

};


#endif // ELEMENT_H
