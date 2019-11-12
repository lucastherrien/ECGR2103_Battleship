#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

char playerOneShipMap[7][7];

char playerTwoShipMap[7][7];

int x;
int y;


char easyDisplayMapP1[5][5] = {
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'}
};

char easyDisplayMapP2[5][5] = {
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*'}
};

char mediumDisplayMapP1[6][6] = {
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'}
};

char mediumDisplayMapP2[6][6] = {
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'}
};

char hardDisplayMapP1[7][7] = {
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'}
};

char hardDisplayMapP2[7][7] = {
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'}
};

string mode;

bool playerOneDead = false;
bool playerTwoDead = false;

char easyMap1[5][5] = {
	{'*', '*', '*', '*', '*'},
	{'*', 'B', 'B', 'B', 'B'},
	{'S', '*', '*', '*', '*'},
	{'S', '*', '*', 'D', '*'},
	{'S', '*', '*', 'D', '*'}
};

char easyMap2[5][5] = {
	{'D', 'D', '*', '*', '*'},
	{'*', '*', '*', '*', 'B'},
	{'*', 'S', 'S', 'S', 'B'},
	{'*', '*', '*', '*', 'B'},
	{'*', '*', '*', '*', 'B'}
};

char easyMap3[5][5] = {
	{'*', 'B', 'B', 'B', 'B'},
	{'*', '*', '*', '*', 'S'},
	{'*', '*', 'D', 'D', 'S'},
	{'*', '*', '*', '*', 'S'},
	{'*', '*', '*', '*', '*'}
};

char easyMap4[5][5] = {
	{'S', '*', '*', '*', '*'},
	{'S', '*', '*', 'B', '*'},
	{'S', '*', '*', 'B', '*'},
	{'*', '*', '*', 'B', '*'},
	{'*', 'D', 'D', 'B', '*'}
};

char mediumMap1[6][6] = {
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', 'S', 'S','*'},
	{'*', 'B', '*', '*', '*','*'},
	{'*', 'B', '*', '*', '*','*'},
	{'*', 'B', '*', '*', '*','*'},
	{'*', 'B', '*', 'D', 'D','D'}
};
char mediumMap2[6][6] = {
	{'*', '*', '*', '*', 'D','D'},
	{'*', '*', '*', '*', '*','*'},
	{'*', 'B', 'B', 'B', 'B','*'},
	{'S', '*', '*', '*', '*','*'},
	{'S', '*', '*', '*', '*','*'},
	{'S', '*', '*', '*', '*','*'}
};
char mediumMap3[6][6] = {
	{'*', '*', '*', '*', '*','*'},
	{'*', '*', '*', '*', '*','*'},
	{'B', 'B', 'B', 'B', '*','*'},
	{'*', 'S', '*', '*', '*','*'},
	{'*', 'S', '*', '*', '*','D'},
	{'*', 'S', '*', '*', '*','D'}
};
char mediumMap4[6][6] = {
	{'*', '*', 'B', '*', '*','*'},
	{'*', '*', 'B', '*', '*','*'},
	{'*', '*', 'B', '*', '*','*'},
	{'S', '*', 'B', '*', '*','*'},
	{'S', '*', '*', '*', '*','*'},
	{'*', '*', '*', 'S', 'S','S'}
};

char hardMap1[7][7] = {
	{'*', 'S', '*', '*', '*', '*', '*'},
	{'*', 'S', '*', '*', '*', '*', '*'},
	{'*', 'S', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', 'B'},
	{'*', '*', '*', '*', '*', '*', 'B'},
	{'*', '*', 'D', 'D', '*', '*', 'B'},
	{'*', '*', '*', '*', '*', '*', 'B'}
};

char hardMap2[7][7] = {
	{'*', 'D', '*', '*', '*', '*', '*'},
	{'*', 'D', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', 'S', 'S', 'S'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', 'B', 'B', 'B', 'B', '*', '*'}
};

char hardMap3[7][7] = {
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', 'S', '*', '*', '*', 'D'},
	{'*', '*', 'S', '*', '*', '*', 'D'},
	{'*', '*', 'S', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', 'B', 'B', 'B', 'B', '*', '*'}
};

char hardMap4[7][7] = {
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*'},
	{'*', '*', '*', 'B', '*', '*', '*'},
	{'*', '*', '*', 'B', '*', '*', '*'},
	{'*', '*', '*', 'B', '*', '*', 'S'},
	{'D', '*', '*', 'B', '*', '*', 'S'},
	{'D', '*', '*', '*', '*', '*', 'S'}
};

void main() {
	srand(22);
	selectMode();
	bool gameRunning = true;
	while(gameRunning){
		if(playerOneDead || playerTwoDead){
			gameRunning = false;
		}
		shipAttackP1();
		shipAttackP2();
		GameOverCheck();
	}
}

void selectMode() {
	cout << "select a game mode (easy, medium or hard)" << endl;
	cin >> mode;
	if(mode == "easy"){
		int mapP1 = (rand() % 4) + 1;
		int mapP2 = (rand() % 4) + 1;
		switch(mapP1){
			case 1:
				playerOneShipMap = easyMap1;
				break;
			case 2:
				playerOneShipMap = easyMap2;
				break;
			case 3:
				playerOneShipMap = easyMap3;
				break;
			case 4:
				playerOneShipMap = easyMap4;
				break;
			default:
				playerOneShipMap = easyMap1;
				break;
		}
		switch(mapP2){
			case 1:
				playerTwoShipMap = easyMap1;
				break;
			case 2:
				playerTwoShipMap = easyMap2;
				break;
			case 3:
				playerTwoShipMap = easyMap3;
				break;
			case 4:
				playerTwoShipMap = easyMap4;
				break;
			default:
				playerTwoShipMap = easyMap1;
				break;
		}
	}
	if(mode == "medium"){
		int mapP1 = (rand() % 4) + 1;
		int mapP2 = (rand() % 4) + 1;
		switch(mapP1){
			case 1:
				playerOneShipMap = mediumMap1;
				break;
			case 2:
				playerOneShipMap = mediumMap2;
				break;
			case 3:
				playerOneShipMap = mediumMap3;
				break;
			case 4:
				playerOneShipMap = mediumMap4;
				break;
			default:
				playerOneShipMap = mediumMap1;
				break;
		}
		switch(mapP2){
			case 1:
				playerTwoShipMap = mediumMap1;
				break;
			case 2:
				playerTwoShipMap = mediumMap2;
				break;
			case 3:
				playerTwoShipMap = mediumMap3;
				break;
			case 4:
				playerTwoShipMap = mediumMap4;
				break;
			default:
				playerTwoShipMap = mediumMap1;
				break;
		}
	}
	if(mode == "hard"){
		int mapP1 = (rand() % 4) + 1;
		int mapP2 = (rand() % 4) + 1;
		switch(mapP1){
			case 1:
				playerOneShipMap = hardMap1;
				break;
			case 2:
				playerOneShipMap = hardMap2;
				break;
			case 3:
				playerOneShipMap = hardMap3;
				break;
			case 4:
				playerOneShipMap = hardMap4;
				break;
			default:
				playerOneShipMap = hardMap1;
				break;
		}
		switch(mapP2){
			case 1:
				playerTwoShipMap = hardMap1;
				break;
			case 2:
				playerTwoShipMap = hardMap2;
				break;
			case 3:
				playerTwoShipMap = hardMap3;
				break;
			case 4:
				playerTwoShipMap = hardMap4;
				break;
			default:
				playerTwoShipMap = hardMap1;
				break;
		}
	}
}


void GameOverCheck(int x, int y) {
    bool gameRunning = true;
    int i;
    int j;
    playerOneDead = true;
    playerTwoDead = true;
    if (mode == "easy") {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (playerOneShipMap[x][y] == 'D' || playerOneShipMap[x][y] == 'S' || playerOneShipMap == 'B') {
                    playerOneDead = false;
                }
            }
        }
	for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (playerTwoShipMap[x][y] == 'D' || playerTwoShipMap[x][y] == 'S' || playerTwoShipMap == 'B') {
                    playerTwoDead = false;
                }
            }
        }
    }

    if (mode == "medium") {
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                if (playerOneShipMap[x][y] == 'D' || playerOneShipMap[x][y] == 'S' || playerOneShipMap == 'B') {
                    playerOneDead = false;
                }
            }
        }
	for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                if (playerTwoShipMap[x][y] == 'D' || playerTwoShipMap[x][y] == 'S' || playerTwoShipMap == 'B') {
                    playerTwoDead = false;
                }
            }
        }
    }

    if (mode == "hard") {
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                if (playerOneShipMap[x][y] == 'D' || playerOneShipMap[x][y] == 'S' || playerOneShipMap == 'B') {
                    playerOneDead = false;
                }
            }
        }
	for (i = 0; i < 5; i++) {
            for (j = 0; j < 7; j++) {
                if (playerTwoShipMap[x][y] == 'D' || playerTwoShipMap[x][y] == 'S' || playerTwoShipMap == 'B') {
                    playerTwoDead = false;
                }
            }
        }
    }
}

void shipAttackP1() {
   
   if(mode == "easy"){
   cout << "Player 2:" << endl;
   for(int r = 0; r < 5; r++){
	for(int c = 0; c < 5; c++){
	    cout << easyDisplayMapP2[r][c];
	}
   	cout << endl;
   }
   cout << "Player 1, pick coordinates to attack" << endl
            cin >> x >> y;
            if(!(x > 4) && !(y > 4) && !(x < 0) && !(y < 0)){
                if (playerOneShipMap[x][y] == 'D' || playerOneShipMap[x][y] == 'B' || playerOneShipMap[x][y] == 'S') {
                    cout << "Hit" << endl;
                    playerTwoShipMap[x][y] = 'X';
       		    easyDisplayMapP2[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMap[x][y] = 'O';
       		    easyDisplayMapP2[x][y] = 'O';
                }
            }
    }

if(mode == "medium"){
   cout << "Player 2:" << endl;
   for(int r = 0; r < 6; r++){
    for(int c = 0; c < 6; c++){
    cout << mediumDisplayMapP2[r][c];
    }
    cout << endl;
   }
   cout << "Player 1, pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 5) && !(y > 5) && !(x < 0) && !(y < 0)){
                if (playerTwoShipMap[x][y] == 'D' || playerTwoShipMap[x][y] == 'B' || playerTwoShipMap[x][y] == 'S') {
                    cout << "Hit" << endl;
                    playerTwoShipMap[x][y] = 'X';
                    mediumDisplayMapP2[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMapMap[x][y] = 'O';
		    mediumDisplayMapP2[x][y] = 'O';
                }
            }
    }

	if(mode == "hard"){
	   cout << "Player 2:" << endl;
	   for(int r = 0; r < 7; r++){
		for(int c = 0; c < 7; c++){
			cout << hardDisplayMapP2[r][c];
		}
		cout << endl;
	}
   	cout << "Player 1, pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 6) && !(y > 6) && !(x < 0) && !(y < 0)){
                if (playerTwoShipMap[x][y] == 'D' || playerTwoShipMap[x][y] == 'B' || playerTwoShipMap[x][y] == 'S') {
                    cout << "Hit" << endl;
                    playerTwoShipMap[x][y] = 'X';
	   	    hardDisplayMapP2[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMap[x][y] = 'O';
		    hardDisplayMapP2[x][y] = 'O';
                }
            }
    }
}

void shipAttackP2() {
       if(mode == "easy"){
	    cout << "Player 1:" << endl;
	    for(int r = 0; r < 5; r++){
		for(int c = 0; c < 5; c++){
			cout << easyDisplayMapP1[r][c];
		}
		cout << endl;
	    }
	    cout << "Player 2, pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 4) && !(y > 4) && !(x < 0) && !(y < 0)){
                if (playerOneShipMap[x][y] == 'D' || playerOneShipMap[x][y] == 'B' || playerOneShipMap[x][y] == 'S') {
                    cout << "Hit" << endl;
                    playerOneShipMap[x][y] = 'X';
		    easyDisplayMapP1[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMap[x][y] = 'O';
		    easyDisplayMapP1[x][y] = 'O';
                }
            }
    	}

	if(mode == "medium"){
	    cout << "Player 1:" << endl;
	    for(int r = 0; r < 6; r++){
		for(int c = 0; c < 6; c++){
			cout << mediumDisplayMapP1[r][c];
		}
		cout << endl;
	    }
	    cout << "Player 2, pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 5) && !(y > 5) && !(x < 0) && !(y < 0)){
                if (playerOneShipMap[x][y] == 'D' || playerOneShipMap[x][y] == 'B' || playerOneShipMap[x][y] == 'S') {
                    cout << "Hit" << endl;
                    playerOneShipMap[x][y] = 'X';
		    mediumDisplayMapP1[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMap[x][y] = 'O';
		    mediumDisplayMapP1[x][y] = 'O';
                }
            }
    	}

	if(mode == "hard"){
	    cout << "Player 1:" << endl;
	    for(int r = 0; r < 5; r++){
		for(int c = 0; c < 5; c++){
			cout << easyDisplayMapP1[r][c];
		}
		cout << endl;
	    }
	    cout << "Player 2, pick coordinates to attack" << endl
            cin >> x >> y;
            if(!(x > 6) && !(y > 6) && !(x < 0) && !(y < 0)){
                if (playerOneShipMap[x][y] == 'D' || playerOneShipMap[x][y] == 'B' || playerOneShipMap[x][y] == 'S') {
                    cout << "Hit" << endl;
                    playerOneShipMap[x][y] = 'X';
		    hardDisplayMapP1[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMap[x][y] = 'O';
		    hardDisplayMapP1[x][y] = 'O';
                }
            }
    	}
}

