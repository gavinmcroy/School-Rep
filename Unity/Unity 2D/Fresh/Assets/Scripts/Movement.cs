using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField] private int health = 2;
    [SerializeField] private float moveSpeed = 3;
    private float lastPosition;
    private float speed;
    private float direction = 1;
    Rigidbody2D rigidBody2D;
    Animator animator;
    Vector2 movement;

    void Start()
    {
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
    }

    void FixedUpdate()
    {
        if (animator.GetCurrentAnimatorStateInfo(0).IsName("Death"))
        {

        }
        else
        {
            Move();
            AnimationController();
        }
    }
    
    private void OnCollisionEnter2D(Collision2D collision)
    {
        Debug.Log("Collision with " + collision.gameObject);
    }

    private void Move()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        movement = new Vector2(horizontal, transform.position.y);

        GetSpeed();
        GetDirection();

        Vector2 position = rigidBody2D.position;
        position.x += movement.x * moveSpeed * Time.deltaTime;
        rigidBody2D.MovePosition(position);
    }

    private void Attack()
    {
        if (Input.GetKeyDown(KeyCode.C))
        {

        }
    }

    private void AnimationController()
    {
        animator.SetFloat("MoveX", movement.x);
        animator.SetFloat("Speed", Mathf.Abs(speed));
        animator.SetInteger("Health", health);
        animator.SetFloat("Direction", direction);
    }

    private void GetSpeed()
    {
        speed = transform.position.x - lastPosition;
        lastPosition = transform.position.x;
    }

    private void GetDirection()
    {
        //---Padding for innacuracies
        if (speed > .045)
        {
            direction = 1;
        }
        if (speed < -.045)
        {
            direction = -1;
        }
    }
}
