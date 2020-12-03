/// Welford algorithm for computing running variance
/// \see https://www.johndcook.com/blog/standard_deviation/
#include <cmath>
#include <iostream>
#include <vector>

class RunningStat {
public:
    RunningStat() : _numValues(0) {}

    void clear() {
        _numValues = 0;
    }

    void push(double value) {
        ++_numValues;

        /// \see Knuth TAOCP vol 2, 3rd edition, page 232
        if (_numValues == 1) {
            _oldMean = _newMean = value;
            _oldSigma = 0.0;
        } else {
            _newMean = _oldMean + (value - _oldMean) / _numValues;
            _newSigma = _oldSigma + (value - _oldMean) * (value - _newMean);

            // set up for next iteration
            _oldMean = _newMean;
            _oldSigma = _newSigma;
        }
    }

    int numDataValues() const {
        return _numValues;
    }

    double mean() const {
        return (_numValues > 0) ? _newMean : 0.0;
    }

    double variance() const {
        return ((_numValues > 1) ? _newSigma / (_numValues - 1) : 0.0);
    }

    double standardDeviation() const {
        return std::sqrt(variance());
    }

private:
    int _numValues{0};
    double _oldMean{0.0};
    double _newMean{0.0};
    double _oldSigma{0.0};
    double _newSigma{0.0};
};

int main() {
    std::vector<int> rando{17, 18, 16, 25, 1, 13, 11, 19, 12, 15, 22, 5, 7,
                           10, 14, 9,  6,  8, 23, 4,  20, 2,  24, 3,  21};

    RunningStat stats;
    for (const auto& rand : rando) {
        stats.push(rand);
    }

    std::cout << "Mean: " << stats.mean() << " Variance: " << stats.variance()
              << " Std Dev: " << stats.standardDeviation() << std::endl;
}
