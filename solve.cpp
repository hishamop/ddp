#include "solve.h"

solve<IPOPT>::solve(CModel* problem): m_ipopt(problem)
{

}

class solve<1> ;
class solve<2>;
