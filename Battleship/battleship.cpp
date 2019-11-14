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
   cout << "abcde" << endl;
   for(int r = 0; r < 5; r++){
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
            if(!(x > 4) && !(y > 'e') && !(x < 0) && !(y < 'a')){
                if (playerTwoShipMapE[x][y] == 'D' || playerTwoShipMapE[x][y] == 'B' || playerTwoShipMapE[x][y] == 'S') {
                    cout << "Hit" << endl;
		    p1Hits++;
                    playerTwoShipMapE[x][y] = 'X';
           	    easyDisplayMapP2[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMapE[x][y] = 'O';
                    easyDisplayMapP2[x][y] = 'O';
                }
            }
    }

if(mode == "medium"){
   cout << p2Name << "'s board:" << endl;
   cout << "abcdef" << endl;
   for(int r = 0; r < 6; r++){
    for(int c = 0; c < 6; c++){
    cout << mediumDisplayMapP2[r][c];
    }
    cout << endl;
   }
   cout << p1Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 5) && !(y > 'f') && !(x < 0) && !(y < 'a')){
                if (playerTwoShipMapM[x][y] == 'D' || playerTwoShipMapM[x][y] == 'B' || playerTwoShipMapM[x][y] == 'S') {
                    cout << "Hit" << endl;
		    p1Hits++;
                    playerTwoShipMapM[x][y] = 'X';
                    mediumDisplayMapP2[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMapM[x][y] = 'O';
           	    mediumDisplayMapP2[x][y] = 'O';
                }
            }
    }

if(mode == "hard"){
  cout << p2Name << "'s board:" << endl;
cout << "abcdefg" << endl;
  for(int r = 0; r < 7; r++){
for(int c = 0; c < 7; c++){
cout << hardDisplayMapP2[r][c];
}
cout << endl;
}
    cout << p1Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 6) && !(y > 'g') && !(x < 0) && !(y < 'a')){
                if (playerTwoShipMapH[x][y] == 'D' || playerTwoShipMapH[x][y] == 'B' || playerTwoShipMapH[x][y] == 'S') {
                    cout << "Hit" << endl;
		    p1Hits++;
                    playerTwoShipMapH[x][y] = 'X';
     		    hardDisplayMapP2[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerTwoShipMapH[x][y] = 'O';
   		    hardDisplayMapP2[x][y] = 'O';
                }
            }
    }
}

void shipAttackP2() {
       if(mode == "easy"){
	cout << "abcde" << endl;
   cout << p1Name << "'s board:" << endl;
   for(int r = 0; r < 5; r++){
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
            if(!(x > 4) && !(y > 'e') && !(x < 0) && !(y < 'a')){
                if (playerOneShipMapE[x][y] == 'D' || playerOneShipMapE[x][y] == 'B' || playerOneShipMapE[x][y] == 'S') {
                    cout << "Hit" << endl;
		    p2Hits++;
                    playerOneShipMapE[x][y] = 'X';
   		    easyDisplayMapP1[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMapE[x][y] = 'O';
   easyDisplayMapP1[x][y] = 'O';
                }
            }
    }

if(mode == "medium"){
   cout << p1Name << "'s board:" << endl;
cout << "abcdef" << endl;
   for(int r = 0; r < 6; r++){
for(int c = 0; c < 6; c++){
cout << mediumDisplayMapP1[r][c];
}
cout << endl;
   }
   cout << p2Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 5) && !(y > 'f') && !(x < 0) && !(y < 'a')){
                if (playerOneShipMapM[x][y] == 'D' || playerOneShipMapM[x][y] == 'B' || playerOneShipMapM[x][y] == 'S') {
                    cout << "Hit" << endl;
		    p2Hits++;
                    playerOneShipMapM[x][y] = 'X';
   		    mediumDisplayMapP1[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMapM[x][y] = 'O';
   		    mediumDisplayMapP1[x][y] = 'O';
                }
            }
    }

if(mode == "hard"){
   cout << p1Name << "'s board:" << endl;
cout << "abcdefg" << endl;
   for(int r = 0; r < 5; r++){
for(int c = 0; c < 5; c++){
cout << easyDisplayMapP1[r][c];
}
cout << endl;
   }
   cout << p2Name << ", pick coordinates to attack" << endl;
            cin >> x >> y;
            if(!(x > 6) && !(y > 'g') && !(x < 0) && !(y < 'a')){
                if (playerOneShipMapH[x][y] == 'D' || playerOneShipMapH[x][y] == 'B' || playerOneShipMapH[x][y] == 'S') {
                    cout << "Hit" << endl;
		    p2Hits++;
                    playerOneShipMapH[x][y] = 'X';
   		    hardDisplayMapP1[x][y] = 'X';
                }
                else {
                    cout << "Miss" << endl;
                    playerOneShipMapH[x][y] = 'O';
   		    hardDisplayMapP1[x][y] = 'O';
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
