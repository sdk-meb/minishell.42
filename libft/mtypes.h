/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:01:43 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/18 11:40:36 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTYPES_H
#define MTYPES_H

typedef const char		*t_path;    /* path name and also considered as file name */
typedef const char		*t_str;		/* const string  */
typedef char			*t_ptr;		/* pointer */
typedef char			**t_head;	/* head of pointer */
typedef struct s_list	*t_cmd;		/* command tree */

typedef short t_req;				/*  work request */

/*   specific work request  */
#define ERRMSG 0					/* add message to error name   */
#define STRERR 1					/* sufficiency with error name */
#define ERRON STRERR
#define _RETURN 0

#define NEWCHLD 0
#define EMPTY (-2)

#define SAVE 0b1000
#define _SET 0b0100
#define _GET 0b0010
#define _ADD 0b0001

#endif