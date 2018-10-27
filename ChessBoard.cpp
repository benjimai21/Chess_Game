//I failed to implement the function that a move that puts the king in a chess situation is not a legal move, therefore some checkmates tests might fail not because of my checkmate function but because the king making a move that would put him in check is not taken into account in this program


#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include "ChessBoard.h"
#include "chesspiece.h"
#include "king.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "knight.h"
#include "pawn.h"

using namespace std;

ChessBoard::ChessBoard() {

  initialize_board();

}
ChessBoard::~ChessBoard()
{

}

void ChessBoard::clear_board()
{
  map<string, chesspiece*>::iterator all;
  for(all = piece.begin() ; all != piece.end() ; all++)
    delete all->second;
  
  piece.clear();
}

void ChessBoard::resetBoard()
{
  clear_board();
  initialize_board();
}

void ChessBoard::initialize_board() {

  cout << "A new chess game is started!" << endl;

  m_turn = true; //set first turn to true meaning whites play first
  
  //initializing empty positions to NULL
  piece["A6"] = NULL;
  piece["A5"] = NULL;
  piece["A4"] = NULL;
  piece["A3"] = NULL;
  piece["B6"] = NULL;
  piece["B5"] = NULL;
  piece["B4"] = NULL;
  piece["B3"] = NULL;
  piece["C6"] = NULL;
  piece["C5"] = NULL;
  piece["C4"] = NULL;
  piece["C3"] = NULL;
  piece["D6"] = NULL;
  piece["D5"] = NULL;
  piece["D4"] = NULL;
  piece["D3"] = NULL;
  piece["E6"] = NULL;
  piece["E5"] = NULL;
  piece["E4"] = NULL;
  piece["E3"] = NULL;
  piece["F6"] = NULL;
  piece["F5"] = NULL;
  piece["F4"] = NULL;
  piece["F3"] = NULL;
  piece["G6"] = NULL;
  piece["G5"] = NULL;
  piece["G4"] = NULL;
  piece["G3"] = NULL;
  piece["H6"] = NULL;
  piece["H5"] = NULL;
  piece["H4"] = NULL;
  piece["H3"] = NULL;
  
  //initializing positions of white pieces
  
  piece["A1"] = new rook(true);
  piece["B1"] = new knight(true);
  piece["C1"] = new bishop(true);
  piece["D1"] = new queen(true);
  piece["E1"] = new king(true);
  piece["F1"] = new bishop(true);
  piece["G1"] = new knight(true);
  piece["H1"] = new rook(true);
  piece["A2"] = new pawn(true);
  piece["B2"] = new pawn(true);
  piece["C2"] = new pawn(true);
  piece["D2"] = new pawn(true);
  piece["E2"] = new pawn(true);
  piece["F2"] = new pawn(true);
  piece["G2"] = new pawn(true);
  piece["H2"] = new pawn(true);
  
  //initializing positions of black pieces
  
  piece["A8"] = new rook(false);
  piece["B8"] = new knight(false);
  piece["C8"] = new bishop(false);
  piece["D8"] = new queen(false);
  piece["E8"] = new king(false);
  piece["F8"] = new bishop(false);
  piece["G8"] = new knight(false);
  piece["H8"] = new rook(false);
  piece["A7"] = new pawn(false);
  piece["B7"] = new pawn(false);
  piece["C7"] = new pawn(false);
  piece["D7"] = new pawn(false);
  piece["E7"] = new pawn(false);
  piece["F7"] = new pawn(false);
  piece["G7"] = new pawn(false);
  piece["H7"] = new pawn(false);
  
  
}

//My function submit move follows 5 steps from 1 to 5
bool ChessBoard::submitMove(string source_square, string destination_square)
{

  //1)checking for wrong source and destination positions and wrong colour player  
  if(source_square[0] < 65 || source_square[0] > 72) {
    cout << "Invalid source file!" << endl;
    return false;
  }
    
  if(source_square[1] < 49 || source_square[1] > 56) {
    cout << "Invalid source rank!" << endl;
    return false;
  }

  if(destination_square[0] < 65 || destination_square[0] > 72) {
    cout << "Invalid destination file!" << endl;
    return false;
  }

  if(destination_square[1] < 49 || destination_square[1] > 56) {
    cout << "Invalid destination rank!" <<  endl;
    return false;
  }

  if(piece[source_square] == NULL) {
    cout << "There is no piece at position " << source_square << "!\n";
    return false;
  }

  if(piece[source_square] == piece[destination_square]) {
    cout << "A piece has to move to another square" << endl;
    return false;
  }
 
   
  if(!piece[source_square]->get_colour() && m_turn == true) {
    cout << "It is not Black's turn to move!" << endl;
    return false;
  }

  if(piece[source_square]->get_colour() && m_turn == false) {
    cout << "It is not White's turn to move!" << endl;
    return false;
  }

    

  //2) operating move of a piece
  if(piece[source_square]->complete_move(source_square, destination_square, piece))
    {

      if(piece[source_square]->get_colour()) {
	
	if(piece[destination_square] != NULL && !piece[destination_square]->get_colour()) {
	  cout <<  "White's " << piece[source_square]->get_type() <<" moves from " << source_square << " to " << destination_square << " taking Black's " << piece[destination_square]->get_type() << endl;
      
	}  
	else {
	  cout << "White's " << piece[source_square]->get_type() <<" moves from " << source_square << " to " << destination_square << endl;
	
	}
	
      }
  
      if(!piece[source_square]->get_colour()) {
	if(piece[destination_square] != NULL && piece[destination_square]->get_colour()) {
     
	  cout <<  "Black's " << piece[source_square]->get_type() <<" moves from " << source_square << " to " << destination_square << " taking White's " << piece[destination_square]->get_type() << endl;
	  
	}
  
	else {
	  cout << "Black's " << piece[source_square]->get_type() << " moves from " << source_square << " to " << destination_square << endl;
	 
	}
      }

      delete piece[destination_square];
      piece[destination_square] = piece[source_square];
      piece[source_square] = NULL;

      

      
      //3) if piece is a pawn in its first move, set attribute first_move to false
      if(piece[destination_square]->get_first_move())
	piece[destination_square]->unset_true();

      
      //4) checking for check checkmate and stalemate and if not check checking for stalemate
      if(check(destination_square)) {
	if(piece[destination_square]->get_colour()) 
	  cout << "Black is in check";
	
	if(!piece[destination_square]->get_colour()) 
	  cout << "White is in check";
	
      
        if(check_mate(destination_square)) 
	  cout << "mate" << endl;
	else 
	  cout << endl;	
      }
      
      else if(!check(destination_square)) {
	if(stalemate(destination_square)) 
	  cout << "Stalemate: There is a draw" << endl;
      }
	

      //5)switching player 
      if(m_turn) 
	m_turn = false;
      else
	m_turn = true;

    }

  //if 1) fails, a piece cannot move to another square
  else {
    
    if(piece[source_square]->get_colour()) 
      cout << "White's " << piece[source_square]->get_type() << " cannot move to " << destination_square << "!\n";
    else if(!piece[source_square]->get_colour())
      cout << "Black's " << piece[source_square]->get_type() << " cannot move to " << destination_square << "!\n";
  }


  return false;

  
}


bool ChessBoard::check(string destination_square) {

  map<string, chesspiece*>::iterator white, black;

  //if white played we check for check
  if(piece[destination_square]->get_colour()) {

    for(white = piece.begin() ; white != piece.end() ; white++) {
      if((white->second != NULL) && ((white->second)->get_colour() == true)) {
	
	for(black = piece.begin() ; black != piece.end() ; black++) {  
	  if((black->second != NULL) && ((black->second)->get_colour() == false)) {
	
	    if((white->second)->complete_move(white->first, black->first, piece)) {

	      if((black->second)->get_type() == "King") {
		black_king_position = black->first;      //black_king_position saves the adress of the black king to be used in the checkmate function
		black_king = black->second;            //black_king saves the string position of the black king to be used in the checkmate function

		return true;
	      }
	    }
	  }
	}
      }
    }
    return false;
  }


  //if black played we check for check
  if(!piece[destination_square]->get_colour()) {

    for(black = piece.begin() ; black != piece.end() ; black++) {
      if((black->second != NULL) && ((black->second)->get_colour() == false)) {

	for(white = piece.begin() ; white != piece.end() ; white++) {
	  if((white->second != NULL) && ((white->second)->get_colour() == true)) {

	    if((black->second)->complete_move(black->first, white->first, piece)) {
	    
	      if((white->second)->get_type() == "King") {
		white_king_position = white->first;              //white_king_position saves the adress of the white king to be used in the checkmate function
		white_king = white->second;                       //white_king saves the string position of the white king to be used in the checkmate function
		return true;
	      }
	    }
	  }
	}
      }
    }
    return false;     
  }
  
  return false;
 
}



bool ChessBoard::check_mate(string destination_square)
{

  map<string, chesspiece*>::iterator black, white, all, black_2, black_3, all_2, white_2, white_3;

   
  //if the piece that put the opponent in check is white
  if(piece[destination_square]->get_colour()) {

    //if a black piece can eat the white piece that threatens the king
    for(black_2 = piece.begin() ; black_2 != piece.end() ; black_2++) {
      if((black_2->second != NULL) && ((black_2->second)->get_colour() == false)) {
	if((black_2->second)->complete_move(black_2->first, destination_square, piece)) {
	  
	  return false;
	}
      }
    }

	   
    //if a black piece can interpose between the king and white the piece that threatens
    for(black_3 = piece.begin() ; black_3 != piece.end() ; black_3++) {
      if(black_3->second != NULL && (black_3->second)->get_colour() == false && (black_3->second)->get_type() != "King") {
	       
	for(all_2 = piece.begin() ; all_2 != piece.end() ; all_2++) {
	  if(all_2->second == NULL) {
		   
	    if((black_3->second)->complete_move(black_3->first, all_2->first, piece)) {
	      if(piece[destination_square]->complete_move(destination_square, all_2->first, piece)) {    
		all_2->second =  piece[black_3->first];
		piece[black_3->first] = NULL;
       
		if(!piece[destination_square]->complete_move(destination_square, black_king_position, piece)) {

		  piece[black_3->first] = all_2->second;
		  all_2->second = NULL;
		  return false;
		}
		else {

		  piece[black_3->first] = all_2->second;
		  all_2->second = NULL;
		}
		     
		      
	      }
		       
	    }
	  }
	}
      }
    }
	   		 
	   
    //if the king can move to a square where he is not threaten anymore
    for(all = piece.begin() ; all != piece.end() ; all++) {
      if((black_king)->complete_move(black_king_position, all->first, piece)) {

	for(white = piece.begin() ; white != piece.end() ; white++) {
	  if((white->second != NULL) && ((white->second)->get_colour() == true)) {
	    if(((white->second)->complete_move(white->first, all->first, piece))) {

	      break;
	    }
	  }
	
	}
	    
	if(white == piece.end())        //if for a position no pieces can threaten the black king
	  return false;
	
      }
    }

    return true;
   
  }

   
  //if the piece that put the opponent in check is black
  if(!piece[destination_square]->get_colour()) {
      
    //if a white piece can eat the black piece that threatens the king
    for(white_2 = piece.begin() ; white_2 != piece.end() ; white_2++) {
      if((white_2->second != NULL) && ((white_2->second)->get_colour() == true)) {
	if((white_2->second)->complete_move(white_2->first, destination_square, piece))
	  return false;
      }
    }

    //if a piece can interpose between the king and the piece that threatens
    for(white_3 = piece.begin() ; white_3 != piece.end() ; white_3++) {
      if(white_3->second != NULL && (white_3->second)->get_colour() == true && (white_3->second)->get_type() != "King") {
	for(all_2 = piece.begin() ; all_2 != piece.end() ; all_2++) {
	  if(all_2->second == NULL) {
	    if((white_3->second)->complete_move(white_3->first, all_2->first, piece)) {
	      if(piece[destination_square]->complete_move(destination_square, all_2->first, piece)) {
		all_2->second =  piece[black_3->first];
		piece[black_3->first] = NULL;
       
		if(!piece[destination_square]->complete_move(destination_square, black_king_position, piece)) {
		  piece[white_3->first] = all_2->second;
		  all_2->second = NULL;
		  return false;
		}
		       
		else {
		  piece[white_3->first] = all_2->second;
		  all_2->second = NULL;
		}

	      }
	    }
		       
	  }
	}
      }
    }
    

    //if a king can move to a piece in which he is not threaten	   
    for(all = piece.begin() ; all != piece.end() ; all++) {
      if((white_king)->complete_move(white_king_position, all->first, piece)) {
		
	for(black = piece.begin() ; black != piece.end() ; black++) {
		
	  if((black->second != NULL) && ((black->second)->get_colour() == false)) {
	    if(((black->second)->complete_move(black->first, all->first, piece))) {
		
	      break;
	    }
	  }
	
	}
	     
	if(black == piece.end())       //if for a position no pieces can threaten the white king
	  return false;	     
      }
    }

    return true;
  }
  return true;
}

bool ChessBoard::stalemate(string destination_square)
{

  map<string, chesspiece*>::iterator white, black, all, black_2, all_2, white_2;


  //checking that the only valid move is from the black king
  if(piece[destination_square]->get_colour()) {
    
    for(all = piece.begin() ; all != piece.end() ; all++) {
      
      for(black = piece.begin() ; black != piece.end() ; black++) {
	if(black->second != NULL && !(black->second)->get_colour()) {
	  
	  if((black->second)->get_type() != "King") {
	    
	    if(black->first != all->first) {
	      
	      if((black->second)->complete_move(black->first, all->first, piece)) {
		return false;
	      }
	    }
	  }
	}
      }
    }


    //checking that whatever move the black king does put him in chess
    for(black_2 = piece.begin() ; black_2 != piece.end() ; black_2++) {
      if(black_2->second != NULL && !(black_2->second)->get_colour()) {
	
	for(all_2 = piece.begin() ; all_2 != piece.end() ; all_2++) {
	  
	  if((black_2->second)->complete_move(black_2->first, all_2->first, piece)) {
	    
	    for(white = piece.begin() ; white != piece.end() ; white++) {
	      if(white->second != NULL && (white->second)->get_colour())  {
		
		if((white->second)->complete_move(white->first, all_2->first, piece)) {
		  break;
		}
	      }
	    }
	  }
	}
	if(all_2 == piece.end())
	  return true;
      }
    }
 
    return false; 
  }
   
  
  //checking that the only valid move is from the white king
  if(!piece[destination_square]->get_colour()) {
    
    for(all = piece.begin() ; all != piece.end() ; all++) {
      for(white = piece.begin() ; white != piece.end() ; white++) {
	
	if(white->second != NULL && (white->second)->get_colour()) {
	  if((white->second)->get_type() != "King") {
	    
	    if(white->first != all->first) {
	      if((white->second)->complete_move(white->first, all->first, piece)) {

		return false;
	      }
	    }
	  }
	}
      }
    }


      //checking that whatever move the white king does put him in chess
    for(white_2 = piece.begin() ; white_2 != piece.end() ; white_2++) {
      if(white_2->second != NULL && (white_2->second)->get_colour()) {
	
	for(all_2 = piece.begin() ; all_2 != piece.end() ; all_2++) {
	  
	  if((white_2->second)->complete_move(white_2->first, all_2->first, piece)) {
	    
	    for(black = piece.begin() ; black != piece.end() ; black++) {
	      if(black->second != NULL && !(black->second)->get_colour())  {
		
		if((black->second)->complete_move(black->first, all_2->first, piece)) {
		  break;
		}
	      }
	    }
	  }
	}
	if(all_2 == piece.end())
	  return true;
      }
    }
 
    return false; 
  }
  return false; 
  
}

		  

		  

		 
	 
