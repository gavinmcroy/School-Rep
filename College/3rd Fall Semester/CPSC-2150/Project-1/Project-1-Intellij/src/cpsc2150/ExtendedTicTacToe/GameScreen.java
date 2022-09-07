package cpsc2150.ExtendedTicTacToe;

public class GameScreen {

    boolean isPlayerXTurn = true;
    boolean isPlayerOTurn = false;
    String winnerMessage = " ";
    String drawMessage = " ";
    GameBoard gameBoard = new GameBoard();

    public static void main(String[] args) {

    }

    /**
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

    }

    /**
     * Resets the game board back to its default settings by setting the instance of gameBoard equal to null
     * and creating a new instance. Changes the active players turn back to its default settings
     *
     * @pre: none
     * @post: isPlayerXTurn = true and isPlayerOTurn = false and gameBoard = new GameBoard();
     */
    private void resetGameBoard() {

    }

}
