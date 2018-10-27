#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"
#include<iostream>
#include<map>
#include<string>
#include<cstring>

using namespace std;

class pawn: public chesspiece {
 public:
  pawn(bool colour);
  ~pawn();
  bool complete_move(string source_square, string destination_square, map<string, chesspiece*> piece); 

};

#endif
