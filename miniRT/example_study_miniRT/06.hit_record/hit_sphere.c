/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:43:22 by junssong          #+#    #+#             */
/*   Updated: 2024/02/02 13:25:05 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec3	oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double	a;
	double	half_b;
	double	c;
	double	discriminant; //판별식
	double	sqrtd;
	double	t;

	oc = vminus(ray->orig, sp->center);
	// a = vdot(ray->dir, ray->dir);
	// half_b = vdot(oc, ray->dir);
	// c = vdot(oc, oc) - sp->radius2;
	// // discriminant 는 판별식
	// discriminant = half_b * half_b - a * c;
	// // 판별식이 0보다 크다면 광선이 구를 hit한 것!
	// // 판별식이 0보다 작을 때 : 실근 없을 때,
	// if (discriminant < 0)
	// 	return (-1.0);
	// else
	// 	return (-half_b - sqrt(discriminant)) / a; // 두 근 중 작은 근
	a = vlength2(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - sp->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	//두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크.
	t = (-half_b - sqrtd) / a;
	if (t < rec->tmin || rec->tmax < t)
	{
		t = (-half_b + sqrtd) / a;
		if (t < rec->tmin || rec->tmax < t)
			return (FALSE);
	}
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터.
	set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	return (TRUE);
}
