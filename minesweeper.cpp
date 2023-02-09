#include <iostream>
#include <vector>
#include <random>
using namespace std;

int width = 10;
int height = 10;
int bomb_percentage = 10;
vector<vector<int> > board (width, vector<int> (height, 0));
void printBoard();

int main(int argc, char* argv[]){
    srand((unsigned) time(NULL));
    int random;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            random = rand()%10;
            if(random == 1){
                board[i][j] = 1;
            }
        }
    }
    
    

}

void printBoard(){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}