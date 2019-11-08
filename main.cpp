#include "complex.hpp"
#include <cmath>

int main() {
    complex a, b, ans;
    
    a.read(std::cin);
    b.read(std::cin);

    std::cout << "First number : ";
    a.write(std::cout);
    std::cout << "second number : ";
    b.write(std::cout);

    std::cout << "\n +\n =\n";
    ans = a.add(b);
    ans.write(std::cout);

    std::cout << "\n -\n =\n";
    ans = a.sub(b);
    ans.write(std::cout);

    std::cout << "\n *\n =\n";
    ans = a.mul(b);
    ans.write(std::cout);

    std::cout << "\n /\n =\n";
    ans = a.div(b);
    ans.write(std::cout);

    std::cout << "\nconj  =  ";
    ans = a.conj(a);
    ans.write(std::cout);
    std::cout << "\nconj  =  ";
    ans = b.conj(b);
    ans.write(std::cout);

    if (a.equ(b) == 1) {
        std::cout << "a = b\n";
    } else {
        std::cout << "a != b\n";
    }
    
}
