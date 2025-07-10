#include "pipex.h"

// int	cmd_check(char *argv[], char *envp[])
// {
// 	int	valid;

// 	valid = 0;
// 	if (valid != "correct path placeholder")
// 		return (-1);
// 	if (valid == "correct path placeholder")
// 		return (1);
// }

int	cmd_findpath(char *argv[], char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5); // return the path location
		i++;
	}
	return (NULL);
}

char	**cmd_split(char *cmd_path)
{
	char	**paths;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (cmd_path[i])
	{
		if (cmd_path[i] == ':')
			count++;
		i++;
	}
	count++;
	paths = malloc(sizeof(char *) * (count + 1));
	split(cmd_path, ":"); // replace with ft_split <<<<<<<<<<<<
	return (paths);
}

char	*cmd_check(char *envp[], char *cmd)
{
	char	*path_env;
	char	**paths;
	char	*full_paths;
	int		i;

	i = 0;
	if (cmd[i] == '/' || cmd[i] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}
}
