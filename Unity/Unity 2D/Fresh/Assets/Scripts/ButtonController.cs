using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class ButtonController : MonoBehaviour
{
    [SerializeField] private GameObject loadingImage;

    public void OnApplicationStart(int sceneIndex)
    {
        loadingImage.SetActive(true);
        SceneManager.LoadScene(sceneIndex);
    }

    public void OnApplicationQuit()
    {
        Application.Quit();
    }
}
