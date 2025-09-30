# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Base* basePtr = Base().generate();
	Base().identify(basePtr);
	Base().identify(*basePtr);

	delete basePtr;
	return 0;
}