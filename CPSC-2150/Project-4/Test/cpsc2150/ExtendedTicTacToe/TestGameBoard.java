package cpsc2150.ExtendedTicTacToe;

import org.junit.Test;

import java.util.Random;

import static org.junit.Assert.*;

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

        assertTrue(testGameBoard.checkSpace(new BoardPosition(4, 4)));
    }

    @Test
    public void checkSpacePlacementOneAwayFromFullBoard() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);
        boolean inverse = false;
        for (int i = 0; i < row; i++) {
            if (i == 4) {
                inverse = true;
            } else {
                inverse = false;
            }
            for (int j = 0; j < col; j++) {
                if (i == 4 && j == 4) {
                    continue;
                }
                if (j % 2 == 0) {
                    if (inverse) {
                        tmpBoard[i][j] = 'X';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
                    } else {
                        tmpBoard[i][j] = 'O';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'O');
                    }
                } else if (j % 2 == 1) {
                    if (inverse) {
                        tmpBoard[i][j] = 'O';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'O');
                    } else {
                        tmpBoard[i][j] = 'X';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
                    }
                }
            }
        }
        String formatted = formatInput(tmpBoard, row, col);
        //System.out.println(formatted);
        assertTrue(testGameBoard.checkSpace(new BoardPosition(4, 4)) &&
                formatted.equals(testGameBoard.toString()));
    }


    @Test
    public void checkSpacePlacementNormalBoard() {
        int row = 8;
        int col = 8;
        int numToWin = 4;
        Random rand = new Random(3);

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);
        boolean inverse = false;
        for (int i = 0; i < row; i++) {

            if (i == 4) {
                inverse = true;
            } else {
                inverse = false;
            }
            for (int j = 0; j < col; j++) {
                boolean randomVal = rand.nextBoolean();
                if (i == 4 && j == 4) {
                    continue;
                }

                if (j % 2 == 0) {
                    if (randomVal) {
                        tmpBoard[i][j] = 'X';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
                    } /*else {
                        tmpBoard[i][j] = 'O';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'O');
                    }*/
                } else {
                    if (randomVal) {
                        tmpBoard[i][j] = 'O';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'O');
                    } else {
                        tmpBoard[i][j] = 'X';
                        testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
                    }
                }
            }
        }
        String formatted = formatInput(tmpBoard, row, col);
        //System.out.println(formatted);
        assertTrue(testGameBoard.checkSpace(new BoardPosition(4, 4)) &&
                formatted.equals(testGameBoard.toString()));
    }
    /* checkSpace TEST CASES */

    /* checkHorizontalWin TEST CASES*/
    /* 1. */
    @Test
    public void checkHorizontalWinPlacedInMiddle() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < 5; i++) {
            tmpBoard[0][i] = 'X';
            testGameBoard.placeMarker(new BoardPosition(0, i), 'X');
        }
        //System.out.println(formatInput(tmpBoard, row, col));
        //System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkHorizontalWin((new BoardPosition(0, 0)), 'X'));

    }

    /* 2. */
    @Test
    public void checkHorizontalWinNoFalsePositive() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < 3; j++) {
                tmpBoard[i][j] = 'X';
                testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 4; j < 7; j++) {
                tmpBoard[i][j] = 'X';
                testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
            }
        }
        //tmpBoard[4][4] = 'X';
        // testGameBoard.placeMarker(new BoardPosition(4,4),'X');
        //  System.out.println(formatInput(tmpBoard, row, col));
        //System.out.println(testGameBoard.toString());
        assertFalse(testGameBoard.checkHorizontalWin((new BoardPosition(0, 0)), 'X'));
    }

    /* 3. */
    @Test
    public void checkHorizontalDetectingProperWin() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < 3; j++) {
                tmpBoard[i][j] = 'X';
                testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 4; j < 7; j++) {
                tmpBoard[i][j] = 'X';
                testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
            }
        }
        tmpBoard[4][7] = 'X';
        testGameBoard.placeMarker(new BoardPosition(4, 7), 'X');
        // System.out.println(formatInput(tmpBoard, row, col));
        // System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkHorizontalWin((new BoardPosition(4, 3)), 'X'));
    }

    /* 4. */
    @Test
    public void checkHorizontalWinWithMixedChars() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < 3; j++) {
                if (i % 2 == 1) {
                    tmpBoard[i][j] = 'X';
                    testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
                } else {
                    tmpBoard[i][j] = 'O';
                    testGameBoard.placeMarker(new BoardPosition(i, j), 'O');
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 4; j < 7; j++) {
                if (i % 2 == 1) {
                    tmpBoard[i][j] = 'X';
                    testGameBoard.placeMarker(new BoardPosition(i, j), 'X');
                } else {
                    tmpBoard[i][j] = 'O';
                    testGameBoard.placeMarker(new BoardPosition(i, j), 'O');
                }
            }
        }
        tmpBoard[4][7] = 'O';
        tmpBoard[4][3] = 'X';
        testGameBoard.placeMarker(new BoardPosition(4, 7), 'O');
        testGameBoard.placeMarker(new BoardPosition(4, 3), 'X');
        // System.out.println(formatInput(tmpBoard, row, col));
        // System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkHorizontalWin((new BoardPosition(4, 7)), 'O'));
    }
    /* checkHorizontalWin TEST CASES*/

    /* checkVerticalWin TEST CASES */
    /* 1. */
    @Test
    public void checkVerticalWinPlacedInMiddle() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < 5; i++) {
            tmpBoard[i][0] = 'X';
            testGameBoard.placeMarker(new BoardPosition(i, 0), 'X');
        }
        //System.out.println(formatInput(tmpBoard, row, col));
        // System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkVerticalWin((new BoardPosition(0, 0)), 'X'));

    }

    /* 2. */
    @Test
    public void checkVerticalWinNoFalsePositive() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < 3; j++) {
                tmpBoard[j][i] = 'X';
                testGameBoard.placeMarker(new BoardPosition(j, i), 'X');
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 4; j < 7; j++) {
                tmpBoard[j][i] = 'X';
                testGameBoard.placeMarker(new BoardPosition(j, i), 'X');
            }
        }
        //tmpBoard[4][4] = 'X';
        // testGameBoard.placeMarker(new BoardPosition(4,4),'X');
        //  System.out.println(formatInput(tmpBoard, row, col));
        //System.out.println(testGameBoard.toString());
        assertFalse(testGameBoard.checkVerticalWin((new BoardPosition(0, 0)), 'X'));
    }

    /* 3. */
    @Test
    public void checkVerticalDetectingProperWin() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < 3; j++) {
                tmpBoard[j][i] = 'X';
                testGameBoard.placeMarker(new BoardPosition(j, i), 'X');
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 4; j < 7; j++) {
                tmpBoard[j][i] = 'X';
                testGameBoard.placeMarker(new BoardPosition(j, i), 'X');
            }
        }
        tmpBoard[7][4] = 'X';
        testGameBoard.placeMarker(new BoardPosition(7, 4), 'X');
        // System.out.println(formatInput(tmpBoard, row, col));
        //System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkVerticalWin((new BoardPosition(7, 4)), 'X'));
    }

    /* 4. */
    @Test
    public void checkVerticalWinWithMixedChars() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < 3; j++) {
                if (i % 2 == 1) {
                    tmpBoard[j][i] = 'X';
                    testGameBoard.placeMarker(new BoardPosition(j, i), 'X');
                } else {
                    tmpBoard[j][i] = 'O';
                    testGameBoard.placeMarker(new BoardPosition(j, i), 'O');
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 4; j < 7; j++) {
                if (i % 2 == 1) {
                    tmpBoard[j][i] = 'X';
                    testGameBoard.placeMarker(new BoardPosition(j, i), 'X');
                } else {
                    tmpBoard[j][i] = 'O';
                    testGameBoard.placeMarker(new BoardPosition(j, i), 'O');
                }
            }
        }
        tmpBoard[7][4] = 'O';
        tmpBoard[3][4] = 'X';
        testGameBoard.placeMarker(new BoardPosition(7, 4), 'O');
        testGameBoard.placeMarker(new BoardPosition(3, 4), 'X');
        // System.out.println(formatInput(tmpBoard, row, col));
        //System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkVerticalWin((new BoardPosition(7, 4)), 'O'));
    }
    /* checkVerticalWin TEST CASES */


    /* checkDiagonalWin TEST CASES*/
    /* 1. */
    @Test
    public void checkDiagonalWinStandardRightDiagonal() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);

        int columnsCount = 0;
        /* Draws right Diagonal through center */
        for (int i = testGameBoard.getNumRows() - 1; i >= 0; i--) {
            tmpBoard[i][columnsCount] = 'X';
            testGameBoard.placeMarker(new BoardPosition(i, columnsCount), 'X');
            columnsCount++;
        }

        //System.out.println(testGameBoard.toString());

        assertTrue(testGameBoard.checkDiagonalWin(new BoardPosition(4, 3), 'X'));


    }

    /* 2. */
    @Test
    public void checkDiagonalWinStandardLeftDiagonal() {
        int row = 8;
        int col = 8;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);
        int columns = 0;
        /* Draws left Diagonal through center */
        for (int i = 0; i < testGameBoard.getNumColumns(); i++) {
            tmpBoard[i][columns] = 'X';
            testGameBoard.placeMarker(new BoardPosition(i, columns), 'X');
            columns++;
        }

        //System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkDiagonalWin(new BoardPosition(4, 4), 'X'));
    }

    /* 3. */
    @Test
    public void checkDiagonalWinOnRightDB(){
        int row = 5;
        int col = 9;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);
        int columns = 0;
        /* Draws left Diagonal through center */
        for (int i = testGameBoard.getNumRows()-1; i >= 0; i--) {
            tmpBoard[i][columns] = 'X';
            testGameBoard.placeMarker(new BoardPosition(i, columns), 'X');
            columns++;
            if(columns==row){
                break;
            }
        }
        //System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkDiagonalWin(new BoardPosition(1,3 ), 'X'));
    }

    /* 4. */
    @Test
    public void checkDiagonalWinOnLeftDB(){
        int row = 5;
        int col = 9;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);
        int columns = 0;
        /* Draws left Diagonal through center */
        for (int i = 0; i < testGameBoard.getNumColumns(); i++) {
            tmpBoard[i][columns] = 'X';
            testGameBoard.placeMarker(new BoardPosition(i, columns), 'X');
            columns++;
            if(columns==row){
                break;
            }
        }

        //System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkDiagonalWin(new BoardPosition(4, 4), 'X'));
    }

    /* 5. */
    @Test
    public void checkDiagonalWinOnRightWithRHigherThanC(){
        int row = 9;
        int col = 5;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);
        int columns = 0;
        /* Draws left Diagonal through center */
        for (int i = testGameBoard.getNumRows()-1; i >= 0; i--) {
            tmpBoard[i][columns] = 'X';
            testGameBoard.placeMarker(new BoardPosition(i, columns), 'X');
            columns++;
            if(columns==col){
                break;
            }
        }
        //System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkDiagonalWin(new BoardPosition(8,0 ), 'X'));
    }

    /* 6. */
    @Test
    public void checkDiagonalWinOnLeftWithRHigherThanC(){
        int row = 9;
        int col = 5;
        int numToWin = 4;

        testGameBoard = myFactory(row, col, numToWin);
        char[][] tmpBoard = generateBoard(row, col);
        int columns = 0;
        /* Draws left Diagonal through center */
        for (int i = 0; i < testGameBoard.getNumColumns(); i++) {
            tmpBoard[i][columns] = 'X';
            testGameBoard.placeMarker(new BoardPosition(i, columns), 'X');
            columns++;
            if(columns==col){
                break;
            }
        }
        System.out.println(testGameBoard.toString());
        assertTrue(testGameBoard.checkDiagonalWin(new BoardPosition(0,0 ), 'X'));
    }


}

