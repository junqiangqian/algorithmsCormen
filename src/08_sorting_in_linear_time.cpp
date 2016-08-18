#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

/*
   INPUT: a - vector to be sorted in ascending order
          b - vector A sorted
          k - maximum element in vector A
*/
template <typename T>
void counting_sort(vector<T>& a, vector<T>& b, long long k) {
  vector<T> c(k + 1);
  for (unsigned j = 0; j < a.size(); j++) {
    c[a[j]]++;
  }
  for (unsigned i = 1; i <= k; i++) {
    c[i] += c[i - 1];
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    b[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }
}

int main() {
  vector<int> a = {8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> b(a.size());
  counting_sort(a, b, 9);
  std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, " "));
}
