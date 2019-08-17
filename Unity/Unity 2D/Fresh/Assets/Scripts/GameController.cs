using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class GameController : MonoBehaviour
{
    private static int score;
    [SerializeField] TextMeshProUGUI text;
    public static GameController instance;

    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Application.Quit();
        }
    }

    void Start()
    {
        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = 144;
        text.text = score.ToString();
    }

    public void AddScore(int scoreAmount)
    {
        score += scoreAmount;
        text.text = score.ToString();
    }

    public void RemoveScore(int removeAmount)
    {
        score -= removeAmount;
        text.text = score.ToString();
    }

    public int GetScore()
    {
        return score;
    }


}
