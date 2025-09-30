# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base() {}

Base *Base::generate() {
    int randNum = rand() % 3;

    if (randNum == 0) {
        std::cout << "Generated instance of A" << std::endl;
        return new A();
    } else if (randNum == 1) {
        std::cout << "Generated instance of B" << std::endl;
        return new B();
    } else {
        std::cout << "Generated instance of C" << std::endl;
        return new C();
    }
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Identified type: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Identified type: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Identified type: C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void Base::identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified type: A" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified type: B" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified type: C" << std::endl;
        return;
    } catch (std::exception &e) {}

    std::cout << "Unknown type" << std::endl;
}