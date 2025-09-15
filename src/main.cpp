#include <iostream>
#include <ostream>

#include "Winterval.h"

void test_sanity() {
    auto winter = Winterval(0, 2);
    std::cout << winter.to_string() << std::endl;

    std::cout << winter.contains(0) << std::endl;
    std::cout << winter.contains(-1) << std::endl;
    std::cout << winter.contains(1) << std::endl;
}

void test_add() {
    auto left = Winterval(0, 2);
    auto right = Winterval(-2, 1);

    std::cout << (left + right).to_string() << std::endl;
}

void test_sub() {
    auto left = Winterval(0, 2);
    auto right = Winterval(-1, 2);

    std::cout << (left - right).to_string() << std::endl;
}

int main() {
    test_sub();
}
