/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:29:49 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/25 18:35:39 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	euler_x(float *old_y, float *old_z, double angle)
{//애네들 각 바꿔야 하긴함 처음에 축이 뒤집어져있어서
	float	y;
	float	z;
	float	new_y;
	float	new_z;
	double	radian;

	radian = M_PI / 180.0 * angle;
	y = *old_y;
	z = *old_z;
	new_y = y * cos(radian) - z * sin(radian);
	new_z = y * sin(radian) + z * cos(radian);
	*old_y = new_y;
	*old_z = new_z;
}

void	euler_y(float *old_x, float *old_z, double angle)
{
	float	x;
	float	z;
	float	new_x;
	float	new_z;
	double	radian;
	
	radian = M_PI / 180.0 * angle;
	x = *old_x;
	z = *old_z;
	new_x = cos(radian) * x - sin(radian) * z;
	new_z = sin(radian) * x + cos(radian) * z;
	*old_x = new_x;
	*old_z = new_z;
}

void	euler_z(float *old_x, float *old_y, double angle)
{
	float	x;
	float	y;
	float	new_x;
	float	new_y;
	double	radian;

	radian = M_PI / 180.0 * angle;
	x = *old_x;
	y = *old_y;
	// new_x = cos(radian) * x + sin(radian) * y;
	// new_y = sin(radian) * -x + cos(radian) * y;
	new_x = cos(radian) * x - sin(radian) * y;
	new_y = sin(radian) * x + cos(radian) * y;
	*old_x = new_x;
	*old_y = new_y;
}
// new_x = (cos(30.0 * (M_PI / 180.0)) * x - sin(30.0 * (M_PI / 180.0)) * y);
// 	new_y = ((sin(30.0 * (M_PI / 180.0)) * x) + cos(30.0 * (M_PI / 180.0)) * y);