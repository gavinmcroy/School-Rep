 using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Paddle : MonoBehaviour {
    //---Configuration Paramater
    [SerializeField] float screenWidthInUnits = 16f;
    [SerializeField] float minX = 1f;
    [SerializeField] float maxX = 15f;

    //---Cached Reference
    GameStatus gameStatus;
    ball ball;
    //---Use this for initialization
    void Start ()
    {
        gameStatus = FindObjectOfType<GameStatus>();
        ball = FindObjectOfType<ball>(); 
    }
	
	void Update ()
    {
        MousePositionController();
    }

    private void MousePositionController()
    {
        //---Declars a 2D vector to equal the x mouse position and a y to remain where it is
        Vector2 paddlePosition = new Vector2(transform.position.x, transform.position.y);
        //---Limits paddles position to stay in screen 
        paddlePosition.x = Mathf.Clamp(GetXPos(), minX, maxX);
        //---updates paddle sprite position to equal the x position of mouse
        transform.position = paddlePosition;
    }
    private float GetXPos()
    {
        if (gameStatus.IsAutoPlayedEnabled())
        {
            return ball.transform.position.x;
        }
        else
        {
            //---Records Mouse X position and converts it into Unity Units
            return Input.mousePosition.x / Screen.width * screenWidthInUnits;
        }
    }
}
