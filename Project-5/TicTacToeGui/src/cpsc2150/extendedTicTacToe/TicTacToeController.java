package cpsc2150.extendedTicTacToe;

import java.util.Hashtable;

/**
 * The TicTacToe controller class will handle communication between our TicTacToeView and our Model (IGameBoard and BoardPosition)
 * <p>
 * This is where you will write code
 * <p>
 * You will need to include your BoardPosition class, the IGameBoard interface
 * and the implementations from previous homeworks
 * If your code was correct you will not need to make any changes to your IGameBoard classes
 */
public class TicTacToeController {


    //---Default Players
    final char[] twoDefaultPlayers = {'X', 'O'};
    //--- Keeps track of active players
    private static final Hashtable<Integer, Character> hashTable = new Hashtable<>();
    //--- Keeps track of active player by indexing into the hashTable
    private static int currentPlayer = 0;
    //--- our current game that is being played
    private IGameBoard curGame;
    //--- Number of players in the game
    private int numPlayers;
    //--- The screen that provides our view
    private TicTacToeView screen;
    public static final int MAX_PLAYERS = 10;

    //--- Initiates the game over process if true
    private boolean gameOver;

    /**
     * @param model the board implementation
     * @param view  the screen that is shown
     * @param np    The number of players for the game
     * @post the controller will respond to actions on the view using the model.
     */
    public TicTacToeController(IGameBoard model, TicTacToeView view, int np) {
        this.curGame = model;
        this.screen = view;
        this.numPlayers = np;
        gameOver = false;

        // Some code is needed here.
        if (np > MAX_PLAYERS) {
            numPlayers = MAX_PLAYERS;
        }

        setPlayersUp();
    }

    /**
     * @param row the row of the activated button
     * @param col the column of the activated button
     * @pre row and col are in the bounds of the game represented by the view
     * @post The button pressed will show the right token and check if a player has won.
     */
    public void processButtonClick(int row, int col) {
        if (gameOver) {
            newGame();
            gameOver = false;
        }

        if (curGame.checkSpace(new BoardPosition(row, col))) {
            curGame.placeMarker(new BoardPosition(row, col), hashTable.get(currentPlayer));
            screen.setMarker(row, col, hashTable.get(currentPlayer));
        } else {
            screen.setMessage("Position is already taken");
        }
        if (curGame.checkForDraw()) {
            gameOver = true;
            screen.setMessage("Draw");
        } else if (curGame.checkForWinner(new BoardPosition(row, col))) {
            gameOver = true;
            screen.setMessage(hashTable.get(currentPlayer) + " is the Winner");
        }

        //--- So we don't change the winners message with the current players turn
        if (!gameOver) {
            changeTurns();
            screen.setMessage("It is " + hashTable.get(currentPlayer) + "'s Turn");
        }
    }

    private void newGame() {
        // You do not need to make any changes to this code.
        screen.dispose();
        GameSetupScreen screen = new GameSetupScreen();
        GameSetupController controller = new GameSetupController(screen);
        screen.registerObserver(controller);
    }

    /**
     * Handles changing the turns to different players and cycles through all active players before wrapping
     * back to the first player once all players have gone
     *
     * @pre none
     * @post currentPlayers = currentPlayers + 1  || currentPlayer = 0 iff(currentPlayers > hashTable.size();
     */
    private static void changeTurns() {
        currentPlayer++;
        if (currentPlayer == hashTable.size()) {
            currentPlayer = 0;
        }
    }

    private void setPlayersUp() {
        char startLetter = 'A';
        char endLetter = 'Z';
        //---We are adding two default players, so players 0 and 1 are taken so if there are more than 2 there
        // cant be 0 or 1
        int randomizePlayerAfterXAndO = 2;
        hashTable.put(0, twoDefaultPlayers[0]);
        hashTable.put(1, twoDefaultPlayers[1]);

        for (int i = 0; i < numPlayers - randomizePlayerAfterXAndO; i++) {
            char randomASCII = (char) ((Math.random() * (endLetter - startLetter)) + startLetter);
            while (hashTable.containsValue(randomASCII)) {
                randomASCII = (char) ((Math.random() * (endLetter - startLetter)) + startLetter);
            }
            hashTable.put(i + randomizePlayerAfterXAndO, randomASCII);
        }
    }
}