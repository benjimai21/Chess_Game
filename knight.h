#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"
#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;

class knight: public chesspiece {
 public:
  knight(bool colour);
  bool complete_move(string source_square, string destination_square, map<string, chesspiece*> piece); 
  ~knight();
};

#endif 
