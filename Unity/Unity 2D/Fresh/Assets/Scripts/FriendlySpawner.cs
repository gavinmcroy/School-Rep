using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FriendlySpawner : MonoBehaviour
{
    [SerializeField] Friendly friendly;
    [SerializeField] int spawnHeight = 10;

    private void OnTriggerStay2D(Collider2D collision)
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Movement player = collision.GetComponent<Movement>();
            if (player != null)
            {
                Instantiate(friendly, new Vector2(transform.position.x, spawnHeight), Quaternion.identity);
            }
        }
    }

}
