#include<iostream>
#include<string>
#include<cstring>
#include "chesspiece.h"
#include<map>


using namespace std;

chesspiece::chesspiece(bool colour) {
  m_colour = colour;
    }

chesspiece::~chesspiece() {}

string chesspiece::get_type() { return m_type; }

bool chesspiece::get_colour() {return m_colour; }

void chesspiece::unset_true() {first_move = false; } 

bool chesspiece::get_first_move() {return first_move; }

bool chesspiece::same_colour_move(string source_square, string destination_square, map<string, chesspiece*> piece) 
{
  //checking that white king does not move on a case with another white piece
  if(piece[source_square]->get_colour()) {
    if(piece[destination_square] != NULL && piece[destination_square]->get_colour()) {;
      return true;
   }
 }

    //checking that black king does not move on a case with another black piece
  if(!piece[source_square]->get_colour()) {
    if(piece[destination_square] != NULL && piece[destination_square]->get_colour() == false) {
      return true;
   }
 }
  return false;
}
