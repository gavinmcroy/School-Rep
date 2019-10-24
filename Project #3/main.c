#include <stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


/*FIXME left of incorporating remove player function. Potential issue of determining string size and
 * adding in a null character at the end of the player name.
 */
void initialize(char playerName[10][100], int jerseyNumber[], double rating[]);

int findPlayer(int whichPlayer, const int jerseyNumber[], int maxJersyCount);

void printMenu();

void addPlayer(char playerNames[10][100], int jerseyNumbers[], double ratings[]);

void updatePlayerInformation(char playerNames[10][100], const int jerseyNumbers[], double ratings[]);

void removePlayer(char playerNames[10][100], int jerseyNumbers[], double ratings[]);

void displayPlayerInformation(const char playerNames[10][100], const int jerseyNumbers[], const double ratings[]);

void printFullRoster(const char playerNames[10][100], const int jerseyNumbers[], const double ratings[]);

void printStarPlayers(const char playerNames[10][100], const int jerseyNumbers[], const double ratings[]);


const int MAX_PLAYERS = 10;


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
                addPlayer(playerNames, jerseyNumbers, ratings);
                break;
            case 'U':
                updatePlayerInformation(playerNames, jerseyNumbers, ratings);
                break;
            case 'R':
                removePlayer(playerNames, jerseyNumbers, ratings);
                break;
            case 'D':
                displayPlayerInformation(playerNames, jerseyNumbers, ratings);
                break;
            case 'P':
                printFullRoster(playerNames, jerseyNumbers, ratings);
                break;
            case 'S':
                printStarPlayers(playerNames, jerseyNumbers, ratings);
                break;
            case 'Q':
                printf("Ending! \n");
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
           "Choose an option: ");
}

/*
 * '-1' Represents data unfilled for type int
 * '+'  Represents data unfilled for type char
 */
void initialize(char playerName[10][100], int jerseyNumber[], double rating[]) {

    for (int i = 0; i < MAX_PLAYERS; i++) {
        playerName[i][0] = '+'; //---FIXME some incorperation of a null character?
        jerseyNumber[i] = -1;
        rating[i] = -1;
    }
}

int findPlayer(int whichPlayer, const int jerseyNumber[], int maxJersyCount) {

    //---Returns negative if player already exists corresponding to location has padding to avoid 0
    for (int i = 0; i < maxJersyCount; i++) {

        if (jerseyNumber[i] == whichPlayer) {
            return -1 * (i + 1);
        }
    }
    //---returns available spot if player does not exist has padding to avoid 0
    for (int i = 0; i < maxJersyCount; i++) {
        if (jerseyNumber[i] == -1) {
            return i + 1;
        }
    }
    //---for if no space available
    return -99;
}

void addPlayer(char playerNames[10][100], int jerseyNumbers[], double ratings[]) {
    int jerseyToAdd = 0;
    char playerToAdd[100];
    double ratingToAdd = 0.0;

    printf("Enter player jersey number:\n");
    scanf("%d", &jerseyToAdd);
    printf("Enter player first or nick name:\n");
    scanf("%s", playerToAdd);
    printf("Enter player rating:\n");
    scanf("%lf", &ratingToAdd);

    int playerLocation = findPlayer(jerseyToAdd, jerseyNumbers, MAX_PLAYERS);

    if (playerLocation > 0) {
        playerLocation -= 1;
        jerseyNumbers[playerLocation] = jerseyToAdd;
        for (int i = 0; i < strlen(playerToAdd); i++) {
            playerNames[playerLocation][i] = playerToAdd[i];
        }
        ratings[playerLocation] = ratingToAdd;
        //---printf("Player successfully added\n");
    } else if (playerLocation < 0 && playerLocation > -15) {
        printf("Jersey # already in use.\n");
    } else if (playerLocation == -99) {
        printf("The Roster is full.\n");
    }
}

void updatePlayerInformation(char playerNames[10][100], const int jerseyNumbers[], double ratings[]) {
    int jerseyNum = 0;
    printf("Enter player jersey number:\n");
    scanf("%d", &jerseyNum);

    int playerLocation = findPlayer(jerseyNum, jerseyNumbers, MAX_PLAYERS);

    if (playerLocation > 0) {
        printf("Jersey not in use. No such player.\n");
        return;
    }

    if (playerLocation < 0 && playerLocation != -99) {
        printf("Player found at %d \n", (playerLocation + 1) * -1);
    }

    if (playerLocation < 0) {
        char playerName[100];
        double playerRating = 0.0;

        playerLocation += 1;
        playerLocation *= -1;

        printf("Enter player first or nickname:\n");
        scanf("%s", playerName);
        printf("Enter player rating:\n");
        scanf("%lf", &playerRating);

        ratings[playerLocation] = playerRating;
        for (int i = 0; i < strlen(playerName); i++) {
            playerNames[playerLocation][i] = playerName[i];
        }
    }
    //printf("Successfully Updated player information! \n");
}

void removePlayer(char playerNames[10][100], int jerseyNumbers[], double ratings[]) {
    //---FIXME finish writing to properly remove player
    int num = 0;
    printf("Enter player jersey number:\n");
    scanf("%d", &num);
    int location = findPlayer(num, jerseyNumbers, MAX_PLAYERS);

    if (location > 0) {
        printf("Player does not exist");
        return;
    } else if (location < 0 && location > -15) {
        location += 1;
        location *= -1;
        for (int i = 0; i < strlen(playerNames[location]); i++) {
            playerNames[location][i] = '+';
        }
        jerseyNumbers[location] = -1;
        ratings[location] = -1.0;
    }

}

void displayPlayerInformation(const char playerNames[10][100], const int jerseyNumbers[], const double ratings[]) {
    int num = 0;
    printf("Enter player jersey number:\n");
    scanf("%d", &num);
    int location = findPlayer(num, jerseyNumbers, MAX_PLAYERS);
    if (location > 0) {
        printf("Jersey not in use.  No such player.\n");
        return;
    }
    if (location <= -1 && location > -15) {
        location += 1;
        location *= -1;
        //printf("Player exists at location %d\n", location);
    }
    if (location == -99) {
        printf("There is no available space: (displayPlayerInformation)\n");
        return;
    }

    printf("%s\n", playerNames[location]);
    printf("%d\n", jerseyNumbers[location]);
    printf("%lf\n", ratings[location]);

}

void printFullRoster(const char playerNames[10][100], const int jerseyNumbers[], const double ratings[]) {
    printf("ROSTER\n");
    printf("------\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (playerNames[i][0] == '+' && jerseyNumbers[i] == -1) {
            continue;
        }
        printf("\n");
        printf("%s\n", playerNames[i]);
        printf("%d\n", jerseyNumbers[i]);
        printf("%lf\n", ratings[i]);
    }
}

void printStarPlayers(const char playerNames[10][100], const int jerseyNumbers[], const double ratings[]) {
    double starRating = 0.0;
    printf("Enter \"STAR\" rating:");
    scanf("%lf", &starRating);
    printf("MY STARS\n");
    printf("--------\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (ratings[i] >= starRating) {
            printf("%s\n", playerNames[i]);
            printf("%d\n", jerseyNumbers[i]);
            printf("%lf\n", ratings[i]);
        }
    }
}




