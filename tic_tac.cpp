#include<iostream>
using namespace std;
void display_board(char board[][3]){
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            cout<<board[i][j];
            if(j<2)cout<<" | ";

        }
         cout<<endl;               
        if(i<2)
         cout<<"----------";
         cout<<endl;
        
    }    
}
int move(char board[][3]){
    int move;
    cout<<"enter the move"<<endl;
    cin>>move;
    move--;
    int i =move/3;
    int j =move%3;
    if(board[i][j]!=' '){
        cout<<"try again this box is already filled"<<endl;
        return -1;       
    }
    else {  
        return move;
    }

}
bool check_winner(char board[][3],char symbol){
    for(int i =0;i<3;i++){
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
        return true;
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        return true;        
    }
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    return true;

    if(board[2][0] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    return true;

    return false;
    


}

int main(){
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    display_board(board);
    char symbol = '0';
    string player ="player1";
    while(true){
        int box=move(board);
        if(box==-1)continue;
        int i =box/3;
        int j = box%3;
        board[i][j]=symbol;
        display_board(board);
        bool full = true;
        for(int i =0;i<3;i++){
            for(int j =0;j<3;j++){
                if(board[i][j]==' '){
                    full =false;
                    break;
                }
            }
            if(!full)break;
        }
        if(full){
            cout<<"draw well played guys"<<endl;
            break;
        }
       bool win= check_winner(board,symbol);
       if(win){
        cout<<"Yay! "<<player<<" Has won the game"<<endl;
        break; 
       }
       player=(player=="player1")?player="player2":player="player1";
       symbol=(symbol=='0')?symbol='X':symbol='0';



    }

    return 0;


}