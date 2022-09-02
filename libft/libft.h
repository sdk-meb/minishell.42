/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:30:21 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/02 15:28:03 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "mtypes.h"

typedef struct integer
{
	int	i;
	int	j;
	int	n;
}				t_intgr;

# define APPROVED	0b1000	  /* memory approved by programme */
# define TEMPORARY	0b10000 /* temporary memory */

/* *** garbage collector (^,^) ***
dangling pointer  /?  {dangle : hold something so that it hangs loosely} */
typedef struct s_heap
{
	void			*dng_ptr;
	struct s_heap	*extra;
	int				dangel;
}			t_heap;
/*  requirement  order  APPROVED or TEMPORARY (memory)
		dangel for group id if you want to remeve on of group */
void	*new_heap(size_t, t_req ord, int dangel);
void	c_delete(t_req ord, int dangel);
void	c_merge(void *ptr, t_req ord, int dangel);
t_heap	**governor(t_req ord);
void	*freen(void **ptr);

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int i);
void	*ft_memchr(const void *s, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
int		ft_strnindex(const void *s, int c, int len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
