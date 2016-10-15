/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:53:55 by gallard           #+#    #+#             */
/*   Updated: 2014/11/05 12:53:57 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*p;

	if (!dest || !src)
		return (NULL);
	p = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (p);
}
