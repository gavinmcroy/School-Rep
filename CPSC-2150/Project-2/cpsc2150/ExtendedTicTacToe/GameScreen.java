package cpsc2150.ExtendedTicTacToe;

import java.util.Scanner;

public class GameScreen {

    /* TODO Potentially Temporary Variable */
    private static final char PLAYER_ONE = 'X';
    private static final char PLAYER_TWO = 'O';
    private static final Scanner scanner = new Scanner(System.in);

    private static boolean isPlayerXTurn = true;
    private static boolean isPlayerOTurn = false;
    private static GameBoard gameBoard = new GameBoard();

    public static void main(String[] args) {
        String playAgain = "Y";
        /* If the player wants to play again, reset board and play again , else close program */
        System.out.println(gameBoard.toString());
        while (playAgain.equals("Y")) {
            runGame();
            System.out.println("Play again ?");
            playAgain = scanner.nextLine();
            resetGameBoard();
        }
        /* TODO Issue with game not looping (flush input)? */
        System.out.println(playAgain);
        System.out.println("[TMP] Closing");
    }

    /**
     * TODO Potential Post Condition ?
     * Controls the flow of the game. Prompts player to enter a location as (row,column), The method then will
     * check to see if this position is valid. If not it will loop until a valid position is entered. If the
     * position is valid it will check for a win. If a win is detected it will print a congrats message and prompt
     * the user to play again. If a win is not detected it will attempt to detect a draw. If a draw is detected a
     * message about the draw will be printed. If there is no draw the turns will be changed and the boards current
     * layout will be displayed looping back to the beginning by asking the player to enter another location
     *
     * @pre: isPlayerXTurn = true and isPlayerOTurn = false
     * @post: none
     */
    private static void runGame() {
        while (true) {
            System.out.println("Player " + currentPlayer() + " Please enter your ROW ");
            int row = scanner.nextInt();
            System.out.println("Player " + currentPlayer() + " Please enter your COLUMN");
            int column = scanner.nextInt();
            /* If input is invalid ask for it again */
            while (row > gameBoard.getNumRows() || column > gameBoard.getNumColumns()
                    || gameBoard.whatsAtPos(new BoardPosition(row, column)) != ' ') {
                System.out.println("That space is unavailable, please pick again");
                System.out.println("Player " + currentPlayer() + " Please enter your ROW ");
                row = scanner.nextInt();
                System.out.println("Player " + currentPlayer() + " Please enter your COLUMN");
                column = scanner.nextInt();
            }
            /* Place players desired position */
            gameBoard.placeMarker(new BoardPosition(row, column), currentPlayer());
            /* If any conditions for win or draw are met end runGame, else continue looping */
            if (gameBoard.checkForWinner(new BoardPosition(row, column))) {
                System.out.println("Player " + currentPlayer() + " wins!");
                break;
            } else if (gameBoard.checkForDraw()) {
                System.out.println("drawMessage");
                break;
            } else {
                changeTurns();
                System.out.println(gameBoard.toString());
            }
        }


        //---Insert
        //---CheckForWin
        //---No Check Draw
        //---No Change Turn
        //---Yes Draw print Message
        //---Print Win Message
        //---Ask play again Y/N
    }

    /**
     * Resets the game board back to its default settings by setting the instance of gameBoard equal to null
     * and creating a new instance. Changes the active players turn back to its default settings
     *
     * @pre: none
     * @post: isPlayerXTurn = true and isPlayerOTurn = false and gameBoard = new GameBoard();
     */
    private static void resetGameBoard() {
        isPlayerXTurn = true;
        isPlayerOTurn = false;
        gameBoard = null;
        gameBoard = new GameBoard();
    }


    /**
     * This method returns the current player by checking which player turn it currently is
     *
     * @return returns the current player by checking which players turn it currently is
     * @pre: none
     * @post: currentPlayer = playerTwo iff(isPlayerOTurn) or playerOne iff(!isPlayerOTurn)
     */
    private static char currentPlayer() {
        if (isPlayerOTurn) {
            return PLAYER_TWO;
        }
        return PLAYER_ONE;
    }

    /**
     * This method changes turns by assigning each variable to the opposite of itself. This ensures that each
     * player is able to play without one having multiple turns
     *
     * @pre: None
     * @post: isPlayerOTurn = !isPlayerOTurn and isPlayerXTurn = !isPlayerXTurn
     */
    private static void changeTurns() {
        isPlayerOTurn = !isPlayerOTurn;
        isPlayerXTurn = !isPlayerXTurn;
    }

}
