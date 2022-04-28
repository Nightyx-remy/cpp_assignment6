#include <iostream>
#include "String.h"

int main() {
    String str{"Alice and Bob have mice"};

    auto alice = str.substr(0, 5); // alice contains "Alice"
    auto mice = str.substr(19); // mice contains "mice"
    std::cout << str.starts_with("alice") << std::endl; // 0
    std::cout << str.ends_with("mice") << std::endl; // 1
    std::cout << str.contains("b h") << std::endl; // `
    std::cout << str.find("ic") << std::endl; // 2
    std::cout << str.find("ic", 3) << std::endl; // 20

    return 0;
}
