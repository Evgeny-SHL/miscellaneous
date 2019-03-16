#include <stdio.h>
int main(){
  long double a;
  a = 2.1;
  printf("%+.3e\n", 3.76856); // +3.369e+000
  printf("%+.3e\n", a); // -1.637+237
  printf("%e", a); // -1.637+237
  return 0;
}