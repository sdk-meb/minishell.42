/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtypes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:01:43 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/24 00:21:25 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTYPES_H
# define MTYPES_H

/* path name and also considered as file name */
typedef char const		*t_path;

/* const string  */
typedef char const		*t_str;

/* pointer */
typedef char			*t_ptr;

/* head of pointer */
typedef char			**t_head;

/* command tree */
typedef struct s_list	*t_cmd;

/*  work request */
typedef short			t_req;

/*   specific work request  */
# define ERRON STRERR
# define _RETURN 0

# define NEWCHLD 0
# define EMPTY (-2)

# define SAVE 0b1000
# define _SET 0b0100
# define _GET 0b0010
# define _ADD 0b0001

#endif
