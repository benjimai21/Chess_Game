#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

class queen: public chesspiece {
 public:
  queen(bool colour);
  bool complete_move(string source_square, string destination_square, map<string, chesspiece*> piece); ~queen(); 

};

#endif 
