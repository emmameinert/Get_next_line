/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:09:35 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/28 12:04:43 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif 

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_make_stash(void);
char	*ft_call_join(char *stash, char *buf);

#endif
