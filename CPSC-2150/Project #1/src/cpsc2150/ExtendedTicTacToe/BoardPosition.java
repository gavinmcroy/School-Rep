package cpsc2150.ExtendedTicTacToe;

public class BoardPosition {

    /**
     * @invarient 0 < row <= 8
     */
    private int row;

    /**
     * @invarient 0 < column <= 8
     */
    private int column;

    /* TODO IMPLEMENT CONTRACT */

    /**
     * @pre: 0 < row <= 8
     * 0 < column <= 8
     * @post: row = row
     * column = column
     */
    BoardPosition(int row, int column) {
        this.row = row;
        this.column = column;
    }

    /**
     * Returns the current value of row
     *
     * @return returns value of row
     * @pre: none
     * @post: 0 < row <= 8
     * getRow = row
     */
    public int getRow() {
        return row;
    }

    /**
     * Returns the current value of column
     *
     * @return returns the value of column
     * @pre: none
     * @post: 0 < column <= 8
     * getColumn = column
     */
    public int getColumn() {
        return column;
    }

    /*TODO ---------------------------------Implement Post and Pre---------------------------------- TODO */


    /**
     * returns a formatted string for (row, column)
     *
     * @return returns a formatted string in the structure of (row,column)
     * @pre: none
     * @post:
     */
    @Override
    public String toString() {
        return super.toString();
    }

    /**
     * @return returns true if the positions object
     * @pre: obj = #obj instanceof(BoardPosition)
     * @post: iff()
     */
    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }
}
