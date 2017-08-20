#ifndef CFILEIO_H
#define CFILEIO_H
#include <iostream>
#include <fstream>
#include "cmodel.h"
#include "element_types.h"
class CModel;
class CFileio
{
public:
    CFileio(std::string , CModel*);
    void print_numberofnodes() const;                // print number of nodes in the mesh
    void print_numberofelements() const;             //
    void print_nodeset();                            // print nodesets.
    void print_nodeset(std::string);                 // print nodeset with name-id.
    void print_elset() const;
    void print_elset(std::string) const;

private:
    std::ifstream m_File;
    CModel* m_model;
    void read_nodes();
    void read_elems(std::string);
    void read_nodeset(std::string);
    void read_elset(std::string);
    void read_nloads();
    void read_dload();
    void read_disp();
    void read_fixity();
    void set_boundary();
    void read_boundary();
    void read_material(std::string line);
};

#endif // CFILEIO_H
