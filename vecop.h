//
// Created by Paul Walker on 5/5/21.
//

#ifndef AVXSSE_TEMP_VECOP_H
#define AVXSSE_TEMP_VECOP_H

#include <immintrin.h>

enum Engine
{
    SSE2,
    AVX
};

template<Engine T>
struct EngineParams
{
};

template<>
struct EngineParams<SSE2>
{
    static constexpr int flen = 4;
    static constexpr int dlen = 2;
    typedef  __m128 ftype;
    typedef  __m128d dtype;
};

template<>
struct EngineParams<AVX>
{
    static constexpr int flen = 8;
    static constexpr int dlen = 4;
    typedef  __m256 ftype;
    typedef  __m256d dtype;
};

template<Engine E>
struct fV
{
    inline fV(const typename EngineParams<E>::ftype &o) : v(o) {}
    typename EngineParams<E>::ftype v;
};

inline fV<SSE2> operator+(const fV<SSE2> &a, const fV<SSE2> &b)
{
    return _mm_add_ps(a.v,b.v);
}
inline fV<SSE2> operator-(const fV<SSE2> &a, const fV<SSE2> &b)
{
    return _mm_sub_ps(a.v,b.v);
}

inline fV<AVX> operator+(const fV<AVX> &a, const fV<AVX> &b)
{
    return _mm256_add_ps(a.v,b.v);
}
inline fV<AVX> operator-(const fV<AVX> &a, const fV<AVX> &b)
{
    return _mm256_sub_ps(a.v,b.v);
}

template<Engine E>
inline fV<E> set1(const float &f);

template<>
inline fV<SSE2> set1(const float &f)
{
    return _mm_set1_ps(f);
}

template<>
inline fV<AVX> set1(const float &f)
{
    return _mm256_set1_ps(f);
}
#endif // AVXSSE_TEMP_VECOP_H
