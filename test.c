#include <stdio.h>

int Fork(void) 
{
    int pid;

    if ((pid = fork()) < 0)
	unix_error("Fork error");
    return pid;
}

int main()
{
	int i;
	for (i = 0; i < 2; i++) {
		Fork();
  }
	printf("hello\n");
	exit(0);
}

/* output:
hello
hello
hello
hello
*/