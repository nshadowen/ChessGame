/*Written by: Nicole Shadowen
* Spring 2016
*/


/* Example for a chessboard: pair (column , row) each from 0-7
 * col and row are records of struct position
 * struct move is a struct containing structs
 * You can do assignments and pass a struct to a function (pass by value or by reference)
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
/*
1)piece of type position
2)scanf to get in the "from" and "to" values for piece
3)functions to "check legal moves" use move struct to establish whether it's a legal move or not, then operate, else give error statement 
 
to check for move:
•check that it's the person's piece - piecesArray[t].name[0] = b or w
•check that destination square does not have Player's piece
•check that no pieces (other than knight) are in the squares leading up to spot you want to move to check piecesArray[t].position.row, piecesArray[t].position.col, 
 
to remove one of the pieces from our array = pieceArray[t--] (from class on 3/24 used in array in heap so idk if will work normal talk)
 
 
REMAINING on 3/29/16
• graveyard for "taken" pieces
• checking legality
*/
 
 
typedef struct position {
    int col, row;
} Position;
 
typedef struct move {
    Position from ;
    Position to;
}Move;
 
typedef struct piece
{
    char name[2];
    Position position;
}Piece;
 
void printMove(Move move); // function declaration, code below
 
//Piece bRook, Piece bKnight, Piece bBishop, Piece bQueen, Piece bKing, Piece bBishop2, Piece bKnight2, Piece bRook2, Piece bPawn, Piece bPawn2, Piece bPawn3, Piece bPawn4, Piece bPawn5, Piece bPawn6, Piece bPawn7, Piece bPawn8, Piece wRook, Piece wKnight, Piece wBishop, Piece wQueen, Piece wKing, Piece wBishop2, Piece wKnight2, Piece wRook2, Piece wPawn, Piece wPawn2, Piece wPawn3, Piece wPawn4, Piece wPawn5, Piece wPawn6, Piece wPawn7, Piece wPawn8
 
int printBoard(Piece piecesArray[32], Move move)
{    
    char BoardArray[10][10][3] = {'\0'};
    int i = 0;
    int j;
    int t=0;
     
    /*for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            BoardArray[i][j][0] = '\0';
        }
    }
    */
     
    for(t=0;t<32;t++)
    {
        BoardArray[piecesArray[t].position.row][piecesArray[t].position.col][0] = piecesArray[t].name[0];
        BoardArray[piecesArray[t].position.row][piecesArray[t].position.col][1] = piecesArray[t].name[1];
        BoardArray[piecesArray[t].position.row][piecesArray[t].position.col][2] = piecesArray[t].name[2];
    }        
    for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++){
           
          {
                if((j==0 || j == 9)&&(i>0 && i<9))
                  { 
                      printf("  %i  ", 9-i);                     
                  }               
                  else if((i == 0 || i == 9)&&(j>0 && j<9))
                  {
                      printf("  %c  ", 'a'+ (j-1));
                  } 
                  else if(BoardArray[i][j][0] != '\0')
                  {
                      printf(" %c%c%c ", BoardArray[i][j][0], BoardArray[i][j][1], BoardArray[i][j][2]);                    
                  } 
                  else if(BoardArray[i][j][0] == '\0')
                  {
                      printf("  -  ");                       
                  }           
          }         
      }
           
        printf("\n");
    } 
}
 
 
 
Move getMove(Move move, int x)
{
      
     char *moveFrom; //string input piece initial position
     char *moveTo; //string input piece move position
     moveFrom = malloc(sizeof *moveFrom);
     moveTo = malloc(sizeof *moveTo);
     
    if((x%2) == 0)
    {
       printf("\nIt is White's turn, choose a piece using starting location by letter followed by a number and hit enter: \nChoose x to give up:\n");
       scanf("%s", moveFrom); 
       if(moveFrom[0] == 'x')
       {
           move.from.col = 0;
           move.from.row = 0;
           move.to.col = 0;
           move.to.row = 0; 
           return move;          
       }
       printf("choose target location by letter followed by a number:\nChoose x to give up:\n");
       scanf("%s", moveTo);
       if(moveFrom[0] == 'x')
       {
           move.from.col = 0;
           move.from.row = 0;
           move.to.col = 0;
           move.to.row = 0; 
           return move;          
       }
    }
    else
    {
       printf("\nIt is Black's turn, choose a piece using starting location by letter followed by a number and hit enter: \nChoose x to give up:\n");
       scanf("%s", moveFrom);
       if(moveFrom[0] == 'x')
       {
           move.from.col = 0;
           move.from.row = 0;
           move.to.col = 0;
           move.to.row = 0; 
           return move;          
       }
       printf("choose target location by letter followed by a number:\nChoose x to give up:\n");
       scanf("%s", moveTo);  
       if(moveFrom[0] == 'x')
       {
           move.from.col = 0;
           move.from.row = 0;
           move.to.col = 0;
           move.to.row = 0; 
           return move;          
       }
    }
     
    Position from, to; // declare two variables of our type Position
    from.col = (int)moveFrom[0]-96;
    from.row = 9-((int)moveFrom[1] - 48);
    to.col = (int)moveTo[0]-96;
    to.row = 9-((int)moveTo[1]-48);
    move.from = from;
    move.to = to; 
 
    if(move.from.row<9 && move.from.col<9 && move.to.row<9 && move.to.col<9)
    {
        return move;       
    }
    else
    {
        printf("This is an invalid move. Please re-enter.\n");
        getMove(move,x);
    }            
}
 
int checkValid(Piece piecesArray[32], Move move, int x, int t)
{
     
    if((x%2)== 0 && piecesArray[t].name[0] == 'w' )
    {
         return 1;
    }
    else if((x%2)==1 && piecesArray[t].name[0] == 'b')
    {
        return 1;
    }
    /*for(int s = 0;s<32;s++)
    {
        printf("This is working.\n");
      if(piecesArray[s].position.col == move.to.col && piecesArray[s].position.row == move.to.row)
        {
            if((x%2) == 0 && piecesArray[s].name[0]=='w')
            {
                printf("That's your own piece. Please pick again.\n");
                printBoard(piecesArray, move); 
            }
            
        }
        else if(piecesArray[s].position.col == move.to.col && piecesArray[s].position.row == move.to.row && piecesArray[s].name[0] == 'b' && (x%2)==1)
        {
            if((x%2)==1&& piecesArray[s].name[0] == 'b')
            {
                printf("That's your own piece. Please pick again.\n");
                printBoard(piecesArray, move);
            }            
        }  
    }*/
         
}
 
/*void movePiece(Piece bRook, Piece bKnight, Piece bBishop, Piece bQueen, Piece bKing, Piece bBishop2, Piece bKnight2, Piece bRook2, Piece bPawn, Piece bPawn2, Piece bPawn3, Piece bPawn4, Piece bPawn5, Piece bPawn6, Piece bPawn7, Piece bPawn8, Piece wRook, Piece wKnight, Piece wBishop, Piece wQueen, Piece wKing, Piece wBishop2, Piece wKnight2, Piece wRook2, Piece wPawn, Piece wPawn2, Piece wPawn3, Piece wPawn4, Piece wPawn5, Piece wPawn6, Piece wPawn7, Piece wPawn8, Move move)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(j == move.from.col && i == move.from.row)
            {
                printf("The piece you're looking for is: %s\n", bRook.name);
            }
            else
            printf("this didn't work.\n");
        }
    }    
    
}
*/
 
int takePiece(Piece piecesArray[32], Move move, int x, int t)
{
    int s;
    int v = 1;
    for(s = 0;s<32;s++)
    {
        if(move.to.col == piecesArray[s].position.col && move.to.row == piecesArray[s].position.row)
        {
           if((x%2)==0 && piecesArray[s].name[0] == 'b')
           {   
                   piecesArray[s].position.col = 0;
                   piecesArray[s].position.row = 0;               
                   v = 1;               
           }
           else if((x%2)==0 && piecesArray[s].name[0] == 'w')
           {
               //printf("You can't take your own piece. Please try again.\n\n");
               v = 0;
           }
           else if((x%2)==1 && piecesArray[s].name[0] == 'w')
           {
               if(piecesArray[t].name[2] == 'P' && move.to.col - move.from.col ==1 && move.to.row - move.from.row == 0)
               {
                   v = 0;
               }
               else
               {
                   piecesArray[s].position.col = 0;
                   piecesArray[s].position.row = 0;               
                   v = 1;  
               }  
           }
           else if((x%2)==1 && piecesArray[s].name[0] == 'b')
           {
               //printf("You can't take your own piece. Please try again.\n\n");
               v = 0;
           }
        }
    }
    return v;
}
 
/*
int checkPath(Piece piecesArray[32], Move move, int t, int x)
{
    int P;
    int s;
    for(s=0;s<32; s++)
    {        
        if(move.to.col == piecesArray[s].position.col && move.to.row == piecesArray[s].position.row)
        {
             if(piecesArray[t].name[0] == 'w')
             {
                if(piecesArray[t].name[2] == 'R')
                {
                    P=0;
                }
                if(piecesArray[t].name[2] == 'N')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'B')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'Q')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'K')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'P')
                {
                    if(move.from.row - move.to.row ==1 && move.from.col - move.to.col == 0) //return 0 if there is a piece in the path of a pawn moving one forward (can't take, can't move) = not going to give the right error message
                    {
                        if(piecesArray[s].name[0] == 'b' || piecesArray[s].name[0] == 'w')
                        {
                           P = 0; 
                        }
                        P = 1;                      
                    }
                    if(move.from.col - move.to.col == 2 && move.from.row - )
                      
                }                
            }
            if(piecesArray[t].name[0] == 'b')
            {
                if(piecesArray[t].name[2] == 'R')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'N')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'B')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'Q')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'K')
                {
                    P = 0;
                }
                if(piecesArray[t].name[2] == 'P')
                {
                    P = 0;
                }                
            }   
        }
         
    }
}
*/
 
int legalMove(Piece piecesArray[32], Move move, int t)
{
    int s;
    int L=1;
     
    if(piecesArray[t].name[0] == 'w')
    {
        if(piecesArray[t].name[2] == 'R')
            L = 0;  
        else if(piecesArray[t].name[2] == 'N')
        {
           if(abs(move.to.col - move.from.col)!=2 && abs(move.to.row - move.from.row) != 1 || abs(move.to.col-move.from.col)!=1 && abs(move.to.row-move.from.row)!=2) 
               L = 0;
        }
        else if(piecesArray[t].name[2] == 'B')
            L = 0;  
        else if(piecesArray[t].name[2] == 'Q')
            L = 0;  
        else if(piecesArray[t].name[2] == 'K')
            L =0; 
        else if(piecesArray[t].name[2] == 'P')
        {
            if(move.from.row == 7)
            {
                if(move.from.row - move.to.row == 2 && move.from.col - move.to.col == 0)
                {
                    int s;
                    for(s = 0;s<32;s++)
                    {
                        if((move.to.row == piecesArray[s].position.row && move.to.col == piecesArray[s].position.col) || move.from.row-1 == piecesArray[s].position.row && move.to.col == piecesArray[s].position.col)
                        {
                            if(piecesArray[s].name[0] == 'b' || piecesArray[s].name[0] == 'w')
                                 L = 0;                               
                        }                        
                    }
                }
                else if(move.from.row - move.to.row ==1 && move.from.col - move.to.col == 0)
                {
                    int s;
                    for(s = 0;s<32;s++)
                    {
                      if(move.to.row == piecesArray[s].position.row && move.to.col == piecesArray[s].position.col)
                        {
                            if(piecesArray[s].name[0] == 'b' || piecesArray[s].name[0]=='w')
                                L = 0;
                        } 
                    }                                           
                }
                else if(move.from.col - move.to.col == 1 && move.from.row - move.to.row == 1)
                {
                    int s;
                    for(s = 0;s<32;s++)
                    {
                        if(move.to.row == piecesArray[s].position.row && move.to.col == piecesArray[s].position.col)
                        {
                            if(piecesArray[s].name[0] != 'b')
                                L = 0;
                        }
                    }
                }
            }
            else if(move.from.row !=7)
            {
                if(move.from.row - move.to.row ==1 && move.from.col - move.to.col == 0)
                {
                    int s;
                    for(s = 0;s<32;s++)
                    {
                      if(move.to.row == piecesArray[s].position.row && move.to.col == piecesArray[s].position.col)
                        {
                            if(piecesArray[s].name[0] == 'b' || piecesArray[s].name[0]=='w')
                                L = 0;
                        }                        
                    }
                }
                else if(move.from.col - move.to.col == 1 && move.from.row - move.to.row == 1)
                {
                    int s;
                    for(s = 0;s<32;s++)
                    {
                        if(move.to.row == piecesArray[s].position.row && move.to.col == piecesArray[s].position.col)
                        {
                            if(piecesArray[s].name[0] != 'b')
                                L = 0;
                        }
                    }
                }
            }              
        }
    }
    else if(piecesArray[t].name[0] == 'b')
    {
        if(piecesArray[t].name[2] == 'R')
        {
           L = 0; 
        }
        else if(piecesArray[t].name[2] == 'N')
        {
           if(abs(move.to.col - move.from.col)!=2 && abs(move.to.row - move.from.row) != 1 || abs(move.to.col-move.from.col)!=1 && abs(move.to.row-move.from.row)!=2) 
           {
               L = 1;
           } 
        }
        else if(piecesArray[t].name[2] == 'B')
        {
            L = 0;
        }
        else if(piecesArray[t].name[2] == 'Q')
        {
            L =0;
        }
        else if(piecesArray[t].name[2] == 'K')
        {
            L = 0;
        }
        else if(piecesArray[t].name[2] == 'P')
        {
            L = 0;
        }
    }
    return L; 
}
 
int main ()
{ 
    //char BoardArray[10][10][3];
    int i = 0;
    int j;
    int t=0;
    int x = 0;
    int game = 1;
    int z = 0;
    int d = 0;
     
    Piece bRook, bKnight, bBishop, bQueen, bKing, bBishop2, bKnight2, bRook2, bPawn, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8;
    Piece wRook, wKnight, wBishop, wQueen, wKing, wBishop2, wKnight2, wRook2, wPawn, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8;
     
    
    strcpy(bRook.name,"b-R"); 
    strcpy(bRook2.name,"b-R");
    strcpy(bKnight.name,"b-N"); 
    strcpy(bKnight2.name,"b-N");
    strcpy(bBishop.name,"b-B"); 
    strcpy(bBishop2.name,"b-B");
    strcpy(bQueen.name, "b-Q"); 
    strcpy(bKing.name, "b-K");
    strcpy(bPawn.name,"b-P"); strcpy(bPawn2.name,"b-P"); strcpy(bPawn3.name,"b-P"); strcpy(bPawn4.name,"b-P"); 
    strcpy(bPawn5.name,"b-P"); strcpy(bPawn6.name,"b-P"); strcpy(bPawn7.name,"b-P"); strcpy(bPawn8.name,"b-P");
     
    strcpy(wRook.name,"w-R"); strcpy(wRook2.name,"w-R");
    strcpy(wKnight.name,"w-N"); strcpy(wKnight2.name,"w-N");
    strcpy(wBishop.name,"w-B"); strcpy(wBishop2.name,"w-B");
    strcpy(wQueen.name, "w-Q"); strcpy(wKing.name, "w-K");
    strcpy(wPawn.name,"w-P"); strcpy(wPawn2.name,"w-P"); strcpy(wPawn3.name,"w-P"); strcpy(wPawn4.name,"w-P");
    strcpy(wPawn5.name,"w-P"); strcpy(wPawn6.name,"w-P"); strcpy(wPawn7.name,"w-P"); strcpy(wPawn8.name,"w-P");
     
     
    bRook.position.col = wRook.position.col = 1;
    bKnight.position.col = wKnight.position.col = 2;
    bBishop.position.col = wBishop.position.col = 3;
    bQueen.position.col = wQueen.position.col = 4;
    bKing.position.col = wKing.position.col = 5;
    bBishop2.position.col = wBishop2.position.col = 6;
    bKnight2.position.col = wKnight2.position.col = 7;
    bRook2.position.col = wRook2.position.col = 8;   
    bPawn.position.col = wPawn.position.col = 1;
    bPawn2.position.col = wPawn2.position.col = 2;
    bPawn3.position.col = wPawn3.position.col = 3;
    bPawn4.position.col = wPawn4.position.col = 4;
    bPawn5.position.col = wPawn5.position.col = 5;
    bPawn6.position.col = wPawn6.position.col = 6;
    bPawn7.position.col = wPawn7.position.col = 7;
    bPawn8.position.col = wPawn8.position.col = 8;
     
    bRook.position.row = bKnight.position.row = bBishop.position.row = bQueen.position.row = bKing.position.row = bBishop2.position.row = bKnight2.position.row = bRook2.position.row = 8;
    bPawn.position.row = bPawn2.position.row = bPawn3.position.row = bPawn4.position.row = bPawn5.position.row = bPawn6.position.row = bPawn7.position.row = bPawn8.position.row = 7;
    wRook.position.row = wKnight.position.row = wBishop.position.row = wQueen.position.row = wKing.position.row = wBishop2.position.row = wKnight2.position.row = wRook2.position.row = 1;
    wPawn.position.row = wPawn2.position.row = wPawn3.position.row = wPawn4.position.row = wPawn5.position.row = wPawn6.position.row = wPawn7.position.row = wPawn8.position.row = 2; 
 
     
    Position from, to; // declare two variables of our type Position
     
    Piece piecesArray[32] =  {bRook, bKnight, bBishop, bQueen, bKing, bBishop2, bKnight2, bRook2, bPawn, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8, wRook, wKnight, wBishop, wQueen, wKing, wBishop2, wKnight2, wRook2, wPawn, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8};
    Move move;
    printBoard(piecesArray, move);
     
    
     
    while(game)
    {
        int L;
        int c = 0;
        int y;
        int e = 0;
        y = x;       
        move = getMove(move, x);                    
        int t;               
        for(t=0;t<32;t++)
        {                       
            if(move.from.col == piecesArray[t].position.col && move.from.row == piecesArray[t].position.row)
            {
                if(checkValid(piecesArray, move, x, t) ==1)
                {
                    if(legalMove(piecesArray, move, t)==1)
                    {
                        if(takePiece(piecesArray, move, x, t)==1)
                        {                           
                            piecesArray[t].position.col = move.to.col;
                            piecesArray[t].position.row = move.to.row; 
                            printBoard(piecesArray, move);
                            x++;   
                        }
                        else 
                            d = 2; //variable to indicate validity
                    }
                    else
                        e = 2; //variable to indicate legality
                }
                else
                {
                    c = 2; //variable to indicate there is a piece at the location, but it is not the player's piece
                }                    
            } 
            else if (move.from.col == 0 && move.from.row == 0 && move.to.col == 0 && move.to.row ==0)
            {
            game = 0;
            }
        }  
        if(y == x)
        {
            if(c == 2)
            {
                printf("\nThat's not your piece. Please try again.\n\n");
                printBoard(piecesArray, move);
            }
            else if(d==2)
            {
                printf("\nThat's your own piece. Please try again.\n\n");
                printBoard(piecesArray, move);
            }
            else if(e ==2)
            {
                 printf("\nNot a valid move. Please try again.\n\n");
                 printBoard(piecesArray, move);
            }
            else if (c!=2 && d!=2 && e!=2)
            {
                printf("\nThere is no piece at that location. Please try again.\n\n");
                printBoard(piecesArray, move);
            }
                 
                 
        }
         
    }             
    if((x%2)== 0)
    {
        printf("White lost. Game over.\n");
         
    }
    if((x%2)==1)
    {
        printf("Black lost. Game over.\n");
    }
     
           
    return 0;
}
 
// function to print the move:
void printMove(Move move)
{
    printf("Move from %c%d to %c%d\n", 'a' + move.from.col + 1, // if the line is too long, can continue on the next
           move.from.row + 1, 'a' + move.to.col + 1, move.to.row + 1);
}
