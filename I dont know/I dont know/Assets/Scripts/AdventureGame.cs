using TMPro;
using UnityEngine;

public class AdventureGame : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI textMeshPro;
    
    void Start()
    {
        textMeshPro.text = ("Hello there");
    }

}
