#include <iostream>
#include <ostream>

#include "Winterval.h"

int main() {
    auto winter = Winterval(0, 2);
    std::cout << winter.min() << " " << winter.max() << std::endl;

    std::cout << winter.contains(0) << std::endl;
    std::cout << winter.contains(-1) << std::endl;
    std::cout << winter.contains(1) << std::endl;
}
