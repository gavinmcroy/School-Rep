package cpsc2150.ExtendedTicTacToe;

import org.junit.Test;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;

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

    private char[][] generateBoard(int row, int column) {
        char[][] tmpBoard = new char[row][column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                tmpBoard[i][j] = ' ';
            }
        }
        return tmpBoard;
    }

    /* CONSTRUCTOR TEST CASES */
    /* 1. */
    @Test
    public void constructorTestAssignmentMin() {
        testGameBoard = myFactory(3, 3, 3);
        assertTrue(testGameBoard.getNumRows() == 3 && testGameBoard.getNumColumns() == 3
                && testGameBoard.getNumToWin() == 3);
    }

    /* 2. */
    @Test
    public void constructorTestAssignmentMax() {
        testGameBoard = myFactory(100, 100, 25);

        assertTrue(testGameBoard.getNumRows() == 100 && testGameBoard.getNumColumns() == 100
                && testGameBoard.getNumToWin() == 25);
    }

    /* 3. */
    @Test
    public void constructorTestAssignmentNormal() {
        testGameBoard = myFactory(8, 8, 4);

        assertTrue(testGameBoard.getNumRows() == 8 && testGameBoard.getNumColumns() == 8
                && testGameBoard.getNumToWin() == 4);
    }
    /* CONSTRUCTOR TEST CASES */


    /* placeMarker TEST CASES */
    /* 1. */
    @Test
    public void placeMarkerOnEmptyBoard() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        testGameBoard.placeMarker(new BoardPosition(2, 2), 'X');
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[2][2] = 'X';
        String formatted = formatInput(tmpBoard, row, col);
        assertEquals(formatted, testGameBoard.toString());

    }

    /* 2. */
    @Test
    public void placeMarkerTopLeft() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);

        testGameBoard.placeMarker(new BoardPosition(2, 2), 'X');
        testGameBoard.placeMarker(new BoardPosition(0, 0), 'X');
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[2][2] = 'X';
        tmpBoard[0][0] = 'X';
        String formatted = formatInput(tmpBoard, row, col);
        assertEquals(formatted, testGameBoard.toString());
    }

    /* 3. */
    @Test
    public void placeMarkerBottomRight() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        testGameBoard.placeMarker(new BoardPosition(2, 2), 'X');
        testGameBoard.placeMarker(new BoardPosition(7, 7), 'X');
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[2][2] = 'X';
        tmpBoard[7][7] = 'X';
        String formatted = formatInput(tmpBoard, row, col);
        assertEquals(formatted, testGameBoard.toString());
    }

    /* 4. */
    @Test
    public void placeMarkerOnRowBoundary() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        testGameBoard.placeMarker(new BoardPosition(2, 2), 'X');
        testGameBoard.placeMarker(new BoardPosition(7, 0), 'X');
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[2][2] = 'X';
        tmpBoard[7][0] = 'X';
        String formatted = formatInput(tmpBoard, row, col);
        assertEquals(formatted, testGameBoard.toString());
    }

    /* 5. */
    @Test
    public void placeMarkerOnColumnBoundary() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        testGameBoard.placeMarker(new BoardPosition(2, 2), 'X');
        testGameBoard.placeMarker(new BoardPosition(0, 7), 'X');
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[2][2] = 'X';
        tmpBoard[0][7] = 'X';
        String formatted = formatInput(tmpBoard, row, col);
        assertEquals(formatted, testGameBoard.toString());
    }
    /* placeMarker TEST CASES */


    /* whatsAtPos TEST CASES*/
    /* 1. */
    @Test
    public void whatsAtPosOnEmptyBoard() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);

        assertEquals(' ', testGameBoard.whatsAtPos(new BoardPosition(4, 4)));

    }

    /* 2. */
    @Test
    public void whatsAtPosOnMarkedTopLeft() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[0][0] = 'X';
        testGameBoard.placeMarker(new BoardPosition(0, 0), 'X');

        assertEquals('X', testGameBoard.whatsAtPos(new BoardPosition(0, 0)));

    }

    /* 3. */
    @Test
    public void whatsAtPosOnMarkedBottomRight() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[7][7] = 'X';
        testGameBoard.placeMarker(new BoardPosition(7, 7), 'X');

        assertEquals('X', testGameBoard.whatsAtPos(new BoardPosition(7, 7)));

    }

    /* 4. */
    @Test
    public void whatsAtPosOnMarkedBottomLeft() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[7][0] = 'X';
        testGameBoard.placeMarker(new BoardPosition(7, 0), 'X');

        assertEquals('X', testGameBoard.whatsAtPos(new BoardPosition(7, 0)));

    }

    /* 5. */
    @Test
    public void whatsAtPosOnMarkedTopRight() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        tmpBoard[0][7] = 'X';
        testGameBoard.placeMarker(new BoardPosition(0, 7), 'X');

        assertEquals('X', testGameBoard.whatsAtPos(new BoardPosition(0, 7)));

    }
    /* whatsAtPos TEST CASES*/


    /* checkSpace TEST CASES */
    /* 1. */
    @Test
    public void checkSpacePlacementEmptyBoard() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);

        assertTrue(testGameBoard.checkSpace(new BoardPosition(0, 0)));
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
