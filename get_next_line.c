  
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:02:18 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/29 01:35:57 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int             get_next_line(int fd, char **line)
{
    char        b[BUFF_SIZE + 1];
    static char *s[1025];
    char        *h;
    int         r;

    if (s[fd] == NULL)
        s[fd] = (char *)malloc(1);
    while ((r = read(fd, b, BUFF_SIZE)) > 0 || (ft_strchr(s[fd], '\n') != NULL))
    {
        b[r] = '\0';
        h = ft_strjoin(s[fd], b);
        free(s[fd]);
        s[fd] = ft_strdup(h);
        free(h);
        if ((h = ft_strchr(s[fd], '\n')) != NULL)
        {
            *line = ft_strsub(s[fd], 0, ft_strlen(s[fd]) - ft_strlen(h));
            free(s[fd]);
            s[fd] = ft_strdup(h + 1);
            return (1);
        }
    }
    if (fd < 0 || !line || r < 0 || (read(fd, b, 0)) < 0)
        return (-1);
    return (0);
}
