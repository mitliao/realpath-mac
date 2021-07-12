#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/param.h>

int main(int argc, char **argv)
{
	char relative_to[PATH_MAX] = {0};
	char result[PATH_MAX];
	int i;

	while (1)
	{
		int opt;
		static const struct option long_options[] =
		{
			{ "relative-to", required_argument, 0, 'r'},
			{ 0, 0, 0, 0 }
		};

		if (-1 == (opt = getopt_long(argc, argv, "r:", long_options, NULL)))
		{
			break;
		}

		switch (opt)
		{
		case 'r':
			if (realpath(optarg, relative_to))
			{
				/* realpath stripped / from path, add it back */
				snprintf(relative_to, sizeof(relative_to), "%s/", relative_to);
				//printf("fixed-relative-to:%s\n", relative_to);
			}
			else
			{
				printf("invalid relative-to: %s\n", optarg);
				return -1;
			}
			break;
		default:
			return -1;
		}
	}

	for (i = 1; i < argc; i++)
	{
		if (realpath(argv[i], result))
		{
			if (relative_to[0])
			{
				if (strnstr(result, relative_to, strlen(result)))
				{
					printf("%s\n", result + strlen(relative_to));
					continue;
				}
			}
			printf("%s\n", result);
		}
	}
	return 0;
}
