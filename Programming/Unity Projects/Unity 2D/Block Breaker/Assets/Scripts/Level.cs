using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level : MonoBehaviour {
    
    //---Serialize for Debugging
    [SerializeField] int breakableBlocks;

    //---Cached Reference
    SceneController sceneLoader;

    private void Start()
    {
        sceneLoader = FindObjectOfType<SceneController>(); 
    }

    public void CountBreakableBlocks()
    {
        breakableBlocks++;
    }
    public void BlockDestroyed()
    {
        breakableBlocks--;
        if (breakableBlocks <= 0)
        {
            sceneLoader.nextScene();
        }
    }
}
