#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int gameEnds(int matrix[][3]){
    for(int i = 0; i < 3; i++){
        //check one row at a time
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != 0){
                return matrix[i][0];
        }
        //check one column at a time
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != 0){
            return matrix[0][i];
        }
        //left diagonal
    }
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != 0){
            return matrix[1][1];
    }
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != 0){
        return matrix[1][1];
    }
    //checking for space in the precense of 0 in the matrix
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matrix[i][j] == 0){
                return 0; //game is still going on, so game continues
            }
        }
    }
    //there is no clear winner or looser
    return -1;

}

int checkAvailableSpot(int matrix[][3], int row, int column, int turn){
    while(matrix[row][column] > 0){
        cout << (matrix[row][column] > 3? "row and column out of range": "spot is taken") << endl << "row: "; cin >> row; cout << "column: "; cin >> column;
        row--; column--;
    }
    if(turn%2 == 0){
        cout << "Player 1" << endl;
        matrix[row][column] = 1; //player one
    }else{
        cout << "Player 2" << endl;
        matrix[row][column] = 2; //player two
    }
    return matrix[row][column];
}

void updateBoard(int matrix[][3], string placeholder[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            placeholder[i][j] = "   ";
        }
    }
    for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(matrix[i][j] == 1){
                    placeholder[i][j] = " X ";
                    cout << placeholder[i][j];
                }else if(matrix[i][j] == 2){
                    placeholder[i][j] = " O ";
                    cout << placeholder[i][j];
                }else{
                    cout << placeholder[i][j];
                }
            }
            cout << endl;
    }
}

int main(){
    int board[][3] = {{0,0,0},{0,0,0},{0,0,0}}, row, column;
    int k = 0; // marker
    string placeholder[][3] = {{},{},{}};

    while(gameEnds(board) == 0){
        cout << "row: "; cin >> row; cout << "column: "; cin >> column;
        checkAvailableSpot(board, row-1, column-1, k);
        k++;
        updateBoard(board, placeholder);
    }
    switch(gameEnds(board)){
        case 1:
            cout << "Player 1 wins" << endl;
            break;
        case 2:
            cout << "Player 2 wins" << endl;
            break;
        default:
            cout << "Tie/Draw" << endl;
            break;
    }

    return 0;
}
