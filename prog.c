#include "minishell.h"

int main(int argc, char **argv)
{
	char c = getchar();
	if (c == EOF)
		return 0;
	if (argv[1])
		printf("test successful with args\n");
	else
		printf("test successful without args\n");
}