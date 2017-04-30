#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>


int main() {
	long double literal = 0.0;
	std::cin >> literal;

	unsigned long long firstIndex = 1;
	unsigned long long maxLength = 1;

	try {
		unsigned long long number = std::floor( literal );
		if( literal != number) {
			throw std::invalid_argument( "1 Нет числа на входе" );
		}
		if( number < 2 ) {
			throw std::out_of_range( "2 Число N меньше 2" );
		}

		long double prev;
		if( !(std::cin >> prev )) {
			throw std::out_of_range( "3 Нет входной последовательности" );
		}

		unsigned long long length = 1;
		unsigned long long currentFirstIndex = 1;
		unsigned long long currentMaxLength = 1;
		long double value;

		while( ( std::cin >> value ) && ( length < number ) ) {
			++length;
			if( value >= prev ) {
				++currentMaxLength;
			} else {
				currentMaxLength = 1;
				currentFirstIndex = length;
			}
			if( currentMaxLength > maxLength ) {
				maxLength = currentMaxLength;
				firstIndex = currentFirstIndex;
			}
			prev = value;
		}

		if( ( std::cin.fail() && ( length != number ) ) || length < number ) {
			throw std::invalid_argument( "4 Неправильные входная последовательность" );
		}

	} catch( std::logic_error e ) {
		std::cout << "[error]" << std::endl;
		return 0;
	}

	if( maxLength == 1 ) {
		std::cout << 0 << std::endl;
	} else {
		std::cout << maxLength << " " << firstIndex << std::endl;
	}

	return 0;
}
