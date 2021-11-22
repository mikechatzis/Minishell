#include "minishell.h"

int main(int argc, char **argv)
{
	if (argv[1])
		printf("test successful with args\n");
	else
		printf("test successful without args\n");
}