#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::stringstream ss;
        ss.str(s);

        std::vector<std::string> wyrds;
        for (std::string line; std::getline(ss, line, ' ');) {
            if (!line.empty()) {
                wyrds.push_back(line);
            }
        }

        if (!wyrds.empty()) {
            auto last = wyrds.rbegin();
            return last->length();
        }

        return 0;
    }
};

int main() {
    Solution solution;
    std::string t1{"   fly me   to   the moon  "};
    std::cout << std::boolalpha << (solution.lengthOfLastWord(t1) == 4) << std::endl;

    std::string t2{"luffy is still joyboy"};
    std::cout << std::boolalpha << (solution.lengthOfLastWord(t2) == 6) << std::endl;
}
