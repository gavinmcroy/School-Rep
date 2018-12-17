using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro; 

public class NumberWizardScript : MonoBehaviour
{
    [SerializeField] int max = 1000;
    [SerializeField] int min = 0;
    [SerializeField] TextMeshProUGUI guessText; 
     int guess;

    // Use this for initialization
    void Start()
    {
        startGame(); 
    }
    public void startGame()
    {
        //---guess = Random.Range(1, 1001);
        nextGuess(); 
        max = max + 1;
    }
    public void OnPressHigher()
    {
        min = guess+1;
        nextGuess();
    }
    public void OnPressLower()
    {
        max = guess-1;
        nextGuess();     
    }
    //---Runs next Guess
     void nextGuess()
    {
        //guess = (max + min) / 2;
        guess = Random.Range(min, max+1); 
        guessText.text = guess.ToString();
    }



} 