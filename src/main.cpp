
#include <iosfwd>

#include "Winterval.hpp"
#include "../lib/cereal/archives/json.hpp"

int main() {
    std::stringstream ss;
    // Scoping necessary to ensure data leaves scope.
    {
        cereal::JSONOutputArchive archive(ss);
        auto w = Winterval(0, 2);
        archive( w );
    }

    cereal::JSONInputArchive archive(ss);
    Winterval w2 = Winterval(0, 0);
    archive( w2 );
    std::cout << w2 << std::endl;

    return 0;
}
