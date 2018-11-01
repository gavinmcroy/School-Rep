using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ball : MonoBehaviour {
    //---Configuration Paramaters; 
    [SerializeField] Paddle paddle1;
    [SerializeField] float velocityX;
    [SerializeField] float velocityY;
    [SerializeField] AudioClip[] ballSounds;

    //---States
    bool hasStarted = false;
    Vector2 paddleToBall;

    //---Cached Component Reference
    AudioSource myAudioSource;

	// Use this for initialization
	void Start ()
    {
           //---Keeps the y cordinate of the ball but updates the x cordinate
        paddleToBall = transform.position - paddle1.transform.position;
        myAudioSource = GetComponent<AudioSource>();
    }
	
	// Update is called once per frame
	void Update ()
    {
        //--If it hasnt started lock the ball and launch on mouse click. If launched both functions are disabled. 
        if (!hasStarted)
        {
            lockBallToPaddle();
            LaunchOnClick();
        }
    }

    private void LaunchOnClick()
    {
        if (Input.GetMouseButtonDown(0))
        {
            hasStarted = true;
            GetComponent<Rigidbody2D>().velocity = new Vector2 (velocityX,velocityY);
        }
    }

    private void lockBallToPaddle()
    {
        //---Stores the paddles x and y position
        Vector2 paddlePosition = new Vector2(paddle1.transform.position.x, paddle1.transform.position.y);
        //---Assigns the balls X,Y to the paddles position plus the balls position so it updates the x and keeps the y
        transform.position = paddlePosition + paddleToBall;
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (hasStarted)
        {
            AudioClip clip = ballSounds[UnityEngine.Random.Range(0, ballSounds.Length)];
            
            myAudioSource.PlayOneShot(clip);
        }
    }
}
