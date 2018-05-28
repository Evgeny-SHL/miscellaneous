#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>


int main() {
	const unsigned long long MaxValue = 9223372036854775807;

	std::string literal = "";
	std::getline( std::cin, literal );
	if( literal[0] != '+' ) {
		literal = "+" + literal;
	}

	unsigned long long number;
	try {
		number = std::stoull( literal );
		if( literal != "+" + std::to_string( number ) ) {
			throw std::invalid_argument( "Нет числа на входе" );
		}
		if( number > MaxValue || number < 1 ) {
			throw std::out_of_range( "Число не принадлежит диапазону от 1 до 9223372036854775807" );
		}
	} catch( std::logic_error e ) {
		std::cout << 0 << std::endl;
		return 0;
	}

	double discriminant = static_cast<double>( number ) * 8.0 + 1.0;
	unsigned long long root = static_cast<int>( std::sqrt( discriminant ) );

	for( int shift = -2; shift <= 2; ++shift ) {
		long long guessIndex = ( root + shift - 1 ) / 2;
		if ( guessIndex * ( guessIndex + 1 ) == 2 * number ) {
			std::cout << guessIndex << std::endl;
			return 0;
		}
	}

	std::cout << 0 << std::endl;
	return 0;
}
