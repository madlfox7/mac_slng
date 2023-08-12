#include "so_long.h"

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C' || c == 'T')
		return (1);
	return (0);
}
int valid(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (!valid_char(data->mp[i][j]))
            {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

void borders(t_data *data)
{
    int i;
    int j;

    if (data->width < 3 || data->height < 3)
        exit(1); ///?????
    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if ((i == 0 || i == (data->height - 1)) && data->mp[i][j] != '1')
            {
                printf("Map must be surrounded by walls\n");
                exit(1);
            }
            else if ((j == 0 || j == data->width - 1) && data->mp[i][j] != '1')
            {
                printf("Map must be surrounded by walls\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
}



int flood_fill(t_data *data, int x, int y, int *exit_is_accessable)
{
    static int count_of_collect_reached;
    
    if (data->mp[y][x] == 'C')
        count_of_collect_reached++;
      if (data->mp[y][x] == 'E')
        *exit_is_accessable = 1;
    if (x < 0 || y < 0 || x >= data->width || y >= data->height)
        return count_of_collect_reached;
    if (data->mp[y][x] != '0' && data->mp[y][x] != 'P' && data->mp[y][x] != 'C')
        return count_of_collect_reached;
    if (data->mp[y][x] == 'V')
        return count_of_collect_reached;
    data->mp[y][x] = 'V';
    flood_fill(data, x + 1, y, exit_is_accessable); 
    flood_fill(data, x - 1, y, exit_is_accessable); 
    flood_fill(data, x, y + 1, exit_is_accessable); 
    flood_fill(data, x, y - 1, exit_is_accessable); 
     return count_of_collect_reached;
}



void initialize_map_validation_data(MapValidationData *map_data)
{
    map_data->player_x = -1;
    map_data->player_y = -1;
    map_data->player_found = 0;
    map_data->exit_found = 0;
    map_data->collect_count = 0;
    map_data->exit_is_accessible = 0;
}

void map_error_msg(MapValidationData map_data, int flag )
{
    if (map_data.player_found && flag == 1)
                {
                    printf("Error: Multiple players (P) found!\n");
                    exit (1);
                }
        if (map_data.exit_found && flag == 2)
                {
                    printf("Error: Multiple exits (E) found!\n");
                    exit (1);
                }
                if (flag == 3)
                {
                     if (!map_data.player_found)
                    {
                          printf("Error: Player (P) not found!\n");
                             exit (1);
                     }   
                    if (!map_data.exit_found)
                      {
                         printf("Error: Exit (E) not found!\n");
                          exit (1);
                        } 
                }
}
void validate_map(t_data *data, MapValidationData *map_data)
{
    int y = 0;
    int x;

    while (y++ < data->height)
    {
        x = 0;
        while (x++ < data->width)
        {
            if (data->mp[y-1][x-1] == 'P')
            {
                map_error_msg(*map_data, 1);
                map_data->player_x = x - 1;
                map_data->player_y = y - 1;
                map_data->player_found = 1;
            }
            else if (data->mp[y-1][x-1] == 'E')
            {
                map_error_msg(*map_data, 2);
                map_data->exit_found = 1;
            }
        }
    }
}

int is_map_valid(t_data *data)
{
    MapValidationData map_data;
    initialize_map_validation_data(&map_data);
    validate_map(data, &map_data);
    get_collect_count(data, &map_data.collect_count);
    map_error_msg(map_data, 3);
    if (flood_fill(data, map_data.player_x, map_data.player_y, 
    &map_data.exit_is_accessible) != map_data.collect_count || !map_data.exit_is_accessible)
    {
        printf("Invalid map, collectibles are not accessible or exit is blocked\n");
        exit(1);
    }
    return 1;
}
