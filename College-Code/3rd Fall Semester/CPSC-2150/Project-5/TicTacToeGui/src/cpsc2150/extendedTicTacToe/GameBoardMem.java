package cpsc2150.extendedTicTacToe;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GameBoardMem extends AbsGameBoard implements IGameBoard {

    /**
     * @invarient gameBoard[][] != null
     * MIN_BOARD_SIZE <= rows <= MAX_BOARD_SIZE
     * MIN_BOARD_SIZE <= columns <= MAX_BOARD_SIZE
     * (MIN_NUM_TO_WIN < numToWin <= MAX_SIZE) and (MIN_NUM_TO_WIN < numToWin <= MAX_NUM_TO_WIN)
     * @correspondence numRequiredToWin = numToWIn
     * totalRows = rows
     * totalColumns = columns
     */

    /*
     * Game board is represented by a map
     * Map <Character, BoardPosition>
     */
    private final int rows;
    private final int columns;
    private final int numToWin;
    Map<Character, List<BoardPosition>> boardPositionMap;


    /**
     * Initializes the game board to be a row by column array of empty characters. A character is
     * said to be empty if its board position inside of it equals " "
     *
     * @pre: MIN_BOARD_SIZE <= rows <= MAX_BOARD_SIZE
     * MIN_BOARD_SIZE <= columns <= MAX_BOARD_SIZE
     * (MIN_NUM_TO_WIN < numToWin <= MAX_SIZE) and (MIN_NUM_TO_WIN < numToWin <= MAX_NUM_TO_WIN)
     * @post: gameBoard != null
     */

    public GameBoardMem(int rows, int columns, int numToWin) {
        this.rows = rows;
        this.columns = columns;
        this.numToWin = numToWin;
        boardPositionMap = new HashMap<>();
        System.out.println("Memory Efficient Call ");
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
    @Override
    public void placeMarker(BoardPosition marker, char player) {
        ArrayList<BoardPosition> positions = (ArrayList<BoardPosition>) boardPositionMap.get(player);
        /* If the board is empty there would be no positions */
        if (positions == null) {
            positions = new ArrayList<>();
            positions.add(marker);
            boardPositionMap.put(player, positions);
        } else {
            positions.add(marker);
            boardPositionMap.put(player, positions);
        }
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
    @Override
    public char whatsAtPos(BoardPosition pos) {
        /* If the board contains the position find the character associated with it */

        for (Map.Entry<Character, List<BoardPosition>> m : boardPositionMap.entrySet()) {
            List<BoardPosition> tmp = m.getValue();
            for (BoardPosition boardPosition : tmp) {
                if (boardPosition.equals(pos)) {
                    return m.getKey();
                }
            }
        }
        return ' ';
    }

    /**
     * Todo test
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
    @Override
    public boolean isPlayerAtPos(BoardPosition pos, char player) {
        for (Map.Entry<Character, List<BoardPosition>> m : boardPositionMap.entrySet()) {
            List<BoardPosition> tmp = m.getValue();
            for (BoardPosition boardPosition : tmp) {
                if (boardPosition.equals(pos)) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * This method gets the current number of rows present in the game board
     *
     * @return returns the number of rows that are present in the Game Board
     * @pre: none
     * @post: getNumRows() = MAX_SIZE
     */
    @Override
    public int getNumRows() {
        return rows;
    }

    /**
     * This method gets the current number of columns present in the game board
     *
     * @return returns the number of columns that are present in the Game Board
     * @pre: none
     * @post: getNumColumns() = MAX_SIZE
     */
    @Override
    public int getNumColumns() {
        return columns;
    }

    /**
     * Returns the number of consecutive marks on the game board to win the game
     *
     * @return returns the number of consecutive marks required to win the game. Meaning if
     * getNumToWin = numToWin that means it takes numToWin consecutive vertical horizontal or diagonal marks
     * to win the game
     * @pre: none
     * @post: getNumToWin() = numToWin
     */
    @Override
    public int getNumToWin() {
        return numToWin;
    }

}
