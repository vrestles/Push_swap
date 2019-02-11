/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:22:08 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 17:14:04 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define CHECK_PTR(x) if (!(x)) return (-1)
# define BUFF_SIZE 32
# include <string.h>

char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_straddchar(char const *s, char c);
void			*ft_memalloc(size_t size);
void			ft_strdel(char **as);
void			ft_arrdel(char **as, int count);
int				ft_count_numbers(int n);
char			*ft_itoa(int nb);
long long int	ft_atoi(const char *str);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
int				ft_is_number(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strdup(const char *s1);
void			ft_strclr(char *s);
char			*ft_strcpy(char *dst, const char *src);
int				get_next_line(const int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_count_words(char const *s, char c);

#endif
