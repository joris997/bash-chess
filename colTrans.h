#ifndef COLTRANS_H
#define COLTRANS_H

char colTrans(int col){
  if(col>=1 && col<=8){
    return "abcdefgh"[col-1];
  }
  else{
    char alt = "a";
    return alt;
  }
}

#endif
