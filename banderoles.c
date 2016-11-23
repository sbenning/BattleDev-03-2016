/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banderoles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:52:16 by sbenning          #+#    #+#             */
/*   Updated: 2016/11/23 18:05:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void			*xmalloc(size_t size)
{
	void			*xmem = malloc(size);

	if (!xmem)
		exit(1);
	return (xmem);
}

int			main()
{
	int		n;
	int		*band;
	int		i = 0;
	int		j;
	long	total = 0;

	if (scanf("%d", &n) < 1)
		return (1);
	band = xmalloc(sizeof(int) * n);
	while (i < n)
	{
		if (scanf("%d", band + i) < 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (band[i] >= band[j])
			{
				if (band[i] == band[j])
					total += (j - i);
				break ;
			}
			j++;
		}
		i++;
	}
	printf("%ld", total);
	return (0);
}
