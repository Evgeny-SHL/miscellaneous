#include <stdio.h>
int main(){
  long double a;
  scanf("%Lf", &a);
  printf("%+.3e", a);
  return 0;
}