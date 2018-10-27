#include "bishop.h"
#include "chesspiece.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;


using namespace std;

bishop::bishop(bool colour): chesspiece(colour) {
  m_type = "Bishop";

}

bishop::~bishop() {}

bool bishop::complete_move(string source_square, string destination_square, map<string, chesspiece*> piece) {
  
  int source_file = source_square[0] - 64;
  int destination_file = destination_square[0] - 64;
  int source_rank = source_square[1] - 48;
  int destination_rank = destination_square[1] - 48;


  //white bishop cannot move horizontally or vertically
  if(piece[source_square]->get_colour()) {
    if((source_file == destination_file) || (source_rank == destination_rank)) {
      return false;
    }
  }


  //black bishop cannot move horizontally or vertically
  if(!piece[source_square]->get_colour()) {
    if((source_file == destination_file) || (source_rank == destination_rank)) {

      return false;
    }
  }

  //white bishop can only move in diagonal
  if(piece[source_square]->get_colour()) {
    if((source_file != destination_file) && (source_rank != destination_rank) && (abs(destination_file - source_file) != abs(destination_rank - source_rank))) {
      return false;
    }
  }

  
  //black bishop can only move in diagonal
  if(!piece[source_square]->get_colour()) {
    if((source_file != destination_file) && (source_rank != destination_rank) && (abs(destination_file - source_file) != abs(destination_rank - source_rank))) {
      return false;
    }
  }


  //if obstacle North East
  if((destination_file > source_file) && (destination_rank > source_rank)) {
    for(int i = 1 ; i < (destination_file - source_file) ; i++) {
      string obstacle_NorthEast("A1");
      obstacle_NorthEast[0] = source_square[0] + i;
      obstacle_NorthEast[1] = source_square[1] + i;

      if(piece[obstacle_NorthEast] != NULL) {

	return false;
      }

    }

  }

  //if obstacle North West
  if((destination_file < source_file) && (destination_rank > source_rank)) {
    for(int i = 1 ; i < (source_file - destination_file) ; i++) {
      string obstacle_NorthWest("A1");
      obstacle_NorthWest[0] = source_square[0] - i;
      obstacle_NorthWest[1] = source_square[1] + i;

      if(piece[obstacle_NorthWest] != NULL) {

	return false;
      }

    }
  }

  //if obstacle South East
  if((destination_file > source_file) && (destination_rank < source_rank)) {
    for(int i = 1 ; i < (destination_file - source_file) ; i++) {
      string obstacle_SouthEast("A1");
      obstacle_SouthEast[0] = source_square[0] + i;
      obstacle_SouthEast[1] = source_square[1] - i;

      if(piece[obstacle_SouthEast] != NULL) {

	return false;
      }

    }
  }

  //if obstacle South West
  if((destination_rank < source_rank) && (destination_file < source_file)) {
    for(int i = 1 ; i < (source_rank - destination_rank) ; i++) {
      string obstacle_southWest("A1");
      obstacle_southWest[0] = source_square[0] - i;
      obstacle_southWest[1] = source_square[1] - i;

      if(piece[obstacle_southWest] != NULL) {

	return false;
      }

    }
  }
	
  //checking that white or black bishop does not move on a case with another white piece
  if(same_colour_move(source_square, destination_square, piece))
    return false;
  
  return true;
		
}
