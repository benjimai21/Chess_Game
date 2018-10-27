#include "pawn.h"
#include "chesspiece.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

pawn::pawn(bool colour): chesspiece(colour) {
  m_type = "Pawn";
  first_move = true; //to reach specificities of the pawn first move
}


pawn::~pawn() {} 

bool pawn::complete_move(string source_square, string destination_square, map<string, chesspiece*> piece)
{
  int source_file = source_square[0] - 64;
  int destination_file = destination_square[0] - 64;
  int source_rank = source_square[1] - 48;
  int destination_rank = destination_square[1] - 48;

  int direction;

  if(piece[source_square]->get_colour())
    direction = 1;
  else if(!piece[source_square]->get_colour())
    direction = -1;

  if(first_move) {

    //if a pawn tries to move backward to its side and more than 2 squares on the first move
    if(((piece[source_square]->get_colour() && (((destination_rank - source_rank) > 2*direction) || (destination_rank - source_rank) < 0))) || (!piece[source_square]->get_colour() && (((destination_rank - source_rank) < 2*direction) || (destination_rank - source_rank) > 0))) 
      return false;


    //if a pawn tries to move horizontally
    if((source_rank == destination_rank) && (source_file != destination_file)) 
      return false;
	
		
    //if a pawn tries to move more than one square in diagonal
    if((destination_rank != source_rank) && (destination_file != source_file) && ((abs(destination_rank - source_rank) > 1) || (abs(destination_file - source_file) > 1)))  
      return false;


    //if a pawn tries to move in diagonal and the square is empty
    if((destination_rank != source_rank) && (destination_file != source_file) && (piece[destination_square] == NULL))
      return false;


    //if a pawn tries to eat a piece of its colour in diagonal 
    if(piece[destination_square] != NULL && (piece[source_square]->get_colour() == piece[destination_square]->get_colour())) 
      return false;

    //if a pawn tries to eat another piece by moving forward
    if((((destination_rank - source_rank) == direction) || (destination_rank - source_rank) == 2*direction) && (source_file == destination_file) && (piece[destination_square] != NULL) && (piece[source_square]->get_colour() != piece[destination_square]->get_colour()))
      return false;
      

    //if a pawn moves 2 squares forward and there is an obstacle, return false
    if(((destination_rank - source_rank) == 2*direction) && (destination_file == source_file)) {
      string obstacle_north("A1");
      obstacle_north[0] = source_square[0];
      obstacle_north[1] = source_square[1] + direction;

      if(piece[obstacle_north] != NULL) {
	return false;
      }
    }
       
  }

  
  //if not first move
  else {

    //if a pawn tries to move backward to its side and more than 2 squares on the first move
    if(((piece[source_square]->get_colour() && (((destination_rank - source_rank) > direction) || (destination_rank - source_rank) < 0))) || (!piece[source_square]->get_colour() && (((destination_rank - source_rank) < direction) || (destination_rank - source_rank) > 0))) 
      return false;
  
    //if a pawn tries to move horizontally
    if((source_rank == destination_rank) && (source_file != destination_file)) 
      return false;
  
    //if a pawn tries to move more than one square in diagonal
    if((destination_rank != source_rank) && (destination_file != source_file) && ((abs(destination_rank - source_rank) > 1) || (abs(destination_file - source_file) > 1)))  
      return false;


   
    //if a pawn tries to move in diagonal and the square is empty
    if((destination_rank != source_rank) && (destination_file != source_file) && (piece[destination_square] == NULL))
      return false;


    //if a pawn tries to eat a piece of its colour in diagonal 
    if(piece[destination_square] != NULL && (piece[source_square]->get_colour() == piece[destination_square]->get_colour())) 
      return false;

      
    //if a pawn tries to eat another piece by moving forward
    if(((destination_rank - source_rank) == direction) && (source_file == destination_file) && (piece[destination_square] != NULL) && (piece[source_square]->get_colour() != piece[destination_square]->get_colour()))
      return false;
  
      
  }
      
  return true;

}
  


  
    
