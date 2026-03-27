/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:55:00 by moouhida          #+#    #+#             */
/*   Updated: 2026/01/08 09:44:36 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*get_ref_fd(int fd, char *str, char *buffer);
char	*get_after_line(char *str);
char	*ft_start(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
