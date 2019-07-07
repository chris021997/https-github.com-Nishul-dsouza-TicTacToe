#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

// Deletes moves that are already performed
void removemove(int compmoves[], int movenos, int element) {
  int pos;
  for (int j = 0; j < movenos; j++) {
    if (compmoves[j] == element) {
      pos = j + 1;
    }
  }
  if (pos != movenos) {
    for (int i = pos - 1; i < movenos; i++) {
      compmoves[i] = compmoves[i + 1];
    }
  }
}

// The computer selects a random move from the remaining moves
int computermove(int compmoves[], int movenos) {
  srand((unsigned int)(time(NULL)));
  int move = rand() % movenos;
  return compmoves[move];
}

// Checks for winning condition of the rows
bool row(char layout[][4]) {
  for (int i = 1; i < 4; i++) {
    if (layout[i][1] == layout[i][2] && layout[i][2] == layout[i][3] &&
        layout[i][1] != NULL) {
      return true;
    }
  }
  return false;
}

// Checks for winning condition of the columns
bool column(char layout[][4]) {
  for (int i = 1; i < 4; i++) {
    if (layout[1][i] != NULL && layout[1][i] == layout[2][i] &&
        layout[2][i] == layout[3][i]) {
      return true;
    }
  }
  return false;
}

// Checks for winning condition of the diagonal
bool diagonal(char layout[][4]) {
  if (layout[1][1] != NULL && layout[1][1] == layout[2][2] &&
      layout[2][2] == layout[3][3]) {
    return true;
  } else if (layout[1][3] != NULL && layout[1][3] == layout[2][2] &&
             layout[2][2] == layout[3][1]) {
    return true;
  }
  return false;
}

// Checks for all conditions and tells whether any player has won
bool win(char layout[][4]) {
  return (row(layout) || column(layout) || diagonal(layout));
}

// Function to show the board layout
void showlayout(char layout[][4], int temp, int psym, int comp) {
  system("CLS");
  char symp1, symp2;
  if (temp) {
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t The board layout\n";
  }
  if (comp) {
    if (psym == 1) {
      symp1 = 'X';
      symp2 = 'O';
    } else {
      symp1 = 'O';
      symp2 = 'X';
    }
    if (temp) {
      cout << "\n\t\t\t\t\t\t   Player : " << symp1;
      cout << "\n\t\t\t\t\t\t  Computer : " << symp2 << "\n\n";
    } else {
      cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t   Tic-Tac-Toe\n";
      cout << "\n\t\t\t\t\t\t  Player : " << symp1;
      cout << "\n\t\t\t\t\t\t Computer : " << symp2 << "\n\n";
    }
  } else {
    if (psym == 1) {
      symp1 = 'X';
      symp2 = 'O';
    } else {
      symp1 = 'O';
      symp2 = 'X';
    }
    if (temp) {
      cout << "\n\t\t\t\t\t\t  Player 1 : " << symp1;
      cout << "\n\t\t\t\t\t\t  Player 2 : " << symp2 << "\n\n";
    } else {
      cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t   Tic-Tac-Toe\n";
      cout << "\n\t\t\t\t\t\t  Player 1 : " << symp1;
      cout << "\n\t\t\t\t\t\t  Player 2 : " << symp2 << "\n\n";
    }
  }
  cout << "\t\t\t\t\t\t"
       << "     |     |     "
       << "\n";
  cout << "\t\t\t\t\t\t"
       << "  " << layout[1][1] << "  |  " << layout[1][2] << "  |  "
       << layout[1][3] << "\n";
  cout << "\t\t\t\t\t\t"
       << "_____|_____|_____"
       << "\n";
  cout << "\t\t\t\t\t\t"
       << "     |     |     "
       << "\n";
  cout << "\t\t\t\t\t\t"
       << "  " << layout[2][1] << "  |  " << layout[2][2] << "  |  "
       << layout[2][3] << "\n";
  cout << "\t\t\t\t\t\t"
       << "_____|_____|_____"
       << "\n";
  cout << "\t\t\t\t\t\t"
       << "     |     |     "
       << "\n";
  cout << "\t\t\t\t\t\t"
       << "  " << layout[3][1] << "  |  " << layout[3][2] << "  |  "
       << layout[3][3] << "\n";
  cout << "\t\t\t\t\t\t"
       << "     |     |     "
       << "\n"
       << "\n";
  if (temp) {
    cout << "\t\t\t\t\t   The game will begin shortly";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
  }
}

// Function that controls the gameplay
void playgame(char layout[][4], int choice, int psym, int player) {
  system("CLS");
  int input, compmoves[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, moves = 0,
             movenos = 9;
  char symbolpos[4][4] = {NULL}, symbolplayerone, symbolplayertwo;
  if (psym == 1) {
    symbolplayerone = 'X';
    symbolplayertwo = 'O';
  } else if (psym == 2) {
    symbolplayerone = 'O';
    symbolplayertwo = 'X';
  }
  if (choice == 1) {
    while (!win(symbolpos) && moves != 9) {
      if (player == 1) {
      a:
        showlayout(symbolpos, 0, psym, 1);
        cout << "\t\t\t\t\t\tEnter position : ";
        cin >> input;
        for (int i = 1; i < 4; i++) {
          for (int j = 1; j < 4; j++) {
            if (layout[i][j] == input + '0') {
              if (symbolpos[i][j] == NULL) {
                symbolpos[i][j] = symbolplayerone;
                player--;
                removemove(compmoves, movenos, input);
                movenos--;
                moves++;
                showlayout(symbolpos, 0, psym, 1);
              } else {
                cout << "\t\t\t\t\t\tEnter Valid Position";
                Sleep(1000);
                goto a;
              }
            }
          }
        }
      } else if (player == 0) {
      b:
        showlayout(symbolpos, 0, psym, 1);
        input = computermove(compmoves, movenos);
        for (int i = 1; i < 4; i++) {
          for (int j = 1; j < 4; j++) {
            if (layout[i][j] == input + '0') {
              if (symbolpos[i][j] == NULL) {
                symbolpos[i][j] = symbolplayertwo;
                player++;
                removemove(compmoves, movenos, input);
                movenos--;
                moves++;
                showlayout(symbolpos, 0, psym, 1);
              } else {
                goto b;
              }
            }
          }
        }
      }
    }
    if (!win(symbolpos) && moves == 9) {
      cout << "\t\t\t\t\t\tIt's a draw!!!";
    } else {
      if (player == 0) {
        cout << "\t\t\t\t\t\t    You Win!!!";
      } else {
        cout << "\t\t\t\t\t\t  Computer Wins!!!";
      }
    }
  } else {
    while (!win(symbolpos) && moves != 9) {
      if (player == 1) {
      a1:
        showlayout(symbolpos, 0, psym, 0);
        cout << "\t\t\t\t\t\tPlayer 1's turn\n";
        cout << "\t\t\t\t\t\tEnter position : ";
        cin >> input;
        for (int i = 1; i < 4; i++) {
          for (int j = 1; j < 4; j++) {
            if (layout[i][j] == input + '0') {
              if (symbolpos[i][j] == NULL) {
                symbolpos[i][j] = symbolplayerone;
                player--;
                moves++;
                showlayout(symbolpos, 0, psym, 0);
              } else {
                cout << "\t\t\t\t\t\tEnter Valid Position";
                Sleep(1000);
                goto a1;
              }
            }
          }
        }
      } else if (player == 0) {
      b1:
        showlayout(symbolpos, 0, psym, 0);
        cout << "\t\t\t\t\t\tPlayer 2's turn\n";
        cout << "\t\t\t\t\t\tEnter Position : ";
        cin >> input;
        for (int i = 1; i < 4; i++) {
          for (int j = 1; j < 4; j++) {
            if (layout[i][j] == input + '0') {
              if (symbolpos[i][j] == NULL) {
                symbolpos[i][j] = symbolplayertwo;
                player++;
                moves++;
                showlayout(symbolpos, 0, psym, 0);
              } else {
                cout << "\t\t\t\t\t\tEnter Valid Position";
                Sleep(1000);
                goto b1;
              }
            }
          }
        }
      }
    }
    if (!win(symbolpos) && moves == 9) {
      cout << "\t\t\t\t\t\tIt's a draw!!!";
    } else {
      if (player == 0) {
        cout << "\t\t\t\t\t\tPlayer 1 Wins!!!";
      } else {
        cout << "\t\t\t\t\t\tPlayer 2 Wins!!!";
      }
    }
  }
}

// Function to initialize positions on the board and to start the game
void initialize(int choice, int psym, int comp, int player) {
  char layout[4][4];
  int c = 1, i, j;

  for (i = 1; i < 4; i++) {
    for (j = 1; j < 4; j++) {
      char s = c + '0';
      layout[i][j] = s;
      c++;
      cout << layout[i][j] << "\n";
    }
  }
  showlayout(layout, 1, psym, comp);
  playgame(layout, choice, psym, player);
}

int main() {
  // Main function handles the player modes and initializes the game
  int choice, psym = 0, player = 2;
  char ch, ch1;
inp:
  system("CLS");
  cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t     Tic-Tac-Toe\n\n\t\t\t\t\t\t  1. "
          "Single "
          "Player\n\n\t\t\t\t\t\t  2. "
          "Multi-Player\n\n\t\t\t\t\t\tEnter your choice : ";
  cin >> choice;
  switch (choice) {
  case 1:
  askagain:
    cout << "\n\t\t\t\t\t     Choose a symbol 'X' or 'O' : ";
    cin >> ch;
    if (ch == 'x' || ch == 'X') {
      cout << "\n\t\t\t\t\t\t   You have chosen X\n";
      psym = 1;
    c:
      cout << "\n\t\t\t\t\tDo you want to start first ? (Y / N) : ";
      cin >> ch1;
      if (ch1 == 'Y' || ch1 == 'y') {
        player = 1;
        initialize(choice, psym, 1, player);
      } else if (ch1 == 'N' || ch1 == 'n') {
        player = 0;
        initialize(choice, psym, 1, player);
      } else {
        cout << "\n\t\t\t\t\t\t   Invalid Choice\n";
        goto c;
      }
    } else if (ch == 'o' || ch == 'O') {
      cout << "\n\t\t\t\t\t\t   You have chosen O\n";
      psym = 2;
    d:
      cout << "\n\t\t\t\t\tDo you want to start first ? (Y / N) : ";
      cin >> ch1;
      if (ch1 == 'Y' || ch1 == 'y') {
        player = 1;
        initialize(choice, psym, 1, player);
      } else if (ch1 == 'N' || ch1 == 'n') {
        player = 0;
        initialize(choice, psym, 1, player);
      } else {
        cout << "\n\t\t\t\t\t\t   Invalid Choice\n";
        goto d;
      }
    } else {
      cout << "\t\t\t\t\t\tChoose a valid option\n";
      Sleep(1000);
      goto askagain;
    }
    break;
  case 2:
    srand((unsigned int)(time(NULL)));
    psym = (rand() % (2)) + 1;
    player = rand() % 2;
    initialize(choice, psym, 0, player);
    break;
  default:
    cout << "\n\t\t\t\t\t\tEnter a valid choice";
    Sleep(1000);
    goto inp;
    break;
  }
  return 0;
}
