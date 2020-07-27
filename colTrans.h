#ifndef COLTRANS_H
#define COLTRANS_H

char num2char(int col){
  if(col>=1 && col<=8){
    return "abcdefgh"[col-1];
  }
  else{
    char alt = 'a';
    return alt;
  }
}

int char2num(char col){
  int num = (int) col - 97;
  if(num>=1 && num<=8){
    return num;
  }
  else{
    return 1;
  }
}
#endif
