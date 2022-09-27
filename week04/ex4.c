#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

const int INPUT_SIZE = 256;

char INPUT[INPUT_SIZE];
char *args[INPUT_SIZE];
char i = 0;


void sShell();
void commandConvert();
void log_handle(int sig);

int main(int args, char *argv[])
{
	sShell();
	return 0;
}

void commandConvert()
{
	char *p;
	i = 0; //get new sequence of commands
	p = strtok(INPUT, " ");
	while (p != NULL)
	{
		args[i] = p;
		i++;
		p = strtok(NULL, " "); //split string into tokens
	}
	if (strcmp("&", args[i - 1]) == 0) //handle && symbols
	{
		args[i - 1] = NULL;
		args[i] = "&";
	}
	else
	{
		args[i] = NULL;
	}
}

void sShell()
{
	while (1)
	{
		printf("Enter command >");
		fgets(INPUT, INPUT_SIZE, stdin);

		if ((strlen(INPUT) > 0) && (INPUT[strlen(INPUT) - 1] == '\n'))
			INPUT[strlen(INPUT) - 1] = '\0'; //delete \n

		if (!strcmp("exit", INPUT))
			break;
		;
		if (!strcmp("", INPUT))
			continue;
		;
		commandConvert();

		pid_t pid = fork();
		
		if (pid == 0)
		{
			execvp(args[0], args);
		}
		else
		{
			if (NULL == args[i])
				waitpid(pid, NULL, 0);
		}
	}
};
