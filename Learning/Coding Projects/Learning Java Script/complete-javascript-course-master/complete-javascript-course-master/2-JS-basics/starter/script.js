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
*/
var john = {
  firstname: 'John',
  lastName: 'Smith',
  birthYear: 1999,
  family: ['Jane', 'Mark', 'Bob', 'Emily'],
  job: 'teacher ',
  marriageState: false,
  calcAge: function(birthYear) {
    this.age = 2018 - this.birthYear;
  }
};
console.log(john.calcAge());
console.log(john);
///----