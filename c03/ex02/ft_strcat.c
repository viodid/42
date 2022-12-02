/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:57:22 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/10 15:57:23 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
char *ft_strcat(char *dest, char *src);

int main() {
   char str1[100] = "Tonto el q", str2[] = "";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   ft_strcat(str1, str2);

	int i = 0;
	while (i < 20)
	{
		printf("%c\n", str1[i]);
		i++;
	}
   return 0;
}
*/

char	*ft_strcat(char *dest, char *src)
{
	char	*start_dest;

	start_dest = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (start_dest);
}
