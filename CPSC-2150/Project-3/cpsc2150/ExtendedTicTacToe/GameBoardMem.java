package cpsc2150.ExtendedTicTacToe;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GameBoardMem extends AbsGameBoard implements IGameBoard {

    /**
     * Game board is represented by a map
     * Map <Character, BoardPosition>
     */
    private final int rows;
    private final int columns;
    private final int numToWin;
    Map<Character, List<BoardPosition>> boardPositionMap;


    public GameBoardMem(int rows, int columns, int numToWin) {
        this.rows = rows;
        this.columns = columns;
        this.numToWin = numToWin;
        boardPositionMap = new HashMap<>();
        System.out.println("Memory Efficient Call ");
    }

    /**
     * TODO update Explanation
     * places the character in marker on the position specified by
     * marker, and should not be called if the space is not available.
     *
     * @param marker the position on the board at which the character will be placed
     * @param player the type of character that will be placed on the board (O or X)
     * @pre: marker != null and player = 'O' or player = 'X'
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
        //boardPositionMap.put(player, marker);
    }

    /**
     * TODO update explanation
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
        //if (boardPositionMap.containsValue(pos)) {
        for (Map.Entry<Character, List<BoardPosition>> m : boardPositionMap.entrySet()) {
            List<BoardPosition> tmp = m.getValue();
            for (BoardPosition boardPosition : tmp) {
                if (boardPosition.equals(pos)) {
                    return m.getKey();
                }
            }
        }
        // }
        return ' ';
    }


    @Override
    public boolean isPlayerAtPos(BoardPosition pos, char player) {
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
     * getNumToWin = 5 that means it takes 5 consecutive vertical horizontal or diagonal marks
     * to win the game
     * @pre: none
     * @post: getNumToWin() = numToWin
     */
    @Override
    public int getNumToWin() {
        return numToWin;
    }

}
