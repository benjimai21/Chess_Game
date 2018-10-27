#ifndef KING_H
#define KING_H
#include "chesspiece.h"
#include<iostream>
#include<map>
#include<string>
#include<cstring>

using namespace std;

class king: public chesspiece {
 public:
  king(bool colour);
  ~king();
  bool complete_move(string source_square, string destination_square, map<string, chesspiece*> piece); 

};

#endif
