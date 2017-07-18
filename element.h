#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <utility>
#include <iostream>
#include "node.h"
#include <memory>
#include<eigen3/Eigen/Dense>
enum element_type {CPS4=1,CPS8};   //Element types are equated into numbers.

using node_ptr=std::shared_ptr<node>;
using face = std::vector<node_ptr> ;

class element
{
public:
    element();
    element(int, std::vector<node_ptr>);
    virtual ~element();

    //NON-INTERFACE FUNCTIONS
    unsigned int                            getindex()       const;
    void                           print_element()  const;
    node_ptr                       getnode(int)     const;     //return nth node_ptr.
    std::vector<node_ptr>&         get_nodes() ;         //get reference of nodelist.
    void                           assign_var_vector();  //


    // VIRTUAL FUNCTIONS
    virtual std::vector<node_ptr>  get_face(unsigned int)                const =0;    // return node_ptrs of nth face of element.
    virtual element_type           get_element_type()                    const =0;
    virtual int                    faces_count()                         const =0;
    virtual bool                   is_boundary()                         const =0;
    virtual int                    elements_shared_by_face(unsigned int) const =0;
    virtual int                    get_dof_count()                       const =0;
    virtual void                   set_node_dof()                       =0;


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
