using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RubyController : MonoBehaviour
{
    private readonly float speed = 8.0f;

    public int GetMaxHealth { get; } = 5;

    public int GetCurrentHealth { get; private set; }

    private readonly float timeInvicible = 2.0f;
    private float invicibleTimer;
    bool isInvicible;

    Rigidbody2D rigidBody2D;

    void Start()
    {
        rigidBody2D = GetComponent<Rigidbody2D>();
        GetCurrentHealth = GetMaxHealth;
        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = 144;
    }

    void Update()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");

        Vector2 position = rigidBody2D.position;
        position.x += speed * horizontal * Time.deltaTime;
        position.y += speed * vertical * Time.deltaTime;

        rigidBody2D.MovePosition(position);

        if (isInvicible)
        {
            invicibleTimer -= Time.deltaTime;
            if (invicibleTimer < 0)
            {
                isInvicible = false;
            }
        }

    }

    public void ChangeHealth(int amount)
    {
        if (amount < 0)
        {
            if (isInvicible)
                return;
            isInvicible = true;
            invicibleTimer = timeInvicible;
        }
        GetCurrentHealth = Mathf.Clamp(GetCurrentHealth + amount, 0, GetMaxHealth);
        Debug.Log(GetCurrentHealth + "/" + GetMaxHealth);
    }

}
