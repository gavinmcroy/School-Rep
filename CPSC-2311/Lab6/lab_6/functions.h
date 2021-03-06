/****************************** /
* Gavin McRoy                 *
* CPSC2310 Spring 2021        *
* UserName: gmcroy            *
* Instructor:Dr. Yvon Feaster *
/ *****************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#define ABS(a) (a < 0 ? a*-1 : a)
#define LARGEST(a, b, c) (MAX(a,b) == MAX(a,c) ? a : MAX(b,c) == b ? b : c )
#define SMALLEST(a, b, c) (MIN(a,b) == MIN(a,c) ? a : MIN(b,c) == b ? b : c)
#define DEBUG_FPRINT() (fprintf(stderr,"%s %s line %d",__FUNCTION__, __FILE__, __LINE__))
#define ISEVEN_ODD(a) (a%2 == 1 ? printf("%d is odd\n",a) : printf("%d is even\n",a))
#define MALLOC(a, b) (b*)(malloc(sizeof(b) * a))
#define ADD_TO_SUM(sum_number, value) (sum ## sum_number += value)

int printReturn(int a, int b, int action);

#endif
