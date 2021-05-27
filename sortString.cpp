#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

class Solution {
public:
    std::string sortString(std::string s) {
        std::cout << s << std::endl;
        std::string result;

        auto loop{0};
        while (!s.empty()) {
            // Step 1
            auto smoll{std::min_element(s.begin(), s.end())};
            std::cout << "1< " << *smoll << std::endl;
            result.append({*smoll});

            // Step 2
            smoll = std::min_element(s.begin(), s.end());
            while (smoll != s.end()) {
                if (*smoll > result[result.length() - 1]) {
                    std::cout << "2< " << *smoll << std::endl;
                    result.append({*smoll});
                    auto smolldex{std::distance(s.begin(), smoll)};
                    s.erase(smolldex, 1);
                    smoll = s.begin();
                }

                smoll = std::min_element(smoll + 1, s.end());
            }

            // Step 3
            auto hyuge{std::max_element(s.begin(), s.end())};
            std::cout << "3> " << *hyuge << std::endl;
            result.append({*hyuge});
            auto hyugedex{std::distance(s.begin(), hyuge)};
            s.erase(hyugedex, 1);

            // Step 4
            hyuge = std::max_element(s.begin(), s.end());
            while (hyuge != s.end()) {
                std::cout << "4? " << *hyuge << std::endl;
                if (*hyuge < result[result.length() - 1]) {
                    std::cout << "4> " << *hyuge << std::endl;
                    result.append({*hyuge});
                    auto hyugedex{std::distance(s.begin(), hyuge)};
                    s.erase(hyugedex, 1);
                    hyuge = s.begin();
                }

                hyuge = std::max_element(hyuge + 1, s.end());
            }
            std::cout << "loop: " << loop++ << " : " << result << std::endl;
        }

        return result;
    }
};

int main() {
    Solution solution;

    std::string test1{"aaaabbbbcccc"};
    std::cout << solution.sortString(test1) << std::endl;
}