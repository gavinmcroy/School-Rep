
using UnityEngine;
using TMPro;

public class GameStatus : MonoBehaviour {

    //---Config Paramaters
    [Range(0.1f,10f)][SerializeField] float gameSpeed = 1f;
    [SerializeField] int pointsPerBlockDestroyed = 83;
    [SerializeField] bool isAutoPlayedEnabled;
    //---State Variables
    [SerializeField] int currentScores = 0;
    [SerializeField] TextMeshProUGUI scoreText;

    //---Singleton 
    private void Awake()
    {
        int gameStatusCount = FindObjectsOfType<GameStatus>().Length;
        if (gameStatusCount>1)
        {  
            //---Destroy is called last and for a moment in the frame , there are two. Functions rely on being one and this causes score to not update.
            gameObject.SetActive(false); 
            Destroy(gameObject);
        }
        else
        {
            Debug.Log("Object is not being destroyed! ");
            DontDestroyOnLoad(gameObject); 
        }
    }

    // Use this for initialization
    private void Start ()
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
        Debug.Log(currentScores);
        scoreText.text = currentScores.ToString();
    }
    public void ResetScore()
    {
        Debug.Log("reset Score was called");
        Destroy(gameObject);
        currentScores = 0;
    }
    public bool IsAutoPlayedEnabled()
    {
        return isAutoPlayedEnabled; 
    }

    }
 

