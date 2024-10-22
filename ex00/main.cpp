#include "ScalarConverter.hpp"

int main()
{
	ScalarConverter f;
	f.convert("3.12313e+17");
	f.convert("127");
	f.convert("nan");
}