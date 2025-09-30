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

int ft_stoi(const std::string &str) {
	int result = 0;
	size_t i = 0;
	int sign = 1;

	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < str.length() && std::isdigit(str[i])) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * sign;
}

float ft_stof(const std::string &str) {
	size_t i = 0;
	int sign = 1;
	float result = 0.0f;
	float decimalPlace = 0.1f;

	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < str.length() && std::isdigit(str[i])) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i < str.length() && str[i] == '.') {
		i++;
		while (i < str.length() && std::isdigit(str[i])) {
			result += (str[i] - '0') * decimalPlace;
			decimalPlace *= 0.1f;
			i++;
		}
	}
	return result * sign;
}

double ft_stod(const std::string &str) {
	size_t i = 0;
	int sign = 1;
	double result = 0.0;
	double decimalPlace = 0.1;

	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < str.length() && std::isdigit(str[i])) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i < str.length() && str[i] == '.') {
		i++;
		while (i < str.length() && std::isdigit(str[i])) {
			result += (str[i] - '0') * decimalPlace;
			decimalPlace *= 0.1;
			i++;
		}
	}
	return result * sign;
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

void convertInt(const std::string &toConvert) {
	int intValue = ft_stoi(toConvert);
	
	if (intValue < 0 || intValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(intValue))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
	if (ft_stod(toConvert) < static_cast<int>(INT_MIN) || ft_stod(toConvert) > static_cast<int>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
}

void convertFloat(const std::string &toConvert) {
	float floatValue = ft_stof(toConvert);

	if (floatValue < 0 || floatValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(floatValue)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
	if (floatValue < static_cast<float>(INT_MIN) || floatValue > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
	if (floatValue == static_cast<int>(floatValue))
        std::cout << "float: " << static_cast<float>(floatValue) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(floatValue) << "f" << std::endl;
    if (floatValue == static_cast<int>(floatValue))
        std::cout << "double: " << floatValue << ".0" << std::endl;
    else
        std::cout << "double: " << floatValue << std::endl;}

void convertDouble(const std::string &toConvert) {
    double doubleValue = ft_stod(toConvert);

    if (doubleValue < 0 || doubleValue > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(doubleValue)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
    if (doubleValue < static_cast<double>(INT_MIN) || doubleValue > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
    if (doubleValue < -(FLT_MAX) || doubleValue > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else {
        if (doubleValue == static_cast<int>(doubleValue))
            std::cout << "float: " << static_cast<float>(doubleValue) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
    }
    if (doubleValue == static_cast<int>(doubleValue))
        std::cout << "double: " << doubleValue << ".0" << std::endl;
    else
        std::cout << "double: " << doubleValue << std::endl;
}

void convertChar(const std::string &toConvert) {
	char charValue = toConvert[0];
	int intValue = static_cast<int>(charValue);
	float floatValue = static_cast<float>(charValue);
	double doubleValue = static_cast<double>(charValue);

	if (!std::isprint(charValue))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << floatValue << ".0f" << std::endl;
	std::cout << "double: " << doubleValue << ".0" << std::endl;
}

void invalidConvert(const std::string &toConvert) {
	(void)toConvert;
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

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