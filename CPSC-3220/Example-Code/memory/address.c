#include <stdio.h>
#include <unistd.h>

int x = 0;

int main() {
  if (fork()==0) {
    x++;
  }
  printf("Hello, %d, %p\n", x, &x);
}
