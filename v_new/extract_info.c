#include "extract_info.h"
#include "ft_print.h"

void	ft_fillstructs(char *str)
{
	static int		objtofill[6];
	/*
	0 - Camera
	1 - Sphere
	2 - Plane
	3 - Cylinder
	4 - Cone
	5 - Light
	*/

	if (strcmp(str, "Camera") == 0 || objtofill[0] == 1)
	{
		objtofill[0] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[0] = 0;
			return ;
		}
		ft_fillcamera(str);
	}
	else if (strcmp(str, "Sphere") == 0 || objtofill[1] == 1)
	{
		objtofill[1] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[1] = 0;
			return ;
		}
		ft_fillsphere(str);
	}
	else if (strcmp(str, "Plane") == 0 || objtofill[2] == 1)
	{
		objtofill[2] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[2] = 0;
			return ;
		}
		ft_fillplane(str);
	}
	else if (strcmp(str, "Cylinder") == 0 || objtofill[3] == 1)
	{
		objtofill[3] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[3] = 0;
			return ;
		}
		ft_fillcylinder(str);
	}
	else if (strcmp(str, "Cone") == 0 || objtofill[4] == 1)
	{
		objtofill[4] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[4] = 0;
			return ;
		}
		ft_fillcone(str);
	}
	else if (strcmp(str, "Light") == 0 || objtofill[5] == 1)
	{
		objtofill[5] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[5] = 0;
			return ;
		}
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
	ft_print_structs();
	return (0);
}