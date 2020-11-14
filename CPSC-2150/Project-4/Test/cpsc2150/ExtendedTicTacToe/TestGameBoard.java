package cpsc2150.ExtendedTicTacToe;

import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class TestGameBoard {

    IGameBoard testGameBoard;

    IGameBoard myFactory(int row, int columns, int numToWin) {
        return new GameBoard(row, columns, numToWin);
    }

    private String formatInput(char[][] input, int row, int col) {
        StringBuilder formatted = new StringBuilder();
        /* Moves top row of characters over by " " */
        formatted.append("   ");
        for (int i = 0; i < col; i++) {
            if (i < 10) {
                formatted.append("  ").append(i);
            } else {
                formatted.append(" ").append(i);
            }
        }
        formatted.append("\n");
        /* Builds 2D grind for tic tac toe board */
        for (int i = 0; i < row; i++) {
            if (i < 10) {
                formatted.append(" ").append(i);
            } else {
                formatted.append(i);
            }

            for (int j = 0; j < col; j++) {
                formatted.append(" |").append(input[i][j]);
            }
            formatted.append(" |");
            formatted.append("\n");
        }
        return formatted.toString();
    }

    /* CONSTRUCTOR TEST CASES */
    @Test
    public void constructorTestAssignmentMin() {
        testGameBoard = myFactory(3, 3, 3);
        assertTrue(testGameBoard.getNumRows() == 3 && testGameBoard.getNumColumns() == 3
                && testGameBoard.getNumToWin() == 3);
    }

    @Test
    public void constructorTestAssignmentMax() {
        testGameBoard = myFactory(100, 100, 25);

        assertTrue(testGameBoard.getNumRows() == 100 && testGameBoard.getNumColumns() == 100
                && testGameBoard.getNumToWin() == 25);
    }

    @Test
    public void constructorTestAssignmentNormal() {
        testGameBoard = myFactory(8, 8, 4);

        assertTrue(testGameBoard.getNumRows() == 8 && testGameBoard.getNumColumns() == 8
                && testGameBoard.getNumToWin() == 4);
    }
    /* CONSTRUCTOR TEST CASES */


    /* placeMarker TEST CASES */
    @Test
    public void placeMarkerOnEmptyBoard() {

    }

    @Test
    public void placeMarkerTopLeft() {

    }

    @Test
    public void placeMarkerOnAlmostFullBoard() {

    }

    @Test
    public void placeMarkerOnColumnBoundary() {

    }

    @Test
    public void placeMarkerOnRowBoundary() {

    }

    /* placeMarker TEST CASES */


    /* checkSpace TEST CASES */
    @Test
    public void checkSpacePlacementEmptyBoard() {
        BoardPosition pos = new BoardPosition(4, 4);
        testGameBoard = myFactory(8, 8, 4);

        assertTrue(testGameBoard.checkSpace(pos));
    }

    @Test
    public void checkSpacePlacementOneAwayFromFullBoard() {
        BoardPosition pos = new BoardPosition(4, 4);
        testGameBoard = myFactory(8, 8, 4);

        /* TODO fill board with productive garbage */

        assertTrue(testGameBoard.checkSpace(pos));
    }

    @Test
    public void checkSpacePlacementNormalBoard() {
        BoardPosition pos = new BoardPosition(4, 4);
        testGameBoard = myFactory(8, 8, 4);

        /* TODO Fill board with productive garbage */

        assertTrue(testGameBoard.checkSpace(pos));
    }
    /* checkSpace TEST CASES */


}
