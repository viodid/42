/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:57:27 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/14 16:23:07 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

/*
#include <stdio.h>

int main () {
   char haystack[30] = "Hey therea there man!";
   char needle[10] = "there";
   char *ret;

   ret = ft_strstr(haystack, needle);

   printf("The substring is: %s\n", ret);
   
   return(0);
}
*/

int	find_substring(char	*haystack, char	*needle)
{
	while ((*haystack == *needle) && (*haystack && *needle))
	{
		haystack++;
		needle++;
	}
	if (*needle == '\0')
	{
		return (1);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*start_haystack;
	char	*start_needle;

	start_haystack = str;
	start_needle = to_find;
	if (!*to_find)
	{
		return (start_haystack);
	}
	while (*str)
	{
		if (*str == *to_find)
		{
			if (find_substring(str, to_find))
			{
				printf("here\n");
				return (start_needle);
			}
		}
		str++;
	}
	return (0);
}
