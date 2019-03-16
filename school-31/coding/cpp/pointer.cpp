#include <iostream>

int main() {
    int x = 5;
    int y = 7;
    int z = 11;
    int* a = &x;
    int* b = &y;
    int *c = &z;
    std::cout << a << " " << b << " " << c << std::endl;
    std::cout << *a << " " << *b << " " << *c << std::endl;
    a = b;
    b = c;
    std::cout << a << " " << b << " " << c << std::endl;
    std::cout << *a << " " << *b << " " << *c << std::endl;

    return 0;
}