/*
** graph.h for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Oct 27 22:23:55 2014
** Last update Wed Oct 29 18:48:38 2014 
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# include <X11/mlx.h>
# include <stdlib.h>
# include <keys.h>

# define ABS(x)			((x) < 0 ? (x) * -1: (x))

typedef struct s_point		t_point;
typedef struct s_mlx		t_mlx;
typedef struct s_img		t_img;
typedef struct s_expose		t_expose;

struct		s_point
{
  int		x;
  int		y;
};

struct		s_mlx
{
  void		*mlx;
  void		*win;
  t_point	win_size;
};

struct		s_expose
{
  t_mlx		*mlx;
  t_img		*img;
};

/*
** DISPLAY ON WINDOW
** =============================================================================
*/

int		draw_line(t_mlx *mlx, t_point *from, t_point *to, int color);
int		draw_circle(t_mlx *mlx, t_point *orig, int r, int color);
int		draw_ellipse(t_mlx *mlx, t_point *orig, int r[2], int color);

/*
** IMAGES MANIPULATION
** =============================================================================
*/

struct		s_img
{
  void		*img;
  void		*data;
  t_point	pos;
  t_point	size;
  int		bpp;
  int		size_line;
  int		endian;
};

/*
** Create a new image by calling mlx_new_image(). pos and size fields of the
** s_img struct must be set since their value will be passed as parameters to
** the mlx_new_image function. All others fields of the s_img struct will be
** automatically set using mlx_get_data_addr().
**
*/
int		new_image(t_mlx *mlx, t_img *img);
/*
** Draw a pixel on image pointed to by img at position pix and of color color.
** automatically convert color using mlx_get_color_value according to the fields
** of the s_img structure. Thus, a previous call to new_image() is necessary.
*/
void		img_put_pixel(t_mlx *mlx, t_img *img, t_point *pix,
			      unsigned long color);
/*
** Draw a line on image from point coord[0] to point coord[1] using
** img_put_pixel.
*/
int		img_put_line(t_mlx *mlx, t_img *img, t_point coord[2],
			     unsigned long color);
/*
** Draw a circle of position coord[0] and of radius coord[1].x to image
** using img_put_pixel.
*/
int		img_put_circle(t_mlx *mlx, t_img *img, t_point coord[2],
			       unsigned long color);
/*
** Return the color of the pixel at pix position (relative to image).
*/
unsigned long	img_get_color(t_img *img, t_point *pix);
/*
** Fill a form delimited by color colors[1] or by the edges of the image with
** colors[0], using img_put_pixel.
*/
void		img_fill_inside(t_mlx *mlx, t_img *img, t_point *coord,
				unsigned long colors[2]);

#endif /* !GRAPH_H_ */
