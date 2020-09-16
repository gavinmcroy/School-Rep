package cpsc2150.ExtendedTicTacToe;

public class GameBoard {

    char gameBoard[][];

    /* TODO IMPLEMENT */
    GameBoard() {

    }

    /* TODO IMPLEMENT */

    /**
     * returns true if the position specified in pos is available,
     * false otherwise. If a space is not in bounds, then it is not available
     */
    public boolean checkSpace(BoardPosition pos) {
        return false;
    }

    /* TODO IMPLEMENT */

    /**
     * places the character in marker on the position specified by
     * marker, and should not be called if the space is not available.
     */
    public void placeMarker(BoardPosition marker, char player) {

    }

    /* TODO IMPLEMENT */

    /**
     * this function will check to see if the lastPos placed resulted
     * in a winner. It so it will return true, otherwise false.
     * Passing in the last position will help limit the possible
     * places to check for a win condition, since you can assume that any win
     * condition that did not include the most recent play made would have
     * been caught earlier.
     * You may call other methods to complete this method
     */
    public boolean checkForWinner(BoardPosition lastPos) {
        return false;
    }

    /* TODO IMPLEMENT */

    /**
     * this function will check to see if the game has resulted in a
     * tie. A game is tied if there are no free board positions remaining.
     * You do not need to check for any potential wins, because we can assume
     * that the players were checking for win conditions as they played the
     * game. It will return true if the game is tied, and false otherwise.
     */
    public boolean checkForDraw() {
        return false;
    }

    /* TODO IMPLEMENT */

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * horizontally. Returns true if it does, otherwise false
     */

    public boolean checkHorizontalWin(BoardPosition lastPos, char player) {
        return false;
    }

    /* TODO IMPLEMENT */

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * vertically. Returns true if it does, otherwise false
     */
    public boolean checkVerticalWin(BoardPosition lastPos, char player) {
        return false;
    }

    /* TODO IMPLEMENT */

    /**
     * checks to see if the last marker placed resulted in 5 in a row
     * diagonally. Returns true if it does, otherwise false
     * Note: there are two diagonals to check
     */
    public boolean checkDiagonalWin(BoardPosition lastPos, char player) {
        return false;
    }

    /* TODO IMPLEMENT */

    /**
     * returns what is in the GameBoard at position pos
     * If no marker is there it returns a blank space char ‘ ‘
     */
    public char whatsAtPos(BoardPosition pos) {
        return ' ';
    }

    /* TODO IMPLEMENT */

    /**
     * returns true if the player is at pos, otherwise it returns false
     * Note: this method will be implemented very similarly to
     * whatsAtPos, but it’s asking a different question. We only know they
     * will be similar because we know GameBoard will contain a 2D array. If
     * the data structure were to change in the future these two methods
     * could end up being radically different.
     */
    public boolean isPlayerAtPos(BoardPosition pos, char player) {
        return false;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
