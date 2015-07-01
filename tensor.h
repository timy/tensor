#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
using std::vector;

// the universal tensor
template <typename T, long N>
class tensor {
private:
  vector<tensor<T, N-1>> vv;
public:
  tensor<T, N>() = default;
  tensor<T, N>(const vector<long>& args) {
    vv.resize(args[0]);
    for (long i = 0; i < args[0]; i ++) {
      vv[i].resize(vector<long>(std::next(args.begin(), 1), args.end()));
    }
  }
  inline void resize(const vector<long>& args) {
    vv.resize(args[0]);
    for (long i = 0; i < args[0]; i ++) {
      vv[i].resize(vector<long>(std::next(args.begin(), 1), args.end()));
    }
  }
  inline const tensor<T, N-1>& operator[](long nr) const {
    return vv[nr];
  }
  inline tensor<T, N-1>& operator[](long nr) {
    return vv[nr];
  }
  void print();
};

// 1st-rank tensor, just a wrapper for vector
template <typename T>
class tensor<T, 1>: public vector<T> {
public:
  tensor<T, 1>(): vector<T>() {}
  tensor<T, 1>(long n): vector<T>(n) {}
  tensor<T, 1>(const vector<long>& args): vector<T>(args[0]) {}

  void resize(const vector<long>& args) {
    vector<T>::resize(args[0]);
  }
  void print();
};

#endif
