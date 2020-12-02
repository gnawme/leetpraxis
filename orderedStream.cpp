#include <iostream>
#include <string>
#include <utility>
#include <vector>

class OrderedStream {
public:
    OrderedStream(int n) : _size(n), _stream(new std::pair<int, std::string>[n + 1]) {}

    ~OrderedStream() {
        delete[] _stream;
    }

    std::vector<std::string> insert(int id, std::string value) {
        std::vector<std::string> chunk;
        auto aupair{std::make_pair(id, value)};
        _stream[id] = aupair;
        if (id == _pos) {
            for (auto i = id; i <= _size; ++i) {
                const auto& [sid, svalue]{_stream[i]};
                if (svalue.empty()) {
                    break;
                } else {
                    chunk.push_back(svalue);
                }
                ++_pos;
            }
        }
        return chunk;
    }

private:
    int _size{0};
    std::pair<int, std::string>* _stream;
    int _pos{1};
};

void blowChunks(const std::vector<std::string>& chunk) {
    std::cout << "Chunks: ";
    for (const auto& chud : chunk) {
        std::cout << chud << " ";
    }
    std::cout << std::endl;
}

int main() {
    OrderedStream test1(5);
    auto chunk = test1.insert(3, "ccccc");
    blowChunks(chunk);
    chunk = test1.insert(1, "aaaaa");
    blowChunks(chunk);
    chunk = test1.insert(2, "bbbbb");
    blowChunks(chunk);
    chunk = test1.insert(5, "eeeee");
    blowChunks(chunk);
    chunk = test1.insert(4, "ddddd");
    blowChunks(chunk);
}