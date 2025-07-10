#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h> //wait
# include <unistd.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *strc, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *strc, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	kid_one(char *argv[], char *envp[], int *pipefd);
void	kid_two(char *argv[], char *envp[], int *pipefd);
int		cmd_check(char *argv[], char *envp[]);
int		cmd_findpath(char *argv[], char *envp[]);

#endif