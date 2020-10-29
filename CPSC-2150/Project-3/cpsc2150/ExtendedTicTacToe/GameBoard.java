package cpsc2150.ExtendedTicTacToe;


public class GameBoard extends AbsGameBoard implements IGameBoard {

    /**
     * @invarient gameBoard[][] != null
     * MIN_BOARD_SIZE <= rows <= MAX_BOARD_SIZE
     * MIN_BOARD_SIZE <= columns <= MAX_BOARD_SIZE
     * (MIN_NUM_TO_WIN < numToWin <= MAX_SIZE) and (MIN_NUM_TO_WIN < numToWin <= MAX_NUM_TO_WIN)
     * @correspondence numRequiredToWin = numToWIn
     * totalRows = rows
     * totalColumns = columns
     */

    private final int rows;
    private final int columns;
    private final int numToWin;
    private final char[][] gameBoard;


    /**
     * Initializes the game board to be a rows by columns array of empty characters. A character is
     * said to be empty if its board position inside of it equals " "
     *
     * @pre: MIN_BOARD_SIZE <= rows <= MAX_BOARD_SIZE
     * MIN_BOARD_SIZE <= columns <= MAX_BOARD_SIZE
     * (MIN_NUM_TO_WIN < numToWin <= MAX_SIZE) and (MIN_NUM_TO_WIN < numToWin <= MAX_NUM_TO_WIN)
     * @post: gameBoard = (all elements = ' ')
     */
    GameBoard(int rows, int columns, int numToWin) {
        this.numToWin = numToWin;
        this.rows = rows;
        this.columns = columns;
        gameBoard = new char[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
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
     * @param player the type of character that will be placed on the board
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
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
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
        return rows;
    }

    /**
     * This method gets the current number of columns present in the game board
     *
     * @return returns the number of columns that are present in the Game Board
     */
    @Override
    public int getNumColumns() {
        return columns;
    }

    /**
     * Returns the number of consecutive marks on the game board required to win the game
     *
     * @return returns the number of consecutive marks required to win the game. Meaning if
     * getNumToWin = numToWin that means it takes numToWin consecutive vertical horizontal or diagonal marks
     * to win the game
     */
    @Override
    public int getNumToWin() {
        return numToWin;
    }

}
