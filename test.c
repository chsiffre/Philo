/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:43:37 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/28 13:46:22 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>

int main()
{
    int time;

    time = gettimeofday();
    printf("%d"m time);
}