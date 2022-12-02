/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:50:28 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/04 12:33:08 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_print_comb2(void);
void	ft_putchar(int n);

int main(void)
{
    ft_print_comb2();
    return (0);
}

void	ft_putchar(int n)
{
    int n0 = n / 10;
    int n1 = n % 10;

    char cn0 = n0 + 48;
    char cn1 = n1 + 48;

	write(1, &cn0, sizeof(char));
	write(1, &cn1, sizeof(char));
}

void    ft_print_comb2(void)
{
    int a = 0;
    int b = 1;

    while (a <= 99)
    {
        b = a + 1;
        while (b <= 99)
        {
            ft_putchar(a);
            write(1, " ", 1);
            ft_putchar(b);
            write(1, ",", 1);
            write(1, " ", 1);
            ++b;
        }
        ++a;
    }
}