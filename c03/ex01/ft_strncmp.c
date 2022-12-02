/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:57:19 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/10 15:57:21 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	ft_strncmp(char *s1, char *s2, unsigned int n);

#include <stdio.h>

int main() {
	char str1[] = "abcde", str2[] = "abcda";
	int result;

	// comparing strings str1 and str2
	result = ft_strncmp(str1, str2, 5);
	printf("strncmp(str1, str2) = %i\n", result);

	// comparing strings str1 and str3
	result = ft_strncmp(str2, str1, 5);
	printf("strncmp(str2, str1) = %i\n", result);

	return 0;
}
*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (*s1 || *s2))
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
		i++;
	}
	return (0);
}
