#include <fstream>
#include "cereal/archives/json.hpp"
#include "Winterval.hpp"

int main() {
    // Quick I/O sanity test.
    std::ofstream file("out.json");
    cereal::JSONOutputArchive archive(file);

    Winterval w = Winterval(-2, 3);
    w = w * Winterval(4, 5) + Winterval(-1, 1);

    archive(w);
    return 0;
}
