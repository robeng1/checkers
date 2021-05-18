/*DEBUG THE MOVE_IS_VALID FUNCTION
IT IS TOO FLEXIBLE*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Funcs.h"
void printRules(ifstream& current_file);
using namespace std;
int main()
{
     int  mode;
     int i,j,k,l,m;
     string temp;
     ifstream infile;
     infile.open("rules.txt");


     char  board[rows][cols]={
       {' ','w',' ','w',' ','w',' ','w'},
       {'w',' ','w',' ','w',' ','w',' '},
       {' ','w',' ','w',' ','w',' ','w'},
       {' ',' ',' ',' ',' ',' ',' ',' '},
       {' ',' ',' ',' ',' ',' ',' ',' '},
       {'r',' ','r',' ','r',' ','r',' '},
       {' ','r',' ','r',' ','r',' ','r'},
       {'r',' ','r',' ','r',' ','r',' '},
       };

    Info player1, player2;/*declaration of objects of type info*/
    /*initializes the number of pieces won and assigns 1 and 2 to player one and two respectively*/
    player1.pieces_won=0;
    player2.pieces_won=0;
    player1.number=1;
    player2.number=2;

   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t............................................................................." << endl;
   cout << endl;
   cout << endl;
   cout<<setw(45) << "\t\t\t\t\t\t\t\t  CONSOLE VERSION OF CHECKERS GAME" << endl;
   cout << endl;
   cout<<"\t\t\t\t\t............................................................................." << endl;
   wait(delay);
   system("cls");
   /*loop executes while proper mode is not selected*/
   do{
   cout << "\n\t\t\t\t\t\tWELCOME TO THE CONSOLE VERSION OF THE CHECKERS GAME" << endl;
   cout << "\n\n\t\t\t\t\t\t\t\tENTER PLAYER MODE" << endl;
   cout << endl;
   cout << "\t\t\tSINGLE PLAYER MODE NOT YET ACTIVE"<< endl;
   cout << "\t\t\tENTER 1 FOR SINGLE PLAYER:"<<endl;
   cout << endl;
   cout << "\t\t\tENTER 2 FOR TWO PLAYERS:"<<endl;
   cout << endl;
   cout <<"\t\t\tMODE:";
   cin >> mode;
   if(!(mode==1 || mode==2)){
        cout << endl;
    cout << "\t\t\t\t\t\t\t\tSELECTED MODE MUST BE 1 OR 2!";
    cout << endl;
    wait(delay);
    system("cls");
   }
   }while(!(mode==1 || mode==2));
    cout << endl;
    cout << endl;
    wait(delay);
    system("cls");
   cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
   cout <<"PLAYER 1 NAME : ";
   cin >> player1.name;
   //converts the player's  name to upper case
    for(i=0;i<player1.name.length();i++){
        temp+=toupper(player1.name[i]);
   }
   player1.name=temp;

   if(mode==2){

       cout<<"\n\n\t\t\t\t\t\t\t\tPLAYER 2 NAME : ";
       cin>>player2.name;
       temp="";//empty the temporary string
           for(i=0;i<player2.name.length();i++){
              temp+=toupper(player2.name[i]);
   }
        player2.name=temp;
   }
   else
   {
       player2.name="COMPUTER";
   }
   system("clear");
    printRules(infile);
    wait(delay);
    system("clear");
    /*prints board to start the game */
   printBoard(board, player1, player2);
   /*loop executes so long as game is not over*/
   do{
        /*loop continues to execute until valid move is made by player1*/
        do{
    cout <<"\t\t\t\t\t\t\t  "<< player1.name << "'S TURN " << endl;
    cout << "\t\t\t\t\t\t\t  MOVE PIECE FROM" << endl;
    cout << "\t\t\t\t\t\t\t  ROW:";
    cin >> j;
    cout << "\t\t\t\t\t\t\t  COLUMN:";
    cin >> k;
    cout << "\t\t\t\t\t\t\t  TO " << endl;
    cout << "\t\t\t\t\t\t\t  ROW:";
    cin >> l;
    cout << "\t\t\t\t\t\t\t  COLUMN:";
    cin >> m;
    cout << endl;
    if(isKing(board,player1.number,j,k)){
      allow_king(board,player1.number,j,k,l,m);
        win_for_king(board,player1.number,player1.pieces_won,j,k,l,m);

          swap_piece(board,j,k,l,m);
    }

    else if(move_is_valid(board,player1.number,j,k,l,m)){
            if(player_can_win_piece(board,j,k, l,m)){
                  win_piece(board,player1.number,player1.number, player1.pieces_won, j,k,l,m);
                }
                 swap_piece(board,j,k,l,m );
                 king_me(board,player1.number,l,m);

    }


    else{
        cout << "\t\t\t\t\t\t\t\tINVALID MOVE OR PIECE SELCETION,TRY AGAIN!";
    }
    wait(delay);
    system("cls");
    printBoard(board ,player1,player2);/*prints board after swapping for player 2*/

    }while(!(move_is_valid(board,player1.number,j,k,l,m))||(isKing(board,player1.number,j,k)));
    /*loop continue to execute until valid move is made by player 2*/

    do
    {

    cout <<"\t\t\t\t\t\t\t  "<< player2.name << "'S TURN" << endl;
    cout <<"\t\t\t\t\t\t\t  MOVE PIECE FROM" << endl;
    cout << "\t\t\t\t\t\t\t  ROW:";
    cin >> j;
    cout << "\t\t\t\t\t\t\t  COLUMN:";
    cin >> k;
    cout << "\t\t\t\t\t\t\t  TO " << endl;
    cout << "\t\t\t\t\t\t\t  ROW:";
    cin >> l;
    cout << "\t\t\t\t\t\t\t  COLUMN:";
    cin >> m;
    if(isKing(board,player2.number,j,k)){
       allow_king(board,player2.number,j,k,l,m);
        win_for_king(board,player2.number,player2.pieces_won,j,k,l,m);
        swap_piece(board,j,k,l,m);
    }

    else if(move_is_valid(board,player2.number,j,k,l,m)){
                if(player_can_win_piece(board,j,k, l,m)){
                    win_piece(board,player2.number,player2.number, player2.pieces_won, j,k,l,m);
                }
                swap_piece(board,j,k,l,m );
                king_me(board,player2.number,l,m);
              }
    else{
        cout << "\t\t\t\t\t\t\t\tINVALID MOVE OR PIECE SELCETION,TRY AGAIN!" << endl;
    }
    wait(delay);
    system("cls");
    printBoard(board ,player1,player2);/*prints board again after swapping for player 1*/

    }while(!(move_is_valid(board,player2.number,j,k,l,m))||(isKing(board,player2.number,j,k)));

   }while(!(game_over(player1,player2)));

return 0;
}
/*prints the rules from the file rules.txt*/
void printRules(ifstream& current_file){

  string current_line;
  char ch;

   system("cls");
   getline(current_file,current_line);
   current_file.get(ch);
   while(!current_file.eof()){
   cout<<current_line;
   cout<<endl<<endl<<endl;
   getline(current_file, current_line);
   current_file.get(ch);
  }
}


