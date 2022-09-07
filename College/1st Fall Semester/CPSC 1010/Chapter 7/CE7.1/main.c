#include <stdio.h>
#include<string.h>

typedef struct fruitType_struct {
    char name[50];
    char color[10];
    int fat;
    int sugar;
    int carbohydrate;
} fruitType;

fruitType getFruit(void);

void printFruit(fruitType fruitType);

int main() {
    fruitType banana;
    strcpy(banana.name, "banana");
    strcpy(banana.color, "yellow");
    banana.fat = 1;
    banana.sugar = 15;
    banana.carbohydrate = 22;
    printFruit(banana);
    fruitType apple = getFruit();
    printf("\n");
    printFruit(apple);
    return 0;
}

fruitType getFruit(void) {
    fruitType fruit;
    printf("Enter a fruit \n");
    printf("Fruit: ");
    scanf("%s", fruit.name);
    printf("Color: ");
    scanf("%s", fruit.color);
    printf("Fat: ");
    scanf("%d", &fruit.fat);
    printf("Sugar: ");
    scanf("%d", &fruit.sugar);
    printf("Carbohydrate: ");
    scanf("%d", &fruit.carbohydrate);
    return fruit;
}

void printFruit(fruitType fruitType) {
    printf("Your fruit is...\n");
    printf("Fruit: %s\n", fruitType.name);
    printf("Color: %s\n", fruitType.color);
    printf("Fat: %d\n", fruitType.fat);
    printf("Sugar: %d\n", fruitType.sugar);
    printf("Carbohydrate: %d\n\n", fruitType.carbohydrate);
}