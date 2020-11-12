package cpsc2150.ExtendedTicTacToe;

import org.junit.Test;

public class TestGameBoard {

    IGameBoard testGameBoard;

    IGameBoard myFactory(int row, int columns, int numToWin) {
        return new GameBoard(row, columns, numToWin);
    }

    @Test
    public void constructor1() {
        testGameBoard = myFactory(8, 8, 4);

    }

    @Test
    public void constructor2() {
        testGameBoard = myFactory(10, 9, 5);
    }

    @Test
    public void constructor3() {
        testGameBoard = myFactory(10, 9, 5);
    }


    @Test
    public void checkSpaceTest1() {
        System.out.println("Function called");
    }

}
