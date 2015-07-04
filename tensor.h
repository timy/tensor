#ifndef TENSOR_H_
#define TENSOR_H_

#include <vector>
using std::vector;

// Nth-rank tensor
template <typename T, long N>
class tensor: public vector<T> {
private:
  vector<tensor<T, N-1>> vt;
public:
  tensor<T, N>() = default;
  tensor<T, N>(const vector<long>& args) {
    vt.resize(args[0]);
    for (long i = 0; i < args[0]; i ++) {
      vt[i].resize(vector<long>(std::next(args.begin(), 1), args.end()));
    }
  }
  inline void resize(const vector<long>& args) {
    vt.resize(args[0]);
    for (long i = 0; i < args[0]; i ++) {
      vt[i].resize(vector<long>(std::next(args.begin(), 1), args.end()));
    }
  }
  inline const tensor<T, N-1>& operator[](long nr) const {
    return vt[nr];
  }
  inline tensor<T, N-1>& operator[](long nr) {
    return vt[nr];
  }
  inline void push_back(tensor<T, N-1>& args) {
    vt.push_back(args);
  }
  void print();
  // size() is only for regular form, returns vector<long> of [n_dim1, n_dim2, n_dim3, ...]
  // size 1: less efficient due to the use of vector::insert and value copies
  vector<long> size() {
    long n = vt.size();
    vector<long> s;
    if (n > 0)
      s = vt[0].size();
    s.insert(s.begin(), n);
    return s;
  }
  // size 2: more efficient
  void size(vector<long>& s) {
    long n = vt.size();
    s.push_back(n);
    if (n > 0)
      vt[0].size(s);
  }
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
  // size 1
  vector<long> size() {
    vector<long> s;
    s.insert(s.begin(), vector<T>::size());
    return s;
  }
  // size 2
  void size(vector<long>& s) {
    s.push_back(vector<T>::size());
  }
};

#endif
