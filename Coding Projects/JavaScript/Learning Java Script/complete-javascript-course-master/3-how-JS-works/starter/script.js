///////////////////////////////////////
// Lecture: Hoisting

function calculateAge(year){
    return 2016-year 
}
console.log(calculateAge(1994)); 

var calc = function(year){
    return year +1;
}
console.log(calc(1990));
var age = 20
function foo(){
    console.log(age)
    var age = 10
    console.log(age)
}
foo(); 










///////////////////////////////////////
// Lecture: Scoping


// First scoping example

/*
var a = 'Hello!';
first();

function first() {
    var b = 'Hi!';
    second();

    function second() {
        var c = 'Hey!';
        console.log(a + b + c);
    }
}
*/



// Example to show the differece between execution stack and scope chain

/*
var a = 'Hello!';
first();

function first() {
    var b = 'Hi!';
    second();

    function second() {
        var c = 'Hey!';
        third()
    }
}

function third() {
    var d = 'John';
    console.log(a + b + c + d);
}
*/



///////////////////////////////////////
// Lecture: The this keyword









