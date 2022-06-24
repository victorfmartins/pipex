/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:50:26 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 13:57:41 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int x1, int x2)
{
	return (x1 * (x1 <= x2) + x2 * (x2 < x1));
}
