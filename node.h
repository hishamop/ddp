#ifndef NODE_H
#define NODE_H


#include <vector>
class node
{
private:
    float m_xcord,m_ycord,m_zcord;
    int m_id;
    std::vector<unsigned int>m_incident_elements;// ids of shared elements.
    std::vector<double>m_dispDof;                // x,y,z displacement at nodes.
    std::vector<double>m_stressDof;              // stress Dof at node.
    int m_Nddof;
    int m_Nsdof;
    std::vector<double>  m_ddof;
    std::vector<double>  m_sdof ;

    node (node&);
    node& operator=(const node&);
public:
    node();
    node(int id,float x,float y);
    node(int id,float x, float y, float z);
    ~node();

    const double x()
    {
        return m_xcord;
    }

    const double y()
    {
        return m_ycord;
    }

    void set_dof(int nStsDof, int nDispDof);
    std::vector<double> &get_disp_dof_reference();
    std::vector<double>& get_stress_dof_reference();

    int get_Nddof();
    int get_Nsdof();
    void printnode() const;
    void set_stressDof(int pos, double val);
    void set_dispDof(int constrain_no);
    int getindex() const;
    std::vector<unsigned int> get_shared_elements_id()const ;
    bool is_boundary_node();
    void add_incident_elem_id(unsigned int);
};
#endif // NODE_H
