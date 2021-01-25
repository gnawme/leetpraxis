#include <iostream>
#include <variant>
#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger() = default;

    // Constructor initializes a single integer.
    NestedInteger(int value) : _nestedInteger(value) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return std::holds_alternative<int>(_nestedInteger);
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return std::get<int>(_nestedInteger);
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        _nestedInteger.emplace<int>(value);
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni) {

        _nestedInteger.emplace<NestedInteger>(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger>& getList() const {
        return std::get<NestedInteger>(_nestedInteger);
    }

private:
    std::variant<int, NestedInteger> _nestedInteger;
};

class Solution {
public:
    int depthSum(int sum, int stackDepth, const std::vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) {
            return 0;
        }

        for (const auto& nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                sum += stackDepth * nestedInteger.getInteger();
            } else {
                sum += depthSum(sum, stackDepth + 1, nestedInteger.getList());
            }
        }

        return sum;
    }

    int depthSum(std::vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) {
            return 0;
        }

        auto sum{0};
        auto stackDepth{1};
        for (const auto& nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                sum += stackDepth * nestedInteger.getInteger();
            } else {
                sum += depthSum(sum, stackDepth + 1, nestedInteger.getList());
            }
        }

        return sum;
    }
};

int main() {
    Solution solution;
}