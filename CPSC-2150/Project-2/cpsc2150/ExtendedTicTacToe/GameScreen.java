package cpsc2150.ExtendedTicTacToe;

import java.util.Scanner;

public class GameScreen {

    /* TODO Potentially Temporary Variable */
    char playerOneX = 'X';
    char playerTwoO = 'O';

    boolean isPlayerXTurn = true;
    boolean isPlayerOTurn = false;
    String winnerMessage = " ";
    String drawMessage = " ";
    static GameBoard gameBoard = new GameBoard();
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        /* TODO DEBUG STATEMENT REMOVE LATER */
        System.out.println(gameBoard.toString());
    }

    /**
     * TODO IMPLEMENT
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
    private void runGame() {
        if (isPlayerXTurn) {
            System.out.println("Player X Please enter your ROW ");
            int row = scanner.nextInt();
            System.out.println("Player X Please enter your COLUMN");
            int column = scanner.nextInt();
            while (gameBoard.isPlayerAtPos(new BoardPosition(row, column), playerOneX)) {
                System.out.println("That space is unavailable, please pick again");
                System.out.println("Player X Please enter your ROW ");
                row = scanner.nextInt();
                System.out.println("Player X Please enter your COLUMN");
                column = scanner.nextInt();
            }
            //---Insert
            //---CheckForWin
                //---No Check Draw
                    //---No Change Turn
                //---Yes Draw print Message
            //---Print Win Message
            //---Ask play again Y/N
        } else if (isPlayerOTurn) {

        }

    }

    /**
     * TODO IMPLEMENT
     * Resets the game board back to its default settings by setting the instance of gameBoard equal to null
     * and creating a new instance. Changes the active players turn back to its default settings
     *
     * @pre: none
     * @post: isPlayerXTurn = true and isPlayerOTurn = false and gameBoard = new GameBoard();
     */
    private void resetGameBoard() {
        isPlayerXTurn = true;
        isPlayerOTurn = false;
        gameBoard = null;
        gameBoard = new GameBoard();
    }

}
