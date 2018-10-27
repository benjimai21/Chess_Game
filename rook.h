#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"
#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;

class rook: public chesspiece {
 public:
  rook(bool colour);
  bool complete_move(string source_square, string destination_square, map<string, chesspiece*> piece); ~rook(); 

};

#endif 
