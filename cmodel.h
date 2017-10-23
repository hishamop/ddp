#ifndef CMODEL_H
#define CMODEL_H
#include<vector>
#include<list>
#include<memory>
#include<map>
#include "node.h"
#include "element.h"
#include "cps4.h"
//#include "nodeset.h"
//#include "elset.h"
#include "boundary.h"
#include "material.h"


//using elem_ptr= element*;
using node_ptr =std::shared_ptr<node>;
using elem_ptr = std::shared_ptr<element>;
using boundary_ptr = std::shared_ptr<boundary>;
using material_ptr = std::shared_ptr<material>;
//using elset_ptr = std::shared_ptr<elset>;
//using nset_ptr = std::shared_ptr<nodeset>;

//class CFileio;
class nlp;
class CModel
{
    friend class CFileio;
    friend class dof_handler;
    friend class nlp;

public:
    CModel();

    //INTERFACE FUNCTIONS
    void add_material(std::string,material_ptr);
    void set_dof();

    //INTERFACE DISPLAY
    void                        print_nodes()               const;
    void                        print_nodeset()             const;
    void                        print_elems()               const;
    void                        print_elset()               const;
    void                        print_node_count()          const;
    void                        print_elem_count()          const;
    void                        print_boundary_elements()   const;

    void                        add_node_ptr(node_ptr);
    void                        add_node(node_ptr);
    void                        add_element(elem_ptr);
    void                        add_boundary_element(boundary_ptr);
//   void                        add_nodeset(nset_ptr);
//   void                        add_elset(elset_ptr);
//   void assert_nodeID(int) const;
    elem_ptr                    get_elem_ptr(unsigned int);
    node_ptr                    get_node_ptr(int);
    node_ptr                    get_node_ptr_with_count(int);

    const std::vector<elem_ptr>& get_element_vector() const
    {
        return m_elements;
    }

private:
    std::vector<node_ptr>                            m_nodes;
//    std::vector<node>                                m_nodes;
    std::vector<elem_ptr>                            m_elements;
    std::map<std::string,std::vector<unsigned int>>  m_nodeset_map;
    std::map<std::string,std::vector<unsigned int>>      m_elset_map;
    std::map<std::string,material_ptr>               m_material_map;
    std::map<unsigned int, boundary_ptr>             m_boundary_map;
    std::vector<boundary_ptr>                            m_boundary;
//    std::vector<nset_ptr>       m_nset;
//    std::vector<elset_ptr>      m_elemset;


    CModel (CModel&);    //Compiler defined copy const. not allowed. So defined as private.

};

#endif // CMODEL_H
