#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
T minimum(vector<T>& v) {
    T minSoFar;
    if (v.size() > 0) {
        minSoFar = v[0];
    } else {
        cerr << "Vector is empty, no minimum exists";
        exit(EXIT_FAILURE);
    }
    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i] < minSoFar) {
            minSoFar = v[i];
        }
    }
    return minSoFar;
}

template <typename T>
T maximum(vector<T>& v) {
    T maxSoFar;
    if (v.size() > 0) {
        maxSoFar = v[0];
    } else {
        cerr << "Vector is empty, no maximum exists";
        exit(EXIT_FAILURE);
    }
    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i] > maxSoFar) {
            maxSoFar = v[i];
        }
    }
    return maxSoFar;
}

template <typename T>
struct Pair {
    T minimum;
    T maximum;
};

template <typename T>
Pair<T> minimumAndMaximum(vector<T>& v) {
    unsigned length = v.size();
    if (length < 1) {
        cerr << "Vector is empty, no min/max exists";
        exit(EXIT_FAILURE);
    }
    T minSoFar, maxSoFar;
    bool evenLength = length % 2 == 0;
    if (evenLength) {
        minSoFar = min(v[0], v[1]);
        maxSoFar = max(v[0], v[1]);
    } else {
        minSoFar = v[0];
        maxSoFar = v[0];
    }
    unsigned startingIndex = evenLength? 2: 1;
    T minPairElem, maxPairElem;
    for (unsigned i = startingIndex; i < length - 1; i++) {
        minPairElem = min(v[i], v[i + 1]);
        maxPairElem = max(v[i], v[i + 1]);
        minSoFar = min(minSoFar, minPairElem);
        maxSoFar = max(maxSoFar, maxPairElem);
    }

    Pair<T> results;
    results.minimum = minSoFar;
    results.maximum = maxSoFar;

    return results;
}

int main() {
    vector<int> v = {5, 6, 7, 8, 9, 10, -1, 0, 1, 2, 1, 0};
    Pair<int> results = minimumAndMaximum(v);
    cout << results.minimum << " " << results.maximum << endl;
}
