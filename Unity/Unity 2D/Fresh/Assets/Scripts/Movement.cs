using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField] private float moveSpeed = 3;
    Rigidbody2D rigidBody2D;
    Animator animator;

    private int health = 2;

    void Start()
    {
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
        animator.SetFloat("MoveX", 1f);
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        PlayerMovement();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        health--;
    }

    private void PlayerMovement()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");

        Vector2 movement = new Vector2(horizontal, vertical);
        animator.SetFloat("MoveX",horizontal);
        animator.SetFloat("Speed", movement.magnitude);
        //---Does not work Also Animation Instantly Plays Death Anim
        animator.SetFloat("Health", health);

        if (Mathf.Pow(movement.x, 2) + Mathf.Pow(movement.y, 2) > 1)
        {
            movement.Normalize();
        }

        Vector2 position = rigidBody2D.position;

        position += movement * moveSpeed * Time.deltaTime;
        rigidBody2D.MovePosition(position);
    }
}
