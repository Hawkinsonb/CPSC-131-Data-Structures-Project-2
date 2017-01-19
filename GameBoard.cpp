//
//  GameBoard.cpp
//
#include <iostream>
#include "GameBoard.hpp"

// Build the gameboard
// If the landing square is a chute, set the position to the corresponding lower square
// I.e., player slides down to the lower square
// If the landing square is a ladder, set the position to the corresponding higher square
// Player climbs up to the higher square
// Otherwise, player stays put at the landing square
// TO DO: implement this method
void GameBoard::buildBoard() {
    int ladders[9] {1, 4, 9, 21, 28, 36, 51, 71, 80};
    int chutes[10] {16, 47, 49, 56, 62, 64, 87, 93, 95, 98};
    for (int i=0; i < BOARD_SIZE; i++) {
        gameBoard.insert(i, i);
        for (int n=0; n < 9; n++) {
            if (i == ladders[n]) {
                switch(ladders[n]) {
                    case 1: {gameBoard.insert(i, 38); break;}
                    case 4: {gameBoard.insert(i, 14); break;}
                    case 9: {gameBoard.insert(i, 31); break;}
                    case 21: {gameBoard.insert(i, 42); break;}
                    case 28: {gameBoard.insert(i, 84); break;}
                    case 36: {gameBoard.insert(i, 44); break;}
                    case 51: {gameBoard.insert(i, 67); break;}
                    case 71: {gameBoard.insert(i, 91); break;}
                    case 80: {gameBoard.insert(i, 100); break;}
                }
                break;
            }
        }
        for (int n=0; n < 10; n++) {
            if (i == chutes[n]) {
                switch(chutes[n]){
                    case 16: {gameBoard.insert(i, 6); break;}
                    case 47: {gameBoard.insert(i, 26); break;}
                    case 49: {gameBoard.insert(i, 11); break;}
                    case 56: {gameBoard.insert(i, 53); break;}
                    case 62: {gameBoard.insert(i, 19); break;}
                    case 64: {gameBoard.insert(i, 60); break;}
                    case 87: {gameBoard.insert(i, 24); break;}
                    case 93: {gameBoard.insert(i, 73); break;}
                    case 95: {gameBoard.insert(i, 75); break;}
                    case 98: {gameBoard.insert(i, 78); break;}
                }
            }
        }
    }
}