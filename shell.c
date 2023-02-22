#include"shell.h"
/**
 * main - simple shell
 * Return: 0 (success)
 */
int main(void)
{
	char *cmd;

	while (1)
	{
		printf("#cisfun$ ");
		cmd = getCommand();
		if (cmd == NULL)
			exit(1);
		executeByPath(cmd);
		free(cmd);
	}
	return (0);
}
/**
 * executeByPath - execute command
 * @cmd: command
 * Return: nothing
 */
void executeByPath(char *cmd)
{
	pid_t pid;
	char *cmdv[3] = {NULL, NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(1);
	} else if (pid == 0)
	{
		cmdv[0] = cmd;
		if (execve(cmd, cmdv, environ) == -1)
		{
			perror(program_invocation_name);
			exit(1);
		}
	} else
	{
		wait(NULL);
	}
}
/**
 * getCommand - get command enteren from terminal
 * Return: character string of command entered
 */
char *getCommand(void)
{
	char *line = NULL;
	size_t len;

	if (getline(&line, &len, stdin) == -1)
	{
		return (NULL);
	}
	line[strcspn(line, "\n")] = '\0';
	return (line);
}
