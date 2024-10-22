#include "Base.hpp"

Base::~Base() {};

Base* generate(void)
{
	srand(time(0));
	int random = rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type!" << std::endl;
}

void identify(Base& p)
{
    A* a = dynamic_cast<A*>(&p);
    if (a) 
    {
        std::cout << "A" << std::endl;
        return;
    }

    B* b = dynamic_cast<B*>(&p);
    if (b) 
    {
        std::cout << "B" << std::endl;
        return;
    }

    C* c = dynamic_cast<C*>(&p);
    if (c) 
    {
        std::cout << "C" << std::endl;
        return;
    }

    std::cout << "Unknown type!" << std::endl;
}