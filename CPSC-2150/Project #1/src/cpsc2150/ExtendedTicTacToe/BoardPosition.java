package cpsc2150.ExtendedTicTacToe;

public class BoardPosition {

    private int row;
    private int column;

    /* @pre: row > 0 and column > 0
     * @post: row = row
     *        column = column */
    BoardPosition(int row, int column) {
        this.row = row;
        this.column = column;
    }

    /* @pre: none
     * @post: row > 0
     * getRow = row */
    public int getRow() {
        return row;
    }

    /* @pre: none
     * @post: column 0
     * getColumn = column */
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
