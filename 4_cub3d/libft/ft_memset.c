/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: inghwang <inghwang@student.42seoul.>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/07 08:09:18 by inghwang		  #+#	#+#			 */
/*   Updated: 2023/10/08 15:20:19 by inghwang         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		temp[i++] = (unsigned char)c;
	}
	return (temp);
}
