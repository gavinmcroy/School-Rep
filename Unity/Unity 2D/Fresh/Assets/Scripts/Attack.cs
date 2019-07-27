using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack : MonoBehaviour,AIAttack
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
        animator.SetFloat("Direction", direction);
    }

    void FixedUpdate()
    {
        Follow();
        AttackTarget();
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
            Player player = rayCast.collider.GetComponent<Player>();
            Attack enemy = rayCast.collider.GetComponent<Attack>();
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

        if (-rayCastInfront.distance > -rayCastBehind.distance && Mathf.Approximately(rayCastInfront.distance, 0))
        {
            rigidBody2D.position += new Vector2(-direction,0) * Time.deltaTime * moveSpeed;
            direction = -direction;
        }
        else if (-rayCastInfront.distance < -rayCastBehind.distance && Mathf.Approximately(rayCastBehind.distance, 0))
        {
            rigidBody2D.position += new Vector2(direction,0) * Time.deltaTime * moveSpeed;
            
        }

        if (-rayCastInfront.distance > -rayCastBehind.distance && !Mathf.Approximately(rayCastInfront.distance, 0))
        {
            rigidBody2D.position += new Vector2(direction,0) * Time.deltaTime * moveSpeed;            
        }
        else if (-rayCastInfront.distance < -rayCastBehind.distance && !Mathf.Approximately(rayCastBehind.distance, 0))
        {
            rigidBody2D.position += new Vector2(-direction,0) * Time.deltaTime * moveSpeed;
            direction = -direction;

        }
    }

    private void AttackTarget()
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
