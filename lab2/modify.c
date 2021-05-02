#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
    char name[30];
    printf("Enter name : ");
    fgets(name, sizeof(name), stdin);
    printf("\nMy name is ");
    puts(name);
    printf("My child process => ppid==%d, pid=%d\n\n", getppid(), getpid());
	exit(0);
}

void parentTask()
{
    printf("Parent process => pid==%d\n", getpid());
    printf("Child process is finised!\n");
    printf("Job is done \n \n");
}

void waiting()
{
      printf("waiting for child process to finish…");
      wait(NULL);
      printf("child process finished!!\n");
	printf(">>>>.....................<<<<\n");

}

int main(void)
{
    for(int i=1; i < 5; i++){
	    pid_t pid = fork();
	    if(pid == 0){
	        childTask();
	    }else if(i == 4){
	        waiting();
	        parentTask();

}else waiting();
    }
    return EXIT_SUCCESS;
}
