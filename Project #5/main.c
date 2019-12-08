#include <stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct playerData {
    char playerName[100];
    int jerseyNumber;
    double rating;
} playerData;

void initialize(playerData playerData1[], int size);

//---TODO Data is now dynamic
int MAX_PLAYERS = 1;

int findPlayer(int whichPlayer, playerData players[]);

void printMenu();

playerData *loadRoster(char filenameInput[], int *mySize);

int saveRoster(char filenameOutput[], playerData myRoster[], int playerCount);

void emptyRoster(playerData players[]);

void addPlayer(playerData players[]);

void updatePlayerInformation(playerData players[]);

void removePlayer(playerData players[]);

void displayPlayerInformation(playerData players[]);

void printFullRoster(playerData players[]);

void printStarPlayers(playerData players[]);

bool jerseyValid(int playerJerseyNumber);

bool ratingValid(double playerRating);

int main() {
    //---TODO SEGFAULT from malloc data not containing initialization of new added elements?

    playerData *myTeam = (playerData *) malloc(sizeof(playerData) * MAX_PLAYERS);
    initialize(myTeam, MAX_PLAYERS);
    char fileName[50];
    char userChoice = ' ';
    printMenu();
    while (true) {
        scanf(" %c", &userChoice);
        userChoice = (char) toupper(userChoice);
        if (userChoice == 'Q') {
            break;
        }
        switch (userChoice) {
            case 'L':
                printf("Enter file name: \n");
                scanf("%s", fileName);
                int tmp = 20;
                myTeam = loadRoster(fileName, &tmp);
                break;
            case 'S':
                printf("Enter file name: \n");
                scanf("%s", fileName);
                saveRoster(fileName, myTeam, MAX_PLAYERS);
                break;
            case 'E':
                emptyRoster(myTeam);
                break;
            case 'A':
                addPlayer(myTeam);
                break;
            case 'U':
                updatePlayerInformation(myTeam);
                break;
            case 'R':
                removePlayer(myTeam);
                break;
            case 'D':
                displayPlayerInformation(myTeam);
                break;
            case 'P':
                printFullRoster(myTeam);
                break;
            case '*':
                printStarPlayers(myTeam);
                break;
            case 'Q':
                printf("Ending! \n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        printMenu();
    }
    return 0;
}

void printMenu() {
    printf("\nMENU\n"
           "l - Load the player roster\n"
           "s - Save the player roster\n"
           "e - create an empty player roster\n"
           "a - Add a new player\n"
           "u - Update player information\n"
           "r - Remove a player from the roster\n"
           "d - Display player information\n"
           "p - Print the full roster\n"
           "* - Print \"Star\" players\n"
           "q - Quit\n"
           "\n"
           "Choose an option: ");
}

/*
 * '-1' Represents data unfilled for type int
 * '+'  Represents data unfilled for type char
 */
void initialize(playerData playerData1[], int size) {
    for (int i = 0; i < size; i++) {
        playerData1[i].playerName[0] = '+'; //---FIXME some incorporation of a null character?
        playerData1[i].jerseyNumber = -1;
        playerData1[i].rating = -1;
    }
}

int findPlayer(int whichPlayer, playerData players[]) {

    //---Returns negative if player already exists corresponding to location has padding to avoid 0
    for (int i = 0; i < MAX_PLAYERS; i++) {

        if (players[i].jerseyNumber == whichPlayer) {
            return -1 * (i + 1);
        }
    }
    //---returns available spot if player does not exist has padding to avoid 0
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].jerseyNumber == -1) {
            return i + 1;
        }
    }
    //---for if no space available
    return -99;
}

playerData *loadRoster(char filenameInput[], int *mySize) {
    FILE *file = fopen(filenameInput, "r");
    if (file == NULL) {
        printf("Error loading roster: \"%s\".\n", filenameInput);
        return NULL;
    }
    playerData *data = (playerData *) malloc((sizeof(playerData) * *mySize));
    //---TODO MAX PLAYERS MODIFIED
    MAX_PLAYERS = *mySize;
    initialize(data, MAX_PLAYERS);

    if (data == NULL) {
        printf("Failed allocation");
        return NULL;
    }
    for (int i = 0; i < *mySize; i++) {
        int tmp = fscanf(file, "%s\t%d\t%lf\n", data[i].playerName, &data[i].jerseyNumber, &data[i].rating);
        if (tmp == 0) {
            break;
        }
    }
    printf("Roster Loaded.\n");
    fclose(file);
    return data;
}

int saveRoster(char filenameOutput[], playerData myRoster[], int playerCount) {
    FILE *file = fopen(filenameOutput, "w+");
    if (file == NULL) {
        printf("Error saving roster: \"%s\".\n", filenameOutput);
        return 1;
    }
    for (int i = 0; i < playerCount; i++) {
        if (myRoster[i].playerName[0] == '+' && myRoster[i].jerseyNumber == -1) {
            continue;
        }
        fprintf(file, "%s\t%d\t%lf\n", myRoster[i].playerName, myRoster[i].jerseyNumber, myRoster[i].rating);
    }
    fclose(file);
    printf("Roster Saved.\n");
    return 0;
}

void emptyRoster(playerData players[]) {
    MAX_PLAYERS = 10;
    players = realloc(players, sizeof(playerData) * MAX_PLAYERS);
    initialize(players, MAX_PLAYERS);
    printf("Roster Emptied.\n");
}

void addPlayer(playerData players[]) {
    int jerseyNum = 0;
    char playerName[100];
    double ratingToAdd = 0.0;
    int playerLocation = findPlayer(jerseyNum, players);

    //---True only if array is filled with players
    if (playerLocation == -99) {
        //---TODO LOCATION WHERE MAX_PLAYERS IS MODIFIED
        MAX_PLAYERS++;

        players = realloc(players, sizeof(playerData) * MAX_PLAYERS);
        if (players == NULL) {
            printf("Allocation failed");
            return;
        }
        players[MAX_PLAYERS - 1].playerName[0] = '+';
        players[MAX_PLAYERS - 1].jerseyNumber = -1;
        players[MAX_PLAYERS - 1].rating = -1.0;
    }

    printf("Enter player jersey number: ");
    scanf("%d", &jerseyNum);

    if (!jerseyValid(jerseyNum)) {
        printf("Invalid Jersey");
        return;
    }
    playerLocation = findPlayer(jerseyNum, players);

    if (playerLocation < 0 && playerLocation > -15) {
        printf("Jersey # already in use. ");
        return;
    }
    printf("Enter player first or nick name: ");
    scanf("%s", playerName);
    printf("Enter player rating: ");
    scanf("%lf", &ratingToAdd);

    if (!ratingValid(ratingToAdd)) {
        printf("Invalid Rating");
        return;
    }

    playerLocation = findPlayer(jerseyNum, players);
    printf("Location %d",playerLocation);

    if (playerLocation > 0) {
        playerLocation -= 1;
        players[playerLocation].jerseyNumber = jerseyNum;
        strcpy(players[playerLocation].playerName, playerName);
        players[playerLocation].rating = ratingToAdd;
    }
}

void updatePlayerInformation(playerData players[]) {
    int jerseyNum = 0;
    printf("Enter a jersey number: ");
    scanf("%d", &jerseyNum);

    if (!jerseyValid(jerseyNum)) {
        printf("Invalid Jersey");
        return;
    }
    int playerLocation = findPlayer(jerseyNum, players);

    if (playerLocation > 0) {
        printf("Jersey not in use. No such player.\n");
        return;
    }

    if (playerLocation < 0) {
        char playerName[100];
        double playerRating = 0.0;

        playerLocation += 1;
        playerLocation *= -1;

        printf("Enter player first or nick name: ");
        scanf("%s", playerName);
        printf("Enter player rating: ");
        scanf("%lf", &playerRating);

        if (!ratingValid(playerRating)) {
            printf("Invalid Rating");
            return;
        }

        players[playerLocation].rating = playerRating;
        strcpy(players[playerLocation].playerName, playerName);
    }
}

void removePlayer(playerData players[]) {
    int jerseyNum = 0;
    printf("Enter a jersey number:\n");
    scanf("%d", &jerseyNum);
    if (!jerseyValid(jerseyNum)) {
        printf("Invalid Jersey");
        return;
    }

    int location = findPlayer(jerseyNum, players);

    if (location > 0) {
        printf("Jersey not in use. No such player.\n");
        //printf("%d",location);
        return;
    } else if (location < 0 && location > -15) {
        location += 1;
        location *= -1;
        for (int i = 0; i < strlen(players[location].playerName); i++) {
            players[location].playerName[i] = '+';
        }
        players[location].jerseyNumber = -1;
        players[location].rating = -1.0;
    }

}

void displayPlayerInformation(playerData players[]) {
    int jerseyNum = 0;
    printf("Enter a jersey number:\n");
    scanf("%d", &jerseyNum);

    if (!jerseyValid(jerseyNum)) {
        printf("Invalid Jersey");
        return;
    }

    int location = findPlayer(jerseyNum, players);
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

    printf("Name: %s\n", players[location].playerName);
    printf("Jersey #: %d\n", players[location].jerseyNumber);
    printf("Rating: %lf\n", players[location].rating);

}

void printFullRoster(playerData players[]) {
    printf("ROSTER\n");
    printf("------\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].playerName[0] == '+' && players[i].jerseyNumber == -1) {
            continue;
        }
        printf("%s\n", players[i].playerName);
        printf("%d\n", players[i].jerseyNumber);
        printf("%lf\n", players[i].rating);
        printf("\n");
    }
}

void printStarPlayers(playerData players[]) {
    double starRating = 0.0;
    printf("Enter minimum STAR rating: ");
    scanf("%lf", &starRating);
    printf("MY STARS\n");
    printf("--------\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].rating >= starRating) {
            printf("%s\n", players[i].playerName);
            printf("%d\n", players[i].jerseyNumber);
            printf("%lf\n", players[i].rating);
        }
    }
}

bool jerseyValid(int playerJerseyNumber) {
    if (playerJerseyNumber > 99 || playerJerseyNumber < 1) {
        return false;
    } else {
        return true;
    }
}

bool ratingValid(double playerRating) {
    if (playerRating > 100.0 || playerRating < 0.0) {
        return false;
    } else {
        return true;
    }
}
