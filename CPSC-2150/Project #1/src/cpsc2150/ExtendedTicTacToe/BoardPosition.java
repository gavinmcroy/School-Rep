package cpsc2150.ExtendedTicTacToe;

public class BoardPosition {

    /**
     * @invarient
     */
    private int row;

    /**
     * @invarient
     */
    private int column;

    /* TODO IMPLEMENT CONTRACT */
    /**
     * @pre: row > 0 and row < 8
     *      column > 0 and column < 8
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
     * @post: row > 0 and row < 8
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
     * @post: column > 0 and column < 8
     * getColumn = column
     */
    public int getColumn() {
        return column;
    }

    /**
     * IMPLEMENT
     */
    @Override
    public String toString() {
        return super.toString();
    }

    /**
     * IMPLEMENT
     */
    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }
}
