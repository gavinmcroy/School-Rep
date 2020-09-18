package cpsc2150.ExtendedTicTacToe;

public class GameBoard {

    char gameBoard[][];

    /* TODO IMPLEMENT */
    GameBoard() {

    }


    /**
     * Checks if the desired space is available on the board such that its not taken, and
     * in the board bounds
     *
     * @return returns true if the position specified in pos is available,
     * false otherwise. If a space is not in bounds, then it is not available
     */
    public boolean checkSpace(BoardPosition pos) {
        return false;
    }

    /* TODO IMPLEMENT CONTRACT */

    /**
     * places the character in marker on the position specified by
     * marker, and should not be called if the space is not available.
     *
     * @param marker the position on the board at which the character will be placed
     * @param player the type of character that will be placed on the board (O or X)
     */
    public void placeMarker(BoardPosition marker, char player) {

    }

    /* TODO IMPLEMENT CONTRACT */

    /**
     * this function will check to see if the lastPos placed resulted
     * in a winner. It so it will return true, otherwise false.
     * Passing in the last position will help limit the possible
     * places to check for a win condition, since you can assume that any win
     * condition that did not include the most recent play made would have
     * been caught earlier.
     * You may call other methods to complete this method
     *
     * @param lastPos the most recently placed marker on the board
     * @return true if there is a winner based on the previous move
     */
    public boolean checkForWinner(BoardPosition lastPos) {
        return false;
    }

    /* TODO IMPLEMENT CONTRACT */

    /**
     * this function will check to see if the game has resulted in a
     * tie. A game is tied if there are no free board positions remaining.
     * You do not need to check for any potential wins, because we can assume
     * that the players were checking for win conditions as they played the
     * game
     *
     * @return true if the game is tied, and false otherwise
     */
    public boolean checkForDraw() {
        return false;
    }

    /* TODO IMPLEMENT CONTRACT */

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * horizontally. Returns true if it does, otherwise false
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker (O or X)
     * @return true if there is a horizontal win by the player and false if not
     */

    public boolean checkHorizontalWin(BoardPosition lastPos, char player) {
        return false;
    }

    /* TODO IMPLEMENT CONTRACT */

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * vertically. Returns true if it does, otherwise false
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker (O or X)
     * @return true if there is a vertical win by the player and false if not
     */
    public boolean checkVerticalWin(BoardPosition lastPos, char player) {
        return false;
    }

    /* TODO IMPLEMENT CONTRACT*/

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * diagonally. Returns true if it does, otherwise false
     * Note: there are two diagonals to check
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker (O or X)
     * @return true if there is a diagonal win by the player and false if not
     */
    public boolean checkDiagonalWin(BoardPosition lastPos, char player) {
        return false;
    }

    /* TODO IMPLEMENT CONTRACT */

    /**
     * returns what is in the GameBoard at position pos
     * If no marker is there it returns a blank space char ‘ ‘
     *
     * @param pos the desired position to be checked
     * @return the marker present at the desired location and if there is no marker it
     * will return ' ' instead
     */
    public char whatsAtPos(BoardPosition pos) {
        return ' ';
    }

    /* TODO IMPLEMENT CONTRACT */

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
     */
    public boolean isPlayerAtPos(BoardPosition pos, char player) {
        return false;
    }

    /* TODO IMPLEMENT JAVA DOC AND OR CONTRACT */
    @Override
    public String toString() {
        return super.toString();
    }
}
