#include <iostream>
#include <string>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        const std::string dot{"."};
        const std::string defang{"[.]"};
        std::string::size_type pos = address.find(dot, 0);
        while (pos != std::string::npos) {
            address.replace(pos, 1, defang);
            pos += defang.length();
            pos = address.find(dot, pos);
        }

        return address;
    }
};

int main() {
    std::string test1{"1.1.1.1"};
    Solution solution;
    std::cout << solution.defangIPaddr(test1) << std::endl;

    std::string test2{"255.100.50.0"};
    std::cout << solution.defangIPaddr(test2) << std::endl;
}