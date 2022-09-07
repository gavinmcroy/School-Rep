using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Fade : MonoBehaviour
{
    [SerializeField] private RawImage fadeImage;
    private Color _color;
    private bool _fadeOut;
    private bool _fadeIn = true;
    private bool _isTransitioningOnce = true;
    private bool _isLoading;
    private IEnumerator _coroutine;
    public static Fade instance;
    private Canvas _canvas;
    private string _sceneTransition;

    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(this.gameObject);
        } else {
            instance = this;
        }
    }

    void Start()
    {
        instance = this;
        DontDestroyOnLoad(gameObject);
        _color = fadeImage.GetComponent<RawImage>().color;
        fadeImage = fadeImage.GetComponent<RawImage>();
        _coroutine = Check();
    }

    public void StartTransition(String transition)
    {
        _sceneTransition = transition;
        _canvas = GetComponent<Canvas>();
        _canvas.sortingOrder = 1;
        _coroutine = Check();
        StartCoroutine(_coroutine);
    }

    private void Transition()
    {
        if (_fadeOut && _isTransitioningOnce)
        {
            if(_color.a<=0)
            {
                _fadeOut = false;
                _fadeIn = true;
                _isTransitioningOnce = false;
            }
            _color.a -= Time.deltaTime;
            fadeImage.color = _color;
        }
        else if (_fadeIn && _isTransitioningOnce)
        {
            if (_color.a>=1)
            {
                _fadeIn = false;
                _fadeOut = true;     
            }
            _color.a += Time.deltaTime;
            fadeImage.color = _color;
        }
        if (_color.a >= 1 && !_isLoading)
        {
            SceneManager.LoadScene(_sceneTransition);
            _isLoading = true;
        }
    }

    private void Reset()
    {
        _isTransitioningOnce = true;
        _fadeOut = false;
        _fadeIn = true;
        _isLoading = false;
        _canvas.sortingOrder = 0;
    }

    IEnumerator Check()
    {
        while (_isTransitioningOnce)
        {
            yield return new WaitForSeconds(.00025f);
            Transition();
        }
        Reset();
    }
}
