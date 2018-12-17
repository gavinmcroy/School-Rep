using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class scriptBlock : MonoBehaviour {
    //---Configuration Paramaters
    [SerializeField] AudioClip breakSound;
    [SerializeField] GameObject blockParticleEffectVFX;
    [SerializeField] float particleAffectsDelayAfterDestroy = 2f;
    [SerializeField] int maxHits;
    [SerializeField] Sprite[] hitSprites;
    
    //---Cached Reference
    Level level;
    GameStatus points;


    //---State Variables
    [SerializeField] int timesHit; //---Debug purposes only

    private void Start()
    {
        CountBreakableBlocks();
    }

    private void CountBreakableBlocks()
    {
        points = FindObjectOfType<GameStatus>();
        level = FindObjectOfType<Level>();
        if (tag == "Breakable")
        {
            level.CountBlocks();
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if(tag == "Breakable")
        {
            HandleHit();
        }
    }

    private void ShowNextHitSprite()
    {
        int spriteIndex = timesHit-1;
        if(hitSprites[spriteIndex] != null)
        {
            GetComponent<SpriteRenderer>().sprite = hitSprites[spriteIndex];
        }
        else
        {
            Debug.LogError("Block Sprite is missing from array "+gameObject.name);
        }
    }

    private void HandleHit()
    {
        timesHit++;
        if (timesHit >= maxHits)
        {
            DestroyBlock();
        }
        else
        {
            ShowNextHitSprite();
        }
    }

    private void DestroyBlock()
    {
        BlockBreakingSoundSFX();
        RemoveBlock();
        TriggerSparklesVFX();
    }

    private void RemoveBlock()
    {
        level.BlockDestroyed();
        Destroy(gameObject, 0f);
        points.AddToScore();
    }

    private void BlockBreakingSoundSFX()
    {
        AudioSource.PlayClipAtPoint(breakSound, Camera.main.transform.position);
    }

    private void TriggerSparklesVFX()
    {
        GameObject sparkles = Instantiate(blockParticleEffectVFX,transform.position,transform.rotation);
        Destroy(sparkles,particleAffectsDelayAfterDestroy); 
    }
}
