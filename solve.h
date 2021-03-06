#ifndef SOLVE_H
#define SOLVE_H

#include "ipopt_solve.h"
#include "nlp.h"
#include "cmodel.h"

enum algo_type {IPOPT =1, SQP};

template<int ALG>
class solve
{
public:
    solve()
    {

    }
};

template<>
class solve<IPOPT>
{
public:
    solve(CModel*);

private:
    Ipopt_solve m_ipopt;


};

#endif // SOLVE_H
