using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Friendly : MonoBehaviour
{
    private float direction = -1;
    private int moveSpeed = 1;
    private int health = 20;
    Rigidbody2D rigidBody2D;
    Rigidbody2D enemyPos;
    Enemy enemy;
    Animator animator;

    private void Awake()
    {
        enemy = GameObject.FindGameObjectWithTag("Enemy").GetComponent<Enemy>();
        animator = GetComponent<Animator>();
        enemyPos = enemy.GetComponent<Rigidbody2D>();
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator.SetInteger("Health", health);
    }

    void FixedUpdate()
    {
        FollowEnemy();
    }

    public void SetMovementSpeed(int speed)
    {
        moveSpeed = speed;
    }

    public void DealDamage(int damage)
    {
        RaycastHit2D rayCast = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction, 0), .75f, LayerMask.GetMask("Hostile"));
        if (rayCast.collider != null)
        {
            enemy.TakeDamage(damage);
        }
    }


    public void TakeDamage(int damage)
    {
        if (health > 0)
        {
            health -= damage;
            animator.SetInteger("Health", health);
        }
        if (health <= 0)
        {
            Debug.Log("Killed Friendly");
        }
    }

    public void DestroyObject()
    {
        Destroy(gameObject, 3);
    }

    public void DestroyCollision()
    {
        //rigidBody2D.gravityScale = 0;
        Destroy(GetComponent<BoxCollider2D>());
    }

    private void FollowEnemy()
    {
        if (enemy == null)
        {
            enemy = GameObject.FindGameObjectWithTag("Enemy").GetComponent<Enemy>();
            enemyPos = enemy.GetComponent<Rigidbody2D>();
        }
        Vector2 follow = enemyPos.position - rigidBody2D.position;
        animator.SetFloat("Direction",direction);
        if (follow.x < -.5)
        {
            rigidBody2D.position += Vector2.left * Time.deltaTime * moveSpeed;
            direction = -1;
        }else if (follow.x > .5)
        {
            rigidBody2D.position -= Vector2.left * Time.deltaTime * moveSpeed;
            direction = 1;
        }
        else if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
        {
            animator.SetTrigger("Attack");
        }
    }

    //private void Follow()
    //{
    //    //Vector2 follow = playerController.transform.position - transform.position;
    //    Vector2 follow = playerPosition.position - rigidBody2D.position;
    //    animator.SetFloat("Direction", direction);
    //    if (follow.x < -.5)
    //    {
    //        //transform.Translate(Vector2.left * Time.deltaTime * moveSpeed);
    //        //rigidBody2D.MovePosition(Vector2.left * Time.deltaTime * moveSpeed);
    //        rigidBody2D.position += Vector2.left * Time.deltaTime * moveSpeed;
    //        direction = -1;
    //    }
    //    else if (follow.x > .5)
    //    {
    //        //transform.Translate(Vector2.right * Time.deltaTime * moveSpeed);
    //        //rigidBody2D.MovePosition(Vector2.right * Time.deltaTime * moveSpeed);
    //        rigidBody2D.position -= Vector2.left * Time.deltaTime * moveSpeed;
    //        direction = 1;
    //    }
    //    else if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
    //    {
    //        animator.SetTrigger("Attack");
    //    }
    //}
}
