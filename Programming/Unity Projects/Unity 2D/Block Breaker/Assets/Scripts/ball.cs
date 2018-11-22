using UnityEngine;

public class ball : MonoBehaviour {
    //---Configuration Paramaters; 
    [SerializeField] Paddle paddle1;
    [SerializeField] float velocityX;
    [SerializeField] float velocityY;
    [SerializeField] AudioClip[] ballSounds;
    [SerializeField] float randomFactor = .2f;

    //---States
    bool hasStarted = false;
    Vector2 paddleToBall;

    //---Cached Component Reference
    Rigidbody2D myRigidBody2D;
    AudioSource myAudioSource;

	// Use this for initialization
	void Start ()
    {
        //---Keeps the y cordinate of the ball but updates the x cordinate
        paddleToBall = transform.position - paddle1.transform.position;
        myAudioSource = GetComponent<AudioSource>();
        myRigidBody2D = GetComponent<Rigidbody2D>();
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
            myRigidBody2D.velocity = new Vector2 (velocityX,velocityY);
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
        Vector2 velocityTweek = new Vector2
            (Random.Range(0f, randomFactor),
             Random.Range(0f, randomFactor)); 
        if (hasStarted)
        {
            AudioClip clip = ballSounds[UnityEngine.Random.Range(0, ballSounds.Length)];
            myAudioSource.PlayOneShot(clip);
            myRigidBody2D.velocity += velocityTweek; 
        }
    }
}
