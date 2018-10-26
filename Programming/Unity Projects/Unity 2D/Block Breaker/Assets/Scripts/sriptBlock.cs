using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class sriptBlock : MonoBehaviour {

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(gameObject,0f);
    }
}
