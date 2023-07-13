#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;


int main(int argc, char **argv, char **envp)
{

	if (fork() == 0)
  {
    setenv("JACOBSVAR","SOMETHINGELSE",1);
    execl("./envdemo", "./envdemo", NULL);

  }
  printf("Parent! JACOBSVAR=%s\n",getenv("JACOBSVAR"));

}
