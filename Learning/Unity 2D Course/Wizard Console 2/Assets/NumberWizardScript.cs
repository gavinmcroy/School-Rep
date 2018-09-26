using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NumberWizardScript : MonoBehaviour {
    int max;
    int min;
    int guess;

    // Use this for initialization
    void Start () {
        startGame();

    }
    void startGame()
    {
        max = 1000;
        min = 1;
        guess = 500;
        Debug.Log("Welcome to number wizard  ");
        Debug.Log("Pick a number between these 2 restrictions ");
        Debug.Log("Lowest Number you can pick is:  " + min);
        Debug.Log("Highest Number you can pick is: " + max);
        Debug.Log("Tell me if your Number is higher or lower than: " + guess);
        Debug.Log("Push up = higher , Push down = lower , Push enter = Correct");
        max++;
    }
	
	// Update is called once per frame
	void Update (){
        //---Higher
        if (Input.GetKeyUp(KeyCode.UpArrow)) {
            min = guess;
            nextGuess();
        }
        //---Lower 
        else if (Input.GetKeyUp(KeyCode.DownArrow)){
            max = guess;
            nextGuess();
        }
        //---Correct
        else if (Input.GetKeyUp(KeyCode.Return)){
            Debug.Log("Im Brilliant..lol ");
            startGame(); 
        }
    }
    void nextGuess()
    {
        guess = (max + min) / 2;
        Debug.Log("Is it higher or lower than: " + guess);
    }
}
