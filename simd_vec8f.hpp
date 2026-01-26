#pragma once
#include <immintrin.h>

namespace simd {

struct aligned_t {};
constexpr aligned_t aligned{};

struct alignas(32) Vec8_32f {
    
    __m256 data;
    

    // Default constructor
    Vec8_32f() = default;

    // Simd vector type Contructor
    explicit Vec8_32f(__m256 d) : data(d) {}

    // Element-wise constructor
    Vec8_32f(float a0, float a1, float a2, float a3,
          float a4, float a5, float a6, float a7)
    : data(_mm256_set_ps(a7, a6, a5, a4, a3, a2, a1, a0)) {}

    // Broadcast constructor
    explicit Vec8_32f(float f) : data(_mm256_set1_ps(f)) {}
    
    // Unaligned array constructor
    explicit Vec8_32f(const float* arr) : data(_mm256_loadu_ps(arr)) {}

    // Aligned array constructor
    explicit Vec8_32f(const float* arr, aligned_t) : data(_mm256_load_ps(arr)) {}

    // basic operators
    inline Vec8_32f operator+(const Vec8_32f& rhs) const {
       return Vec8_32f(_mm256_add_ps(this->data, rhs.data)); 
    }

    inline Vec8_32f operator-(const Vec8_32f& rhs) const {
        return Vec8_32f(_mm256_sub_ps(this->data, rhs.data));
    }

    inline Vec8_32f operator*(const Vec8_32f& rhs) const {
        return Vec8_32f(_mm256_mul_ps(this->data, rhs.data));
    }

    inline Vec8_32f operator/(const Vec8_32f& rhs) const {
        return Vec8_32f(_mm256_div_ps(this->data, rhs.data));
    }

    inline float sum() const {
        __m128 up = _mm256_extractf128_ps(data, 1);
        __m128 lo = _mm256_castps256_ps128(data);

        __m128 sum1 = _mm_add_ps(up, lo);

        __m128 temp = _mm_movehdup_ps(sum1);
        __m128 sum2 = _mm_add_ps(sum1, temp);

        temp = _mm_movehl_ps(temp, sum2);
        sum2 = _mm_add_ss(sum2, temp);

        return _mm_cvtss_f32(sum2);
    }

    inline void store(float* out) const {
        _mm256_storeu_ps(out, this->data);
    }

    inline void store(float* out, aligned_t) const {
        _mm256_store_ps(out, this->data);
    }
};
}
