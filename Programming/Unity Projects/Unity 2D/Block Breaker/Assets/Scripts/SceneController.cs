using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class SceneController : MonoBehaviour {
    GameStatus resetScore;



    private void Start()
    {
        resetScore = FindObjectOfType<GameStatus>(); 
    }

    public void nextScene()
    {
        int sceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(sceneIndex + 1);
    }
    public void QuitGame()
    {
        Application.Quit(); 
    }
    public void RestartScene()
    {
        resetScore.ResetScore(); 
        SceneManager.LoadScene(0); 
    }
}
