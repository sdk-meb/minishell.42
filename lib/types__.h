/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:01:43 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/02 14:59:06 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TYPED_H
# define __TYPED_H

typedef char**          t_env;

typedef const char*     t_path;/* path name and also considered as file name */
typedef const char*     _str;
typedef char*           _ptr;
typedef char**          _head;
typedef const char**    _2d_arr;
typedef unsigned int    t_index;

#define ROOT    0x0777
#define USER    0x0700

# endif