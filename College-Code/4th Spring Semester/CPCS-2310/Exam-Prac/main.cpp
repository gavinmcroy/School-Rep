#include <stdio.h>
#include <cstdint>
#include <iostream>

typedef struct Date {
    int m, d, y;
} date_t;
typedef struct Address {
    char *streetName;
    int streetNum;
    char *city;
    char *state;
    int zip;
} address_t;
typedef struct Person {
    char *name;
    date_t d;
    struct Address a;
} person_t;


int main() {
//    enum colors {
//        red, white = 5, blue, green = 10, yellow
//    };
//    enum colors c = red;
//    enum colors w = white;
//    enum colors b = blue;
//    enum colors g = green;
//    enum colors y = yellow;
//
//    printf("%d %d %d %d %d", c, w, b, g, y);
//    date_t date = {1,1,1};
//    Address address = {"a",1,"r","f",5};
//    person_t person1 = { "Gavin", date, address };
//    printf("%s %d %s",person1.name,person1.a.zip,person1.d);

    int c = 0, num, myst = 0, d;
    int *ptr;

    scanf("%d", &num);
    ptr = (int *) malloc(num * num * (sizeof(int)));
    while (c < num * num) {
        scanf("%d", &ptr[c]);
        c++;
    }
    c = 0;
    while (c < num * num) {
        myst = myst + *(ptr + c);
        c = c + num + 1;
    }
    c = 0;
    while (c < num) {
        d = (c) * num - c + num - 1;
        myst = myst + *(ptr + d);
        c++;
    }

    printf("%d\n", myst);
    return 0;


    return 0;

}
