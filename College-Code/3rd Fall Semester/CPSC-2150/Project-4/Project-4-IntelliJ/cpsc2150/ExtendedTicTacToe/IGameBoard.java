package cpsc2150.ExtendedTicTacToe;

import static java.lang.Math.abs;

/**
 * Contains information about the game board necessary methods to control the flow of tic tac toe
 * <p>
 * Defines: numRequiredToWin : Z [The number of consecutive marks either vertical horizontal or diagonal to win]
 * totalRows : Z [The number of rows on the board]
 * totalColumns : Z [The number of columns on the board]
 * <p>
 * Initialization Ensures: [An empty (Empty is defined as " ") 2D grid of characters with row >= MIN_BOARD_SIZE and
 * row <= MAX_BOARD_SIZE and column >= MIN_BOARD_SIZE and column <= MAX_BOARD_SIZE]
 * <p>
 * Constraints:
 * MIN_BOARD_SIZE <= totalRows <= MAX_BOARD_SIZE
 * MIN_BOARD_SIZE <= totalColumns <= MAX_BOARD_SIZE
 * (MIN_NUM_TO_WIN < numRequiredToWin <= MAX_SIZE) and (MIN_NUM_TO_WIN < numRequiredToWin <= MAX_NUM_TO_WIN)
 */
public interface IGameBoard {

    /**
     * The maximum size that the table can be. This speaks for both the tables row and column
     */
    int MAX_BOARD_SIZE = 100;
    int MIN_BOARD_SIZE = 3;
    int MAX_NUM_TO_WIN = 25;
    int MIN_NUM_TO_WIN = 3;
    int MAX_PLAYERS = 10;
    int MIN_PLAYERS = 2;

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
     * @param player the type of character that will be placed on the board
     * @pre: marker != null
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
            return true;
        } else if (checkVerticalWin(lastPos, player)) {
            return true;
        } else {
            System.out.println("Diago");
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
     * checks to see if the last marker placed resulted in numRequiredToWin in a row
     * horizontally. Returns true if it does, otherwise false
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker
     * @return true if there is a horizontal win by the player and false if not
     * @pre: lastPos != null
     * @post: checkHorizontalWin = true iff [numRequiredToWin consecutive horizontal spots on the board [MIN_NUM_TO_WIN
     * ...numRequiredToWin] all equal the same character
     * as player]
     */
    default boolean checkHorizontalWin(BoardPosition lastPos, char player) {
        int countToWin = 0;
        for (int i = 0; i < getNumColumns(); i++) {
            if (countToWin == getNumToWin()) {
                return true;
            }
            if (whatsAtPos(new BoardPosition(lastPos.getRow(), i)) == player) {
                countToWin++;
            } else {
                countToWin = 0;
            }
        }
        return countToWin == getNumToWin();
    }

    /**
     * checks to see if the last marker placed resulted in numRequiredToWin in a row
     * vertically. Returns true if it does, otherwise false
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker
     * @return true if there is a vertical win by the player and false if not
     * @pre: lastPos != null
     * @post: checkVerticalWin = true iff [numRequiredToWin consecutive vertical spots on the board all equal the same character
     * as player]
     */
    default boolean checkVerticalWin(BoardPosition lastPos, char player) {
        int countToWin = 0;
        for (int i = 0; i < getNumRows(); i++) {
            if (countToWin == getNumToWin()) {
                return true;
            }
            if (whatsAtPos(new BoardPosition(i, lastPos.getColumn())) == player) {
                countToWin++;
            } else {
                countToWin = 0;
            }
        }
        return countToWin == getNumToWin();
    }

    /**
     * checks to see if the last marker placed resulted in numRequiredToWin in a row
     * diagonally. Returns true if it does, otherwise false
     * Note: there are two diagonals to check (Left diagonal and right diagonal)
     *
     * @param lastPos the most recently placed marker on the board
     * @param player  the player who placed the most recent marker
     * @return true if there is a diagonal win by the player and false if not
     * @pre: lastPos != null
     * @post: checkDiagonalWin = true iff [numRequiredToWin consecutive diagonal spots on the board all equal the same character
     * as player]
     */
    default boolean checkDiagonalWin(BoardPosition lastPos, char player) {
        int standardSize = getNumColumns();
        int countToWin = 0;
        int index = getNumRows() - 1;
        boolean specialCase = false;
        /* Check right diagonal */
        int columns = 0;
        int start = lastPos.getRow() + lastPos.getColumn();
        if (start > index) {
            //index = getNumRows();
            columns = start - index;
            start = index;
            specialCase = true;
        }

        for (int i = start; i >= 0; i--) {
            if (whatsAtPos(new BoardPosition(i, columns)) == player) {
                countToWin++;
            }else{
                countToWin = 0;
            }
            if (countToWin == getNumToWin()) {
                return true;
            }
            if ( !specialCase && (columns == index)) {
                break;
            }
            if(specialCase && (columns == getNumColumns()-1)){
                break;
            }
            columns++;
        }

        /* Check left diagonal */
        countToWin = 0;
        columns = lastPos.getRow() + lastPos.getColumn();
        if (lastPos.getRow() > lastPos.getColumn()) {
            start = lastPos.getRow() - lastPos.getColumn();
            columns = 0;
        } else if (columns > index) {
            start = 0;
            columns = abs(lastPos.getColumn() - lastPos.getRow());
        } else {
            start = 0;
            columns = lastPos.getColumn() - lastPos.getRow();
        }

        for (int i = start; i < standardSize; i++) {
            if (whatsAtPos(new BoardPosition(i, columns)) == player) {
                countToWin++;
            }else{
                countToWin= 0;
            }
            if (countToWin == getNumToWin()) {
                return true;
            }
            if (columns == index) {
                break;
            }
            columns++;
        }
        return false;
//        int countToWin = 0;
//       // int majDiag;
//       // boolean isMatching = true;
//        //int row = 0;
//        for (int row = 0; row < getNumRows(); row++) {
//            //majDiag = row;   //not being used anywhere
//            if (whatsAtPos(new BoardPosition(row, row)) ==player && whatsAtPos(new BoardPosition(row, row)) == whatsAtPos(new BoardPosition(row + 1, row + 1))) { //out of bounds with row+1
//                countToWin++;
//                if (countToWin == getNumToWin()) {
//                    return true;
//                }
//            }else {
//                countToWin= 0;
//            }
//        }
//
//        for (int row = 0; row < getNumRows(); row++) {
//            for (int col = 0; col < getNumColumns(); col++) {
//                if (row + col == getNumColumns()) {
//                    countToWin++;
//                   if(countToWin == getNumToWin()){
//                       return true;
//                   }else{
//                       countToWin = 0;
//                   }
//                }
//            }
//        }

//        int r = lastPos.getRow();
//        int c = lastPos.getColumn();
//        int index = r;
//
//        int columns = 0;
//        int start = r + c;
//        /* Protects bounds on board */
//        if (start > index) {
//            columns = start - index;
//            start = index;
//        }
//        for (int i = start; i >= 0; i--) {
//            /* Invalid position detected */
//            if (whatsAtPos(new BoardPosition(i,columns)) == 'X') {
//                countToWin++;
//                if(countToWin == getNumToWin()){
//                    return true;
//                }
//                //return false;
//            }else{
//                countToWin=0;
//            }
//            if (columns == index) {
//                break;
//            }
//            columns++;
//        }
//
//        /* Detect for left diagonals given position (r,c)  Starts top left This works similarly to right
//         * diagonal but comes with many more base conditions. Condition for if(r>c) its to the left of the center diagonal ()
//         * which is the diagonal that cuts the board in half, else if columns > index is for if its on the right side of
//         * the half way diagonal, else the the position is inside the half diagonal */
//        columns = r + c;
//        /* Protects bounds on board and left of center diagonal*/
//        if (r > c) {
//            start = r - c;
//            columns = 0;
//        } /* To the right of center diagonal */
//        else if (columns > index) {
//            start = 0;
//            columns = Math.abs(c - r);
//        }/* columns basically is columns = 0  */
//        else {
//            start = 0;
//            columns = c - r;
//        }
//        for (int i = start; i < getNumColumns(); i++) {
//            /* Invalid position detected */
//            if (whatsAtPos(new BoardPosition(i,columns)) == 'X') {
//                countToWin++;
//                if(countToWin == getNumToWin()){
//                    return true;
//                }
//            }else{
//                countToWin=0;
//            }
//            if (columns == index) {
//                break;
//            }
//            columns++;
//        }

        /* Right Diagonal (Contains some padding to not go out of bounds) */
//        for (int i = 0; i < getNumRows() - getNumToWin() - 1; i++) {
//            for (int j = 0; j < getNumColumns() - 1 - getNumToWin(); j++) {
//                /* Count the diagonal streak until it equals getNumToWin()*/
//                while (whatsAtPos(new BoardPosition(i, j)) == player) {
//                    i++;
//                    j++;
//                    countToWin++;
//                    if (countToWin == getNumToWin()) {
//                        return true;
//                    }
//                }
//                countToWin = 0;
//            }
//        }
//        /* Left Diagonal (Contains some padding to not go out of bounds) */
//        for (int i = getNumRows() - 1; i > (getNumToWin() - 2); i--) {
//            for (int j = 0; j < (getNumColumns() - getNumToWin() - 1); j++) {
//                /* Count the diagonal streak until it equals getNumToWin()*/
//                while (whatsAtPos(new BoardPosition(i, j)) == player) {
//                    j++;
//                    i--;
//                    countToWin++;
//                    if (countToWin == getNumToWin()) {
//                        return true;
//                    }
//                }
//                countToWin = 0;
//            }
//        }
//        /* No Diagonal win */
//        return false;
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
     * @param player the player desired to be checked
     * @param pos    the position of the character on the board
     * @return return true if the player is found to be present on the board
     * and false if not
     * @pre: pos != null
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
     * getNumToWin = numRequiredToWin that means it takes numRequiredToWin consecutive vertical horizontal or diagonal marks
     * to win the game
     * @pre: none
     * @post: getNumToWin() = numToWin
     */
    int getNumToWin();

}
