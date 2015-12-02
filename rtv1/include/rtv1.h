/*
** rtv1.h for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb  9 17:18:33 2015
** Last update Sun Mar 15 16:13:02 2015 Cano Chloe
*/

#ifndef RTV1_H_
# define RTV1_H_

# include <graph.h>
# include <math.h>
# include <sys/types.h>

# ifndef M_PI
#  define M_PI		 4.14159265358979323846
# endif

# define DIST_SCREEN	1600
# define RADIANS(x)	((float)(M_PI / 180.00 * (x)))

# define UN		__attribute__((unused))

typedef struct s_obj		t_obj;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cone		t_cone;
typedef struct s_cylinder	t_cylinder;
typedef struct s_scene		t_scene;
typedef struct s_eye		t_eye;

typedef enum	e_obj_id
  {
    O_SPHERE,
    O_PLANE,
    O_CONE,
    O_CYLINDER
  } t_obj_id;

struct		s_sphere
{
  float		radius;
};

struct		s_plane
{
  float		member;
};

struct		s_cone
{
  float		min;
  float		max;
};

struct		s_cylinder
{
  float		r;
  float		min;
  float		max;
};

union		u_obj
{
  t_sphere	sphere;
  t_plane	plane;
  t_cone	cone;
  t_cylinder	cylinder;
};

struct		s_obj
{
  t_3dpoint	pos;
  t_3dpoint	rot;
  long		color;
  int		id;
  int		type;
  union u_obj	obj;
  t_obj		*next;
  float		brillance;
};

struct		s_eye
{
  t_3dpoint	pos;
  t_3dpoint	rot;
};

struct		s_scene
{
  t_obj		*objs;
  t_eye		eye;
  t_3dpoint	spot;
  long		spot_color;
};

/*
** RENDERING FUNCTIONS
** =============================================================================
*/

/*
** main function calling others.
** get_point_color return the color of the point defined by vec (at this point
** in simple coordinates).
** render_img calls get_point_color for each point of the screen and fill an
** image.
*/
long			get_point_color(t_scene *s_scene, t_3dpoint *vec);
void			render_img(t_mlx *mlx, t_img *img, t_scene *scene);

/*
** Returns intersection coefficient k between vector dir and object obj.
*/
float			inter_sphere(t_3dpoint *point, t_3dpoint *dr, float a);
float			inter_plane(t_3dpoint *point, t_3dpoint *dir);
float			inter_cone(t_obj *obj, t_3dpoint *p, t_3dpoint *dir);
float			inter_cylinder(t_obj *obj, t_3dpoint *p, t_3dpoint *d);
float			get_inter(t_eye *eye, t_3dpoint *dir, t_obj *o);

/*
** Return the color of the point after lightning it.
*/
long			add_light(t_scene *spot, t_3dpoint *k, t_obj *closest);
void			get_normal(t_obj *obj, t_3dpoint *i, t_3dpoint *normal);

/*
** return the color of the point after applying shadows
*/
long			add_shadow(t_3dpoint *i, t_3dpoint *svec, t_obj *objs,
				   long color);

/*
** SCENE DESCRIPTION
** =============================================================================
*/
int			make_scene(t_scene *s_scene);
int			make_cross(t_scene *s_scene);
t_obj			*add_obj(t_obj **objs, int type);

/*
** MATHS
** =============================================================================
*/

/*
** matrixes
*/
void			mult_mtx(float mtx[3][3], t_3dpoint *point);
void			rotate_x(t_3dpoint *point, float a);
void			rotate_y(t_3dpoint *point, float a);
void			rotate_z(t_3dpoint *point, float a);

/*
** polynomes
*/
float			solve_poly_min(float a, float b, float c);
int			solve_poly(float *s, float a, float b, float c);

/*
** vectors
*/
void			set_3dpoint(t_3dpoint *p, float x, float y, float z);
float			vec_norme(t_3dpoint *point);
t_3dpoint		*vec_dup(t_3dpoint *dest, t_3dpoint *src);
t_3dpoint		*vec_scalar_div(t_3dpoint *v, float f);
float			vec_dot_product(t_3dpoint *v1, t_3dpoint *v2);
float			vec_angle(t_3dpoint *v1, t_3dpoint *v2);
void			vec3d_rot(t_3dpoint *v, t_3dpoint *rot);
void			vec3d_inv_rot(t_3dpoint *v, t_3dpoint *rot);
void			vec3d_add(t_3dpoint *dst, t_3dpoint *v, t_3dpoint *rot);
void			vec3d_sub(t_3dpoint *dst, t_3dpoint *v, t_3dpoint *rot);

void			my_bzero(void *mem, size_t len);

#endif /* !RTV1_H_ */
