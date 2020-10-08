package cpsc2150.ExtendedTicTacToe;

/* Class complete: */
public class BoardPosition {

    /**
     * @invarient 0 < row <= 8
     */
    private int row;

    /**
     * @invarient 0 < column <= 8
     */
    private int column;

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


    /**
     * returns a formatted string for (row, column)
     *
     * @return returns a formatted string in the structure of (row,column)
     * @pre: none
     * @post: toString = 'row,column'
     */
    @Override
    public String toString() {
        return row + "," + column;
    }

    /**
     * First checks if the object passed in equals the type of object expected. If not then it returns false
     * else if it does than it checks to see if the row and columns are equal by converting them both to strings and
     * checking for equality. If there equal return true, else return false
     *
     * @return returns true if the positions object
     * @pre: obj = #obj instanceof(BoardPosition)
     * @post: equals = true iff(row = obj.row and column = obj.column)
     */
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof BoardPosition) {
            return obj.toString().equals(toString());
        } else {
            return false;
        }
    }
}
