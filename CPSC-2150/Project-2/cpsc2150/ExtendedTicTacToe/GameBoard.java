package cpsc2150.ExtendedTicTacToe;

public class GameBoard extends AbsGameBoard implements IGameBoard {

    /* TODO Remove this variable*/

//    final int SIZE = 8;
//    final int NUM_TO_WIN = 5;

    char[][] gameBoard;

    /**
     * TODO look into if null is the appropriate indication of empty
     * Initializes the game board to be a 8x8 array of empty characters. A character is
     * said to be empty if its board position inside of it equals null
     *
     * @pre: none
     * @post: gameBoard = (all elements = ' ')
     */
    GameBoard() {
        gameBoard = new char[SIZE][SIZE];

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                gameBoard[i][j] = ' ';
            }
        }
        /* TODO DEBUG */
        int j = 0;
        for(int i = 6; i > 1; i--){
            gameBoard[i-1][j] = 'X';
            j++;
        }

//        for(int i = 1; i < 7;i++){
//            gameBoard[i][i] = 'X';
//            j++;
//        }
    }

    /**
     * If the board position is equal to null that means that the position has not been
     * taken on the board. If it does not equal null that means the position has been taken
     * already
     */
//    @Override
//    public boolean checkSpace(BoardPosition pos) {
//        return gameBoard[pos.getRow()][pos.getColumn()] == ' ';
//    }

    /**
     * TODO does this method assume that the space is available ?
     * <p>
     * places the character in marker on the position specified by
     * marker, and should not be called if the space is not available. This method
     * assume that the space is available
     */
    @Override
    public void placeMarker(BoardPosition marker, char player) {
        gameBoard[marker.getRow()][marker.getColumn()] = player;
    }

    /**
     * TODO IMPLEMENT [I think this method is default]
     * this function will check to see if the lastPos placed resulted
     * in a winner. If so it will return true, otherwise false.
     * Passing in the last position will help limit the possible
     * places to check for a win condition, since you can assume that any win
     * condition that did not include the most recent play made would have
     * been caught earlier.
     * You may call other methods to complete this method
     */
//    @Override
//    public boolean checkForWinner(BoardPosition lastPos) {
//        return true;
//    }

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
//    @Override
//    public boolean checkForDraw() {
//        for (int i = 0; i < tmpSize; i++) {
//            for (int j = 0; j < tmpSize; j++) {
//                if (gameBoard[i][j] == ' ') {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }

    /**
     * TODO check to see whats the point of last pos
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
//    @Override
//    public boolean checkHorizontalWin(BoardPosition lastPos, char player) {
//        int countToWin = 0;
//        for (int i = 0; i < tmpSize; i++) {
//            for (int j = 0; j < tmpSize; j++) {
//                if (gameBoard[i][j] != ' ') {
//                    countToWin++;
//                } else {
//                    countToWin = 0;
//                }
//                if (countToWin == getNumToWin()) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }

    /**
     * TODO IMPLEMENT
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
//    @Override
//    public boolean checkVerticalWin(BoardPosition lastPos, char player) {
//        return false;
//    }


    /**
     * TODO IMPLEMENT
     * checks to see if the last marker placed resulted in 5 in a row
     * diagonally. Returns true if it does, otherwise false
     * Note: there are two diagonals to check
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker (O or X)
     * @return true if there is a diagonal win by the player and false if not
     * @pre: lastPos != null and player = 'O' or player 'X'
     * @post: checkDiagonalWin = true iff [5 consecutive diagonal spots on the board all equal the same character
     * as player]
     */
//    @Override
//    public boolean checkDiagonalWin(BoardPosition lastPos, char player) {
//        return false;
//    }

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
//    @Override
//    public boolean isPlayerAtPos(BoardPosition pos, char player) {
//        return gameBoard[pos.getRow()][pos.getColumn()] != ' ';
//    }

    /**
     * TODO implement Description and fix returned Variable
     */
    @Override
    public int getNumRows() {
        return SIZE;
    }

    /**
     * TODO implement Description and fix returned variable
     */
    @Override
    public int getNumColumns() {
        return SIZE;
    }

    /**
     * TODO implement Description and fix returned variable
     */
    @Override
    public int getNumToWin() {
        return NUM_TO_WIN;
    }

}
