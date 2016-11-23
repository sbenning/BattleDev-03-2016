/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mot_le_plus_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:07:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/11/23 16:08:12 by sbenning         ###   ########.fr       */
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

int main()
{
	char    word[751];
	int     size;
	int     i = 0;
	size_t  max = 0;
	size_t  len;

	if (scanf("%d", &size) < 1)
		return (1);
	while (i++ < size)
	{
		if (scanf("%s", word) < 1)
			return (1);
		len = strlen(word);
		max = (len > max ? len : max);
	}
	printf("%zu", max);
	return (0);
}
