# include "ScalarConverter.hpp"

bool isInt(const std::string &str);
bool isFloat(const std::string &str);
bool isDouble(const std::string &str);

int main(int argc, char **argv) {
	if (argv[1])
		ScalarConverter::convert(argv[1]);
	// ScalarConverter::convert("a");
	// ScalarConverter::convert("42");
	// ScalarConverter::convert("nan");
	// ScalarConverter::convert("nanf");
	// ScalarConverter::convert("+inf");
	// ScalarConverter::convert("-inff");
	// ScalarConverter::convert("2147483648");
	// ScalarConverter::convert("42.0f");
	// ScalarConverter::convert("42.0");
	// ScalarConverter::convert("random");
}