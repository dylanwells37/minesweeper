#include <iostream>
#include <vector>
#include <random>
using namespace std;

int width = 10;
int height = 10;
int bomb_rate = 10; // 1 in bomb_rate cells will be a bomb
vector<vector<int> > board (width, vector<int> (height, 0));
void printBoard();
bool isValid();
void fill();

int main(int argc, char* argv[]){
    //Creates the initial board with bombs
    srand((unsigned) time(NULL));
    int random;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            random = rand()%5;
            if(random == 1){
                board[i][j] = -10;
            }
        }
    }
    //now to fill in the adjacencies
    fill();
    printBoard();
    

}

void printBoard(){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
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

