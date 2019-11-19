#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char playerOneShipMapE[5][5];
char playerOneShipMapM[6][6];
char playerOneShipMapH[7][7];

char playerTwoShipMapE[5][5];
char playerTwoShipMapM[6][6];
char playerTwoShipMapH[7][7];


int x;
char y;
int yInt;

string p1Name;
string p2Name;

/* Buggy output:

OOOOO
OOXOO
XOOOO
XOOOO
XOOXO

*****
*BBBB
S****
S**D*
S**D*

*/

int p1Hits = 0;
int p2Hits = 0;

bool gameRunning = true;

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


void CharsToNums(char a){
	    switch(a){
		case 'a':
			yInt = 0;
			break;
		case 'b':
			yInt = 1;
			break;
		case 'c':
			yInt = 2;
			break;
		case 'd':
			yInt = 3;
			break;
		case 'e':
			yInt = 4;
			break;
		case 'f':
			yInt = 5;
			break;
		case 'g':
			yInt = 6;
			break;
		default:
			yInt = 7;
			break;
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
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapE[i][j] = easyMap1[i][j];
       //cout << playerOneShipMapE[i][j];
   }
   //cout << endl;
}
break;
case 2:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapE[i][j] = easyMap2[i][j];
       //cout << playerOneShipMapE[i][j];
   }
   //cout << endl;
}
break;
case 3:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapE[i][j] = easyMap3[i][j];
       //cout << playerOneShipMapE[i][j];
   }
   //cout << endl;
}
break;
case 4:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapE[i][j] = easyMap4[i][j];
       //cout << playerOneShipMapE[i][j];
   }
   //cout << endl;
}
break;
default:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapE[i][j] = easyMap1[i][j];
       //cout << playerOneShipMapE[i][j];
   }
   //cout << endl;
}
break;
}
switch(mapP2){
case 1:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapE[i][j] = easyMap1[i][j];
       //cout << playerTwoShipMapE[i][j];
   }
   //cout << endl;
}
break;
case 2:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapE[i][j] = easyMap2[i][j];
       //cout << playerTwoShipMapE[i][j];
   }
   //cout << endl;
}
break;
case 3:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapE[i][j] = easyMap3[i][j];
       //cout << playerTwoShipMapE[i][j];
   }
   //cout << endl;
}
break;
case 4:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapE[i][j] = easyMap4[i][j];
       //cout << playerTwoShipMapE[i][j];
   }
   //cout << endl;
}
break;
default:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapE[i][j] = easyMap1[i][j];
       //cout << playerTwoShipMapE[i][j];
   }
   //cout << endl;
}
break;
}
}
if(mode == "medium"){
int mapP1 = (rand() % 4) + 1;
int mapP2 = (rand() % 4) + 1;
switch(mapP1){
case 1:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapM[i][j] = mediumMap1[i][j];
   }
}
break;
case 2:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapM[i][j] = mediumMap2[i][j];
   }
}
break;
case 3:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapM[i][j] = mediumMap3[i][j];
   }
}
break;
case 4:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapM[i][j] = mediumMap4[i][j];
   }
}
break;
default:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapM[i][j] = mediumMap1[i][j];
   }
}
break;
}
switch(mapP2){
case 1:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapM[i][j] = mediumMap1[i][j];
   }
}
break;
case 2:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapM[i][j] = mediumMap2[i][j];
   }
}
break;
case 3:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapM[i][j] = mediumMap3[i][j];
   }
}
break;
case 4:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapM[i][j] = mediumMap4[i][j];
   }
}
break;
default:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapM[i][j] = mediumMap1[i][j];
   }
}
break;
}
}
if(mode == "hard"){
int mapP1 = (rand() % 4) + 1;
int mapP2 = (rand() % 4) + 1;
switch(mapP1){
case 1:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapH[i][j] = hardMap1[i][j];
   }
}
break;
case 2:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapH[i][j] = hardMap2[i][j];
   }
}
break;
case 3:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapH[i][j] = hardMap3[i][j];
   }
}
break;
case 4:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapH[i][j] = hardMap4[i][j];
   }
}
break;
default:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerOneShipMapH[i][j] = hardMap1[i][j];
   }
}
break;
}
switch(mapP2){
case 1:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapH[i][j] = hardMap1[i][j];
   }
}
break;
case 2:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapH[i][j] = hardMap2[i][j];
   }
}
break;
case 3:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapH[i][j] = hardMap3[i][j];
   }
}
break;
case 4:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapH[i][j] = hardMap4[i][j];
   }
}
break;
default:
for (int i = 0; i < 5; i++) {
   for (int j = 0; j < 5; j++) {
       playerTwoShipMapH[i][j] = hardMap1[i][j];
   }
}
break;
}
}
}


void GameOverCheck() {
	if(p1Hits == 9){
		cout << p1Name << " wins!" << endl;
		playerTwoDead = true;
	}
	if(p2Hits == 9){
		cout << p2Name << " wins!" << endl;
		playerOneDead = true;
	}
}

void shipAttackP1() {
   
   if(mode == "easy"){
   cout << p2Name << "'s board:" << endl;
   cout << " abcde" << endl;
   for(int r = 0; r < 5; r++){
	cout << r;
	for(int c = 0; c < 5; c++){
	   cout << easyDisplayMapP2[r][c];
	}
	cout << endl;
   }
   cout << p1Name << ", pick coordinates to attack" << endl;
		/*for (int i = 0; i < 5; i++) {
		   for (int j = 0; j < 5; j++) {
		       cout << playerTwoShipMapE[i][j];
		   }
		   cout << endl;
		}*/
            cin >> x >> y;
	    CharsToNums(y);
            if(!(x > 4) && !(yInt > 4) && !(x < 0) && !(yInt < 0)){
                if (playerTwoShipMapE[x][yInt] == 'D' || playerTwoShipMapE[x][yInt] == 'B' || playerTwoShipMapE[x][yInt] == 'S') {
                    cout << "Hit" << endl;
		    p1Hits++;
                    playerTwoShipMapE[x][yInt] = 'X';
           	    easyDisplayMapP2[x][yInt] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMapE[x][yInt] = 'O';
                    easyDisplayMapP2[x][yInt] = 'O';
                }
            }
    }

if(mode == "medium"){
   cout << p2Name << "'s board:" << endl;
   cout << " abcdef" << endl;
   for(int r = 0; r < 6; r++){
	cout << r;
    for(int c = 0; c < 6; c++){
    cout << mediumDisplayMapP2[r][c];
    }
    cout << endl;
   }
   cout << p1Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
	    CharsToNums(y);
            if(!(x > 5) && !(yInt > 5) && !(x < 0) && !(yInt < 0)){
                if (playerTwoShipMapM[x][yInt] == 'D' || playerTwoShipMapM[x][yInt] == 'B' || playerTwoShipMapM[x][yInt] == 'S') {
                    cout << "Hit" << endl;
		    p1Hits++;
                    playerTwoShipMapM[x][yInt] = 'X';
                    mediumDisplayMapP2[x][yInt] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMapM[x][yInt] = 'O';
           	    mediumDisplayMapP2[x][yInt] = 'O';
                }
            }
    }

if(mode == "hard"){
  cout << p2Name << "'s board:" << endl;
cout << " abcdefg" << endl;
  for(int r = 0; r < 7; r++){
	cout << r;
for(int c = 0; c < 7; c++){
cout << hardDisplayMapP2[r][c];
}
cout << endl;
}
    cout << p1Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
	    CharsToNums(y);
            if(!(x > 6) && !(yInt > 6) && !(x < 0) && !(yInt < 0)){
                if (playerTwoShipMapH[x][yInt] == 'D' || playerTwoShipMapH[x][yInt] == 'B' || playerTwoShipMapH[x][yInt] == 'S') {
                    cout << "Hit" << endl;
		    p1Hits++;
                    playerTwoShipMapH[x][yInt] = 'X';
     		    hardDisplayMapP2[x][yInt] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMapH[x][yInt] = 'O';
   		    hardDisplayMapP2[x][yInt] = 'O';
                }
            }
    }
}

void shipAttackP2() {
   if(mode == "easy"){
   cout << p1Name << "'s board:" << endl;
   cout << " abcde" << endl;
   for(int r = 0; r < 5; r++){
	cout << r;
	for(int c = 0; c < 5; c++){
		cout << easyDisplayMapP1[r][c];
	}
	cout << endl;
   }
   cout << p2Name << ", pick coordinates to attack" << endl;
		/*for (int i = 0; i < 5; i++) {
		   for (int j = 0; j < 5; j++) {
		       cout << playerOneShipMapE[i][j];
		   }
		   cout << endl;
		}*/
            cin >> x >> y;
	    CharsToNums(y);
            if(!(x > 4) && !(yInt > 4) && !(x < 0) && !(yInt < 0)){
                if (playerOneShipMapE[x][yInt] == 'D' || playerOneShipMapE[x][yInt] == 'B' || playerOneShipMapE[x][yInt] == 'S') {
                    cout << "Hit" << endl;
		    p2Hits++;
                    playerOneShipMapE[x][yInt] = 'X';
   		    easyDisplayMapP1[x][yInt] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMapE[x][yInt] = 'O';
   		    easyDisplayMapP1[x][yInt] = 'O';
                }
            }
    }

if(mode == "medium"){
   cout << p1Name << "'s board:" << endl;
cout << " abcdef" << endl;
   for(int r = 0; r < 6; r++){
	cout << r;
	for(int c = 0; c < 6; c++){
		cout << mediumDisplayMapP1[r][c];
	}
	cout << endl;
   }
   cout << p2Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
	    CharsToNums(y);
            if(!(x > 5) && !(yInt > 5) && !(x < 0) && !(yInt < 0)){
                if (playerOneShipMapM[x][yInt] == 'D' || playerOneShipMapM[x][yInt] == 'B' || playerOneShipMapM[x][yInt] == 'S') {
                    cout << "Hit" << endl;
		    p2Hits++;
                    playerOneShipMapM[x][yInt] = 'X';
   		    mediumDisplayMapP1[x][yInt] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMapM[x][yInt] = 'O';
   		    mediumDisplayMapP1[x][yInt] = 'O';
                }
            }
    }

if(mode == "hard"){
   cout << p1Name << "'s board:" << endl;
cout << " abcdefg" << endl;
   for(int r = 0; r < 7; r++){
	cout << r;
for(int c = 0; c < 7; c++){
cout << hardDisplayMapP1[r][c];
}
cout << endl;
   }
   cout << p2Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
	    CharsToNums(y);
            if(!(x > 6) && !(yInt > 6) && !(x < 0) && !(yInt < 0)){
                if (playerOneShipMapH[x][yInt] == 'D' || playerOneShipMapH[x][yInt] == 'B' || playerOneShipMapH[x][yInt] == 'S') {
                    cout << "Hit" << endl;
		    p2Hits++;
                    playerOneShipMapH[x][yInt] = 'X';
   		    hardDisplayMapP1[x][yInt] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMapH[x][yInt] = 'O';
   		    hardDisplayMapP1[x][yInt] = 'O';
                }
            }
    }
}

int main() {
	srand(time(0));
	cout << "Enter P1 Name" << endl;
	cin >> p1Name;
	cout << "Enter P2 Name" << endl;
	cin >> p2Name;
	selectMode();
	while(gameRunning){
		shipAttackP1();
		GameOverCheck();
		if(playerTwoDead == true){
			gameRunning = false;
			return 0;
		}
		shipAttackP2();
		GameOverCheck();
		if(playerOneDead == true){
			gameRunning = false;
			return 0;
		}
	}
	return 0;
}
