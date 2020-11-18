#include <iostream>

class ParkingSystem {
public:
    enum CarType { BIG = 1, MEDIUM, SMALL };

    ParkingSystem(int big, int medium, int small)
            : _lrgCapacity(big), _medCapacity(medium), _smlCapacity(small) {}

    bool addCar(int carType) {
        switch (carType) {
        case BIG:
            if (_numLrg < _lrgCapacity) {
                ++_numLrg;
                return true;
            }
            break;

        case MEDIUM:
            if (_numMed < _medCapacity) {
                ++_numMed;
                return true;
            }
            break;

        case SMALL:
            if (_numSml < _smlCapacity) {
                ++_numSml;
                return true;
            }
            break;
        }

        return false;
    }

private:
    int _lrgCapacity{0};
    int _medCapacity{0};
    int _smlCapacity{0};

    int _numLrg{0};
    int _numMed{0};
    int _numSml{0};
};

int main() {
    ParkingSystem park1(1, 1, 0);
    std::cout << std::boolalpha << park1.addCar(1) << std::endl;
    std::cout << std::boolalpha << park1.addCar(2) << std::endl;
    std::cout << std::boolalpha << park1.addCar(3) << std::endl;
    std::cout << std::boolalpha << park1.addCar(1) << std::endl;
}