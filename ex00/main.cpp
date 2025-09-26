# include "ScalarConverter.hpp"

bool isInt(const std::string &str);
bool isFloat(const std::string &str);
bool isDouble(const std::string &str);

int main(int argc, char **argv) {
	if (argv[1])
		std::cout << isFloat(argv[1]) << std::endl;
}