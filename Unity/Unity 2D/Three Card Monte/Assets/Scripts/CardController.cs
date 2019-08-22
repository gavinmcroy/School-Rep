using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardController : MonoBehaviour
{
    [SerializeField] private SpriteRenderer[] spriteRender;
    [SerializeField] private Sprite flippedCard;
    [SerializeField] GameObject cardFlipped;
    [SerializeField] int cardMoveSpeed =2;
    private string[] cardLocation;

    void Start()
    {
        cardLocation = new string[spriteRender.Length];
        SaveLocation();
    }

    void Update()
    {
        //MoveCard();
;        if (Input.GetKeyDown(KeyCode.Space))
        {
            FlipAllCards();
        }
        if (Input.GetKeyDown(KeyCode.E))
        {
            UnFlipAllCards();
        }
    }

    private void MoveCard()
    {
        Vector2 cardMove = new Vector2(1, 0);
        Vector2 position = spriteRender[1].transform.position;
        position.x += cardMove.x * cardMoveSpeed * Time.deltaTime;
        spriteRender[1].transform.position = position;
    }

    private void SaveLocation()
    {
        for(int i = 0; i < spriteRender.Length; i++)
        {
            cardLocation[i] = spriteRender[i].sprite.name;
            Debug.Log(cardLocation[i]);
        }
    }

    private void FlipAllCards()
    {
        cardFlipped.SetActive(false);
    }

    private void UnFlipAllCards()
    {
        cardFlipped.SetActive(true);
        spriteRender[1].transform.localScale = new Vector3(1.5f, 1.5f, 1.5f);
    }


}
