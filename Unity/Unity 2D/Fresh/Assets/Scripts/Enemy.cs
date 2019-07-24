using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Enemy : MonoBehaviour
{
    [SerializeField] private int health = 100;
    [SerializeField] private int moveSpeed = 1;
    [SerializeField] TextMeshProUGUI text;
    Animator animator;
    Movement playerController;
    Rigidbody2D rigidBody2D;
    Rigidbody2D playerPosition;
    private int direction = -1;


    void Awake()
    {
        animator = GetComponent<Animator>();
        playerController = FindObjectOfType<Movement>();
        playerPosition = playerController.GetComponent<Rigidbody2D>();
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator.SetInteger("Health", health);
        text.text = health.ToString();
    }

    void FixedUpdate()
    {
        Follow();   
    }

    public void DestroyObject()
    {
        Destroy(gameObject,3);
    }

    public void DestroyCollision()
    {
        rigidBody2D.gravityScale = 0;
        Destroy(GetComponent<BoxCollider2D>());
    }

    public void DealDamage(int val)
    {
        RaycastHit2D rayCast = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction, 0), .75f, LayerMask.GetMask("Player"));
        if (rayCast.collider != null)
        {
            playerController.TakeDamage(val);
        }
    }

    public void TakeDamage(int damage)
    {
        if (health > 0)
        {
            health -= damage;
            text.text = health.ToString();
            animator.SetInteger("Health", health);
        }
    }

    public void SetMovementSpeed(int speed)
    {
        moveSpeed = speed;
    }

    public void SetDirection(int direction)
    {
        this.direction = direction;
    }

    private void Follow()
    {
        //Vector2 follow = playerController.transform.position - transform.position;
        Vector2 follow = playerPosition.position - rigidBody2D.position;
        animator.SetFloat("Direction", direction);
        if (follow.x < -.5)
        {
            //transform.Translate(Vector2.left * Time.deltaTime * moveSpeed);
            //rigidBody2D.MovePosition(Vector2.left * Time.deltaTime * moveSpeed);
            rigidBody2D.position += Vector2.left * Time.deltaTime * moveSpeed;
            direction = -1;
        }
        else if (follow.x > .5)
        {
            //transform.Translate(Vector2.right * Time.deltaTime * moveSpeed);
            //rigidBody2D.MovePosition(Vector2.right * Time.deltaTime * moveSpeed);
            rigidBody2D.position -= Vector2.left * Time.deltaTime * moveSpeed;
            direction = 1;
        }
        else if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
        {
            animator.SetTrigger("Attack");
        }
    }
}
