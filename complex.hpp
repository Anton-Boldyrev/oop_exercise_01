#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

class complex {

public:
    complex();
    complex(double a, double b) : r(a), fi(b) {}
    
    void read(std::istream&);
    void write(std::ostream&) const;

    complex add(const complex& o) const;
    complex sub(const complex& o) const;
    complex mul(const complex& o) const;
    complex div(const complex& o) const;
    int equ(const complex & o) const;
    complex conj(const complex& o) const;

private:
    double r;
    double fi;
};
#endif
