/*



*/

#include <bits/stdc++.h>

class SqrtDecomposition {
 public:
  explicit SqrtDecomposition(std::vector<int> array)
      : Array(std::move(array)),
        BlockLength(static_cast<int>(std::sqrt(Array.size()))),
        MinBlocks((Array.size() - 1) / BlockLength + 1,
                  std::numeric_limits<int>::max()),
        MaxBlocks((Array.size() - 1) / BlockLength + 1,
                  std::numeric_limits<int>::min()) {
    for (size_t i = 0; i < Array.size(); ++i) {
      MinBlocks[i / BlockLength] =
          std::min(Array[i], MinBlocks[i / BlockLength]);
      MaxBlocks[i / BlockLength] =
          std::max(Array[i], MaxBlocks[i / BlockLength]);
    }
  }

  int RangeMin(size_t leftArrayIndex, size_t rightArrayIndex) {
    int min = std::numeric_limits<int>::max();

    size_t leftBlockIndex = leftArrayIndex / BlockLength;
    size_t rightBlockIndex = rightArrayIndex / BlockLength;

    if (leftBlockIndex == rightBlockIndex) {
      for (size_t arrayIndex = leftArrayIndex; arrayIndex <= rightArrayIndex;
           ++arrayIndex) {
        min = std::min(min, Array[arrayIndex]);
      }
      return min;
    }

    for (int blockIndex = leftBlockIndex + 1; blockIndex <= rightBlockIndex - 1;
         ++blockIndex) {
      min = std::min(min, MinBlocks[blockIndex]);
    }

    for (int arrayIndex = leftArrayIndex; arrayIndex
        < std::min(Array.size(), BlockLength * (leftBlockIndex + 1));
         ++arrayIndex) {
      min = std::min(min, Array[arrayIndex]);
    }

    for (int arrayIndex = BlockLength * rightBlockIndex;
         arrayIndex <= rightArrayIndex; ++arrayIndex) {
      min = std::min(min, Array[arrayIndex]);
    }

    return min;
  }
  int RangeMax(size_t leftArrayIndex, size_t rightArrayIndex) {
    int max = std::numeric_limits<int>::min();

    size_t leftBlockIndex = leftArrayIndex / BlockLength;
    size_t rightBlockIndex = rightArrayIndex / BlockLength;

    if (leftBlockIndex == rightBlockIndex) {
      for (size_t arrayIndex = leftArrayIndex; arrayIndex <= rightArrayIndex;
           ++arrayIndex) {
        max = std::max(max, Array[arrayIndex]);
      }
      return max;
    }

    for (int blockIndex = leftBlockIndex + 1; blockIndex <= rightBlockIndex - 1;
         ++blockIndex) {
      max = std::max(max, MaxBlocks[blockIndex]);
    }

    for (int arrayIndex = leftArrayIndex; arrayIndex
        < std::min(Array.size(), BlockLength * (leftBlockIndex + 1));
         ++arrayIndex) {
      max = std::max(max, Array[arrayIndex]);
    }

    for (int arrayIndex = BlockLength * rightBlockIndex;
         arrayIndex <= rightArrayIndex; ++arrayIndex) {
      max = std::max(max, Array[arrayIndex]);
    }

    return max;
  }

 private:
 private:
  std::vector<int> Array;
  const size_t BlockLength;
  std::vector<int> MinBlocks;
  std::vector<int> MaxBlocks;
};

int main() {
  size_t n = 0;
  std::cin >> n;

  std::vector<int> t(2 * n + 1, 0);
  for (size_t i = 0; i < 2 * n + 1; ++i) {
    std::cin >> t[i];
  }

  SqrtDecomposition sqrt(t);

  size_t b = 0;
  std::cin >> b;
  for (size_t i = 0; i < b; ++i) {
    int tMin = 0;
    int tMax = 0;
    int dMin = 0;
    int dMax = 0;
    std::cin >> tMin >> tMax >> dMin >> dMax;

    int min = sqrt.RangeMin(dMin + n, dMax + n);
    int max = sqrt.RangeMax(dMin + n, dMax + n);
    if (max >= tMin && tMax >= min) {
      std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }
}
