#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "chesspiece.h"
#include<iostream>
#include<map>
#include<cstring>
#include<string>

class ChessBoard {
 private:
  map<string, chesspiece*> piece;
  bool m_turn;
  chesspiece *black_king;
  chesspiece *white_king;
  string black_king_position;
  string white_king_position;
 public:
  ChessBoard();
  ~ChessBoard();
 bool submitMove(string source_square, string destination_square);
 void initialize_board();
 void clear_board();
 void resetBoard();
 bool check(string destination_square);
 bool check_mate(string destination_square);
 bool stalemate(string destination_square);

};

#endif
