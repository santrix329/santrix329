#include <iostream>
using namespace std;

int main() {
    // 0 = blank space, 1 = player 1 move, 2 = player 2 move
    int gameboard[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    string playerName1 = "Luis Mendoza";
    string playerName2 = "Whateveryouwant";
    int play1[2] = {-1,-1}; // -1 the player hasn't input a move
    int play2[2] = {-1,-1};
    int gameover = 1; // when it turns into 0, it's game over
    bool banner = 1; // if True, the play is valid
    int buffer = 0;
    // -------------- PRINTING MENU --------
    cout << "Tic Tac Toe " <<endl;
    cout << "Player 1, whats your name" << endl;
    //getline(cin, playerName1);
    cout << "Player 2, whats your name" << endl;
    //getline(cin, playerName2);
    
    cout << playerName1 << endl;
    cout << playerName2;
    
    // system("cls");
    // --------------------------------------
    
    // ------------- GAME START -------------
    cout << endl << "printing board" << endl;
    
    // -------- Printing Board -----------
    
    do{
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                switch (gameboard[i][j]) {
                    case 0: // blank space 
                        cout << "_";
                        break;
                    case 1: // player 1 move (O)
                        cout << "O";
                        break;
                    case 2: // player 2 move (X)
                        cout << "X";
                        break;
                        
                }
            }
            cout << endl;
        } 
        
        // ------------ PLAYER MOVES -------------
        do{
            cout << "Player 1's turn (O): input the column of your play " << endl;
            cin >> play1[0];
            cout << "Player 1's turn (O): input the row of your play " << endl;
            cin >> play1[1];
            if ((play1[0] < 0 && play1[0] > 3) && (play1[1] < 0 && play1[1] > 3)){
                banner = 0;
            }else{
                banner = 1;
            }
            
        }while( banner  && (gameboard[play1[0]][play1[1]] == 0) );
        
        // writing the move of player 1 on the gameboard
        gameboard[play1[0]][play1[1]] = 1;
        
        
        do{
            cout << "Player 2's turn (X): input the column of your play " << endl;
            cin >> play2[0];
            cout << "Player 2's turn (X): input the row of your play " << endl;
            cin >> play2[1];
            
            if ((play2[0] < 0 && play2[0] > 3) && (play2[1] < 0 && play2[1] > 3)){
                banner = 0;
            }else{
                banner = 1;
            }
        }while( banner && (gameboard[play2[0]][play2[1]] == 0) );
        
        // writing the move of player 2 on the gameboard
        gameboard[play2[0]][play2[1]] = 2; 
        
    }while(gameover == 1);

 
    
    // cin >> buffer;
    return 0;

}