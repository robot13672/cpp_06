#include "Base.hpp"

int main() {
    Base* base = generate();

    std::cout << "Identification through a pointer: ";
    identify(base);

    std::cout << "Identification through reference: ";
    identify(*base);

    delete base;

    return 0;
}