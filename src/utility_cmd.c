#include "libft.h"
#include "pipex.h"

char	**cmd_parse(char *cmd_str)
{
	return (ft_split(cmd_str, ' '));
}

int	cmd_findpath(char *envp[])
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
	ft_split(cmd_path, ":");
	return (paths);
}

char	*cmd_check(char *envp[], char *cmd)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	i = 0;
	if (cmd[i] == '/' || cmd[i] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	path_env = cmd_findpath(envp);
	if (!path_env)
		return (NULL);
	paths = cmd_split(path_env);
	while (paths[i])
	{
		full_path = create_full_path(paths[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
	}
}
char	*create_full_path(char *directory, char *cmd)
{
	int len;
	char *full_path;

	len = ft_strlen(directory) + ft_strlen(cmd) + 2;
	full_path = malloc(len);

	strcpy();
	strcpy();
	strcpy();

	return (full_path);
}