using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField] private int health = 2;
    [SerializeField] private float moveSpeed = 3;
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
            PlayerMovement();
            AnimationController();
        }
    }
    /*Where I left Off
     *Idle animation may need direction based on players looking direction
     */
    
    private void OnCollisionEnter2D(Collision2D collision)
    {
        health--;
        Debug.Log(health);
        Debug.Log("Collision with " + collision.gameObject);
    }

    private void PlayerMovement()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        movement = new Vector2(horizontal, vertical);

        if (Mathf.Pow(movement.x, 2) + Mathf.Pow(movement.y, 2) > 1)
        {
            movement.Normalize();
        }

        Vector2 position = rigidBody2D.position;

        position += movement * moveSpeed * Time.deltaTime;
        rigidBody2D.MovePosition(position);
    }

    private void AnimationController()
    {
        animator.SetFloat("MoveX", movement.x);
        animator.SetFloat("Speed", movement.magnitude);
        animator.SetInteger("Health", health);
    }
}
