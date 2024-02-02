/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:43:22 by junssong          #+#    #+#             */
/*   Updated: 2024/02/02 13:14:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double	a;
	double	half_b;
	double	c;
	double	discriminant; //판별식

	oc = vminus(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vdot(oc, oc) - sp->radius2;
	// discriminant 는 판별식
	discriminant = half_b * half_b - a * c;
	// 판별식이 0보다 크다면 광선이 구를 hit한 것!
	// 판별식이 0보다 작을 때 : 실근 없을 때,
	if (discriminant < 0)
		return (-1.0);
	else
		return (-half_b - sqrt(discriminant)) / a; // 두 근 중 작은 근
}
