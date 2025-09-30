#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits.h>
# include <float.h>

typedef enum e_types {
	PSEUDO = 1,
	INT = 2,
	FLOAT = 3,
	CHAR = 4,
	DOUBLE = 5,
	INVALID = -1
}		e_type;

class ScalarConverter
{
protected:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
	static void convert(const std::string &toConvert);
};

e_type getType(const std::string &str);

#endif
