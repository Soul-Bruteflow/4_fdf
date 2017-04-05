#include "fdf.h"

static void	fdf_scale(t_mlx *mlx, float n, int c, int r)
{
	mlx->m_pixels[c][r]->x *= n;
	mlx->m_pixels[c][r]->y *= n;
	mlx->m_pixels[c][r]->z *= n;
}

static void fdf_scale_plus(t_mlx *mlx)
{
	int c;
	int r;
	int tmpx;
	int tmpy;

	c = 0;
	r = 0;
	if ((mlx->xcen - mlx->m_pixels[c][r]->x) < mlx->width * 20)
	{
		tmpx = mlx->wxcur;
		tmpy = mlx->wycur;
		fdf_center_zero(mlx);
		while (c < mlx->map_y)
		{
			r = 0;
			while (r < mlx->map_x)
			{
				fdf_scale(mlx, 1.1, c, r);
				r++;
			}
			c++;
		}
		mlx->wxcur = tmpx;
		mlx->wycur = tmpy;
	}
}

static void fdf_scale_minus(t_mlx *mlx)
{
	int c;
	int r;
	int tmpx;
	int tmpy;

	c = 0;
	r = 0;
	if ((mlx->xcen - mlx->m_pixels[c][r]->x) > mlx->width * 0.01)
//		if (data->m_pixels[c][r]->x < (data->xcen - 10)
//				|| data->m_pixels[c][r]->y < (data->ycen - 10))
	{
		tmpx = mlx->wxcur;
		tmpy = mlx->wycur;
		fdf_center_zero(mlx);
		while (c < mlx->map_y)
		{
			r = 0;
			while (r < mlx->map_x)
			{
				fdf_scale(mlx, 0.9, c, r);
				r++;
			}
			c++;
		}
		mlx->wxcur = tmpx;
		mlx->wycur = tmpy;
	}
}

void	fdf_zoom(int kcode, t_mlx *mlx)
{
	fdf_center_find(mlx);
	if (kcode == PLUS)
	{
		fdf_scale_plus(mlx);
		fdf_redraw_zoom(mlx);
	}
	if (kcode == MINUS)
	{
		fdf_scale_minus(mlx);
		fdf_redraw_zoom(mlx);
	}
}