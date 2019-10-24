#include <stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

//--- -1 Represents data unfilled for type int
//--- + represents data unfilled for type char

/*FIXME left of incorporating remove player function. Potential issue of determining string size and
 * adding in a null character at the end of the player name.
 */
void initialize(char playerName[10][100], int jerseyNumber[], double rating[]);

int findPlayer(int whichPlayer, const int jerseyNumber[], int maxJersyCount);

void printMenu();

void addPlayer(char playerNames[],int jerseyNumbers[],double ratings);

void updatePlayerInformation();

void removePlayer();

void displayPlayerInformation(const char playerNames[],const int jerseyNumbers[], const double ratings[]);

void printFullRoster();

void printStarPlayers();

void quitApplication();

const int MAX_PLAYERS = 10;
//char playerNames[MAX_PLAYERS][100];
//int jerseyNumbers[MAX_PLAYERS];
//double ratings[MAX_PLAYERS];

int main() {
    char playerNames[MAX_PLAYERS][100];
    int jerseyNumbers[MAX_PLAYERS];
    double ratings[MAX_PLAYERS];
    initialize(playerNames, jerseyNumbers, ratings);
    char userChoice = ' ';
    printMenu();
    while (true) {
        scanf(" %c", &userChoice);
        userChoice = toupper(userChoice);
        if (userChoice == 'Q') {
            break;
        }
        switch (userChoice) {
            case 'A':
                addPlayer();
                break;
            case 'U':
                updatePlayerInformation();
                break;
            case 'R':
                removePlayer();
                break;
            case 'D':
                displayPlayerInformation();
                break;
            case 'P':
                printFullRoster();
                break;
            case 'S':
                printStarPlayers();
                break;
            case 'Q':
                quitApplication();
                break;
            default:
                printf("Invalid option");
                break;
        }
        printMenu();
    }
    return 0;
}

void printMenu() {
    printf("MENU\n"
           "a - Add a new player\n"
           "u - Update player information\n"
           "r - Remove a player from the roster\n"
           "d - Display player information\n"
           "p - Print the full roster\n"
           "s - Print \"Star\" players\n"
           "q - Quit\n"
           "\n"
           "Please make a selection: ");
}

void initialize(char playerName[10][100], int jerseyNumber[], double rating[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        playerName[i][0] = '+'; //---FIXME some incorperation of a null character?
        jerseyNumber[i] = -1;
        rating[i] = -1;
    }
}

int findPlayer(int whichPlayer, const int jerseyNumber[], int maxJersyCount) {
    //---Returns negative if player already exists corresponding to location and -99 for if no space available
    for (int i = 0; i < maxJersyCount; i++) {
        if (jerseyNumber[i] == whichPlayer) {
            return -1 * i;
        }
    }
    //---find available spot if player does not exist
    for (int i = 0; i < maxJersyCount; i++) {
        if (jerseyNumber[i] == -1) {
            return i;
        }
    }
    return -99;
}

void addPlayer() {
    int jersey = 0;
    char player[100];
    double playerRating = 0.0;

    printf("Enter player jersey number:\n");
    scanf("%d", &jersey);
    printf("Enter player first or nick name:\n");
    scanf("%s", player);
    printf("Enter player ratings:\n");
    scanf("%lf", &playerRating);

    int playerLocation = findPlayer(jersey, jerseyNumbers, MAX_PLAYERS);

    if (playerLocation >= 0) {
        jerseyNumbers[playerLocation] = jersey;
        for(int i = 0; i <strlen(player);i++){
            playerNames[playerLocation][i] = player[i];
        }
        ratings[playerLocation] = playerRating;
        printf("Player successfully added\n");
    } else if (playerLocation <= 0 && playerLocation >= -15) {
        printf("Error player already exists\n");
    } else if (playerLocation == -99) {
        printf("Maximum slots reached\n");
    }
}

void updatePlayerInformation() {
    //---Finish writing to properly update information
    int jerseyNum = 0;
    printf("Enter player jersey number: ");
    scanf("%d", &jerseyNum);
    int playerLocation = findPlayer(jerseyNum, jerseyNumbers, MAX_PLAYERS);
    playerLocation *= -1;
    if (playerLocation >= 0) {
        char playerName[100];
        double playerRating = 0.0;
        printf("Player found at %d ", playerLocation);
        printf("Enter player first or nickname:\n");
        scanf("%s", playerName);
        printf("Enter player rating:\n");
        scanf("%lf", &playerRating);
    } else {
        printf("Player was not found\n");
    }

}

void removePlayer() {
    int num = 0;
    printf("Enter player jersey number: ");
    scanf("%d", &num);
    int location = findPlayer(num, jerseyNumbers, MAX_PLAYERS);
    if (location >= 0) {
        printf("Player does not exist");
    } else if (location <= 0 && location >= -15) {
        location *= -1;
        for (int i = 0; i < 100; i++) {
            playerNames[location][i] = '+';
        }
        for(int i = 0; i<MAX_PLAYERS; i++){
            jerseyNumbers[i] = -1;
            ratings[i] = -1.0;
        }
    }

}

void displayPlayerInformation() {
    int num = 0;
    printf("Enter player jersey number: ");
    scanf("%d",&num);
    int location = findPlayer(num,jerseyNumbers,MAX_PLAYERS);
    if(location>0){
        printf("player does not exist \n");
        return;
    }
    if(location<=-1 && location>=-15){
        printf("Player exists at location %d\n",location*-1);
    }
    if(location==-99){
        printf("There is no available space: (displayPlayerInformation)\n");
        return;
    }
    location*=-1;
    printf("Name: %s\n",playerNames[location]);
    printf("Jersey #: %d\n",jerseyNumbers[location]);
    printf("Rating: %lf\n",ratings[location]);

}

void printFullRoster() {

}

void printStarPlayers() {

}

void quitApplication() {

}


