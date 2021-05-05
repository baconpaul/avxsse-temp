//
// Created by Paul Walker on 5/5/21.
//

#include "vecop.h"

template<Engine E>
fV<E> g(float i1, float i2)
{
    auto a = set1<E>(i1);
    auto b = set1<E>(i2);
    auto r = a + b - b + a;
    return r;
}

#if __AVX__
fV<AVX> r(float a, float b) { return g<AVX>(a,b); }
#else
fV<SSE2> r(float a, float b) { return g<SSE2>(a,b); }
#endif

