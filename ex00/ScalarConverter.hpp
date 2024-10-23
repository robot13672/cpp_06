#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> 
#include <cctype>
#include <climits>

class ScalarConverter
{
	private:
	void checkPsuedo(std::string str)
	{
		if (str == "nan" || str == "NAN" || str == "+inf" || str == "inf" || str == "-inf" || str == "+inff" || str == "inff" || str == "-inff" || str == "nanf" || str == "NANf")
		{
			std::cout << "char:   " << "impossible" << std::endl;
			std::cout << "int:    " << "impossible" << std::endl;
			if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf" || str == "NANf")
			{
				std::cout << "float   " << str << std::endl;
				std::cout << "double  " << str.substr(0, str.length() - 1) << std::endl;
			}
			else
			{
				std::cout << "float   " << str << "f" << std::endl;
				std::cout << "double  " << str << std::endl;
			}
			exit(0);
		}
	}
	public:
		void convert(std::string str)
		{
			float floatVal;
			double doubleVal;

			if (str.empty())
			{
				std::cerr << "Error: empty line";
				exit(1);
			}
			checkPsuedo(str);//here I check for special values
			try
			{
				char* end;
				floatVal = std::strtof(str.c_str(), &end);
				if (*end != '\0')
					throw std::invalid_argument("Invalid float value");
				doubleVal = std::strtod(str.c_str(), &end);
				if (*end != '\0')
					throw std::invalid_argument("Invalid double value");
			}
			catch (const std::invalid_argument&)
			{
				std::cerr << "Error: invalid input" << std::endl;
				exit(1);
			}
			catch (const std::out_of_range&)
			{
				std::cerr << "Error: value out of range" << std::endl;
				exit(1);
			}
			if (floatVal < CHAR_MIN || floatVal > CHAR_MAX || floatVal < 0)
				std::cout << "char:   impossible" << std::endl;
			else if((floatVal > 0 && floatVal < 32) || floatVal == 127)
				std::cout << "char:   Non displayable" << std::endl;
			else
				std::cout << "char:   " << static_cast<char>(floatVal) << std::endl;

			if (floatVal < INT_MIN || floatVal > INT_MAX)
				std::cout << "int:    impossible" << std::endl;
			else
				std::cout << "int:    " << static_cast<int>(floatVal) << std::endl;

			std::cout << "float:  " << floatVal << "f" << std::endl;
			std::cout << "double: " << doubleVal << std::endl;
		}

};


#endif 
