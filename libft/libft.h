/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:15:18 by nfararan          #+#    #+#             */
/*   Updated: 2024/04/25 15:24:12 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define FT_NULL 0
# define FT_INT_MIN -2147483648
# define FT_INT_MAX 2147483647

typedef unsigned int	t_size_t;
typedef unsigned char	t_uchar;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
t_size_t	ft_strlen(const char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_bzero(void *s, t_size_t n);
void		*ft_memcpy(void *dest, const void *src, t_size_t n);
void		*ft_memmove(void *dest, const void *src, t_size_t n);
void		*ft_memset(void *s, int c, t_size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
t_size_t	ft_strlcpy(char *dst, const char *src, t_size_t size);
t_size_t	ft_strlcat(char *dst, const char *src, t_size_t size);
int			ft_strncmp(const char *s1, const char *s2, t_size_t n);
void		*ft_memchr(const void *s, int c, t_size_t n);
int			ft_memcmp(const void *s1, const void *s2, t_size_t n);
char		*ft_strnstr(const char *big, const char *little, t_size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(t_size_t nmemb, t_size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *str, unsigned int start, t_size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_itoa(int n);
void		ft_putnbr_fd(int n, int fd);

#endif
