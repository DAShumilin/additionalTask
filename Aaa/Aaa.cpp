#include <iostream>
#include <bitset>

class uint128_t {

public:

    uint128_t(uint64_t x = 0) : data(x) {};

    const uint128_t operator+(uint128_t x) {
        size_t p = 0;
        uint128_t result;
        for (size_t i = 0; i < 128; i++) {
            result.data[i] = (data[i] + x.data[i] + p) % 2;
            p = (data[i] + x.data[i] + p) / 2;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const uint128_t& x) {
        if ((x.data & (~std::bitset<128>(UINT64_MAX))).any()) {
            out << x.data.to_string();
        }
        else {
            out << x.data.to_ullong();
        }
        return out;
    }

private:

    std::bitset<128> data;
};

void sample() {
    uint128_t x;
    for (uint64_t i = 0; i < 10; i++) {
        x = x + i;
    }
    std::cout << x << std::endl;
}

int main(){

    sample();
}