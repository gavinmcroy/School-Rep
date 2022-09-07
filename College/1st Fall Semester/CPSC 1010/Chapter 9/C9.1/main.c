#include <stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct Employee {
    char lastName[22];
    char idNumber[13];
    double grossPay;
    double taxesDeducted;
    double netPay;
} Employee;

void writeEmpFile();

void readEmpFile();

int main() {
    writeEmpFile();
    readEmpFile();
    return 0;
}

void writeEmpFile() {
    Employee employee1;
    FILE *file = fopen("empstat.txt", "w");
    if (file == NULL) {
        perror("ERROR");
        return;
    }
    fprintf(file, "%15s\t %15s\t %15s\t %15s %15s\n", "NAME", "IDNUM", "GROSS", "TAXES", "NET");
    while (true) {
        printf("Enter Last Name (no spaces): ");
        scanf("%s", employee1.lastName);
        if (strcmp(employee1.lastName, "EXIT") == 0) {
            //fflush(stdin);
            break;
        }
        printf("Enter ID Number: ");
        scanf("%s", employee1.idNumber);
        printf("Enter Gross Pay: ");
        scanf("%lf", &employee1.grossPay);
        printf("Enter Taxes: ");
        scanf("%lf", &employee1.taxesDeducted);
        employee1.netPay = employee1.grossPay - employee1.taxesDeducted;
        fprintf(file, "%15s\t %15s\t %08.2lf\t %08.2lf %08.2lf\n", employee1.lastName, employee1.idNumber,
                employee1.grossPay, employee1.taxesDeducted, employee1.netPay);
    }
    fclose(file);
}

void readEmpFile() {
    FILE *file = fopen("empstat.txt", "r");
    char test[30];
    int i = 0;

    while (fscanf(file, "%s", test) == 1) {
        if (i % 5 == 0) {
            printf("\n");
        }
        //fscanf(file, "%s", test);
        printf("%15s", test);
        i++;
    }
    fclose(file);
}