#include "tensor.h"
#include <cstdio>
#include <vector>

#include <complex>
#define complex std::complex<double>

int main(int argc, char* argv[]) {
  // tensor<double, 4>* m = new tensor<double, 4>({2, 2, 3, 2});
  // for (long i = 0; i < 2; i ++) {
  //   for (long j = 0; j < 2; j ++) {
  //     for (long k = 0; k < 3; k ++) {
  //       for (long l = 0; l < 2; l ++) {
  //         printf("(i,j,k,l)=(%ld,%ld,%ld,%ld)\t", i, j, k, l);
  //         (*m)[i][j][k][l] = 1000*i + 100*j + 10*k + l;
  //         printf("%f\t\n", (*m)[i][j][k][l]);
  //       }
  //     }
  //   }
  // }
  // delete m;
  // tensor<double, 4> m({2, 2, 3, 2});


  // tensor<complex, 3> m({2, 3, 4});
  // for (long i = 0; i < 2; i ++) {
  //   for (long j = 0; j < 3; j ++) {
  //     for (long k = 0; k < 4; k ++) {
  //       printf("(i,j,k)=(%ld,%ld,%ld)\t", i, j, k);
  //       m[i][j][k] = 1000*i + 100*j + 10*k;
  //       printf("(%f,%f)\t\n", real(m[i][j][k]), imag(m[i][j][k]));
  //     }
  //   }
  // }

  tensor<double, 2> m;
  m.resize({1, 2});
  for (long i = 0; i < 1; i ++) {
    for (long j = 0; j < 2; j ++) {
      printf("(i,j)=(%ld,%ld)\t", i, j);
      m[i][j] = 1000*i + 100*j;
      printf("%f\t\n", m[i][j]);
    }
  }

  tensor<double, 1> m1(2);
  for (long i = 0; i < 2; i ++) {
      printf("(i)=(%ld)\t", i);
      m1[i] = i;
      printf("%f\t\n", m1[i]);
  }

  m.push_back(m1);

  m.print();

  return 0;
}
