//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// TODO: implement the constructor with all your team members
// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
   // TODO: implement this function properly
    Player brandon;
    brandon.setName("player1");
    Player imaginaryFriend; //this is sad :(
    imaginaryFriend.setName("player2");
    
    queue.enqueue(brandon);
    queue.enqueue(imaginaryFriend);
   }

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   // TODO: implement this function properly
    queue.dequeue();
    queue.dequeue();
}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
    
    Player player1 = queue.front(); //get player1
    queue.dequeue(); //remove from queue
    Player player2 = queue.front(); //get player 2
    queue.dequeue(); //remove from queue
    
    player1.setPostion(0); //reset to start
    queue.enqueue(player1); //add back to the queue
    player2.setPostion(0); //reset to start
    queue.enqueue(player2); //add back to the queue
    
    winner = "no winner";
}

// TO DO: implement this function properly
// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
    while(winner != "player1" && winner != "player2") {
        Player player1 = queue.front(); //get player1
        queue.dequeue(); //remove from queue
        player1.setPostion(player1.rollDieAndMove());
        player1.setPostion(gameBoard.checkChutesLadders(player1.getPostion()));
        if (player1.getPostion() == 100) {
            winner = player1.getName();
        }
        queue.enqueue(player1);
        
        Player player2 = queue.front(); //get player 2
        queue.dequeue(); //remove from queue
        player2.setPostion(player2.rollDieAndMove());
        player2.setPostion(gameBoard.checkChutesLadders(player2.getPostion()));
        if (player2.getPostion() == 100) {
            winner = player2.getName();
        }
        queue.enqueue(player2);
    }
    cout << "Winner!: " << winner << endl;
}
