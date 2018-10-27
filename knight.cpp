#include "knight.h"
#include "chesspiece.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;


using namespace std;

knight::knight(bool colour): chesspiece(colour) {
  m_type = "Knight";

}

knight::~knight() {}

bool knight::complete_move(string source_square, string destination_square, map<string, chesspiece*> piece) {
  
  int source_file = source_square[0] - 64;
  int destination_file = destination_square[0] - 64;
  int source_rank = source_square[1] - 48;
  int destination_rank = destination_square[1] - 48;


  // if white knight moves more than two squares horizontally or vertically, return false
  if(piece[source_square]->get_colour()) {
    if((abs(destination_file - source_file) > 2) || (abs(destination_rank - source_rank) > 2)) {
      return false;
    }
  }


  //if the white knight moves horizontally, vertically or in diagonal, return false
  if(piece[source_square]->get_colour()) {
    if(((destination_rank == source_rank) && (destination_file != source_file)) || ((destination_rank != source_rank) && (destination_file == source_file)) || ((destination_rank != source_rank) && (destination_file != source_file) && (abs(destination_rank - source_rank) == abs(destination_file - source_file)))) {
      return false;
    }
  }


   if(piece[source_square]->get_colour()) {
     if((abs(destination_file - source_file) == 2 && abs(destination_rank - source_rank) != 1) && (abs(destination_file - source_file) != 1 && abs(destination_rank - source_rank) == 2)) {
  
    return false;
     }
   }

     // if black knight moves more than two squares horizontally or vertically, return false
  if(!piece[source_square]->get_colour()) {
    if((abs(destination_file - source_file) > 2) || (abs(destination_rank - source_rank) > 2)) {
 
      return false;
    }
  }

    //if the black knight moves horizontally, vertically or in diagonal, return false
  if(!piece[source_square]->get_colour()) {
    if(((destination_rank == source_rank) && (destination_file != source_file)) || ((destination_rank != source_rank) && (destination_file == source_file)) || ((destination_rank != source_rank) && (destination_file != source_file) && (abs(destination_rank - source_rank) == abs(destination_file - source_file)))) {
 
      return false;
    }
  }

   if(!piece[source_square]->get_colour()) {
     if((abs(destination_file - source_file) == 2 && abs(destination_rank - source_rank) != 1) && (abs(destination_file - source_file) != 1 && abs(destination_rank - source_rank) == 2)) {
 
    return false;
     }
   }

   //checking that white or black king does not move on a case with another white piece
  if(same_colour_move(source_square, destination_square, piece))
  return false;

   
  return true;
}
  
