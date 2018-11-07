 using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Paddle : MonoBehaviour {
    //---Configuration Paramater
    [SerializeField] float screenWidthInUnits = 16f;
    [SerializeField] float minX = 1f;
    [SerializeField] float maxX = 15f;
    //---Use this for initialization
    void Start ()
    {
    }
	
	void Update ()
    {
        //---Records Mouse X position and converts it into Unity Units
        float mousePosition = Input.mousePosition.x / Screen.width * screenWidthInUnits;
        //---Declars a 2D vector to equal the x mouse position and a y to remain where it is
        Vector2 paddlePosition = new Vector2(transform.position.x, transform.position.y);
        //---Limits paddles position to stay in screen 
        paddlePosition.x = Mathf.Clamp(mousePosition, minX, maxX);
        //---updates paddle sprite position to equal the x position of mouse
        transform.position = paddlePosition; 
	}
}
