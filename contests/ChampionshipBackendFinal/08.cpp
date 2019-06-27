/*



*/

#include <bits/stdc++.h>

long long Min(long long a, long long b) {
  return a < b ? a : b;
}

class SqrtDecomposition {
 public:
  explicit SqrtDecomposition(long long arrayLength)
      : Array(arrayLength, 0),
        BlockLength(static_cast<long long>(std::sqrt(Array.size()))),
        Blocks((Array.size() - 1) / BlockLength + 1, 0) {
  }

  void IncreasyBy(long long leftArrayIndex, long long x) {
    long long leftBlockIndex = BlockIndex(leftArrayIndex);
    for (long long blockIndex = leftBlockIndex + 1; blockIndex < Blocks.size();
         ++blockIndex) {
      Blocks[blockIndex] += x;
    }

    for (long long arrayIndex = leftArrayIndex; arrayIndex
        < Min(Array.size(), BlockLength * (leftBlockIndex + 1));
         ++arrayIndex) {
      Array[arrayIndex] += x;
    }

//    Print(Array);
//    Print(Blocks);
  }

  long long LowerBoundRight(long long x) {
    auto blockUpperBound = std::upper_bound(Blocks.begin(), Blocks.end(), x);
    long long rightBlockIndex = blockUpperBound - Blocks.begin();

    assert(rightBlockIndex > 0);

    for (long long blockIndex = rightBlockIndex - 1; blockIndex >= 0;
         --blockIndex) {
//      DumpBlock(blockIndex);
      auto arrayUpperBound =
          std::upper_bound(Array.begin() + BlockLength * blockIndex,
                           Array.begin() + Min(Array.size(),
                                               BlockLength
                                                   * (blockIndex + 1)),
                           x - Blocks[blockIndex]);
      long long arrayIndex = arrayUpperBound - Array.begin();
      if (arrayIndex == BlockLength * blockIndex) {
        continue;
      }
      return arrayIndex - 1;
    }

    return -1;
  }

 private:
  long long BlockIndex(long long arrayIndex) {
    return arrayIndex / BlockLength;
  }

  void DumpBlock(long long blockIndex) {
    long long x = Blocks[blockIndex];
    if (blockIndex != 0) {
      x -= Blocks[blockIndex - 1];
    }

    for (long long ai = blockIndex * BlockLength;
         ai < Min(Array.size(), BlockLength * (blockIndex + 1)); ++ai) {
      Array[ai] += x;
    }

    Blocks[blockIndex] -= x;
  }

  template <typename T>
  void Print(T x) {
    for (auto &&y : x) {
      std::cout << y << " ";
    }
    std::cout << std::endl;
  }

 private:
  std::vector<long long> Array;
  const long long BlockLength;
  std::vector<long long> Blocks;
};

int main() {
  long long n = 0;
  long long q = 0;
  std::cin >> n >> q;

  SqrtDecomposition sqrt(n);

  for (long long i = 0; i < q; ++i) {
    char c = '\0';
    std::cin >> c;
    if (c == '+') {
      long long shard = 0;
      long long weight = 0;
      std::cin >> shard >> weight;
      sqrt.IncreasyBy(shard, weight);
    } else if (c == '?') {
      long long weight = 0;
      std::cin >> weight;
      std::cout << sqrt.LowerBoundRight(weight) << std::endl;
    }
  }
}
