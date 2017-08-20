//comments added
#ifndef CPS4_H
#define CPS4_H
#include <utility>
#include "element.h"


class cps4 :public element
{
public:
    cps4(int id, std::vector<node_ptr>);
    ~cps4();
    void print_element() const;


    //virtual functions
    int get_dof_count() const;
    void set_node_dof();
    void set_faces();
    std::vector<node_ptr> get_face(unsigned int) const ;
    int elements_shared_by_face    (unsigned int ) const;
    element_type get_element_type() const;
    int faces_count() const;
    bool is_boundary() const;
    unsigned int getindex() const;

protected:


  //  Matrix<double,3,24>   Bd_mat;

private:
    cps4(cps4&);



};

#endif // CPS4_H
