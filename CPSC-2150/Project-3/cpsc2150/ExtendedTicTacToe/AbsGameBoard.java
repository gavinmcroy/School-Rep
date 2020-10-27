package cpsc2150.ExtendedTicTacToe;

public abstract class AbsGameBoard implements IGameBoard {

    /**
     * returns the board array formatted as a tic tac toe board 8x8 with lined boundaries
     *
     * @return returns the a string containing a formatted board that shows all the current plays on the board
     * @pre: none
     * @post: toString = [gameBoard formatted]
     */
    @Override
    public String toString() {
        StringBuilder formatted = new StringBuilder();
        /* Moves top row of characters over by " " */
        formatted.append("   ");
        for (int i = 0; i < getNumColumns(); i++) {
            formatted.append("  ").append(i);
        }
        formatted.append("\n");
        /* Builds 2D grind for tic tac toe board */
        for (int i = 0; i < getNumRows(); i++) {
            if(i < 10){
                formatted.append(" ").append(i);
            }else{
                formatted.append(i);
            }

            for (int j = 0; j < getNumColumns(); j++) {
                formatted.append(" |").append(whatsAtPos(new BoardPosition(i, j)));
            }
            formatted.append(" |");
            formatted.append("\n");
        }
        return formatted.toString();
    }
}
