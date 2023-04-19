include "main.h"
/**
 * main - entry point to the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 success, 1 for erro
 */
int main(int argc, char **argv)
{
	info_t info[] = {INFO_INIT};
	int g_nana = 2;

	/* Assembly code to amnipulate g_nana value */
	__asm__ __volatile__(
			"mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (g_nana)
			: "r" (g_nana)
			);

	if (argc == 2)
	{
		/* Open file in read-only mode */
		g_nana = open(argv[1], O_RDONLY);

		if (g_nana == -1)
		{
			/* Handle file opening errors */
			if (errno == EACCESS)
				exit(126);

			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Cannot open");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = g_nana;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, argv);

	return (EXIT_SUCCESS);
}

