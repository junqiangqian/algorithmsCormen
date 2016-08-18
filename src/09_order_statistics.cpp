#include <iostream>
#include <vector>
#include <algorithm> /* min(), max() */
#include <stdlib.h> /* rand() */
#include <time.h> /* time */

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

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

template <typename T>
int partition(vector<T>& v, int p, int r) {
    T pivot = v[r];
    int i = p - 1;
    for (unsigned j = p; j < r; j++) {
        if (v[j] <= pivot) {
            i++;
            SWAP(v[i], v[j], T);
        }
    }
    SWAP(v[i + 1], v[r], T);
    return i + 1;
}

int generateRandomNumberBetween(int p, int r) {
    srand(time(NULL));
    int difference = r - p + 1;
    return p + rand() % difference;
}

template <typename T>
int randomised_partition(vector<T>& v, int p, int r) {
    int randIndex = generateRandomNumberBetween(p, r);
    SWAP(v[r], v[randIndex], T);
    return partition(v, p, r);
}


template <typename T>
T randomised_select(vector<T>& v, int p, int r, int i) {
    if (p == r) {
        return v[p];
    }
    int q = randomised_partition(v, p, r);
    int k = q - p + 1;
    if (i == k) {
        return v[q];
    } else if (i < k) {
        return randomised_select(v, p, q - 1, i);
    } else {
        return randomised_select(v, q + 1, r, i - k);
    }
}


int main() {
    vector<int> v = {10, 5, 1, 7, 2, 8, 9, 6, 4, 3};
    int q = randomised_select(v, 0, v.size() - 1, 5);
    cout << q << endl;

}
