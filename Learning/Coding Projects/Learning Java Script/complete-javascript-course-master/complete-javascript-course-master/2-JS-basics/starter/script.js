/**************************
 *Variables and Data Types
 */
/*
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


function calculateAge(birthYear) {
  return 2018 - birthYear;
}

ageJohn = calculateAge();

function yearsUntilRetirement(year, firstName) {
  var age = calculateAge(year);
  var retirement = 65 - age;
  if (retirement > 0) {
    console.log(firstName + ' retires in ' + retirement + ' years');
  } else if (retirement < 0) {
    console.log(firstName + ' is already retired ');
  }
}

yearsUntilRetirement(1990, 'John');
yearsUntilRetirement(1970, 'Rick');
yearsUntilRetirement(1930, 'Mike');

function test(add1, add2) {
  return add1 + add2;
}

var addValue = test(543343, 3434);
console.log(addValue);

function addition() {
  var add = prompt("enter a number ");
  var add1 = prompt("enter a nunber ");
  return add + add1;
}
var final = addition();
console.log(final);

function subtraction(subValue1, subValue2) {
  return subValue1 - subValue2;
}
var subStore = subtraction(20, 5);
console.log(subStore);
var year = 2018

function retirement(name, birthDate) {
  name = prompt("Enter your name ")
  birthDate = prompt("When were you born ");
  var retireDay = year - birthDate;
  if (retireDay < 70) {
    retireDay = 70 - retireDay;
    console.log(name + " has " + retireDay + " years left until retirement")
  } else {
    console.log(name + " is already Retired ");
  }
}
retirement();
var yearPresent = 2018;

function familyInfo() {
  var fatherName = prompt("Enter your Dads Name ");
  var fatherBirth = prompt("Enter your Dads birthYear ");
  var ageNow = yearPresent - fatherBirth;
  if (ageNow >= 30 && ageNow < 50) {
    console.log("Bruh your dad is young");
  } else if (ageNow >= 50 && ageNow < 70) {
    console.log("Bruh your dad is old");
  } else if (ageNow >= 70 && ageNow < 90) {
    console.log("Bruh your dads dead");
  }
}
familyInfo();


function multiply(mult1, mult2) {
  return mult1 * mult2;
}
var display = multiply(15, 5.69);
console.log(display);

//---Function Statements and Expressions
var whatDoYouDo = function(job, firstname) {
  return firstname;
}
console.log(whatDoYouDo(12, "Gavin"));

var jobList = function(firstName, job) {
  switch (job) {
    case 'teacher':
      return firstName + ' teaches kids how to program! ';
    case 'driver':
      return firstName + ' drives kids around! ';
    case 'hoe':
      return firstName + ' no reply ';
  }
}
console.log(jobList('Dave', 'teacher'));

var names = ['John', 'Mark', 'Jane', 'Josh'];
names[names.length] = 'Mary'
var years = new Array(1990, 1960, 1948);
console.log(names);
console.log(names.length);
names[1] = 'ben';
console.log(names[1]);

var johnInfo = ['John', 'Smith', 1990, 'designer', false];
//---Adds a value at the end of the Array
johnInfo.push('blue');
//---Adds a value at the start of the Array
johnInfo.unshift('Mr. ');
//---Removes a value from the end of the Array
johnInfo.pop();
//---Removes a value from the begginning of a Array
johnInfo.shift();

console.log(johnInfo);
//---Gives position of data point in array
console.log(johnInfo.indexOf(1990));

var isDesigner = johnInfo.indexOf('designer') === -1 ? 'John is not a designer ' : 'John is a designer';
console.log(isDesigner);
//---Bill calculator
var billFinal = [0, 0, 0];
var billValue = [169, 48, 248];
var tipValue = [0, 0, 0];
var i = 0;
var determineTip = function() {
  while (i < 3) {
    if (billValue[i] <= 50) {
      tipValue[i] = billValue[i] * .2;
      billFinal[i] = tipValue[i] + billValue[i];
      i++;
    } else if (billValue[i] > 50 && billValue[i] <= 200) {
      tipValue[i] = billValue[i] * .15;
      billFinal[i] = tipValue[i] + billValue[i];
      i++;
    } else if (billValue[i] > 200) {
      tipValue[i] = billValue[i] * .1;
      billFinal[i] = tipValue[i] + billValue[i];
      i++;
    } else {
      i++;
    }
  }
}
determineTip();
console.log(billValue);
console.log(tipValue);
console.log(billFinal);

//---Objects and properties
//---Object literal
var john = {
  firstname: 'John',
  lastName: 'Smith',
  birthYear: 1999,
  family: ['Jane', 'Mark', 'Bob', 'Emily'],
  job: 'teacher ',
  marriageState: false,
};
console.log(john['lastName']);
console.log(john.lastName);
john.job = 'designer'
console.log(john.job)
john.marriageState = true;
console.log(john.marriageState)
//---Object syntax
var Jane = new Object();
Jane.lastname = 'smith '
Jane.year = 1990;
console.log(Jane);

var john = {
  firstname: 'John',
  lastName: 'Smith',
  birthYear: 1999,
  family: ['Jane', 'Mark', 'Bob', 'Emily'],
  job: 'teacher ',
  marriageState: false,
  calcAge: function(birthYear) {
    this.age = 2018 - this.birthYear;
    return this.age;
  }
}
console.log(john.calcAge());
console.log(john);

var gav = {
  firstName: 'gav',
  lastName: 'McRoy',
  birthYear: 2000,
  gender: 'male',
  gavAge: function(birthYear) {
    this.age = 2018 - this.birthYear;
    return this.age;
  }
};
console.log(gav);
console.log(gav.gavAge());


var mark = {
  mass: 55,
  height: 6,
  firstName: 'Mark',
  birthYear: 1984,
  job: 'teacher',
  markCalc: function(mass, height) {
    this.mbmi = this.mass / (this.height * this.height)
    return this.mbmi;
  }
};
var john = {
  mass: 55,
  height: 6,
  firstName: 'John',
  johnCalc: function(mass, height) {
    this.jbmi = this.mass / (this.height * this.height);
    return this.jbmi;
  }
}

console.log(mark.markCalc());
console.log(john.johnCalc());

if (john.jbmi > mark.mbmi) {
  console.log("John has a higher index of " + john.jbmi + " While mark has " + mark.mbmi);
} else if (john.jbmi === mark.mbmi) {
  console.log("Both john and mark have the same body index of " + mark.mbmi);
} else if (mark.mbmi > john.jbmi) {
  console.log("Mark has a higher index of " + mark.mbmi + " while john has " + john.jbmi);
}
//--------Loops---------------


for (var i = 1; i <= 20; i++) {
  console.log(i);
}
var johnInfo = ['John', 'Smith', 1990, 'designer', false];
//---Loops all the information in array with for loop
for (var i = 0; i < johnInfo.length; i++) {
  console.log(johnInfo[i]);
}
//---Loops all the information in array with while loop
var i = 0;
while (i < johnInfo.length) {
  console.log(johnInfo[i])
  i++
}
//---Only displays string data types in the array with a for loop with continue
for (var i = 0; i < johnInfo.length; i++) {
  if (typeof johnInfo[i] != 'string') continue;
  console.log(johnInfo[i]);
}
//---Only displays string data types in the array with a for loop with break;
for (var i = 0; i < johnInfo.length; i++) {
  if (typeof johnInfo[i] != 'string') break;
  console.log(johnInfo[i]);
}
//---Looping backwards
for (var i = johnInfo.length - 1; i >= 0; i--) {
  console.log(johnInfo[i]);
}
*/ 
/*****************************
* CODING CHALLENGE 5

Remember the tip calculator challenge? Let's create a more advanced version using everything we learned!

This time, John and his family went to 5 different restaurants. The bills were $124, $48, $268, $180 and $42.
John likes to tip 20% of the bill when the bill is less than $50, 15% when the bill is between $50 and $200, and 
10% if the bill is more than $200.

Implement a tip calculator using objects and loops:
1. Create an object with an array for the bill values
2. Add a method to calculate the tip
3. This method should include a loop to iterate over all the paid bills and do the tip calculations
4. As an output, create 1) a new array containing all tips, and 2) an array containing final paid amounts (bill + tip).
 HINT: Start with two empty arrays [] as properties and then fill them up in the loop.


EXTRA AFTER FINISHING: Mark's family also went on a holiday, going to 4 different restaurants. The bills were $77, $375, $110, and $45.
Mark likes to tip 20% of the bill when the bill is less than $100, 10% when the bill is between $100 and $300, and 25% if 
the bill is more than $300 (different than John).

5. Implement the same functionality as before, this time using Mark's tipping rules
6. Create a function (not a method) to calculate the average of a given array of tips. HINT: Loop over the array, and in 
each iteration store the current sum in a variable (starting from 0). After you have the sum of the array, divide it by the number
 of elements in it (that's how you calculate the average)
7. Calculate the average tip for each family
8. Log to the console which family paid the highest tips on average

GOOD LUCK 😀
*/

tip = { 
 finalPrice: [],
 tipAmount: [],
 tipRestuarants: [124,48,268,180,42],
 calcTip: function() {
  for(var i = 0; i <= this.tipRestuarants.length; i++){
    if(i>=0 && i < 50){
    //---Adds tip percentage to array tip amount depending on restuarant price
    this.tipAmount.push()
    this.tipAmount [i] = this.tipRestuarants[i] *.2
    }
    else if(i>=50 && i < 200){
      this.tipAmount.push()
      this.tipAmount [i] = this.tipRestuarants[i] *.15
    }
    else if(i >= 200){
      this.tipAmount.push()
      this.tipAmount [i] = this.tipRestuarants[i] *.1
    }
  }
 },
 //---Add Tip amount to Tip Restuarant!
  tipAdder: function() {
  for(var i = 0; i < this.tipRestuarants.length; i++){
    tip.finalPrice[i] = tip.tipAmount[i]+tip.tipRestuarants[i]; 
  }
}
};   
tip.calcTip()
tip.tipAdder();
for(var i = 0; i<tip.tipRestuarants.length;i++){
  console.log("Tip amount: $"+tip.tipAmount[i])
}
var i = 0
while(i < tip.tipRestuarants.length){
  console.log("Final Price: $"+tip.finalPrice[i])
  i++; 
}
//---Calculates Average 
 var testArray = [1,2,3,4,5,6,6]
 testFunction = function(sum){
   var sum = 0
   for(var i =0; i<testArray.length;i++){
     sum = sum + testArray[i]
   }
   return sum / testArray.length 
 }
//---Work Log 
/*
merge test into object tip 
*/
console.log(testFunction())








///----