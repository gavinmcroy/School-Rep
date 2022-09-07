#include <stdio.h>

typedef struct computerType_struct {
    char manufacturer[50];
    char model[50];
    char processor[15];
    int ram;
    int hardDrive;
    int yearBuilt;
    double price;
} computerType;

computerType intialize(void);

void printSpecs(computerType type);

int main() {
    computerType type = intialize();
    printSpecs(type);
    return 0;
}

computerType intialize(void) {
    computerType type;
    printf("Enter the name of the manufacturer: ");
    fgets(type.manufacturer,48,stdin);
    printf("Enter the model of the computer: ");
    fgets(type.model,48,stdin);
    printf("Enter processor type: ");
    fgets(type.processor,13,stdin);
    fflush(stdin);
    printf("Enter the size of RAM (in GB): ");
    scanf("%d", &type.ram);
    printf("Enter the size of hard drive (in GB): ");
    scanf("%d", &type.hardDrive);
    printf("Enter the year the computer was built: ");
    scanf("%d", &type.yearBuilt);
    printf("Enter the price: ");
    scanf("%lf", &type.price);
    return type;
}

void printSpecs(computerType type) {
    printf("--------------------\n");
    printf("Manufacturer: %s", type.manufacturer);
    printf("Model: %s", type.model);
    printf("Processor: %s", type.processor);
    printf("Ram: %d\n", type.ram);
    printf("Hard Drive Size: %d\n", type.hardDrive);
    printf("Year Built: %d\n", type.yearBuilt);
    printf("Price: $%.2lf\n", type.price);
}

