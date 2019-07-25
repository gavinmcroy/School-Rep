using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Movement : MonoBehaviour
{
    [SerializeField] private int health = 2;
    [SerializeField] private float moveSpeed = 3;
    [SerializeField] TextMeshProUGUI text;
    private float lastPosition;
    private float speed;
    private float direction = 1;
    static Rigidbody2D rigidBody2D;
    Animator animator;
    Vector2 movement;

    void Start()
    {
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
        text.text = health.ToString();
    }

    void Update()
    {
        Attack();
    }

    void FixedUpdate()
    {
        Move();
        AnimationController();
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        Debug.Log("Collision with " + collision.gameObject);
    }

    public void DealDamage(int val)
    {
        RaycastHit2D rayCast = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction, 0), 1.25f, LayerMask.GetMask("Hostile"));
        if (rayCast.collider != null)
        {
            Rewrite enemy = rayCast.collider.gameObject.GetComponent<Rewrite>();
            enemy.TakeDamage(val);
        }
        else
        {
            Debug.Log("Player Attack RayCast Collision Fail");
        }

    }

    public void TakeDamage(int damage)
    {
        if (health > 0)
        {
            health -= damage;
            if (health < 0)
            {
                text.text = "0";
            }
            else
            {
                text.text = health.ToString();
                animator.SetInteger("Health", health);
            }
        }
    }

    public void SetMoveSpeed(int speed)
    {
        moveSpeed = speed;
    }

    public static Vector2 GetPosition()
    {
        return rigidBody2D.position;
    }

    private void Move()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        movement = new Vector2(horizontal, rigidBody2D.position.y);

        GetSpeed();
        GetDirection();

        Vector2 position = rigidBody2D.position;
        position.x += movement.x * moveSpeed * Time.deltaTime;
        rigidBody2D.MovePosition(position);
    }

    private void Attack()
    {
        if (Input.GetKeyDown(KeyCode.C) && !animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
        {
            float randomVal = Mathf.Clamp(Random.value, 0f, .75f);
            animator.SetFloat("Random", randomVal);
            animator.SetTrigger("Attack");
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
        speed = rigidBody2D.position.x - lastPosition;
        lastPosition = rigidBody2D.position.x;
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
