#include <iostream>
#include "vecop.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << EngineParams<SSE2>::flen << std::endl;
    std::cout << EngineParams<AVX>::flen << std::endl;

    auto a = set1<SSE2>(1.0);
    auto b = set1<SSE2>(2.0);
    auto r = a + b;
    std::cout << r.v[0] << std::endl;

    return 0;
}
