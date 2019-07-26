using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface AIAttack 
{
    void SetMovementSpeed(int speed);

    void SetAttackSpeed();

    void ResetAttackSpeed();

    void DealDamage(int damage);

    void TakeDamage(int damage);

    void DestroyObject();

}
