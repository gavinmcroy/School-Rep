using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level : MonoBehaviour {
    //---Serialize for Debugging
    [SerializeField] int breakableBlocks;

    public void CountBreakableBlocks()
    {
        breakableBlocks++;
    }
}
