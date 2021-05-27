#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::cout << std::gcd(357, 234) << std::endl;

    std::vector<double> tens{100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0};

    for (const auto& ten : tens) {
        std::cout << "e : " << std::log(ten) << std::endl;
        std::cout << "2 : " << std::log2(ten) << std::endl;
    }
}