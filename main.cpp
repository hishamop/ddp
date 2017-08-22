#include <iostream>
#include "cmodel.h"
#include "cfileio.h"
using namespace std;
#include "cps4.h"
#include "element.h"
#include "solve.h"
#include<ctime>
int main()
{
    clock_t t1;
    t1 =clock();
    CModel model;
    {
        CFileio read("input.in",&model);
    }
    t1 =clock() - t1;
    cout<<t1<<endl;
   // dof_handler dof(&model);
//    model.print_boundary_elements();
    nlp problem(&model);
    solve<IPOPT> solution(&model);
    model.print_nodes();
    model.print_elems();

}

//int main()
//{
//    node a(1,2,3);
//    node b(2,2,3);
//    node c(3,3,4);
//    node d(4,4,5);

//    vector<node_ptr>n1;
//    n1.push_back(&a);
//    n1.push_back(&b);

//    n1.push_back(&c);
//    n1.push_back(&d);

//    cps4 e1(1,n1);

//    for (unsigned int i=1; i<5; i++)
//    {
//        cout<<e1.elements_shared_by_face(i);
//    }



//}
