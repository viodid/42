/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:52:52 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/10 15:57:17 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	ft_strcmp(char *s1, char *s2);

#include <stdio.h>

int main() {
	char str1[] = "ab", str2[] = "abcd", str3[] = "abcd";
	int result;

	// comparing strings str1 and str2
	result = ft_strcmp(str1, str2);
	printf("strcmp(str1, str2) = %i\n", result);

	// comparing strings str1 and str3
	result = ft_strcmp(str2, str1);
	printf("strcmp(str2, str1) = %i\n", result);

	return 0;
}
*/

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 > *s2)
		{
			return (1);
		}
		else if (*s1 < *s2)
		{
			return (-1);
		}
		s1++;
		s2++;
	}
	return (0);
}
