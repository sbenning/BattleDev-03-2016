/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mot_le_plus_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:07:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/11/23 17:40:44 by sbenning         ###   ########.fr       */
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

static void			*xmalloc(size_t size)
{
	void			*xmem = malloc(size);

	if (!xmem)
		exit(1);
	return (xmem);
}

static int			is_valid(char *s, char ***dict, int *size, int n, int lv)
{
	int				i = 0;
	size_t			len;

	if (lv == n || !*s)
		return (((lv == n && !*s) ? 1 : 0));
	while (i < size[lv])
	{
		len = strlen(dict[lv][i]);
		if (!strncmp(s, dict[lv][i], len))
			if (is_valid(s + (lv + 1 == n ? len : len + 1), dict, size, n, lv + 1))
				return (1);
		i++;
	}
	return (0);
}

int					main()
{
	int				n_dict;
	char			***dict;
	int				*size_dict;
	int				i = 0;
	int				j;
	int				n_test;
	char			*test;
	int				total = 0;

	if (scanf("%d", &n_dict) < 1)
		return (1);
	dict = xmalloc(sizeof(char **) * n_dict);
	size_dict = xmalloc(sizeof(int) * n_dict);
	while (i < n_dict)
	{
		if (scanf("%d", size_dict + i) < 1)
			return (1);
		dict[i] = xmalloc(sizeof(char *) * size_dict[i]);
		i++;
	}
	i = 0;
	while (i < n_dict)
	{
		j = 0;
		while (j < size_dict[i])
		{
			if (scanf(" %m[^\n]", dict[i] + j) < 1)
				return (1);
			j++;
		}
		i++;
	}
	if (scanf("%d", &n_test) < 1)
		return (1);
	i = 0;
	while (i < n_test)
	{
		if (scanf(" %m[^\n]", &test) < 1)
			return (1);
		total += is_valid(test, dict, size_dict, n_dict, 0);
		free(test);
		i++;
	}
	printf("%d", total);
	return (0);
}



