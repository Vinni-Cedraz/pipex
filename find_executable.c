#include "includes/printf_libft_includes.h"

char	*find_executable(char *cmd)
{
	char	*path;
	char	**dirs;
	char	*filename;
	int		i;
	int		fd;

	/* Check if file is already executable */
	if (access(cmd, X_OK) == 0)
		return (cmd);

	/* Split PATH environment variable into directories */
	path = getenv("PATH");
	dirs = my_split(path, ':');

	/* Check each directory for the executable */
	i = 0;
	while (dirs[i])
	{
		filename = malloc(strlen(dirs[i]) + strlen(cmd) + 2);
		ft_strlcpy(filename, dirs[i]);
		ft_strlcat(filename, "/");
		ft_strlcat(filename, cmd);
		if (access(filename, X_OK) == 0)
		{
			free(dirs);
			return (filename);
		}
		free(filename);
		i++;
	}

	/* If executable is not found, return NULL */
	free(dirs);
	return (NULL);
}
