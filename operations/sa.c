/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:30:55 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 09:31:12 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sa(t_stack** stack)
{
    if (*stack != NULL && (*stack)->next != NULL)
    {
        int temp = (*stack)->data;
        (*stack)->data = (*stack)->next->data;
        (*stack)->next->data = temp;
    }
}