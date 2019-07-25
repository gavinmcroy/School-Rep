using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rewrite : MonoBehaviour,AIAttack
{
    [SerializeField] private int moveSpeed = 1;
    [SerializeField] string layerMaskName = "Hostile";
    [SerializeField] private int health = 20;
    [SerializeField] private float attackRange = .75f;
    [SerializeField] private float lookRange = 10f;
    [SerializeField] float attackSpeed = 1f;
    private float direction = 1;
    Rigidbody2D rigidBody2D;
    Animator animator;

    private void Awake()
    {
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
        animator.SetInteger("Health", health);
    }

    void FixedUpdate()
    {
        Follow();
        Attack();
    }

    public void SetMovementSpeed(int speed)
    {
        moveSpeed = speed;
    }

    public void SetAttackSpeed()
    {
        animator.speed = attackSpeed;
    }

    public void ResetAttackSpeed()
    {
        animator.speed = 1;
    }

    public void DealDamage(int damage)
    {
        RaycastHit2D rayCast = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction, 0), attackRange, LayerMask.GetMask(layerMaskName));
        if (rayCast.collider != null)
        {       
            Movement player = rayCast.collider.GetComponent<Movement>();
            Rewrite enemy = rayCast.collider.GetComponent<Rewrite>();
            if (enemy != null)
            {
                enemy.TakeDamage(damage);
            }
            if (player != null)
            {
                player.TakeDamage(damage);
            }
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
            Debug.Log("Killed");
        }
    }

    public void DestroyObject()
    {
        Destroy(gameObject);
    }

    private void Follow()
    {
        animator.SetFloat("Direction", direction);
        RaycastHit2D rayCastInfront = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction,0), lookRange, LayerMask.GetMask(layerMaskName));
        RaycastHit2D rayCastBehind = Physics2D.Raycast(rigidBody2D.position, new Vector2(-direction,0), lookRange, LayerMask.GetMask(layerMaskName));
        Debug.Log(gameObject+"Infront Distance :" + rayCastInfront.distance + " Current Direction "+direction);
        Debug.Log(gameObject+"Behind Distance: " + rayCastBehind.distance+ " Current Direction "+direction);

        if (rayCastInfront.distance > -rayCastBehind.distance && !Mathf.Approximately(rayCastInfront.distance,0))
        {
            rigidBody2D.position += Vector2.right * Time.deltaTime * moveSpeed;
            direction = 1;
        }else if (-rayCastInfront.distance < rayCastBehind.distance && !Mathf.Approximately(rayCastBehind.distance,0))
        {
            rigidBody2D.position += Vector2.left * Time.deltaTime * moveSpeed;
            direction = -1;
        }
    }

    private void Attack()
    {
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
        {
            RaycastHit2D rayCast = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction, 0), attackRange, LayerMask.GetMask(layerMaskName));
            if (rayCast.collider != null)
            {
                animator.SetTrigger("Attack");
            }
        }
    }
}
