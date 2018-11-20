using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class scriptBlock : MonoBehaviour {
    [SerializeField] AudioClip breakSound;
    [SerializeField] GameObject blockParticleEffectVFX;
    [SerializeField] float particleAffectsDelayAfterDestroy = 2f; 
    //---Cached Reference
    Level level;
    GameStatus points; 

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
            DestroyBlock();
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
