//
//  GameBoard.hpp
//

#pragma once

#include <stdexcept>

#include "ExtendableVector.h"

const int OUTSIDE_BOARD = -1;
const int BOARD_SIZE = 101;

class GameBoard {
public:   
   enum Ladders { ONE = 1, FOUR = 4, NINE = 9, TWENTY_ONE = 21, TWENTY_EIGHT = 28, THIRTY_SIX = 36, FIFTY_ONE = 51, SEVENTY_ONE = 71, EIGHTY = 80 };
   
   enum Chutes { SIXTEEN = 16, FORTY_SEVEN = 47, FORTY_NINE = 49, FIFTY_SIX = 56, SIXTY_TWO = 62, SIXTY_FOUR = 64, EIGHTY_SEVEN = 87, NINETY_THREE = 93, NINETY_FIVE = 95, NINETY_EIGHT = 98 };
   
   // Build the gameboard
   // TO DO: implement this function
   void buildBoard();
   
   GameBoard() {
       buildBoard(); //build the game board during constructor. 
   }
   
   // If player lands on chutes or ladders, returns the new position.
   // Otherwise, returns the player's current position.
   // If the player's position is outside of the gameboard, throws index out of bounds exception
   // TO DO: implement this function properly
   int checkChutesLadders(int position) {
      if ((position < 0) || (position > BOARD_SIZE)) {
          throw out_of_range("Index out of bounds");
      }
       if (position == ONE || FOUR || NINE || TWENTY_ONE || TWENTY_EIGHT || THIRTY_SIX || FIFTY_ONE || SEVENTY_ONE || EIGHTY) {
           return gameBoard.at(position);
       } else if (position == SIXTEEN || FORTY_SEVEN || FORTY_NINE || FIFTY_SIX || SIXTY_TWO || EIGHTY_SEVEN || NINETY_THREE || NINETY_FIVE || NINETY_EIGHT) {
           return gameBoard.at(position);
       }
      return gameBoard.at(position);
   }
   
private:
   // TO DO: add storage for squares including square of chutes and ladders
   // Requirement: use ExtendableVector to store the square
   ExtendableVector<int> gameBoard;
};