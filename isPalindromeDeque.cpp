#include <deque>
#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindromeDeque(std::string& pal) {
        std::deque<char> deck(pal.begin(), pal.end());

        bool isPalindrome{true};
        while (!deck.empty()) {
            isPalindrome &= (deck.front() == deck.back());
            if (deck.size() == 1) {
                break;
            }
            deck.pop_front();
            deck.pop_back();
        }

        return isPalindrome;
    }
};

int main() {
    std::string test1{"amanaplanacanalpanama"};
    Solution solution;
    std::cout << std::boolalpha << (solution.isPalindromeDeque(test1) == true) << std::endl;

    std::string test2{"anutforajaroftuna"};
    std::cout << std::boolalpha << (solution.isPalindromeDeque(test2) == true) << std::endl;
}