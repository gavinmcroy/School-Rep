package cpsc2150.ExtendedTicTacToe;

public abstract class AbsGameBoard implements IGameBoard {

    /**
     * TODO Clean up toString()
     * returns the board array formatted as a tic tac toe board 8x8 with lined boundaries
     *
     * @return returns the a string containing a formatted board that shows all the current plays on the board
     * @pre: none
     * @post: toString = [gameBoard formatted]
     */
    @Override
    public String toString() {
        StringBuilder formatted = new StringBuilder("");
        formatted.append(" ");
        for (int i = 0; i < getNumRows(); i++) {
            formatted.append(" ").append(i);
        }
        formatted.append("\n");
        for (int i = 0; i < getNumRows(); i++) {
            formatted.append(i);
            for (int j = 0; j < getNumColumns(); j++) {
                formatted.append("|").append(whatsAtPos(new BoardPosition(i, j)));
            }
            formatted.append("|");
            formatted.append("\n");
        }
        return formatted.toString();
    }
}
