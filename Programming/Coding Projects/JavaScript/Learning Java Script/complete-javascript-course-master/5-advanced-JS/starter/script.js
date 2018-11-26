//---Function Constructor
/*
//---Object John 
var john = {
    name: 'John',
    birthYear: 1990,
    job: 'Teacher'
};
//---Object Constructor
var Person = function(name,birthYear,job){
    this.name = name;
    this.birthYear = birthYear;
    this.job = job;
    } 
//---Inheritance
Person.prototype.calcAge = function(){
    console.log( 2018 - this.birthYear);
}
//---Inheritance
Person.prototype.lastName = 'Smith';

var john1 = new Person('Rick',1990,'Musician'); 
var jane = new Person('Jane',1975,'Designer');
var mark = new Person('Mark',1948,'Retired');

john1.calcAge();
jane.calcAge();
mark.calcAge();

console.log(john1.lastName)
console.log(jane.lastName)
console.log(mark.lastName)


var car = {
    year: 2001,
    color: "red",
    type: "Honda"
}
//---Object Constructor
var carModel = function(year,color,type){
    this.year = year; 
    this.color = color;
    this.type = type; 
}
//---Inherentance
carModel.prototype.calcCarAge = function(){
    console.log(2018-this.year); 
}

var bigTruck = new carModel (1999,"Pink","Ford F150");
bigTruck.calcCarAge(); 


var house = function(size,color,squareFeet,houseAge){
    this.size = size;
    this.color = color;
    this.squareFeet = squareFeet;
    this.houseAge = houseAge;
}
house.prototype.calcHouseAge = function(){
    console.log(2018-this.houseAge+" years old")
}
var redHouse = new house ("large","Pink",6000,1990); 
redHouse.calcHouseAge(); 
*/

var personProto = {
    calulateAge1: function(){
        console.log(2018-this.yearOfBirth)
    }
}
var john = Object.create(personProto)
john.name = "John"
john.yearOfBirth = 1999
john.job = 'Teacher'

var jane = Object.create(personProto,{
    name: {value: 'Jane'},
    yearOfBirth: {value: 1969},
    job: {value: 'Designer'}
});



























