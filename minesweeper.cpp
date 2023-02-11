#include <iostream>
#include <vector>
#include <random>
using namespace std;

int width = 10;
int height = 10;
int bomb_rate = 10; // 1 in bomb_rate cells will be a bomb
int num_dug = 0;
int mum_bombs = 0;
vector<vector<int> > board (width, vector<int> (height, 0));
vector<vector<int> > cover (width, vector<int> (height, 0));
void printBoard(bool isCover);
bool isValid(int i, int j);
void fill();
void unleashTheGates(int i, int j);
void dig(int i, int j);

int main(int argc, char* argv[]){
    //Creates the initial board with bombs
    srand((unsigned) time(NULL));
    int random;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            random = rand()%bomb_rate;
            if(random == 1){
                board[i][j] = -10;
                mum_bombs++;
            }
        }
    }
    //now to fill in the adjacencies
    fill();
    //now to print the board
    //now to play the game
    int i, j;
    while(true){
        cout << "Enter the row and column you want to dig: ";
        cin >> i >> j;
        cout << i << " " << j << endl;
        dig(i, j);
        if(num_dug == width*height - mum_bombs){
            cout << "You win!" << endl;
            exit(0);
        }
        printBoard(true);
    }
    return 0;

}

void printBoard(bool isCover){
    if(isCover == false){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                if(board[i][j] >= 0){
                    cout << board[i][j] << " ";
                }else{
                    cout << "* ";
                }
            }
            cout << endl;
        }
    }else{
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                if(cover[i][j] == 1){
                    cout << board[i][j] << " ";
                }else{
                    cout << "* ";                    
                }
            }
            cout << endl;
        }
    }
}

bool isValid(int i, int j){
    if(i < 0 || j < 0 || j >=width || i >=height){
        return false;
    }
    return true;
}

void fill(){
    for(int i = 0;i < height; i++){
        for(int j =0; j < width; j++){
            if(board[i][j] < 0){
                if(isValid(i-1, j-1)){
                    board[i-1][j-1]++;
                }if(isValid(i-1, j)){
                    board[i-1][j]++;
                }if(isValid(i-1, j+1)){
                    board[i-1][j+1]++;
                }if(isValid(i, j-1)){
                    board[i][j-1]++;
                }if(isValid(i, j+1)){
                    board[i][j+1]++;
                }if(isValid(i+1, j-1)){
                    board[i+1][j-1]++;
                }if(isValid(i+1, j)){
                    board[i+1][j]++;
                }if(isValid(i+1, j+1)){
                    board[i+1][j+1]++;
                }
            }
        }
    }
}

void dig(int i, int j){
    //if the cell is a bomb, game over
    if(isValid(i, j) == true){
        if(cover[i][j] == 1){
            cout << "You already dug this cell" << endl;
            return;
        }
        if(board[i][j] < 0){
            cout << "Game Over" << endl;
            exit(0);
        }
        //if the cell is not a bomb, dig it
        if(board[i][j] >= 0){
            cover[i][j] = 1;
            num_dug++;
        }
        //if the cell is a 0, dig all adjacent cells
        if(board[i][j] == 0){
            if(isValid(i-1, j)){
                if(cover[i-1][j] == 0){
                    dig(i-1, j);
                }
            }
            if(isValid(i-1, j-1)){
                if(cover[i-1][j-1] == 0){
                    dig(i-1, j-1);
                }
            }
            if(isValid(i-1, j+1)){
                if(cover[i-1][j+1] == 0){
                    dig(i-1, j+1);
                }
            }
            if(isValid(i+1, j)){
                if(cover[i+1][j] == 0){
                    dig(i+1, j);
                }
            }
            if(isValid(i+1, j-1)){
                if(cover[i+1][j-1] == 0){
                    dig(i+1, j-1);
                }
            }
            if(isValid(i+1, j+1)){
                if(cover[i+1][j+1] == 0){
                    dig(i+1, j+1);
                }
            }
            if(isValid(i, j-1)){
                if(cover[i][j-1] == 0){
                    dig(i, j-1);
                }
            }
            if(isValid(i, j+1)){
                if(cover[i][j+1] == 0){
                    dig(i, j+1);
                }
            }
        }
    }else{
        cout << "Invalid input" << endl;
    }
}