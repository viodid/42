/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:57:24 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/10 15:57:25 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
char *ft_strncat(char *dest, char *src, unsigned int nb);

int main() {
   char str1[40] = "Tonto el q", str2[] = "ue lo lea";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   ft_strncat(str1, str2, 4);
   return 0;
}
*/

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start_dest;

	start_dest = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src && nb > 0)
	{
		*dest = *src;
		++dest;
		++src;
		--nb;
	}
	*dest = '\0';
	return (start_dest);
}
