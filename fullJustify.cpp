#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// @see https://leetcode.com/problems/text-justification/description/

namespace {
constexpr char SPAZ{' '};
}

class Solution {
public:
    //
    int getLineLength(std::vector<std::string>& line) {
        int length{0};
        for (const auto& wyrd : line) {
            length += wyrd.length();
        }

        return length;
    }

    std::string leftJustify(std::string& line, int maxWidth) {
        auto text{line.find_first_not_of(' ')};

        if (text != std::string::npos) {
            auto shifted{line.substr(text)};
            auto numSpaces{static_cast<int>(maxWidth - shifted.length())};
            std::string spaces(numSpaces, SPAZ);
            shifted.append(spaces);
            return shifted;
        }

        return line;
    }

    std::string
    leftJustify(std::vector<std::string>& line, std::vector<int>& spaceIndx, int maxWidth) {
        for (const auto& indx : spaceIndx) {
            line[indx] = {' '};
        }

        std::stringstream output;
        for (const auto& wyrd : line) {
            output << wyrd;
        }

        auto shifted{output.str()};
        auto numSpaces{static_cast<int>(maxWidth - shifted.length())};
        std::string spaces(numSpaces, SPAZ);
        shifted.append(spaces);
        return shifted;
    }

    std::string justify(std::vector<std::string>& line, std::vector<int>& spaceIndx, int maxWidth) {
        if (spaceIndx.empty()) {
            // Only one word on line, left-justify
            return leftJustify(line[0], maxWidth);
        } else {
            // Justify line by padding spaces
            auto lineLength{getLineLength(line)};
            while (lineLength < maxWidth) {
                for (const auto& idx : spaceIndx) {
                    line[idx].append(1, SPAZ);
                    lineLength = getLineLength(line);
                    if (lineLength == maxWidth) {
                        break;
                    }
                }
            }
        }

        std::stringstream output;
        for (const auto& wyrd : line) {
            output << wyrd;
        }

        return output.str();
    }

    //
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::deque<std::string> wordle(words.begin(), words.end());

        std::vector<int> spaceIdx;
        std::vector<std::string> output;

        std::string space(1, SPAZ);
        std::vector<std::string> line;

        auto windex{0};
        while (!wordle.empty()) {
            auto next{wordle.front()};
            if (line.empty()) {
                line.push_back(next);
                wordle.pop_front();
                ++windex;
            } else {
                auto nextsize{getLineLength(line) + next.length() + 1u};
                if (nextsize <= static_cast<std::size_t>(maxWidth)) {
                    // Put space after previous word
                    line.push_back(space);
                    spaceIdx.push_back(windex);
                    ++windex;

                    // Insert next word
                    line.push_back(next);
                    ++windex;
                    wordle.pop_front();
                } else {
                    // Can't fit next word on line; justify it
                    auto justified{justify(line, spaceIdx, maxWidth)};
                    output.push_back(justified);

                    // Reset for next line
                    spaceIdx.clear();
                    windex = 0;
                    line.clear();

                    // Start next line
                    line.push_back(next);
                    wordle.pop_front();
                    ++windex;
                }
            }
        }

        // Handle last line
        if (!line.empty()) {
            auto justify{leftJustify(line, spaceIdx, maxWidth)};
            output.push_back(justify);
        }

        return output;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> t1{"What", "must", "be", "acknowledgment", "shall", "be"};

    auto r1{solution.fullJustify(t1, 16)};
    for (const auto& line : r1) {
        std::cout << line << std::endl;
    }
}