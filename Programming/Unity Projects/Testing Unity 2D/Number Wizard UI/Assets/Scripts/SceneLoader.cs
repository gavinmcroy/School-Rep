using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement; 

public class SceneLoader : MonoBehaviour {
    
    public void LoadNextScene()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(currentSceneIndex + 1);
    }
    public void restartScene()
    {
        //---Scene.Manger.LoadScene(0); 
        int resetCurrentSceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(resetCurrentSceneIndex - resetCurrentSceneIndex); 
    }
    public void OnApplicationQuit()
    {
        Application.Quit(); 
    }
}
