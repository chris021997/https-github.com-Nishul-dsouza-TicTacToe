#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

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

int computermove(int compmoves[], int movenos) {
  srand((unsigned int)(time(NULL)));
  int move = rand() % movenos;
  return compmoves[move];
}

bool row(char layout[][4]) {
  for (int i = 1; i < 4; i++) {
    if (layout[i][1] == layout[i][2] && layout[i][2] == layout[i][3] &&
        layout[i][1] != NULL) {
      return true;
    }
  }
  return false;
}

bool column(char layout[][4]) {
  for (int i = 1; i < 4; i++) {
    if (layout[1][i] != NULL && layout[1][i] == layout[2][i] &&
        layout[2][i] == layout[3][i]) {
      return true;
    }
  }
  return false;
}

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

bool win(char layout[][4]) {
  return (row(layout) || column(layout) || diagonal(layout));
}
// Function to show the board layout
void showlayout(char layout[][4], int temp, int p1sym, int p2sym, int comp) {
  system("CLS");
  char symp1, symp2;
  if (temp) {
    cout << "The board layout\n";
  }
  if (comp) {
    if (p1sym == 1) {
      symp1 = 'X';
      symp2 = 'O';
    } else {
      symp1 = 'O';
      symp2 = 'X';
    }
    cout << "Player : " << symp1;
    cout << "\nComputer : " << symp2 << endl;
  } else {
    if (p1sym == 1) {
      symp1 = 'X';
      symp2 = 'O';
    } else {
      symp1 = 'O';
      symp2 = 'X';
    }
    cout << "Player 1 : " << symp1;
    cout << "\nPlayer 2 : " << symp2 << endl;
  }
  cout << "     |     |     "
       << "\n";
  cout << "  " << layout[1][1] << "  |  " << layout[1][2] << "  |  "
       << layout[1][3] << "\n";
  cout << "_____|_____|_____"
       << "\n";
  cout << "     |     |     "
       << "\n";
  cout << "  " << layout[2][1] << "  |  " << layout[2][2] << "  |  "
       << layout[2][3] << "\n";
  cout << "_____|_____|_____"
       << "\n";
  cout << "     |     |     "
       << "\n";
  cout << "  " << layout[3][1] << "  |  " << layout[3][2] << "  |  "
       << layout[3][3] << "\n";
  cout << "     |     |     "
       << "\n"
       << "\n";
  if (temp) {
    cout << "The game will begin shortly";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
  }
}

void playgame(char layout[][4], int choice, int p1sym, int p2sym) {
  system("CLS");
  int input, player = 1, compmoves[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, moves = 0,
             movenos = 9;
  char symbolpos[4][4] = {NULL}, symbolplayerone, symbolplayertwo;
  if (p1sym == 1) {
    symbolplayerone = 'X';
    symbolplayertwo = 'O';
  } else {
    symbolplayerone = 'O';
    symbolplayertwo = 'X';
  }
  if (choice == 1) {
    showlayout(symbolpos, 0, p1sym, p2sym, 1);
    while (!win(symbolpos) && moves != 9) {
      if (player == 1) {
      a:
        cout << "Enter position : ";
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
                showlayout(symbolpos, 0, p1sym, p2sym, 1);
              } else {
                goto a;
              }
            }
          }
        }
      } else if (player == 0) {
      b:
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
                showlayout(symbolpos, 0, p1sym, p2sym, 1);
              } else {
                goto b;
              }
            }
          }
        }
      }
    }
    if (!win(symbolpos) && moves == 9) {
      cout << "It's a draw";
    } else {
      if (player == 0) {
        cout << "You Win!!!";
      } else {
        cout << "Computer Wins!!!";
      }
    }
  } else {
    showlayout(symbolpos, 0, p1sym, p2sym, 0);
    while (!win(symbolpos) && moves != 9) {
      if (player == 1) {
      a1:
        cout << "Player 1's turn\n";
        cout << "Enter position : ";
        cin >> input;
        for (int i = 1; i < 4; i++) {
          for (int j = 1; j < 4; j++) {
            if (layout[i][j] == input + '0') {
              if (symbolpos[i][j] == NULL) {
                symbolpos[i][j] = 'X';
                player--;
                moves++;
                showlayout(symbolpos, 0, p1sym, p2sym, 0);
              } else {
                goto a1;
              }
            }
          }
        }
      } else if (player == 0) {
      b1:
        cout << "Player 2's turn\n";
        cout << "Enter Position : ";
        cin >> input;
        for (int i = 1; i < 4; i++) {
          for (int j = 1; j < 4; j++) {
            if (layout[i][j] == input + '0') {
              if (symbolpos[i][j] == NULL) {
                symbolpos[i][j] = 'O';
                player++;
                moves++;
                showlayout(symbolpos, 0, p1sym, p2sym, 0);
              } else {
                goto b1;
              }
            }
          }
        }
      }
    }
    if (!win(symbolpos) && moves == 9) {
      cout << "It's a draw!!!";
    } else {
      if (player == 0) {
        cout << "Player 1 Wins!!!";
      } else {
        cout << "Player 2 Wins!!!";
      }
    }
  }
}

// Function to initialize positions on the board
void initialize(int choice, int p1sym, int p2sym, int comp) {
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
  showlayout(layout, 1, p1sym, p2sym, comp);
  playgame(layout, choice, p1sym, p2sym);
}

int main() {
  int choice, p1sym = 0, p2sym = 0;
inp:
  system("CLS");
  cout << "1. Single Player\n2. Multi-Player\nEnter your choice : ";
  cin >> choice;
  switch (choice) {
  case 1:
    cout << "\n1. X\n2. O";
  askagain:
    cout << "\nChoose a symbol 'X' or 'O' : ";
    cin >> p1sym;
    switch (p1sym) {
    case 1:
      cout << "You have chosen X";
      initialize(choice, p1sym, p2sym, 1);
      break;
    case 2:
      cout << "You have chosen O";
      initialize(choice, p1sym, p2sym, 1);
      break;
    default:
      cout << "Choose a valid option";
      Sleep(1000);
      goto askagain;
      break;
    }
    break;
  case 2:
    initialize(choice, p1sym, p2sym, 0);
    break;
  default:
    cout << "Enter a valid choice";
    Sleep(1000);
    goto inp;
    break;
  }
  return 0;
}
