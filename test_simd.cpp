#include <iostream>
#include "simd_vec8f.hpp"

int main(){
    alignas(32) float data[8] = {1, 2, 3, 4, 5, 6 ,7, 8};
    simd::Vec8_32f a(data, simd::aligned);
    simd::Vec8_32f b(data, simd::aligned);

    simd::Vec8_32f c = a * a;

    float out[8];
    c.store(out);
    float sum = c.sum();

    for (float f : out)
        std::cout << f << " ";
    std::cout << "\n";
    std::cout << sum << "\n";
}
