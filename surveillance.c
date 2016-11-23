/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mot_le_plus_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:07:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/11/23 16:20:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*******
 *
 *  * Read input from STDIN
 *
 *   * Use printf(...) or fprintf( stdout, ...) to output your result.
 *
 *    * Use:
 *
 *     *  localPrint( char* mystring)
 *
 *      * to display variable in a dedicated area.
 *
 *       * ***/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct		s_coo
{
	double			x;
	double			y;
}					t_coo;

static int			is_in(t_coo p, t_coo m, t_coo M)
{
	if (p.x >= m.x && p.y >= m.y && p.x <= M.x && p.y <= M.y)
		return (1);
	return (0);
}

int					main()
{
	t_coo			min;
	t_coo			max;
	t_coo			point;
	int				n;
	int				i = 0;
	int				total = 0;

	if (scanf("%f%f%f%f%i", &min.x, &min.y, &max.x, &max.y, &n) < 5)
		return (1);
	while (i++ < n)
	{
		if (scanf("%f%f", &point.x, &point.y) < 2)
			return (1);
		total += is_in(point, min, max);
	}
	printf("%d", total);
	return (0);
}
