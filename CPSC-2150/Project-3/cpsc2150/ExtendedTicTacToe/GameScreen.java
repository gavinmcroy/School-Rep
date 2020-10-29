package cpsc2150.ExtendedTicTacToe;

import java.util.Hashtable;
import java.util.Scanner;

public class GameScreen {

    private static final Scanner scanner = new Scanner(System.in);

    private static int totalPlayers;
    private static int rows;
    private static int columns;
    private static int numToWin;
    /* Corresponds to the current players index in the hashTable*/
    private static int currentPlayer = 0;
    private static char implementation = '0';

    private static IGameBoard gameBoard;
    private static final Hashtable<Integer, Character> hashTable = new Hashtable<>();

    public static void main(String[] args) {
        String playAgain = "Y";
        /* If the player wants to play again, reset board and play again , else close program */
        while (playAgain.equals("Y")) {
            //System.out.println(gameBoard.toString());
            runGame();
            System.out.println("Would you like to play again ?");
            playAgain = scanner.next();
            playAgain = playAgain.toUpperCase();
            resetGameBoard();
        }
        System.out.println("Thanks for playing! ");
    }

    /**
     * Controls the flow of the game. Prompts player to enter a location as (row,column), The method then will
     * check to see if this position is valid. If not it will loop until a valid position is entered. If the
     * position is valid it will check for a win. If a win is detected it will print a congrats message and prompt
     * the user to play again. If a win is not detected it will attempt to detect a draw. If a draw is detected a
     * message about the draw will be printed. If there is no draw the turns will be changed and the boards current
     * layout will be displayed looping back to the beginning by asking the player to enter another location
     * ---Insert
     * ---CheckForWin
     * ---No Win Check Draw
     * ---No Draw Change Turn
     * ---Yes Draw print Message
     * ---Print Win Message
     * ---Ask play again Y/N
     *
     * @pre: isPlayerXTurn = true and isPlayerOTurn = false
     * @post: none
     */
    private static void runGame() {
        validateInput();
        while (true) {
            System.out.println("Player " + getCurrentPlayer() + " Please enter your ROW ");
            int row = scanner.nextInt();
            System.out.println("Player " + getCurrentPlayer() + " Please enter your COLUMN");
            int column = scanner.nextInt();
            /* If input is invalid ask for it again */
            while (row > gameBoard.getNumRows() - 1 || column > gameBoard.getNumColumns() - 1
                    || gameBoard.whatsAtPos(new BoardPosition(row, column)) != ' ') {
                System.out.println("That space is unavailable, please pick again");
                System.out.println("Player " + getCurrentPlayer() + " Please enter your ROW ");
                row = scanner.nextInt();
                System.out.println("Player " + getCurrentPlayer() + " Please enter your COLUMN");
                column = scanner.nextInt();
            }
            /* Place players desired position */
            gameBoard.placeMarker(new BoardPosition(row, column), getCurrentPlayer());
            /* If any conditions for win or draw are met end runGame, else continue looping */
            if (gameBoard.checkForWinner(new BoardPosition(row, column))) {
                System.out.println(gameBoard.toString());
                System.out.println("Player " + getCurrentPlayer() + " wins!");
                break;
            } else if (gameBoard.checkForDraw()) {
                System.out.println("drawMessage");
                break;
            } else {
                changeTurns();
                System.out.println(gameBoard.toString());
            }
        }
    }

    /**
     * This method contains all the input validation required to ensure no improper values are entered. Such as
     * the table size number of players and exc.
     */
    private static void validateInput() {
        System.out.println("How many players?");
        totalPlayers = scanner.nextInt();
        /* Ask input again if invalid player count entered */
        while (totalPlayers > GameBoard.MAX_PLAYERS) {
            System.out.println("Must be 10 players or fewer\n");
            System.out.println("How many players?");
            totalPlayers = scanner.nextInt();
        }
        /* Ask input again if too few players entered */
        while (totalPlayers < GameBoard.MIN_PLAYERS) {
            System.out.println("Must be at least 2 players");
            System.out.println("How many players?");
            totalPlayers = scanner.nextInt();
        }
        for (int i = 0; i < totalPlayers; i++) {
            /* Store these characters */
            System.out.println("Enter player ");
            char val = scanner.next().charAt(0);
            while (hashTable.containsValue(val)) {
                System.out.println("Duplicate: Enter player ");
                val = scanner.next().charAt(0);
            }
            hashTable.put(i, val);
        }
        System.out.println("How many rows?");
        rows = scanner.nextInt();
        /* Invalid row was entered */
        while (rows > GameBoard.MAX_BOARD_SIZE || rows < GameBoard.MIN_BOARD_SIZE) {
            System.out.println("Rows must be between " + GameBoard.MIN_BOARD_SIZE + " and " + GameBoard.MAX_BOARD_SIZE);
            System.out.println("How many rows?");
            rows = scanner.nextInt();
        }

        System.out.println("How many columns?");
        columns = scanner.nextInt();
        /* Invalid column was entered */
        while (columns > GameBoard.MAX_BOARD_SIZE || columns < GameBoard.MIN_BOARD_SIZE) {
            System.out.println("Columns must be between " + GameBoard.MIN_BOARD_SIZE + " and " + GameBoard.MAX_BOARD_SIZE);
            System.out.println("How many columns?");
            columns = scanner.nextInt();
        }

        System.out.println("How many in a row to win?");
        numToWin = scanner.nextInt();
        /* Invalid number to win was entered */
        while ((numToWin > GameBoard.MAX_NUM_TO_WIN) || (numToWin < GameBoard.MIN_NUM_TO_WIN) ||
                (numToWin > rows) || (numToWin > columns)) {
            System.out.println("Invalid number to win");
            System.out.println("How many in a row to win?");
            numToWin = scanner.nextInt();
        }

        System.out.println("Would you like a Fast Game (F/f) or a Memory Efficient Game (M/m");
        implementation = scanner.next().charAt(0);
        implementation = Character.toUpperCase(implementation);
        while (implementation != 'F' && implementation != 'M') {
            /* Re enter input */
            System.out.println("Would you like a Fast Game (F/f) or a Memory Efficient Game (M/m");
            implementation = scanner.next().charAt(0);
            implementation = Character.toUpperCase(implementation);
        }
        if (implementation == 'F') {
            gameBoard = new GameBoard(rows, columns, numToWin);
            System.out.println("Fast Implementation");
            System.out.println(gameBoard.toString());
        } else if (implementation == 'M') {
            gameBoard = new GameBoardMem(rows, columns, numToWin);
            System.out.println("Memory Implementation");
        }
    }

    /**
     * Resets the game board back to its default settings by setting the instance of gameBoard equal to null
     * and creating a new instance. Changes the active players turn back to its default settings
     *
     * @pre: none
     * @post: isPlayerXTurn = true and isPlayerOTurn = false and gameBoard = new GameBoard();
     */
    private static void resetGameBoard() {
        gameBoard = null;
        hashTable.clear();
    }


    /**
     * This method returns the current player by checking which player turn it currently is
     *
     * @return returns the current player by checking which players turn it currently is
     * @pre: none
     * @post: currentPlayer = playerTwo iff(isPlayerOTurn) or playerOne iff(!isPlayerOTurn)
     */
    private static char getCurrentPlayer() {
        return hashTable.get(currentPlayer);
    }

    /**
     * This method changes turns by assigning each variable to the opposite of itself. This ensures that each
     * player is able to play without one having multiple turns
     *
     * @pre: None
     * @post: isPlayerOTurn = !isPlayerOTurn and isPlayerXTurn = !isPlayerXTurn
     */
    private static void changeTurns() {
        currentPlayer++;
        if (currentPlayer == hashTable.size()) {
            currentPlayer = 0;
        }
    }

}
