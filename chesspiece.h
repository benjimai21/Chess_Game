#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;

class chesspiece {
  
protected:
  bool m_colour;
  string m_type;
  bool first_move;
 public:
  chesspiece(bool colour);
  virtual bool complete_move(string source_square, string destination_square, map<string, chesspiece*> piece) = 0;
  string get_type();
  bool get_colour();
  bool same_colour_move(string source_square, string destination_square, map<string, chesspiece*> piece);
  void unset_true();
  bool get_first_move();
  virtual ~chesspiece();
};

#endif
