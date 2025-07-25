#pragma once
#include <immintrin.h>

namespace simd {

struct alignas(32) Vec8f {
    
    __m256 data;
    

    // Default constructor
    Vec8f() = default;

    // Element-wise constructor
    Vec8f(float a0, float a1, float a2, float a3,
          float a4, float a5, float a6, float a7)
    : data(_mm256_set_ps(a7, a6, a5, a4, a3, a2, a1, a0)) {}


    // Broadcast constructor
    explicit Vec8f(float f) : data(_mm256_set1_ps(f)) {}
    
    // Simd vector type Contructor
    explicit Vec8f(__m256 d) : data(d) {}
    
    // basic operators
    inline Vec8f operator+(const Vec8f& rhs) const {
       return Vec8f(_mm256_add_ps(this->data, rhs.data)); 
    }

    inline Vec8f operator-(const Vec8f& rhs) const {
        return Vec8f(_mm256_sub_ps(this->data, rhs.data));
    }

    inline Vec8f operator*(const Vec8f& rhs) const {
        return Vec8f(_mm256_mul_ps(this->data, rhs.data));
    }

    inline Vec8f operator/(const Vec8f& rhs) const {
        return Vec8f(_mm256_div_ps(this->data, rhs.data));
    }

    void store(float* out) const {
        _mm256_storeu_ps(out, this->data);
    }
};
}
