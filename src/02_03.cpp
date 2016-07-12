#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> merge_sort(vector<int> v) {
  if (v.size() == 1) {
    return v;
  } else {
    int midpoint = v.size() / 2;

    vector<int>::const_iterator first = v.begin();
    vector<int>::const_iterator mid = v.begin() + midpoint;
    vector<int>::const_iterator last = v.end();

    vector<int> left = merge_sort(vector<int> (first, mid));
    vector<int> right = merge_sort(vector<int> (mid, last));

    return merge(left, right);

  }
}

vector<int> merge(vector<int> v, vector<int> w) {
  int i, j;
  i = 0;
  j = 0;
  vector<int> res = {};
  while (i < v.size() && j < w.size()) {
    if (v[i] <= w[j]) {
      res.push_back(v[i]);
      i++;
    } else {
      res.push_back(w[j]);
      j++;
    }
  }
  if (i == v.size()) {
    for (int wIndex = j; wIndex < w.size(); wIndex++) {
      res.push_back(w[wIndex]);
    }
  } else {
    for (int vIndex = i; vIndex < v.size(); vIndex++) {
      res.push_back(v[vIndex]);
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> v = {9, 8, 7, 6, 5, 1, 2, 3, 4, 10, 11, 12};
  vector<int> res = merge_sort(v);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
