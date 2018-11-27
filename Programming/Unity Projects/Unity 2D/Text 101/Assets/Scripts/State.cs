using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "State")]

public class State : ScriptableObject {

    [TextArea(14,10)][SerializeField] string storyText;
    [SerializeField] State[] nextStates;

    public string getStateStory()
    {
        return storyText; 
    }
    public State[] getNextState()
    {
        return nextStates; 
    }
}
