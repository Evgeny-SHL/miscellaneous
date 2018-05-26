// Автор: Евгений Шлыков
// Описание: Установление значения growthFactor и maxLoadFactor в std::unoredered_map<std::string>

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::size_t, std::string> hashTable;
  std::string pattern = "";
  std::size_t maxSize = 10000;
  std::size_t bucketCount = hashTable.bucket_count();
  double maxLoadFactor = hashTable.max_load_factor();
  for( std::size_t i = 0; i < maxSize; ++i ) {
    pattern += std::to_string(i);
    hashTable[i] = pattern;
    if( hashTable.bucket_count() != bucketCount ) {
      std::cout << bucketCount << " -> " << hashTable.bucket_count() << std::endl;
      bucketCount = hashTable.bucket_count();
    }
    if( hashTable.max_load_factor() != maxLoadFactor ) {
      std::cout << maxLoadFactor << " -> " << hashTable.max_load_factor() << std::endl;
      maxLoadFactor = hashTable.max_load_factor();
    }
  }
  std::cout << maxLoadFactor << std::endl;
  return 0;
}
