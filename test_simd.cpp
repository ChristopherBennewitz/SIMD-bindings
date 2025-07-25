#include <iostream>
#include "simd_vec8f.hpp"

int main(){
    simd::Vec8f a(2.0f);
    simd::Vec8f b(1.0f, 2.0f, 3.0f, 1.0f, 1.2f, 4.0f, 4.5f, 2.0f);

    simd::Vec8f c = a * b;

    float out[8];
    c.store(out);

    for (float f : out)
        std::cout << f << " ";
    std::cout << "\n";
}
