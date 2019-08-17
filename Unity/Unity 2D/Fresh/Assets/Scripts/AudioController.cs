using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioController : MonoBehaviour
{
    [SerializeField] AudioSource fxSounds;
    [SerializeField] AudioSource musicSounds;
    [SerializeField] float lowPitch = .95f;
    [SerializeField] float highPitch = 1.05f;
    public static AudioController instance;

    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        DontDestroyOnLoad(gameObject);
    }

    public void PlaySingle(AudioClip clip)
    {
        fxSounds.clip = clip;
        fxSounds.Play();
    }

    public void RandomSFX(params AudioClip[] clip)
    {
        int random = Random.Range(0, clip.Length);
        float randomPitch = Random.Range(lowPitch, highPitch);
        fxSounds.pitch = randomPitch;
        fxSounds.clip = clip[random];
        fxSounds.Play();
    }

    public void MuteSound()
    {
        fxSounds.volume = 0;
    }
}
