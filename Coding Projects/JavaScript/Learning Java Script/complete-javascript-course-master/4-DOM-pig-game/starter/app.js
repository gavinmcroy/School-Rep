/*
GAME RULES:

- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game

*/
var scores , roundScore , activePlayer,gamePlaying,userMaxScore;
init();
var previousRoll = [0,0,0,0];
var switchRoll = 0;




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

//---adds a event if the player clicks the roll button
document.querySelector('.btn-roll').addEventListener('click',function(){
        if(gamePlaying){
            //---Sets the dice to roll 1-6 and updates the picture with the dice roll
            switchRoll === 1 ? switchRoll = 0 : switchRoll = 1;
            var dice = Math.floor((Math.random() *6)+1); 
            var dice1 = Math.floor((Math.random()*6)+1);
            previousRoll[switchRoll]=dice; 
            previousRoll[switchRoll+2]=dice1;
            var diceDOM = document.querySelector('.dice')
            var diceDOM1 = document.querySelector('.dice1');
            document.querySelector('.dice').style.display ='block';
            document.querySelector('.dice1').style.display = 'block';
            diceDOM.src = 'dice-'+dice +'.png';
            diceDOM1.src ='dice-'+dice1+'.png'; 
            //---Checks if the dice rolled a one and if not add score and if so score = 0
                if(dice!==1 && dice1!== 1)
                {
                    roundScore+=dice;
                    roundScore+=dice1;
                    document.querySelector('#current-'+activePlayer).textContent = roundScore;

                }
                else
                {
                    nextPlayer();
                }
                if(previousRoll[0]===6 && previousRoll[1]===6 || previousRoll[2]===6 && previousRoll[3]===6)
                {
                    // console.log(previousRoll[0])
                    // console.log(previousRoll[1])
                    // console.log(previousRoll[2])
                    // console.log(previousRoll[3])
                    scores[activePlayer]=0;
                    document.querySelector('#score-'+activePlayer).textContent = scores[activePlayer]
                    previousRoll = [0,0,0,0];
                    nextPlayer();
                }
     }
});
document.querySelector('.btn-hold').addEventListener('click',function(){
        if(gamePlaying){
            userMaxScore = document.querySelector('#Score').value ;
            //---Add CURRENT score to global score
            scores[activePlayer] +=roundScore; 
            //---Update UI 
            document.querySelector('#score-'+activePlayer).textContent = scores[activePlayer];      
            //---Check if player won the game 
            if(scores[activePlayer]>=userMaxScore){
                gamePlaying = false;
                document.querySelector('#name-'+activePlayer).textContent = 'Winner! '; 
                document.querySelector('.dice').style.display = 'none';
                //---Second dice no longer will display
                document.querySelector('.dice1').style.display='none';
                document.querySelector('.player-'+activePlayer+'-panel').classList.add('winner');
                document.querySelector('.player-'+activePlayer+'-panel').classList.remove('active');
            }
            else{
                nextPlayer();  
    }
        }
})
//---Restarts the game
document.querySelector('.btn-new').addEventListener('click',init)

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
    document.querySelector('.dice1').style.display = 'none';
}
function init(){
    userMaxScore = document.querySelector('#Score').value ;
    scores = [0,0]; 
    activePlayer = 0;
    roundScore = 0;
    gamePlaying = true;
    document.querySelector('.dice').style.display = 'none'; 
    document.querySelector('.dice1').style.display = 'none';
    //---Sets all scores to 0
    document.getElementById('score-0').textContent = '0';
    document.getElementById('score-1').textContent = '0';
    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';
    document.getElementById('name-0').textContent = 'Player 1';
    document.getElementById('name-1').textContent = 'Player 2';

    document.querySelector('.player-0-panel').classList.remove('winner');
    document.querySelector('.player-1-panel').classList.remove('winner');
    document.querySelector('.player-0-panel').classList.remove('active');
    document.querySelector('.player-1-panel').classList.remove('active');

    document.querySelector('.player-0-panel').classList.add('active');
    //document.querySelector('.player-1-panel').classList.add('active');

}



