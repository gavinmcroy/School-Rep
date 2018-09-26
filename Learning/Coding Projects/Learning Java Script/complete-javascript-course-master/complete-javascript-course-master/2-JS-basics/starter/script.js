/**************************
 *Variables and Data Types

var firstName = "Gavin ";
console.log(firstName);
var lastName = "Mcroy";
console.log(lastName);
var age = 28;
var fullAge = true;
if (fullAge = true) {
  console.log("Wow Im awesome! ")
}
var job = "Teacher ";
console.log(job)

//---Variable Mutation and Coercion
/*var firstName = "john";
var age = 28;
//---Type Ceorcion
console.log(firstName + " " + age);

var job, isMarried;
job = "Teacher ";
isMarried = false;
console.log(isMarried);
//---Variable Mutation
age = "twenty eight";
alert(age);
firstName = prompt("What is your first Name? ");
var lastName = prompt("What is your last name ");
alert("Hello " + firstName + " " + lastName);

var firstName = prompt("Hello what is your first name?! ");
var lastName = prompt("and your last name!? ");
console.log("Hi " + firstName + " " + lastName + " its so nice to meet you! ");
alert(firstName + " " + lastName + " get your social stolen get fucked ");

//---Basic Operators
var now = 2018
var age = prompt("Enter your age ");
var age2 = prompt("Enter another age ");
var MaxAge = age >= age2;
alert(MaxAge);
var gav = "Gavin";
alert("Gavin is here! ");
console.log(typeof gav);

var x = 15;
while (x > 10) {
  alert("Destroyed");
}
********************************
Operator Precedence
*******************************

var now = 2018;
var yearJohn = 1989;
var fullAge = 18;

var isfullAge = now - yearJohn >= fullAge

//---Coding Challenge 1
var markHeight = prompt("Mark Enter your Hieght");
var markWeight = prompt("Mark now Enter your Weight ");
var johnHeight = prompt("John Enter your Height");
var johnWeight = prompt("John now enter your Weight ");

var bmiMark = markWeight / (markHeight * markHeight);
var bmiJohn = johnWeight / (johnHeight * johnHeight);
var question = "Is Mark's Bmi Higher than Johns? ";
var answer = bmiMark > bmiJohn;
console.log(question + answer);

//------------------If and Else Statements------------------
var firstName = "Mark";
var civilStatus = "single";

if (civilStatus == "Married") {
  console.log(firstName + " is married! ");

} else {
  console.log(firstName + " is not married :( ");
}

var isMarried = true;
if (isMarried) {
  console.log(firstName + " is married! ");
} else {
  console.log(firstName + " is not married :( ");
}
//-----------------Coding Challenge------------------
var markHeight = prompt("Mark Enter your Hieght");
var markWeight = prompt("Mark now Enter your Weight ");
var johnHeight = prompt("John Enter your Height");
var johnWeight = prompt("John now enter your Weight ");

var bmiMark = markWeight / (markHeight * markHeight);
var bmiJohn = johnWeight / (johnHeight * johnHeight);
if (bmiMark > bmiJohn) {
  console.log("mark's bmi is higher ");
} else {
  console.log("john's bmi is higher ");
}

/**************Boolean Logic**************
var firstName = "John"
var age = 16;

if (age < 13) {
  console.log(firstName + " is a boy! ");
} else if (age < 20 && age >= 13) {
  console.log(firstName + " is a boy! ");
} else if (age >= 20 && age < 31) {
  console.log(firstName + " is a  man! ")
} else {
  console.log(firstName + " is a man! ");
}

//---Ternary Operator
var age = 18;
var firstName = "John ";
age >= 18 ? console.log(firstName + " drinks beer") : console.log(firstName + " drinks juice");

var drink = age >= 18 ? "beer" : "juice";
console.log(drink);
//---Basically what this means
/* if(age>=18){
var drink = "beer";
}else{
var drink = "juice";
}

//----------Switch Statement
var job = "instructor";
var firstName = "John";
switch (job) {
  case "teacher":
  case "instructor":
    console.log(firstName + " teaches kids how to code");
    break;
  case "driver":
    console.log(firstName + " drives people around ");
    break;
  default:
    console.log(firstName + " does something else ");
}

switch (true) {
  case age < 13:
    console.log(firstName + " is a boy! ");
    break;
  case age < 20 && age >= 13:
    console.log(firstName + " teenager! ");
    break;
  case age < 31 && age >= 20:
    console.log(firstName + " is a  man! ");
    break;
  default:
    console.log(firstName + " is old! ");

}
/*
if (age < 13) {
  console.log(firstName + " is a boy! ");
} else if (age < 20 && age >= 13) {
  console.log(firstName + " is a boy! ");
} else if (age >= 20 && age < 31) {
  console.log(firstName + " is a  man! ")
} else {
  console.log(firstName + " is a man! ");
}

var age = 18 >= 10 ? console.log("Helllo! ") : console.log("aw");

//-----Truthy Falsy Values

Will turn out in a true or false condition >> falsy values: undefined,null,0,'',NaN
Will turn out true in a true of false condition >> NOT falsy values

var hieght = 23;
if (hieght || hieght == 0) {
  console.log("Variable Defined");
} else {
  console.log("Variable is undefinded");
}
//---Equality operators
if (hieght == '23') {
  console.log("the == operator does type coercion")
}
*/
var maryTeam = 97 + 134 + 105
var johnsTeam = 89 + 120 + 103
var mikeTeam = 116 + 94 + 123
var maryTeamAverage = maryTeam / 3
var johnTeamAverage = johnsTeam / 3
var mikeTeamAverage = mikeTeam / 3
console.log('Mary Score: ' + maryTeamAverage)
console.log('Mikes Score: ' + mikeTeamAverage)
console.log('Johns Score: ' + johnTeamAverage)
if (johnTeamAverage > mikeTeamAverage && johnTeamAverage > maryTeamAverage) {
  console.log('Johns Team Wins with ' + johnTeamAverage + ' points!')
} else if (johnTeamAverage === mikeTeamAverage || johnTeamAverage === maryTeamAverage || mikeTeamAverage === maryTeamAverage) {
  console.log('The Game is a Tie! ')
} else if (johnTeamAverage < mikeTeamAverage && maryTeamAverage < mikeTeamAverage) {
  console.log('Mikes Team Wins with ' + mikeTeamAverage + ' points!')
} else if (maryTeamAverage > mikeTeamAverage && maryTeamAverage > johnTeamAverage) {
  console.log('Mary Wins with ' + maryTeamAverage + ' points!')
}
