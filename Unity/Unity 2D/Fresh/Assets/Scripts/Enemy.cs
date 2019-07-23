using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    [SerializeField] private int health = 10;
    [SerializeField] private int moveSpeed = 1;
    Animator animator;
    Movement playerController;
    private int direction = -1;

    void Start()
    {
        animator = GetComponent<Animator>();
        playerController = FindObjectOfType<Movement>();
        animator.SetInteger("Health", health);
    }

    
    void FixedUpdate()
    {
        if (health < 1)
        {

        }
        else
        {
            SetMovement();
        }
    }

    public void DealDamage(int damage)
    {   
        health -= damage;
        Debug.Log(health);
        if (health <= 0)
        {
            animator.SetInteger("Health", health);
            Debug.Log("Dead");
        }
    }

    public void SetMovement()
    {
        Vector2 follow = playerController.transform.position - transform.position;
        animator.SetFloat("Direction",direction);
        if (follow.x < -.5)
        {
            transform.Translate(Vector2.left * Time.deltaTime * moveSpeed);
            direction = -1;
        }
        else if (follow.x > .5)
        {
            transform.Translate(Vector2.right * Time.deltaTime * moveSpeed);
            direction = 1;
        }
        else
        {
            animator.SetTrigger("Attack");
        }
    }
}
