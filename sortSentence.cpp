#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

class Solution {
public:
    std::tuple<std::string, int> getPez(std::string s) {
        auto index{(s[s.length() - 1]) - '0'};
        --index;
        auto pez{s.substr(0, s.length() - 1)};
        return {pez, index};
    }

    std::string sortSentence(std::string s) {
        auto numBlanks{std::count(s.begin(), s.end(), ' ')};
        std::vector<std::string> sordid(numBlanks + 1);

        if (auto blank{s.find_first_of(' ')}; blank != std::string::npos) {
            while (!s.empty()) {
                auto chunk{s.substr(0, blank)};
                auto [pez, index]{getPez(chunk)};
                sordid[index] = pez;

                s = s.substr(blank + 1);
                blank = s.find_first_of(' ');
                if (blank == std::string::npos) {
                    auto [pez, index]{getPez(s)};
                    sordid[index] = pez;
                    break;
                }
            }
        } else {
            auto [pez, index]{getPez(s)};
            sordid[index] = pez;
        }

        sordid.shrink_to_fit();
        if (sordid.size() > 1) {
            std::string ret;
            for (auto i = 0; i < sordid.size(); ++i) {
                ret.append(sordid[i]);
                if (i != (sordid.size() - 1)) {
                    ret.append({" "});
                }
            }

            return ret;
        } else {
            return {sordid[0]};
        }

        return {};
    }
};

int main() {

    Solution solution;
    std::string test1{"is2 sentence4 This1 a3"};
    std::cout << solution.sortSentence(test1) << std::endl;

    std::string test2{"Myself2 Me1 I4 and3"};
    std::cout << solution.sortSentence(test2) << std::endl;

    std::string test3{"pTY1"};
    std::cout << solution.sortSentence(test3) << std::endl;
}