/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:01:43 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/13 13:03:52 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TYPED_H
# define __TYPED_H


typedef const char*     t_path;/* path name and also considered as file name */
typedef const char*     _str;
typedef char*           _ptr;
typedef const   char**  t_av;
typedef char**          _head;
typedef const char**    _2d_arr;
typedef unsigned int    t_index;

typedef short  t_req;/*  work request */

/*   specific work request  */
# define ERRMSG 0 /* add message to error name   */
# define STRERR 1 /* sufficiency with error name */
# define ERRON STRERR

# define _SAVE      0x00000
# define _RETURN    0x00000
# define _free      0x00000
# define _CHECK     0x00000
# define _ALT       0x00000
# define _ORG       0x00000
# define _SET       0x00000
# define _GET       0x00000

# endif