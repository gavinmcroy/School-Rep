#include <stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct Address_struct {
    char houseNumber[10];
    char street[50];
    char city[50];
    char state[2];
    char zip[9];
} Address;

typedef struct Name_struct {
    char firstName[50];
    char lastName[50];
} Name;

typedef struct Employee_struct {
    int idNumber;
    Name employeeName;
    Address employeeAddress;
    char jobTitle[100];
} Employee;

Employee getEmployee(void);

int main(void) {
    Employee myCompany[20];
    strcpy(myCompany[0].employeeName.lastName, ("MyName?"));
    if (isalpha(myCompany[0].employeeName.lastName[0])) {

    }
    myCompany[0].idNumber = 1;
    myCompany[1] = getEmployee();

    // print company & employee info
}

Employee getEmployee(void){
    Employee tmp;
    printf("Enter id number: ");
    scanf("%d",&tmp.idNumber);
    return tmp;
}