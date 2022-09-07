#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>

int main() {

    /*
     *  rockpaperscissors-enhanced.c
     *  Author: Gavin McRoy
     *  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
     *  Lab #: 5
     *  submitted on: 9/26/2019
     *  Purpose: Simple rock paper scissors game that goes against a computer
     *  using random values
     *  work and I have neither received nor given assistance that violates
     *  the collaboration policy posted with this assignment. I have not copied
     *  or modified code from any other source other than the lab
     *  assignment, course textbook, or course lecture slides. Any unauthorized
     *  collaboration or use of materials not permitted will be subjected to
     *  academic integrity policies of Clemson University and CPSC 1010/1011.
     *  * I acknowledge that this lab assignment is based upon an assignment
     *  created by Clemson University and that any publishing or
     *  posting of this code is prohibited unless I
     *  receive written permission from Clemson University.
    */



    int gamesToPlay = 0;
    int winsTillQuit = 0;
    bool isWinToQuit = false;
    char userChoice = ' ';
    char makeMyLifeEasier = 0;
    int playerScore = 0;
    int computerScore = 0;
    int ties = 0;

    srand((int) time(0));

    printf("Starting the CPSC 1011 Rock, Paper, Scissors Game!\n\n");

    printf("Would you like to play until: \n");
    printf("(Option S) a set number of matches are played?\n");
    printf("(Option M) either player wins a certain number of matches? \n");
    scanf("%c", &userChoice);

    userChoice = toupper(userChoice);
    if (userChoice == 'S') {
        printf("Enter the amount of games you want to play\n");
        scanf("%d", &gamesToPlay);
    } else if (userChoice == 'M') {
        printf("Enter the number of matches a player must win to end the game: \n");
        scanf("%d", &winsTillQuit);
        isWinToQuit = true;
    }else{
        printf("Invalid val entered");
        return -1;
    }

    //---to avoid making another loop this accounts for every possible scenario for gamesToPlay so main loop still works
    if (isWinToQuit) {
        gamesToPlay = winsTillQuit * winsTillQuit * winsTillQuit + 1;
    }

    //---Main game loop
    for (int i = 0; i < gamesToPlay; i++) {
        if (playerScore >= winsTillQuit && isWinToQuit) {
            break;
        } else if (computerScore >= winsTillQuit && isWinToQuit) {
            break;
        }

        printf("Match %d: Enter R for rock, P for paper, or S for scissors: \n", i + 1);
        scanf(" %c", &userChoice);
        userChoice = toupper(userChoice);

        int random = rand() % 3;

        //---Turns random number into a character
        makeMyLifeEasier = (random == 0) ? 'R' : (random == 1) ? 'S' : (random == 2) ? 'P' : ' ';

        //---What the computer chose
        if (makeMyLifeEasier == 'R') {
            printf("The computer chose rock. ");
        } else if (makeMyLifeEasier == 'S') {
            printf("The computer chose scissors. ");
        } else if (makeMyLifeEasier == 'P') {
            printf("The computer chose paper. ");
        } else {
            printf("Bad stuff happened\n");
        }

        //---All scenarios where the computer wins
        if (makeMyLifeEasier == 'R' && userChoice == 'S') {
            printf("You lose. \n");
            computerScore++;
        } else if (makeMyLifeEasier == 'S' && userChoice == 'P') {
            printf("You lose. \n");
            computerScore++;
        } else if (makeMyLifeEasier == 'P' && userChoice == 'R') {
            printf("You lose. \n");
            computerScore++;
        } else if (makeMyLifeEasier == userChoice) {
            printf("You tied. \n");
            ties++;
        }

        //---All scenarios where the player wins
        if (userChoice == 'R' && makeMyLifeEasier == 'S') {
            printf("You win! \n");
            playerScore++;
        } else if (userChoice == 'S' && makeMyLifeEasier == 'P') {
            printf("You win! \n");
            playerScore++;
        } else if (userChoice == 'P' && makeMyLifeEasier == 'R') {
            printf("You win! \n");
            playerScore++;
        }

        //---Display scores
        if (playerScore > 0) {
            printf("Scores: You-%d ", playerScore);
        }
        if (computerScore > 0) {
            printf("Scores: Computer-%d ", computerScore);
        }
        if (ties > 0) {
            printf("Ties: %d", ties);
        }
        printf("\n");
    }
    printf("\n");
    if (isWinToQuit) {
        printf("The game is complete, because a player reached %d wins. Final scores: \n", winsTillQuit);
    } else {
        printf("The game of %d matches is complete. The final scores are: \n", gamesToPlay);
    }

    printf("%-15s%d\n", "You: ", playerScore);
    printf("%-15s%d\n", "Computer: ", computerScore);
    printf("%-15s%d\n", "Ties: ", ties);
    return 0;
}