#include "fdf.h"

void	set_z(t_map *map)
{
	char	*tmp;

	if (ft_isdigit(map->line[map->beg]) == 0)
	{
		map->tmp_z[map->i] = 0;
		map->i++;
	}
	else if (ft_isdigit(map->line[map->beg]) == 1)
	{
		map->end = map->beg;
		while (ft_isdigit(map->line[map->end]) == 1)
			map->end++;
		tmp = ft_strsub(map->line, map->beg, (map->end - map->beg));
		map->tmp_z[map->i] = ft_atoi(tmp);
		map->i++;
		free(tmp);
	}
}

void	fdf_pixel_color_z(t_map *map, t_mlx *pixel)
{
	map->tmp = 0;
	map->beg = map->end;
	if (map->line[map->beg] == '\0' || map->ctrl == map->map_x)
		return;
	while (map->line[map->beg] != '\0' && map->line[map->beg] == ' ')
		map->beg++;
	set_z(map);
	while (map->line[map->end] != ' ' && map->line[map->end] != '\0')
	{
		if (map->line[map->end] == ',' && map->line[map->end + 1] == '0'
			&& map->line[map->end + 2] == 'x' && map->tmp == 0)
			map->tmp = fdf_save_color(map);
		map->end++;
	}
	if (map->tmp == 0)
		fdf_save_color(map);
	map->ctrl++;
	fdf_pixel_color_z(map, pixel);
}