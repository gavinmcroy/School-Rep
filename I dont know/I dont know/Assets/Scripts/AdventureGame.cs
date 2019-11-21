using TMPro;
using UnityEngine;

public class AdventureGame : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI textMeshPro;
    [SerializeField] private State startingState;

    private State _state;

    private void Start()
    {
        _state = startingState;
        textMeshPro.text = _state.GetStateStory();
    }

    private void Update()
    {
        ManageState();
    }

    private void ManageState()
    {
        var nextStates = _state.GetNextState();
        var size = _state.GetStateSize();
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            _state = nextStates[0];
        }
        else if (Input.GetKeyDown(KeyCode.Alpha2) && size > 1)
        {
            _state = nextStates[1];
        }

        textMeshPro.text = _state.GetStateStory();
    }
}