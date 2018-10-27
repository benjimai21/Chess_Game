#include "rook.h"
#include "chesspiece.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;


using namespace std;

rook::rook(bool colour): chesspiece(colour) {
  m_type = "Rook";

}

rook::~rook() {}

bool rook::complete_move(string source_square, string destination_square, map<string, chesspiece*> piece) {
  int source_file = source_square[0] - 64;
  int destination_file = destination_square[0] - 64;
  int source_rank = source_square[1] - 48;
  int destination_rank = destination_square[1] - 48;

  //white rook cannot move in diagonal
  if(piece[source_square]->get_colour()) {
    if((source_file != destination_file) && (source_rank != destination_rank)) {
      return false;
    }
  }

  //Black rook cannot move in diagonal
  if(!piece[source_square]->get_colour()) {
    if((source_file != destination_file) && (source_rank != destination_rank)) {
      return false;
    }
  }
     
  if(destination_file > source_file) {
    for(int i = 1 ; i < (destination_file - source_file) ; i++) {
      string obstacle_right("A1");
      obstacle_right[0] = source_square[0] + i;
      obstacle_right[1] = source_square[1];

      if(piece[obstacle_right] != NULL) {

	return false;
      }

    }

  }

  //if no obstacles left
  if(destination_file < source_file) {
    for(int i = 1 ; i < (source_file - destination_file) ; i++) {
      string obstacle_left("A1");
      obstacle_left[0] = source_square[0] - i;
      obstacle_left[1] = source_square[1];

      if(piece[obstacle_left] != NULL) {

	return false;
      }

    }
  }

  //if not obstacles up
  if(destination_rank > source_rank) {
    for(int i = 1 ; i < (destination_rank - source_rank) ; i++) {
      string obstacle_north("A1");
      obstacle_north[0] = source_square[0];
      obstacle_north[1] = source_square[1] + i;

      if(piece[obstacle_north] != NULL) {

	return false;
      }

    }
  }

  //if no obstacles down
  if(destination_rank < source_rank) {
    for(int i = 1 ; i < (source_rank - destination_rank) ; i++) {
      string obstacle_south("A1");
      obstacle_south[0] = source_square[0];
      obstacle_south[1] = source_square[1] - i;

      if(piece[obstacle_south] != NULL) {

	return false;
      }

    }
  }


  //checking that white or black rook does not move on a case with another white piece
  if(same_colour_move(source_square, destination_square, piece))
  return false;

  return true;
}



