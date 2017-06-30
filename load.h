#ifndef LOAD_H
#define LOAD_H


class load
{
public:

    load();
    virtual ~load();
};

class Dload:public load
{
   public:
    Dload(unsigned int, double);

   unsigned int m_face;
   double       m_pressure_load;
};

#endif // LOAD_H
