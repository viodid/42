/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:57:29 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/14 16:23:31 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

/*
int	main(void)
{
	char	d[10];
	char	c[10] = "123456789";
	ft_strlcat(d, c, 4);
	printf("%s", d);
	return 0;
}
*/

int	ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (*str)
	{
		++length;
		str++;
	}
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				d_len;
	int				s_len;
	unsigned int	offset;
	unsigned int	src_index;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	offset = d_len;
	src_index = 0;
	while (*(src + src_index) != '\0')
	{
		*(dest + offset) = *(src + src_index);
		offset++;
		src_index++;
		if (offset == size - 1)
			break ;
	}
	*(dest + offset) = '\0';
	return (d_len + s_len);
}
