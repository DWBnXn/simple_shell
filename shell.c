#include"shell.h"
/**
 * main - simple shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0 (success)
 */
int main(void)
{
	char *cmd;

		printf("interactive");
	/* enter interactive Mode */
	while (1)
	{
		printf("($) ");
		cmd = getCommand();
		executeByPath(cmd);
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
		perror("Fork failed");
	if (pid == 0)
	{
		cmdv[0] = cmd;
		if (execve(cmd, cmdv, NULL) == -1)
		{
			perror("Error:");
			exit(0);
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
	char *line;
	size_t len;

	if (getline(&line, &len, stdin) == -1)
		perror("Readline Error");
	line[strcspn(line, "\n")] = '\0';
	return (line);
}
