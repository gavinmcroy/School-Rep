//---Function Constructor

//---Object John 
var john = {
    name: 'John',
    birthYear: 1990,
    job: 'Teacher'
};

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
console.log(john.name); 