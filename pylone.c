/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pylone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:41:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/11/23 17:51:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void		*xmalloc(size_t size)
{
	void		*xmem = malloc(size);

	if (!xmem)
		exit(1);
	return (xmem);
}

static int		compute_left(int index, int *pyl, int n)
{
	int			i = index - 1;
	int			total = 0;
	int			max = 0;

	while (i >= 0)
	{
		if (pyl[i] > max)
		{
			total++;
			max = pyl[i];
		}
		i--;
	}
	return (total);
}

static int		compute_right(int index, int *pyl, int n)
{
	int			i = index + 1;
	int			total = 0;
	int			max = 0;

	while (i < n)
	{
		if (pyl[i] > max)
		{
			total++;
			max = pyl[i];
		}
		i++;
	}
	return (total);
}

static int		compute_vision(int index, int *pyl, int n)
{
	return (compute_left(index, pyl, n) + compute_right(index, pyl, n));
}

int				main()
{
	int			n;
	int			*pyl;
	int			i = 0;
	
	if (scanf("%d", &n) < 1)
		return (1);
	pyl = xmalloc(sizeof(int) * n);
	while (i < n)
	{
		if (scanf("%d", pyl + i) < 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		printf("%d\n", compute_vision(i, pyl, n));
		i++;
	}
	return (0);
}




