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
        playerController = GetComponent<Movement>();
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
        animator.SetFloat("Direction",direction);
        transform.Translate(Vector2.left * Time.deltaTime * moveSpeed);
    }
}
