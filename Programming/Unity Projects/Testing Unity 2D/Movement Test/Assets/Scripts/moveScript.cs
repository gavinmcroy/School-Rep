﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class moveScript : MonoBehaviour {
    [SerializeField] float screenSize = 16f;
    [SerializeField] float minX = 1f;
    [SerializeField] float maxX = 15f;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        float mousePos = (Input.mousePosition.x / Screen.width) * screenSize;
        Vector2 paddlePos = new Vector2(transform.position.x, transform.position.y);
        paddlePos.x = Mathf.Clamp(mousePos, minX, maxX);
        transform.position = paddlePos;

	}
}
