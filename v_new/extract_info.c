#include "extract_info.h"

void	ft_fillcamera(char *str)
{
	
}

void	ft_fillstructs(char *str)
{
	static int		objtofill[3];
	/*
	0 - Camera
	1 - Sphere
	2 - Light
	*/

	if (strcmp(str, "Camera") == 0 || objtofill[0] == 1)
	{
		objtofill[0] = 1;
		if (strcmp(str, "#END") == 0)
			objtofill[0] = 0;
		ft_fillcamera(str);
	}
	else if (strcmp(str, "Sphere") == 0 || objtofill[1] == 1)
	{
		objtofill[1] = 1;
		if (strcmp(str, "#END") == 0)
			objtofill[1] = 0;
		ft_fillsphere(str);
	}
	else if (strcmp(str, "Light") == 0 || objtofill[2] == 1)
	{
		objtofill[2] = 1;
		if (strcmp(str, "#END") == 0)
			objtofill[2] = 1;
		ft_filllight(str);
	}
}

int		ft_extract(int fd, char *path)
{
	char	*buffer;

	while (get_next_line(fd, &buffer) > 0)
	{
		ft_fillstructs(buffer);
		free(buffer);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		fd;

	if (argc < 2)
	{
		printf("Give a file to extract!\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ft_extract(fd, argv[1]);
	return (0);
}