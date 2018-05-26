#include <algorithm>
#include <iostream>
#include<vector>

void PrepareKiller( std::vector<int> &array )
{
  std::size_t length = array.size();
  std::size_t right = length - 1;
  int order[length];

  for( std::size_t i = 0; i < length; i++ ) {
    order[i] = i;
  }

  for( std::size_t left = 0; left < right; left++ )
  {
    std::size_t pivot = ( left + right ) / 2;
    std::swap( order[left], order[pivot] );
  }

  for( std::size_t i = 0; i < length; i++ ) {
    array[order[i]] = i + 1;
  }
}

std::size_t OperationsCount = 0;
bool CheckFailed = false;

void Quicksort( std::vector<int> &array, std::size_t left, std::size_t right )
{
  if( left >= right ) {
    return;
  }

  std::size_t pivot = array[( left + right ) / 2];
  std::size_t leftPtr = left;
  std::size_t rightPtr = right;
  while( leftPtr <= rightPtr )
  {
    while( array[leftPtr] < pivot ) {
      ++leftPtr;
      ++OperationsCount;
    }
    while( array[rightPtr] > pivot ) {
      --rightPtr;
      ++OperationsCount;
    }
    if( leftPtr <= rightPtr )
    {
      ++OperationsCount;
      std::swap( array[leftPtr], array[rightPtr] );
      ++leftPtr, --rightPtr;
    }
  }

  if( !( left >= rightPtr ) )
  {
    std::cout << "Не killer-последовательность: одна из половин не пуста." << std::endl;
    CheckFailed = true;
  }
  Quicksort( array, left, rightPtr );
  Quicksort( array, leftPtr, right );
}

int main()
{
  std::vector<int> array( 1000 );

  PrepareKiller( array );
  for( std::size_t elem : array ) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  Quicksort( array, 0, array.size() - 1 );
  std::cout << OperationsCount << std::endl;
  if( !CheckFailed ) {
    std::cout << "Killer-последовательность построена." << std::endl;
  }

  return 0;
}
