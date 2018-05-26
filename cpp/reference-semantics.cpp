int Global = 22;

void AddGlobalAndFirstArgumentRespectively( int& agr1, int& arg2 ) {
  arg1 += Global;
  agr2 += arg1;
}

int main() {
  AddGlobalAndFirstArgumentRespectively( Global, Global );
  return 0;
}
