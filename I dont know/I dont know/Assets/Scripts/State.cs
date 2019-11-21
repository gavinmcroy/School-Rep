using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "State")]
public class State : ScriptableObject
{
    [TextArea(24, 10)] [SerializeField] private string storyText;
    [SerializeField] private State[] nextStates;

    public string GetStateStory()
    {
        return storyText;
    }

    public State[] GetNextState()
    {
        return nextStates;
    }

    public int GetStateSize()
    {
        return nextStates.Length;
    }
}