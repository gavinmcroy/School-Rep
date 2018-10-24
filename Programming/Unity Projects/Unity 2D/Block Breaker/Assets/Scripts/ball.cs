using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ball : MonoBehaviour {
    //---Configuration Paramaters; 
    [SerializeField] Paddle paddle1;
    //---state
    Vector2 paddleToBall;


	// Use this for initialization
	void Start ()
    {
        paddleToBall = transform.position - paddle1.transform.position; 
	}
	
	// Update is called once per frame
	void Update ()
    {
        Vector2 paddlePosition = new Vector2(paddle1.transform.position.x, paddle1.transform.position.y);
        transform.position = paddlePosition + paddleToBall;
	}
}
