#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>

class Solution {
public:
    char addDigits(char a, char b, int& carry) {
        std::stringstream ss;
        int ad;
        ss << a;
        ss >> ad;

        int bd;
        ss.str("");
        ss.clear();
        ss << b;
        ss >> bd;

        auto sum = ad + bd + carry;

        carry = sum / 2;
        auto result = sum % 2;

        char output;
        ss.str("");
        ss.clear();
        ss << result;
        ss >> output;

        return output;
    }

    void addMsb(std::string& str, int& carry, std::deque<char>& output) {
        for (auto mit = str.rbegin(); mit != str.rend(); ++mit) {
            std::stringstream ss;
            char cbit;
            ss << carry;
            ss >> cbit;

            carry = 0;
            auto digit{addDigits(*mit, cbit, carry)};
            output.push_front(digit);
        }

        if (carry == 1) {
            output.push_front('1');
        }
    }

    int addStrings(std::string& a, std::string& b, std::deque<char>& output) {
        int carry{0};

        auto ait{a.rbegin()};
        auto bit{b.rbegin()};
        for (; ait != a.rend(); ++ait, ++bit) {
            auto digit{addDigits(*ait, *bit, carry)};
            output.push_front(digit);
        }

        return carry;
    }

    std::string addBinary(std::string a, std::string b) {
        auto alen{a.length()};
        auto blen{b.length()};

        int carry{0};
        std::deque<char> output;
        if (alen > blen) {
            auto slen{alen - blen};
            std::string stub = a.substr(slen);
            carry = addStrings(stub, b, output);
            auto msb{a.substr(0, slen)};
            addMsb(msb, carry, output);
        } else if (blen > alen) {
            auto slen{blen - alen};
            std::string stub = b.substr(slen);
            carry = addStrings(a, stub, output);
            auto msb{b.substr(0, slen)};
            addMsb(msb, carry, output);
        } else {
            carry = addStrings(a, b, output);

            char cbit;
            std::stringstream ss;
            ss << carry;
            ss >> cbit;
            output.push_front(cbit);
        }

        std::string binstr(output.begin(), output.end());
        auto zero{binstr.find_first_not_of("0")};
        if (zero != std::string::npos) {
            binstr = binstr.substr(zero);
        } else if ((binstr[0] == '0') || binstr.empty()) {
            binstr = "0";
        }
        return binstr;
    }
};

int main() {
    Solution solution;
    std::string a1 = "1010";
    std::string b1 = "1011";
    auto r1{solution.addBinary(a1, b1)};
    std::cout << std::boolalpha << (r1 == std::string("10101")) << std::endl;
}