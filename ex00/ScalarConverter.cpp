#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

void convertPseudo(const std::string &toConvert) {
	if (toConvert == "nan" || toConvert == "nanf") {
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
	}
	if (toConvert == "-inf" || toConvert == "-inff") {
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
	}
	if (toConvert == "+inf" || toConvert == "+inff") {
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
	}
}

void convertInt(const std::string &toConvert) { }

void convertFloat(const std::string &toConvert) { }

void convertDouble(const std::string &toConvert) { }

void convertChar(const std::string &toConvert) { }

void invalidConvert(const std::string &toConvert) { }

void ScalarConverter::convert(const std::string &toConvert) {
	e_type type = getType(toConvert);
	
	switch (type) {
		case PSEUDO:
			convertPseudo(toConvert);
			break ;
		case INT:
			convertInt(toConvert);
			break ;
		case FLOAT:
			convertFloat(toConvert);
			break ;
		case DOUBLE:
			convertDouble(toConvert);
			break ;
		case CHAR:
			convertChar(toConvert);
			break ;
		case INVALID:
			invalidConvert(toConvert);
			break ;
	}	
}