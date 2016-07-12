#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void insertion_sort(int array[], int length) {
  for (int i = 1; i < length; i++) {
    int key = array[i];
    // Insert key into sorted subsequence
    // Everything is sorted up to index j (inclusive)
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
    for (int x = 0; x < length; x++) {
      cout << array[x] << " ";
    }
    cout << endl;
  }
}

void add_binary(int a[], int b[], const int length) {
  // INPUT : a and b are arrays of 0s or 1s. They represent a binary number
  // with the least significant bit first
  // OUTPUT: c is the array representing the sum of the number representations
  // of a and b
  int c[length];

  int carry = 0;

  for (int i = 0; i < length; i++) {
    c[i] = (a[i] + b[i] + carry) % 2;
    carry = (a[i] + b[i] + carry) / 2;
  }

  c[length] = carry;

  for (int x = 0; x < length + 1; x++) {
    cout << c[x] << " ";
  }

  cout << endl;
}

int main(int argc, char *argv[]) {
  return 0;
}
