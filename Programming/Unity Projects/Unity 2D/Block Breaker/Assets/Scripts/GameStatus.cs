using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;
public class GameStatus : MonoBehaviour {

    //---Config Paramaters
    [Range(0.1f,10f)][SerializeField] float gameSpeed = 1f;
    [SerializeField] int pointsPerBlockDestroyed = 83;
    //---State Variables
    [SerializeField] int currentScores = 0;
    [SerializeField] TextMeshProUGUI scoreText;

    //---Singleton 
    private void Awake()
    {
        int gameStatusCount = FindObjectsOfType<GameStatus>().Length;
        if (gameStatusCount>1)
        {
            Destroy(gameObject);
        }
        else
        {
            DontDestroyOnLoad(gameObject); 
        }
    }

    // Use this for initialization
    void Start ()
    {
        scoreText.text = currentScores.ToString();
    }
	
	// Update is called once per frame
	void Update () {
        Time.timeScale = gameSpeed;
	}
    public void AddToScore()
    {
        currentScores += pointsPerBlockDestroyed;
        scoreText.text = currentScores.ToString();
    }
    public void ResetScore()
    {
        Destroy(gameObject);
        currentScores = 0;
    }
    }
 

