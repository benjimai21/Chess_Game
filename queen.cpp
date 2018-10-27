#include "queen.h"
#include "chesspiece.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;


using namespace std;

queen::queen(bool colour): chesspiece(colour) {
  m_type = "Queen";

}

queen::~queen() {}

bool queen::complete_move(string source_square, string destination_square, map<string, chesspiece*> piece) {
  
  int source_file = source_square[0] - 64;
  int destination_file = destination_square[0] - 64;
  int source_rank = source_square[1] - 48;
  int destination_rank = destination_square[1] - 48;


   //white queen can only move in diagonal
  if(piece[source_square]->get_colour()) {
    if((source_file != destination_file) && (source_rank != destination_rank) && (abs(destination_file - source_file) != abs(destination_rank - source_rank))) {
      return false;
    }
  }

  
     //black queen can only move in diagonal
  if(!piece[source_square]->get_colour()) {
    if((source_file != destination_file) && (source_rank != destination_rank) && (abs(destination_file - source_file) != abs(destination_rank - source_rank))) {
      return false;
    }
  }


  
    //checking no obstacle if queen moves North East
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

  //checking no obstacle if queen moves North West
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

  //checking no obstacle if queen moves South East
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

        //checking no obstacle if queen moves South West 
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

	 //checking no obstacle if queen moves right
	if((destination_file > source_file) && (source_rank == destination_rank)) {
	  for(int i = 1 ; i < (destination_file - source_file) ; i++) {
	    string obstacle_right("A1");
	    obstacle_right[0] = source_square[0] + i;
	    obstacle_right[1] = source_square[1];

	    if(piece[obstacle_right] != NULL) {
	    
	      return false;
	    }

	  }

	}

	//checking no obstacle if queen moves left
	if((destination_file < source_file) && (source_rank == destination_rank) ) {
	  for(int i = 1 ; i < (source_file - destination_file) ; i++) {
	    string obstacle_left("A1");
	    obstacle_left[0] = source_square[0] - i;
	    obstacle_left[1] = source_square[1];

	    if(piece[obstacle_left] != NULL) {
	    
	      return false;
	    }

	  }
	}

	//checking no obstacle if queen moves up
	if((destination_rank > source_rank) && (destination_file == source_file)) {
	  for(int i = 1 ; i < (destination_rank - source_rank) ; i++) {
	    string obstacle_north("A1");
	    obstacle_north[0] = source_square[0];
	    obstacle_north[1] = source_square[1] + i;

	    if(piece[obstacle_north] != NULL) {
	    
	      return false;
	    }

	  }
	}

        //checking no obstacle if queen moves down
	if((destination_rank < source_rank) && (destination_file == source_file)) {
	  for(int i = 1 ; i < (source_rank - destination_rank) ; i++) {
	    string obstacle_south("A1");
	    obstacle_south[0] = source_square[0];
	    obstacle_south[1] = source_square[1] - i;

	    if(piece[obstacle_south] != NULL) {
	    
	      return false;
	    }

	  }
	}

  //checking that white or black quuen does not move on a case with another white piece
  if(same_colour_move(source_square, destination_square, piece))
  return false;
  
  return true;
		
}
