using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "BIG GAV! ")]
public class Test2 : ScriptableObject {
    [SerializeField] int[] x;
    // Use this for initialization
    void Start () {
        Debug.Log("Hello 2 "); 
        
}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            Debug.Log("A Key was Pressed! ");    
        }
	}
}
