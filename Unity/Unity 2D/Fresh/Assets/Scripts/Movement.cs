using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField] private float moveSpeed;
    Rigidbody2D rigidBody2D;
    

    void Start()
    {
        rigidBody2D = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        PlayerMovement();
    }

    private void PlayerMovement()
    {
        Vector2 movement = new Vector2(Input.GetAxisRaw("Horizontal"), Input.GetAxisRaw("Vertical"));

        if (Mathf.Pow(movement.x, 2) + Mathf.Pow(movement.y, 2) > 1)
        {
            movement.Normalize();
        }

        Vector2 position = rigidBody2D.position;

        position += movement * moveSpeed * Time.deltaTime;
        rigidBody2D.MovePosition(position);
    }
}
