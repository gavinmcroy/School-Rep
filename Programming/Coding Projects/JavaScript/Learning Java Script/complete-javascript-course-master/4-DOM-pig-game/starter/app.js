/*
GAME RULES:

- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game

*/
var scores , roundScore , activePlayer;
scores = [0,0]; 
roundScore = 0; 
activePlayer = 0; 

//---Determines Active Player 
//---Only selects text does not read html code
//---document.querySelector('#current-'+activePlayer).textContent = dice; 
//---document.querySelector('#name-0').textContent = 'Hello!';
//---document.querySelector('#name-1').innerHTML = '<em>'+'Hello!!!'+'</em>';
//---gets value from id #score-0 and puts it in x;
//---var x = document.querySelector('#score-0').textContent;
//---console.log(x); 
//---document.querySelector('#name-0').textContent = 'Hello!';
//---document.querySelector('#name-1').innerHTML = '<em>'+'Hello!!!'+'</em>';
//---Unloads Dice



document.querySelector('.dice').style.display = 'none'; 
//---Sets all scores to 0
document.getElementById('score-0').textContent = '0';
document.getElementById('score-1').textContent = '0';
document.getElementById('current-0').textContent = '0';
document.getElementById('current-1').textContent = '0';
//---adds a event if the player clicks the roll button
document.querySelector('.btn-roll').addEventListener('click',function(){
    //---Sets the dice to roll 1-6 and updates the picture with the dice roll
    var dice = Math.floor((Math.random() *6)+1); 
    var diceDOM = document.querySelector('.dice')
    document.querySelector('.dice').style.display ='block';
    //document.getElementById('current-0').textContent = dice;
    diceDOM.src = 'dice-'+dice +'.png';
    //---Checks if the dice rolled a one and if not add score and if so score = 0
    if(dice!==1){
        roundScore+=dice;
        document.querySelector('#current-'+activePlayer).textContent = roundScore;
        }
        else{
        //---If active player = 0 then it should be 1 and else it should be 0
        activePlayer === 0 ? activePlayer = 1 : activePlayer =0;
        roundScore = 0;
        //---Updates the current score to 0 
        document.getElementById('current-0').textContent = 0;
        document.getElementById('current-1').textContent = 0;
        //---Switches between player 0 and 1 depending on which is active
        document.querySelector('.player-0-panel').classList.toggle('active');
        document.querySelector('.player-1-panel').classList.toggle('active');
        //---Turns the dice off for the next player to roll;
        document.querySelector('.dice').style.display = 'none';
        }
});
document.querySelector('.btn-hold').addEventListener('click',function(){
    //---Add CURRENT score to global score
    scores[activePlayer] +=roundScore; 
    //---Update UI 
    document.querySelector('#score-'+activePlayer).textContent = scores[activePlayer];
    nextPlayer();         
    //---Check if player won the game 
})



function nextPlayer() {
//---If active player = 0 then it should be 1 and else it should be 0
activePlayer === 0 ? activePlayer = 1 : activePlayer =0;
roundScore = 0;
//---Updates the current score to 0 
document.getElementById('current-0').textContent = 0;
document.getElementById('current-1').textContent = 0;
//---Switches between player 0 and 1 depending on which is active
document.querySelector('.player-0-panel').classList.toggle('active');
document.querySelector('.player-1-panel').classList.toggle('active');
//---Turns the dice off for the next player to roll;
document.querySelector('.dice').style.display = 'none';
}




