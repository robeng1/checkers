#include <iostream>
#include "Funcs.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>
#include <fstream>

/*Prints the board for the console*/
void printBoard(char board[][cols],Info player1 ,Info player2){
    int i, j;
    cout << endl<< endl<< endl;
    cout << " \t\t\t\t\t\t\t\t   " << player1.name << " VS " << player2.name << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\t"<< player1.name<< endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t    PIECES WON :" << player1.pieces_won<< endl;
    cout << endl<< endl<< endl;
    cout <<"\t\t\t\t\t\t\t   +---+---+---+---+---+---+---+---+" << endl;

    for (i=0; i<8; ++i)
    {
        cout << "\t\t\t\t\t\t\t";
        cout <<" " << i << " |";
        for (j=0; j<8; j++)
        {
            cout<< " " << board[i][j]<< " |" ;
        }

        cout <<endl;
        cout << "\t\t\t\t\t\t\t";
        cout <<"   +---+---+---+---+---+---+---+---+" << endl;
    }
    cout << "\t\t\t\t\t\t\t";
    cout <<"    0    1   2   3   4   5   6   7";
    cout << endl<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t\t\t\t\t"<< player2.name<< endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t    PIECES WON :" << player2.pieces_won<< endl;
    cout << endl;
    }
/*Time function for overall delay of actions*/
void wait(int number_of_seconds){
     bool time_up=false;
     time_t start_time=time(0);
     do{
        time_t finish_time=time(0);
        int time_taken=static_cast<int>(finish_time-start_time);
         if(time_taken==number_of_seconds)
            time_up=true;
     }while(!time_up);
}
/*Swaps piece between chosen boxes by the player*/
void swap_piece(char board [][cols] ,int j, int k, int l ,int m){
    int temp;

    cout<<"\t\t\t\t\t\t\t  SWAPPING FROM:";
    cout << "["<< j << "]"<< "[" << k<< "]";
    cout << "  TO:" ;
    cout << "  ["<< l << "]"<< "[" << m << "]"<<endl;
    temp = board[j][k];
    board[j][k] = board[l][m];
    board[l][m] = temp;

}
/*Checks if movement is valid*/
bool move_is_valid(char board[][cols] ,int player,int j, int k, int l, int m){
bool valid_move=false;
//char temp=' ';
        /*Regular move*/
    if(j - l == -1 || j - l == 1){
        if(k - m == 1 || k - m == -1){
            valid_move=true;
        }
    }

    /* jump move*/
    if(j - l == -2 || j- l == 2){
        if(k - m == -2 || k - m == 2){
             valid_move=true;
        }
        }


 return valid_move;
}
/*Checks to see if player can win piece*/
bool player_can_win_piece(char board[][cols], int j, int k, int l, int m){
  bool can_win=false;
    if(j - l == -2 || j - l ==2 || k-m == 2 || k - m == -2)
        if(board[l][m]==' '){
            can_win=true;
        }
    return can_win;
}
/*Wins piece if player can win piece*/
int win_piece(char board[][cols] ,int current_player,int player,int &pieceswon, int j, int k, int l, int m){
/*if(move_is_valid(board,current_player,j,k,l,m)){*/
    if(player==1 && board[j][k]=='w' && board[l][m]==' '){
        if((l-j<0&&m-k<0) && board[j-1][k-1]=='r'){
                   char temp=' ';
                    board[j-1][k-1]=temp;
                    pieceswon++;

            }
        else if((l-j<0&&m-k>0) && board[j-1][k+1]=='r'){
            char temp=' ';
            board[j-1][k+1]=temp;
            pieceswon++;
        }
        else if((l-j>0&&m-k<0) && board[j+1][k-1]=='r'){
                char temp=' ';
                board[j+1][k-1]=temp;
                pieceswon++;
        }
        else if((l-j>0&&m-k>0) && board[j+1][k+1]=='r'){
            char temp=' ';
            board[j+1][k+1]=temp;
            pieceswon++;
        }
    }

   else{
        if(player==2 && board[j][k]=='r' && board[l][m]==' '){
            if((l-j<0 && m-k < 0 )&& board[j-1][k-1]=='w'){
                    char temp=' ';
                    board[j-1][k-1]=temp;
                    pieceswon++;

            }
        else if((l-j<0 && m-k >0) && board[j-1][k+1]=='w'){
                char temp=' ';
            board[j-1][k+1]=temp;
            pieceswon++;
        }
        else if((l-j>0 && m-k <0)&& board[j+1][k-1]=='w'){
            char temp=' ';
                board[j+1][k-1]=temp;
                pieceswon++;
        }
        else if((l-j >0 && m-k>0) && board[j+1][k+1]=='w'){
            char temp=' ';
            board[j+1][k+1]=temp;
            pieceswon++;
        }
    }


}
return pieceswon;
}

/*This function crowns the player by capitalizing his/her piece when it reaches opposite side*/
void king_me(char board[][cols],int player, int l,int m ){
    char temp=' ';
    if(player==1){
      if(l==7){
            temp=toupper(board[l][m]);
            board[l][m]=temp;

      }
    }
    else if(player==2){
        if(l==0){
            temp=toupper(board[l][m]);
            board[l][m]=temp;
        }
    }

}
/*Checks if selected piece is a king*/
bool isKing(char board[][cols],int player, int j, int k){
bool is_a_king=false;
if (player==1 && board[j][k]=='W'){
     is_a_king=true;
}
else if(player==2 && board[j][k]=='R'){
    is_a_king=true;
}
return is_a_king;
}
/*Checks and allow additional movement privileges to the king*/
bool allow_king(char board[][cols],int player,int j ,int k,int l, int m){
    bool allowKing=false;
    int row,col;
    char temp=' ';
      /*allows long up right movement if piece is a king*/
if(player==1 && l-j<0 && m-k>0 && board[l][m]==temp){
 for(row=j; row >=l; row--){
  for(col=k; col <=m; col++){
    if((board[row][col]==temp||board[row][col]=='r'||board[row][col]=='R')&&(board[row-1][col+1]=temp||board[row-1][col+1]=='r'||board[row-1][col+1]=='R')){
        if((board[row][col]=='r' ||board[row][col]=='R') && board[row-1][col+1]==temp){
            allowKing= true;
        }
        else if((board[row][col]==temp) && (board[row-1][col+1]=='R'|| board[row-1][col+1]=='r')){
            if(board[row-2][col+2]==temp){
                allowKing=true;
            }
        }


    }

            }
        }
      }
else if(player==1 && l-j>0 &&m-k<0 && board[l][m]==temp){
 for(row=j; row <=l; row++){
  for(col=k; col >=m; col--){
    if((board[row][col]==temp||board[row][col]=='r'||board[row][col]=='R')&&(board[row+1][col-1]=temp||board[row+1][col-1]=='r'||board[row+1][col-1]=='R')){

            if((board[row][col]=='r' ||board[row][col]=='R') && board[row+1][col-1]==temp){
            allowKing =true;
        }
        else if((board[row][col]==temp) && (board[row+1][col-1]=='R'|| board[row+1][col-1]=='r')){
            if(board[row+2][col-2]==temp){
                allowKing=true;
            }
        }


        }
    }

            }
        }

else if(player==1 && l-j>0 && m-k>0 && board[l][m]==temp){
 for(row=j; row <=l; row++){
  for(col=k; col <=m; col++){
    if((board[row][col]==temp||board[row][col]=='r'||board[row][col]=='R')&&(board[row+1][col+1]=temp||board[row+1][col+1]=='r'||board[row+1][col+1]=='R')){
        if((board[row][col]=='r' ||board[row][col]=='R') && board[row+1][col+1]==temp){
            allowKing= true;
        }
        else if((board[row][col]==temp)&& (board[row+1][col+1]=='R'|| board[row+1][col+1]=='r')){
            if(board[row+2][col+2]==temp){
                allowKing=true;
            }
        }


    }

            }
        }
      }
else if(player==1 && l-j<0 && m-k<0 && board[l][m]==temp){
 for(row=j; row >=l; row--){
  for(col=k; col >=m; col--){
    if((board[row][col]==temp||board[row][col]=='r'||board[row][col]=='R')&&(board[row-1][col-1]=temp||board[row-1][col-1]=='r'||board[row-1][col-1]=='R')){
        if((board[row][col]=='r' ||board[row][col]=='R') && board[row-1][col-1]==temp){
            allowKing= true;
        }
        else if((board[row][col]==temp) && (board[row-1][col-1]=='R'|| board[row-1][col-1]=='r')){
            if(board[row-2][col-2]==temp){
                allowKing=true;
            }
        }


    }

            }
        }
      }
else if(player==2 && l-j<0 && m-k>0 && board[l][m]==temp){
 for(row=j; row >=l; row--){
  for(col=k; col <=m; col++){
    if((board[row][col]==temp||board[row][col]=='w'||board[row][col]=='W')&&(board[row-1][col+1]=temp||board[row-1][col+1]=='w'||board[row-1][col+1]=='W')){
        if((board[row][col]=='w' ||board[row][col]=='W') && board[row-1][col+1]==temp){
            allowKing =true;
        }
        else if((board[row][col]==temp) && (board[row-1][col+1]=='W'|| board[row-1][col+1]=='w')){
            if(board[row-2][col+2]==temp){
                allowKing=true;
            }
        }


    }

            }
        }
      }
else if(player==2 && l-j>0 &&m-k<0 && board[l][m]==temp){
 for(row=j; row <=l; row++){
  for(col=k; col >=m; col++){
    if((board[row][col]==temp||board[row][col]=='w'||board[row][col]=='W')&&(board[row+1][col-1]=temp||board[row+1][col-1]=='w'||board[row+1][col-1]=='W')){
        if((board[row][col]=='w' ||board[row][col]=='W') && board[row+1][col-1]==temp){
            allowKing =true;
        }
        else if((board[row][col]==temp) && (board[row+1][col-1]=='W'|| board[row+1][col-1]=='w')){
            if(board[row+2][col-2]==temp){
                allowKing=true;
            }
        }
    }

            }
        }
      }
else if(player==2 && l-j>0 && m-k>0 && board[l][m]==temp){
 for(row=j; row <=l; row++){
  for(col=k; col <=m; col++){
    if((board[row][col]==temp||board[row][col]=='w'||board[row][col]=='W')&&(board[row+1][col+1]=temp||board[row+1][col+1]=='w'||board[row+1][col+1]=='W')){
        if((board[row][col]=='w' ||board[row][col]=='W') && board[row+1][col+1]==temp){
            allowKing =true;
        }
        else if((board[row][col]==temp) && (board[row+1][col+1]=='W'|| board[row+1][col+1]=='w')){
            if(board[row+2][col+2]==temp){
                allowKing=true;
            }
        }
    }

            }
        }
      }
else if(player==2 && l-j<0 && m-k<0 && board[l][m]==temp){
 for(row=j; row <=l; row--){
  for(col=k; col >=m; col--){
    if((board[row][col]==temp||board[row][col]=='w'||board[row][col]=='W')&&(board[row-1][col-1]=temp||board[row-1][col-1]=='W'||board[row-1][col-1]=='w')){
        if((board[row][col]=='w' ||board[row][col]=='W') && board[row-1][col-1]==temp){
            allowKing= true;
        }
        else if((board[row][col]==temp) && (board[row-1][col-1]=='W'|| board[row-1][col-1]=='w')){
            if(board[row-2][col-2]==temp){
                allowKing=true;
            }
        }
    }

            }

 }
}
 return allowKing;
}
/*checks the occurrence of other pieces and picks then for the king*/
int win_for_king(char board[][cols],int player,int pieceswon ,int j ,int k,int l, int m){
    int row;
    int col;
    char temp=' ';
    if(player==1 && l-j<0 && m-k>0 && board[l][m]==temp){
            for(row=j; row!=l;row--){
                for(col=k; col!=m; col++){
                    if(board[row][col]=='r'|| board [row][col]=='R'){
                        board[row][col]=temp;
                        pieceswon++;
                    }
                }
            }

    }
else if(player==1 && l-j>0 &&m-k<0 && board[l][m]==temp){
 for(row=j; row !=l; row++){
  for(col=k; col !=m; col--){
      if(board[row][col]=='r' || board[row][col]=='R'){
        board[row][col]=temp;
        pieceswon++;
      }
        }
     }
  }
  else if(player==1 && l-j>0 && m-k>0 && board[l][m]==temp){
 for(row=j; row !=l; row++){
  for(col=k; col !=m; col++){
    if (board[row][col]=='r' || board[row][col]=='R'){
        board[row][col]=temp;
        pieceswon++;
    }
  }
 }
 }
 else if(player==1 && l-j<0 && m-k<0 && board[l][m]==temp){
 for(row=j; row !=l; row--){
  for(col=k; col !=m; col--){
      if(board[row][col]=='r' || board[row][col]=='R'){
        board[row][col]=temp;
        pieceswon++;
      }
  }
  }
 }
 else if(player==2 && l-j<0 && m-k>0 && board[l][m]==temp){
 for(row=j; row !=l; row--){
  for(col=k; col !=m; col++){
    if(board[row][col]=='w' || board[row][col]=='W'){
        board[row][col]=temp;
        pieceswon++;
    }
  }
}
}
else if(player==2 && l-j>0 &&m-k<0 && board[l][m]==temp){
 for(row=j; row !=l; row++){
  for(col=k; col !=m; col--){
        if(board[row][col]=='w'|| board[row][col]=='W'){
            board[row][col]=temp;
            pieceswon++;
        }
  }
 }
}
else if(player==2 && l-j>0 && m-k>0 && board[l][m]==temp){
 for(row=j; row !=l; row++){
  for(col=k; col !=m; col++){
        if(board[row][col]=='w' || board[row][col]=='W'){
            board[row][col]=temp;
            pieceswon++;
        }
  }
 }
}
else if(player==2 && l-j<0 && m-k<0 && board[l][m]==temp){
 for(row=j; row !=l; row--){
  for(col=k; col !=m; col--){
        if(board[row][col]=='w' || board[row][col]=='W'){
            board[row][col]=temp;
            pieceswon++;
        }
  }
 }
}
return pieceswon;
}
/*Checks if game is over , if game is over it returns the number of pieces won by the user*/
bool game_over(Info player1, Info player2){
    bool over=false;
    if(player1.number==1 && player1.pieces_won >=8){
            cout << "\t\t\t\t\t\t\tGAME OVER!" << endl;
            cout <<player1.name << "WON WITH :" << player1.pieces_won << endl;
              return true;

    }
else if(player2.number==2 && player2.pieces_won>=8){
    cout << "\t\t\t\t\t\tGAME OVER!"<< endl;
    cout << player2.name << "WON WITH :" << player2.pieces_won << endl;
     return true;
}
return over;
}
