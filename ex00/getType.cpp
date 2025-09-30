# include <iostream>
# include <string>
# include "ScalarConverter.hpp"

bool isPseudoLiteral(const std::string &str) {
	if (str == "-inff"
	|| str == "+inff"
	|| str == "nanf"
	|| str == "-inf"
	|| str == "+inf"
	|| str == "nan")
		return true;
	return false;
}

bool isChar(const std::string &str) {
	int len = str.length();

	if (len == 1 && !isdigit(str[0]))
		return true;
	if (len == 3 && str[0] == 39 && str[2] == 39)
		return true;
	return false;
}

bool isFloat(const std::string &str) {
	int len = str.length();
	int sign = 0;
	int i = 0;

	if (str[0] == '-' || str[0] == '+') {
		i++;
		sign = 1;
	}
	if (len == 0 || len == 1)
		return false;
	while (i < len && isdigit(str[i])) {
		i++;
	}
	if (str[i] != '.')
		return false;
	i++;
	while (i < len && isdigit(str[i])) {
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	if (str[i] != 'f' || i != len - 1)
		return false;
	return true;
}

bool isDouble(const std::string &str) {
	int len = str.length();
	int sign = 0;
	int i = 0;

	if (str[0] == '-' || str[0] == '+') {
		i++;
		sign = 1;
	}
	if (len == 0 || len == 1)
		return false;
	while (i < len && isdigit(str[i])) {
		i++;
	}
	if (str[i] != '.')
		return false;
	i++;
	while (i < len && isdigit(str[i])) {
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	if (i != len)
		return false;
	return true;
}

bool isInt(const std::string &str) {
	int i = 0;
	int sign = 0;
	int len = str.length();
	long res = 0;

	if (str[0] == '+' || str[0] == '-') {
		i++;
		sign = 1;
	}
	if (len == 0 || (len == 1 && (!isdigit(str[0]) || str[0] == '+' || str[0] == '-')))
		return false;
	while (i < len) {
		if (!isdigit(str[i]))
			return false;
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return true;
}

e_type getType(const std::string &str) {
	if (isPseudoLiteral(str))
		return PSEUDO;
	if (isInt(str))
		return INT;
	if (isFloat(str))
		return FLOAT;
	if (isChar(str))
		return CHAR;
	if (isDouble(str))
		return DOUBLE;
	return INVALID;
}