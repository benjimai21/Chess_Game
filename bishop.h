#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"
#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;

class bishop: public chesspiece {
 public:
  bishop(bool colour);
  bool complete_move(string source_square, string destination_square, map<string, chesspiece*> piece);  ~bishop(); 

};

#endif 
