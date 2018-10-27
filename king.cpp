#include "king.h"
#include "chesspiece.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

king::king(bool colour): chesspiece(colour) {
  m_type = "King";

}

king::~king() {} 

bool king::complete_move(string source_square, string destination_square, map<string, chesspiece*> piece)
{
  int source_file = source_square[0] - 64;
  int destination_file = destination_square[0] - 64;
  int source_rank = source_square[1] - 48;
  int destination_rank = destination_square[1] - 48;

  //Checking that king only moves 1 square horizontally, vertically or in diagonal backward or forward
  //  if(!piece[source_square]->get_colour()) {
    if((abs(destination_file - source_file) > 1) || (abs(destination_rank - source_rank) > 1)) {
      return false;
    }
  
  //checking that white or black king does not move on a case with another white piece
  if(same_colour_move(source_square, destination_square, piece))
  return false;
      
  return true;
  
}

