#ifndef FUNCS_H
#define FUNCS_H
/*global constants for rows , columns and time in seconds */
const int rows=8;
const int cols=8;
/*Allows delayance for two seconds*/
const int delay=5;
/* Holds player data/information*/
//#include<iostream>
using namespace std;
struct Info{
string name;
int pieces_won;
int number;
};
/* Prints and initializes the Checker board*/
void printBoard(char board[][cols], Info player1 , Info player2);
/*Time function for delaying the game or pausing*/
void wait(int number_of_seconds);
/*Checks if the player swaps between the right box*/
void swap_piece( char board [][cols] ,int j, int k, int l ,int m);
/*Checks if move is valid*/
bool move_is_valid(char board[][cols],int player,int j, int k, int l, int m);
/*Checks if theres is a jump over and player can win piece*/
bool player_can_win_piece(char board[][cols],int j, int k, int l, int m);
/*Wins piece if player can win piece*/
int win_piece(char board[][cols],int current_player,int player, int &pieceswon, int j, int k, int l, int m);
/*Checks if an opposite piece is on last row*/
void king_me(char board[][cols], int player,int l, int m);
/*Checks if selected piece is king*/
bool isKing(char board[][cols],int player, int j, int k);
/*Checks for the King's movement*/
bool allow_king(char board[][cols],int player,int j ,int k,int l, int m);
/*Wins piece for king*/
int win_for_king(char board[][cols], int player,int pieceswon,int j,int k,int l, int m);
/*Checks if game is over or still running*/
bool game_over(Info player1, Info player2);
#endif // FUNCS_H
