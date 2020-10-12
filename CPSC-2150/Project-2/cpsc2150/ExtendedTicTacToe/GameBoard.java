package cpsc2150.ExtendedTicTacToe;


public class GameBoard extends AbsGameBoard implements IGameBoard {

    /**
     * @invarient gameBoard[][] != null
     * @correspondence numToWin = NUM_TO_WIN
     */

    private final int NUM_TO_WIN = 5;
    private char[][] gameBoard;

    /**
     * Initializes the game board to be a 8x8 array of empty characters. A character is
     * said to be empty if its board position inside of it equals " "
     *
     * @pre: none
     * @post: gameBoard = (all elements = ' ')
     */
    GameBoard() {
        gameBoard = new char[MAX_SIZE][MAX_SIZE];

        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                gameBoard[i][j] = ' ';
            }
        }
    }

    /* checkSpace */

    /**
     * places the character in marker on the position specified by
     * marker, and should not be called if the space is not available.
     *
     * @param marker the position on the board at which the character will be placed
     * @param player the type of character that will be placed on the board (O or X)
     */
    @Override
    public void placeMarker(BoardPosition marker, char player) {
        gameBoard[marker.getRow()][marker.getColumn()] = player;
    }

    /*checkForWinner*/

    /**
     * This function will check to see if the game has resulted in a
     * tie. A game is tied if there are no free board positions remaining.
     * You do not need to check for any potential wins, because we can assume
     * that the players were checking for win conditions as they played the
     * game
     *
     * @return true if the game is tied, and false otherwise
     */
    @Override
    public boolean checkForDraw() {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                if (gameBoard[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    /* checkForHorizontalWin */

    /* checkForVerticalWin */

    /* checkForDiagonalWin */

    /**
     * returns what is in the GameBoard at position pos
     * If no marker is there it returns a blank space char ‘ ‘
     *
     * @param pos the desired position to be checked
     * @return the marker present at the desired location and if there is no marker it
     * will return ' ' instead
     * @pre: pos != null
     * @post: whatsAtPos = gameBoard[at pos]
     */
    @Override
    public char whatsAtPos(BoardPosition pos) {
        return gameBoard[pos.getRow()][pos.getColumn()];
    }

    /**
     * This method returns the current number of rows present in the game board
     *
     * @return returns the number of rows that are present in the Game Board
     */
    @Override
    public int getNumRows() {
        return MAX_SIZE;
    }

    /**
     * This method gets the current number of columns present in the game board
     *
     * @return returns the number of columns that are present in the Game Board
     */
    @Override
    public int getNumColumns() {
        return MAX_SIZE;
    }

    /**
     * Returns the number of consecutive marks on the game board required to win the game
     *
     * @return returns the number of consecutive marks required to win the game. Meaning if
     * getNumToWin = 5 that means it takes 5 consecutive vertical horizontal or diagonal marks
     * to win the game
     */
    @Override
    public int getNumToWin() {
        return NUM_TO_WIN;
    }

}
