using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour {
    int min;
    int max;
    int guess;
    void Start () {
        welcomeScreen(); 
	}
	void welcomeScreen()
    {
        min = 0;
        max = 1000;
        guess = 500;
        Debug.Log("Guess a number between " + max + " and " + min);
        Debug.Log("Press 1 for Higher, 2 for Lower and Enter for correct!  ");
        max++;

    }
	void Update () {
        

        if(Input.GetKeyDown(KeyCode.UpArrow))
        {
            min = guess; 
            nextGuess(); 
        }
        else if (Input.GetKeyDown(KeyCode.DownArrow))
        {
            max = guess;
            nextGuess();
        }
		else if (Input.GetKeyDown(KeyCode.Return))
        {
            Debug.Log("Im brilliant");
                welcomeScreen();
        }
	}
    void nextGuess()
    {
        guess = (max + min) / 2;
        Debug.Log("Is your number " + guess); 
    }
}
