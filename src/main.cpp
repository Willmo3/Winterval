#include <iostream>
#include <ostream>

#include "Winterval.h"

void test_sanity() {
    auto winter = Winterval(0, 2);
    std::cout << winter << std::endl;

    std::cout << winter.contains(0) << std::endl;
    std::cout << winter.contains(-1) << std::endl;
    std::cout << winter.contains(1) << std::endl;
}

void test_add() {
    auto left = Winterval(0, 2);
    auto right = Winterval(-2, 1);

    std::cout << (left + right) << std::endl;
}

void test_sub() {
    auto left = Winterval(0, 2);
    auto right = Winterval(-1, 2);

    std::cout << (left - right) << std::endl;
}

void test_mul() {
    auto left = Winterval(0, 2);
    auto right = Winterval(-2, 1);

    std::cout << (left * right) << std::endl;
}

void test_div() {
    auto left = Winterval(-1, 2);
    auto right = Winterval(-2, 1);
    std::cout << (left / right) << std::endl;

    left = Winterval(0, 2);
    std::cout << (left / right) << std::endl;

    left = Winterval(-2, 0);
    std::cout << (left / right) << std::endl;

    right = Winterval(0, 0);
    std::cout << (left / right) << std::endl;
}

void test_tanh() {
    auto base = Winterval(-1, 4);
    std::cout << base.tanh().tanh() << std::endl;
}

void test_pow() {
    auto base = Winterval(-1, 4);
    std::cout << base.pow(0) << std::endl;
    std::cout << base.pow(2) << std::endl;
    std::cout << base.pow(3) << std::endl;
}

int main() {
    test_pow();
}
