/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:53:40 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/11 18:02:30 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx_opengl/mlx.h"
// # include <mlx.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define MAX_COUNT 200
# define WIDTH 800
# define HEIGHT 800
# define MOVE_STEP 0.05
# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_juliaset
{
	double	num_a;
	double	num_b;
}				t_juliaset;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		*command1;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_data		img;
	t_juliaset	set;
}			t_vars;

typedef struct s_cal_vars
{
	double	x;
	double	y;
	double	xn;
	double	yn;
	double	value;
	double	a;
	double	b;
	int		i;
	int		j;
	int		count;	
}				t_cal_vars;

enum {
	ON_KEYLEFT = 123,
	ON_KEYRIGHT = 124,
	ON_KEYUP = 126,
	ON_KEYDOWN = 125,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_DESTROY = 17,
	ON_ESC = 53
};

// error handling
int				check_commandline(char *command);
void			display_error(void);

// initialize
t_vars			initialization(char *str);

// draw image
void			my_mlx_pixel_put(t_data *data, int x, int y,
					unsigned int color);
int				render_next_frame(void *params);

// handler
int				key_handler(int keycode, t_vars *env);
int				mouse_handler(int mousecode, int x, int y, t_vars *env);

// mathematics part 
void			make_julia(t_vars vars);
void			make_mandel_ship(t_vars vars);
t_cal_vars		calculator(t_cal_vars params, char *command1);
void			put_color(t_vars vars, t_cal_vars mj);

// data set
void			julia_set(t_vars *vars);
unsigned int	color(char *command, int count);

// close
void			close_window(t_vars *env);

#endif
