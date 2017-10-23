//comments added
#ifndef CPS4_H
#define CPS4_H
#include "element.h"
#include "common.h"
#include "quad.h"
#include "feval.h"

using material_ptr = std::shared_ptr<material>;

class cps4 :public element
{


public:

    class unit_stress
    {
    public:
        unit_stress(double sval, double tval): _sval(sval),_tval(tval){}
            

    private:
        double _sval;
        double _tval;
        
    };

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
//    std::vector<double>    get_stress_vector(double sval, double tval, const double* dof) const;
    double get_objval(const std::vector<double>& x, material_ptr material, FEval& vals) const;
    //double get_objval(const std::vector<double>& x, material_ptr material, int quad_pts) const;
    std::vector<double> get_ref_dof(std::vector<double>& Dof) const;
    std::vector<double> get_standard_stress_dof(const double* var_list);
    std::vector<double> get_standard_stress_dof(const std::vector<double>& var_list);


protected:


  //  Matrix<double,3,24>   Bd_mat;

private:
    cps4(cps4&);




};

#endif // CPS4_H
