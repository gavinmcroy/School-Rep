package cpsc2150.ExtendedTicTacToe;

/**
 * Contains information about the game board necessary methods to control the flow of tic tac toe
 * <p>
 * Defines: numToWin : Z [The number of consecutive marks either vertical horizontal or diagonal to win]
 * <p>
 * Initialization Ensures: [An empty (Empty is defined as " ")2D grid of characters with row == MAX_SIZE
 * and column == MAX_SIZE]
 * <p>
 * Constraints:
 * 0<NUM_TO_WIN <= MAX_SIZE
 */
public interface IGameBoard {

    /**
     * The maximum size that the table can be. This speaks for both the tables row and column
     */
//    int MAX_SIZE = 8;
    public static final int MAX_BOARD_SIZE = 100;
    public static final int MIN_BOARD_SIZE = 3;
    public static final int MAX_NUM_TO_WIN = 25;
    public static final int MIN_NUM_TO_WIN = 3;
    public static final int MAX_PLAYERS = 10;
    public static final int MIN_PLAYERS = 2;
    /**
     * Checks if the desired space is available on the board such that its not taken, and
     * in the board bounds (Not taken is defined as " ")
     *
     * @return returns true if the position specified in pos is available,
     * false otherwise. If a space is not in bounds, then it is not available
     * @pre: pos !=null
     * @post: checkSpace = true iff(gameBoard at pos = ' ') : else it is false
     */
    default boolean checkSpace(BoardPosition pos) {
        char positionDetails = whatsAtPos(pos);
        return positionDetails == ' ';
    }

    /**
     * places the character in marker on the position specified by
     * marker, and should not be called if the space is not available.
     *
     * @param marker the position on the board at which the character will be placed
     * @param player the type of character that will be placed on the board (O or X)
     * @pre: marker != null and player = 'O' or player = 'X'
     * @post: gameBoard [at marker] = player
     */
    void placeMarker(BoardPosition marker, char player);

    /**
     * this function will check to see if the lastPos placed resulted
     * in a winner. If so it will return true, otherwise false.
     * Passing in the last position will help limit the possible
     * places to check for a win condition, since you can assume that any win
     * condition that did not include the most recent play made would have
     * been caught earlier.
     * You may call other methods to complete this method
     *
     * @param lastPos the most recently placed marker on the board
     * @return true if there is a winner based on the previous move
     * @pre: lastPos != null
     * @post: checkForWinner = true iff [checkHorizontalWin or checkVerticalWin or checkDiagonalWin = true]
     */
    default boolean checkForWinner(BoardPosition lastPos) {
        char player = whatsAtPos(lastPos);
        if (checkHorizontalWin(lastPos, player)) {
            //System.out.println("Horizontal");
            return true;
        } else if (checkVerticalWin(lastPos, player)) {
            //System.out.println("Vertical");
            return true;
        } else {
            //System.out.println("Diagonal");
            return checkDiagonalWin(lastPos, player);
        }
    }

    /**
     * this function will check to see if the game has resulted in a
     * tie. A game is tied if there are no free board positions remaining.
     * You do not need to check for any potential wins, because we can assume
     * that the players were checking for win conditions as they played the
     * game
     *
     * @return true if the game is tied, and false otherwise
     * @pre: none
     * @post: checkForDraw = true iff [board is filled with elements not equal to ' ']
     */
    default boolean checkForDraw() {
        for (int i = 0; i < getNumRows(); i++) {
            for (int j = 0; j < getNumColumns(); j++) {
                if (whatsAtPos(new BoardPosition(i, j)) == ' ') {
                    return false;
                }
            }
        }
        /* Board is full */
        return true;
    }

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * horizontally. Returns true if it does, otherwise false
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker (O or X)
     * @return true if there is a horizontal win by the player and false if not
     * @pre: lastPos != null and player = 'O' or player = 'X'
     * @post: checkHorizontalWin = true iff [5 consecutive horizontal spots on the board [1...5] all equal the same character
     * as player]
     */
    default boolean checkHorizontalWin(BoardPosition lastPos, char player) {
        int countToWin = 0;
        for (int i = 0; i < getNumRows(); i++) {
            for (int j = 0; j < getNumColumns(); j++) {
                /* Check if have a player, if so add to the streak till it equals getNumToWin */
                if (whatsAtPos(new BoardPosition(i, j)) == player) {
                    countToWin++;
                } else {
                    countToWin = 0;
                }
                if (countToWin == getNumToWin()) {
                    return true;
                }
            }
        }
        /* No Horizontal win */
        return false;
    }

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * vertically. Returns true if it does, otherwise false
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker (O or X)
     * @return true if there is a vertical win by the player and false if not
     * @pre: lastPos != null and player = 'O' or player = 'X'
     * @post: checkVerticalWin = true iff [5 consecutive vertical spots on the board all equal the same character
     * as player]
     */
    default boolean checkVerticalWin(BoardPosition lastPos, char player) {
        int countToWin = 0;
        for (int i = 0; i < getNumColumns(); i++) {
            for (int j = 0; j < getNumRows(); j++) {
                /* Check if have a player, if so add to the streak till it equals getNumToWin */
                if (whatsAtPos(new BoardPosition(j, i)) == player) {
                    countToWin++;
                } else {
                    countToWin = 0;
                }
                if (countToWin == getNumToWin()) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * diagonally. Returns true if it does, otherwise false
     * Note: there are two diagonals to check (Left diagonal and right diagonal)
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker (O or X)
     * @return true if there is a diagonal win by the player and false if not
     * @pre: lastPos != null and player = 'O' or player 'X'
     * @post: checkDiagonalWin = true iff [5 consecutive diagonal spots on the board all equal the same character
     * as player]
     */
    default boolean checkDiagonalWin(BoardPosition lastPos, char player) {
        int countToWin = 0;

        /* Right Diagonal (Contains some padding to not go out of bounds) */
        for (int i = 0; i < getNumRows() - getNumToWin() - 1; i++) {
            for (int j = 0; j < getNumColumns() - 1 - getNumToWin(); j++) {
                /* Count the diagonal streak until it equals getNumToWin()*/
                while (whatsAtPos(new BoardPosition(i, j)) == player) {
                    i++;
                    j++;
                    countToWin++;
                    if (countToWin == getNumToWin()) {
                        return true;
                    }
                }
                countToWin = 0;
            }
        }
        /* Left Diagonal (Contains some padding to not go out of bounds) */
        for (int i = getNumRows() - 1; i > (getNumToWin() - 2); i--) {
            for (int j = 0; j < (getNumColumns() - getNumToWin() - 1); j++) {
                /* Count the diagonal streak until it equals getNumToWin()*/
                while (whatsAtPos(new BoardPosition(i, j)) == player) {
                    j++;
                    i--;
                    countToWin++;
                    if (countToWin == getNumToWin()) {
                        return true;
                    }
                }
                countToWin = 0;
            }
        }
        /* No Diagonal win */
        return false;
    }

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
    char whatsAtPos(BoardPosition pos);

    /**
     * returns true if the player is at pos, otherwise it returns false
     * Note: this method will be implemented very similarly to
     * whatsAtPos, but it’s asking a different question. We only know they
     * will be similar because we know GameBoard will contain a 2D array. If
     * the data structure were to change in the future these two methods
     * could end up being radically different.
     *
     * @param player the player desired to be checked (O or X)
     * @param pos    the position of the character on the board
     * @return return true if the player is found to be present on the board
     * and false if not
     * @pre: pos != null and player = 'O' or player 'X'
     * @post: isPlayerAtPos = true iff(gameBoard[at pos] == player)
     */
    default boolean isPlayerAtPos(BoardPosition pos, char player) {
        return whatsAtPos(pos) != player;
    }


    /**
     * This method gets the current number of rows present in the game board
     *
     * @return returns the number of rows that are present in the Game Board
     * @pre: none
     * @post: getNumRows() = MAX_SIZE
     */
    int getNumRows();

    /**
     * This method gets the current number of columns present in the game board
     *
     * @return returns the number of columns that are present in the Game Board
     * @pre: none
     * @post: getNumColumns() = MAX_SIZE
     */
    int getNumColumns();

    /**
     * Returns the number of consecutive marks on the game board to win the game
     *
     * @return returns the number of consecutive marks required to win the game. Meaning if
     * getNumToWin = 5 that means it takes 5 consecutive vertical horizontal or diagonal marks
     * to win the game
     * @pre: none
     * @post: getNumToWin() = numToWin
     */
    int getNumToWin();

}
