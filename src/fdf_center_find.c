#include "fdf.h"

void	fdf_center_find(t_mlx *data)
{
	int x1;
	int x2;
	int y1;
	int y2;

	x1 = data->m_pixels[0][0]->x;
	y1 = data->m_pixels[0][0]->y;
	x2 = data->m_pixels[data->map_y - 1][data->map_x - 1]->x;
	y2 = data->m_pixels[data->map_y - 1][data->map_x - 1]->y;
	data->xcen = (x1 + x2) / 2;
	data->ycen = (y1 + y2) / 2;
}