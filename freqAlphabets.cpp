#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string freqAlphabets(std::string s) {
        std::unordered_map<std::string, char> decoder{
                {"1", 'a'},   {"2", 'b'},   {"3", 'c'},   {"4", 'd'},   {"5", 'e'},   {"6", 'f'},
                {"7", 'g'},   {"8", 'h'},   {"9", 'i'},   {"10#", 'j'}, {"11#", 'k'}, {"12#", 'l'},
                {"13#", 'm'}, {"14#", 'n'}, {"15#", 'o'}, {"16#", 'p'}, {"17#", 'q'}, {"18#", 'r'},
                {"19#", 's'}, {"20#", 't'}, {"21#", 'u'}, {"22#", 'v'}, {"23#", 'w'}, {"24#", 'x'},
                {"25#", 'y'}, {"26#", 'z'}};

        std::string coded{};
        while (!s.empty()) {
            auto chunk(s.substr(0, 3));
            auto hash(chunk.find('#'));
            if (hash == std::string::npos) {
                chunk = s.substr(0, 1);
            }

            if (auto decoded{decoder.find(chunk)}; decoded != decoder.end()) {
                coded.append({decoded->second});
            }
            s = s.substr(chunk.size());
        }

        return coded;
    }
};

int main() {
    Solution solution;
    std::string test1{"12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"};
    std::cout << solution.freqAlphabets(test1) << std::endl;
}