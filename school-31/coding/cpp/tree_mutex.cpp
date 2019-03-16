// Автор: Шлыков Евгений, группа 599
// Описание: Решение задачи Tournament Tree Mutex

#include <array>
#include <atomic>
#include <iostream>
#include <vector>
#include <thread>

//----------------------------------------------------------------------------------------------------------------------

class CPetersonMutex {
public:
	CPetersonMutex();
	~CPetersonMutex() = default;

	void DoLock( int indexOfThread );
	void DoUnlock( int indexOfThread );

private:
	std::array<std::atomic<bool>, 2> isWantToLockMutex;
	std::atomic<int> victim;
};

//----------------------------------------------------------------------------------------------------------------------

struct CSegment {
	std::size_t leftBorder;
	std::size_t rightBorder;

	CSegment(std::size_t _leftBorder, std::size_t _rightBorder);
};

//----------------------------------------------------------------------------------------------------------------------

class tree_mutex {

public:
	tree_mutex();
	tree_mutex( std::size_t _threadsCount );
	~tree_mutex() = default;

	lock( std::size_t indexOfThread );
	unlock( std::size_t indexOfThread );

private:
	std::size_t threadsCount;
	std::vector<std::pair<CPetersonMutex, CSegment>> vectorOfMutexes;

	std::size_t getIndexInTree( std::size_t indexOfThread );
	std::size_t getFIndexOfFather( std::size_t indexOfThread );
	std::size_t getIndexOfLeftSon( std::size_t indexOfThread );
	std::size_t getIndexOfRightSon( std::size_t indexOfThread );
	bool isNotLeftSon( std::size_t indexOfThread );
};

//----------------------------------------------------------------------------------------------------------------------

CSegment::CSegment(std::size_t _leftBorder, std::size_t _rightBorder) :
	leftBorder(_leftBorder),
	rightBorder(_rightBorder)
{
}

//----------------------------------------------------------------------------------------------------------------------

CPetersonMutex::CPetersonMutex()
{
	isWantToLockMutex[0].store( false );
	isWantToLockMutex[1].store( true );
	victim.store( 0 );
}

void CPetersonMutex::DoLock( int indexOfThread )
{
	isWantToLockMutex[indexOfThread].store( true );
	victim.store( indexOfThread );
	while( isWantToLockMutex[1 - indexOfThread] && victim.load() == indexOfThread ) {
		std::this_thread::yield();
	}
}

void CPetersonMutex::DoUnlock( int indexOfThread )
{
	isWantToLockMutex[indexOfThread].store( false );
}

//----------------------------------------------------------------------------------------------------------------------

tree_mutex::tree_mutex( std::size_t _threadsCount ) :
	: threadsCount(_threadsCount)
{
	assert( _threadsCount > 1 );
	vectorOfMutexes.resize( 1 );
	// Не храним нижний слой (как бы потоки), так как важны только мьютексы.
	while( 2 * vectorOfMutexes.size() < _threadsCount ) {
		vectorOfMutexes.resize( 2 * vectorOfMutexes.size() );
	}
	// Инициализация зоны действия мьютекса.
	for( auto i = vectorOfMutexes.size() - 1; i >= vectorOfMutexes.size() / 2; --i ) {
		vectorOfMutexes[i].second = CSegment( 2 * i + 1, 2 * i + 2 );
	}
	for (auto i = vectorOfMutexes.size() / 2 - 1; i >= 0; --i) {
		vectorOfMutexes[i].second = CSegment( vectorOfMutexes[getIndexOfLeftSon( i )].second.leftBorder,
			vectorOfMutexes[getIndexOfRightSon( i )].secind.rightBorder );
	}
}

void tree_mutex::lock( std::size_t indexOfThread )
{
	std::size_t indexInTree = getIndexInTree( indexOfThread );
	do {
		indexInTree = getIndexOfFather( indexOfTree );
		if( isNotLeftSon( indexInTree ) ) {
			vectorOfMutexes[indexInTree].lock( 1 );
		} else {
			vectorOfMutexes[indexInTree].lock( 0 );
		}
	} while( indexInTree != 0 );
}

void tree_mutex::unlock( std::size_t indexOfThread )
{
	assert( indexOfThread < threadsCount );
	std::size_t indexInTree = getIndexInTree( indexOfThread );
	std::size_t currentIndex = 0;
	while( currentIndex != indexInTree ) {
		std::size_t leftSegment = vectorOfMutexes[getIndexOfLeftSon( currentIndex )].second;
		std::size_t rightSegment = vectorOfMutexes[getIndexOfRightSon( currentIndex )].second;
		if ( indexInTree <= lefSegment.right ) {
			vectorOfMutexes[currentIndex].unlock( 0 );
			currentIndex = getIndexOfLeftSon( currentIndex );
		} else {
			vectorOfMutexes[currentIndex].unlock( 1 );
			currentIndex = getIndexOfRightSon( currentIndex );
		}
	}
}

std::size_t tree_mutex::getIndexInTree( std::size_t indexOfThread )
{
	if( vectorOfMutexes.size() > 1 ) {
		return indexOfThread + vectorOfMutexes.size() - 1;
	}
	return 0;
}

std::size_t tree_mutex::getIndexOfFather( std::size_t indexOfThread )
{
	assert( indexOfThread > 0 );
	return ( indexOfThread - 1 ) / 2;
}

std::size_t tree_mutex::getIndexOfLeftSon( std::size_t indexOfThread )
{
	assert( indexOfThread < vectorOfMutexes.size() );
	return 2 * indexOfThread + 1;
}

std::size_t tree_mutex::getIndexOfRightSon( std::size_t indexOfThread )
{
	assert( indexOfThread < vectorOfMutexes.size() );
	return 2 * indexOfThread + 2;
}

bool tree_mutex::isNotLeftSon( stdL::size_t indexOfThread )
{
	return ( indexOfThread % 2 == 0);
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	int hello;
	std::cin >> hello;
	std::cout << hello << std::endl;
	return 0;
}