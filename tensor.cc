#include "tensor.h"
#include <cstdio>

template<typename T, long N>
void tensor<T, N>::print() {
  long n = vv.size();
  for (long i = 0; i < n; i ++) {
    printf("%ld:%ld\n", N, i);
    vv[i].print();
  }
}

template<>
void tensor<double, 1>::print() {
  long n = this->size();
  for (long i = 0; i < n; i ++) {
    printf("1:%ld: (%le)\n", i, (*this)[i]);
  }
}

#include <complex>
#define complex std::complex<double>
template<>
void tensor<complex, 1>::print() {
  long n = this->size();
  for (long i = 0; i < n; i ++) {
    printf("1:%ld: (%le %le)\n", i, real((*this)[i]), imag((*this)[i]));
  }
}

// instantation all needs
template class tensor<double, 4>;
template class tensor<complex, 3>;
