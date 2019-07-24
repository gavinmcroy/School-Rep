using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class GameController : MonoBehaviour
{
    private static int score = 0;
    [SerializeField] TextMeshProUGUI text;

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


}
