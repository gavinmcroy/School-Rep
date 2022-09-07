#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <fstream>

void print_board(char board[9][9]);
//bool check_board_rows(char board[9][9]);
//bool check_board_colunms(char board[9][9]);

int main() {
    int size = 0;
    std::ifstream file;
    file.open("rowInvalid.txt");
    char charC, temp;
    char c[9][9] = {};
    int i, j;
    i = 0;
    j = 0;
    while (file>>charC) {
        if (charC == ' ') {
            temp = charC;
        } else {
            c[i][j] = charC;
            j += 1;
            if (j == 10) {
                i += 1;
                j = 0;
            }
            size += 1;
        }
        //printf("%c", charC);
    }
    //if (size - 9 != 81)
        //printf("Not enough inputs");
    //printf("%i\n", size - 9);

    print_board(c);

    //if (check_board_rows(c)==false){
    //  printf("Invalid1");
    //}
    //else{
    //  printf("Valid1");
    //}
    //if (check_board_colunms(c)==false){
    //  printf("Invalid2");
    //}
//  else{
    //  printf("Valid2");
    //}
    return 0;
}


void print_board(char board[9][9]) {
    printf("+---+---+---+\n");
    //char buffer[128];//nullptr;
   // std::string buffer;
    int counter = 0;
    for (int i = 0; i < 9; i++) {
       // buffer = new char[128];
        char buffer[64] = {};
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                strcat(buffer, "|");
            } else if (j % 3 == 0) {
                strcat(buffer, "|");
            }
            counter++;

            char var = board[i][j];
            strcat(buffer, &var);
        }
        printf("%s", buffer);
        printf("\n");
        //delete[] buffer;
        //buffer = nullptr;
        buffer[0] = '\0';
    }

    printf("+---+---+---+\n");

    //return 0;
}


bool check_board_rows(char board[9][9]) {
    int i, j, k;
    bool x = true;
    for (i = 0; i < 9; i++) {
        int digitcount[9] = {0};
        for (j = i; j < 9; j++) {
            switch (board[i][j]) {
                case '1':
                    digitcount[0] += 1;
                case '2':
                    digitcount[1] += 1;
                case '3':
                    digitcount[2] += 1;
                case '4':
                    digitcount[3] += 1;
                case '5':
                    digitcount[4] += 1;
                case '6':
                    digitcount[5] += 1;
                case '7':
                    digitcount[6] += 1;
                case '8':
                    digitcount[7] += 1;
                case '9':
                    digitcount[8] += 1;
            }
            for (k = 0; k < 9; k++) {
                if (digitcount[k] > 1) {
                    //return false;
                }
                printf("interation %d %d\n", i, digitcount[k]);
            }
        }

    }
    return x;
}

/*
bool check_board_colunms(char board[9][9]){
  int i,j,k;
  bool x=true;
  for(i=0;i<9;i++){
    int digitcount[9]={0};
    for(j=0;j<9;j++){
      switch(board[j][i]){
        case '1':
          digitcount[0]+=1;
        case '2':
          digitcount[1]+=1;
        case '3':
          digitcount[2]+=1;
        case '4':
          digitcount[3]+=1;
        case '5':
          digitcount[4]+=1;
        case '6':
          digitcount[5]+=1;
        case '7':
          digitcount[6]+=1;
        case '8':
          digitcount[7]+=1;
        case '9':
          digitcount[8]+=1;
      }
      for(k=0;k<9;k++){
        if (digitcount[k]>1){
          return false;
        }
        printf("%i",digitcount[k]);
      }
    }

  }
  return x;
}
*/
/*
bool check_board_3x3(char board[9][9]){
  int i,j,k,l;
  bool y=true;
  for(i=0;i<7;i++3){
    int digitcount[9]={0};
    for(j=0;j<7;j+=3){
      for(l=0;l<3;l++){
        for(x=0;x<3;x++){
          switch(board[i+l][j+x]){
            case '1':
              digitcount[0]+=1;
            case '2':
              digitcount[1]+=1;
            case '3':
              digitcount[2]+=1;
            case '4':
              digitcount[3]+=1;
            case '5':
              digitcount[4]+=1;
            case '6':
              digitcount[5]+=1;
            case '7':
              digitcount[6]+=1;
            case '8':
              digitcount[7]+=1;
            case '9':
              digitcount[8]+=1;
            }
          }
      }

      for(k=0;k<9;k++){
        if (digitcount[k]>1){
          return false;
        }
        printf("%i",digitcount[k]);
      }
    }

  }
  return y;
}
*/
