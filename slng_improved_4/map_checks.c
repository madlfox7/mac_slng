#include "so_long.h"


int valid_char(char c)
{
    if (c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C' || c == 'T')
        return 1;
    return 0;
}

int valid(t_data *data)
{
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
        {
            if (!valid_char(data->mp[i][j]) )
            {
                return 0;
            }
        }
    }
    return 1;
} 

void borders(t_data *data)
{
    
    if (data->width < 3 || data->height < 3)
        exit(1); ///?????
    for (int i = 0; i < data->height; i++)
    {
          for (int j = 0; j < data->width; j++)
          {
                if ((i == 0 || i == (data->height - 1)) && data->mp[i][j] != '1')
                {
                    printf("Map must be surrounded by walls\n");
                    exit(1);
                }
                else if ((j == 0 || j == data->width - 1 ) && data->mp[i][j] != '1')
                {
                       printf("Map must be surrounded by walls\n");
                    exit(1);
                }
          }
    }
} //change fors


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


int is_map_valid(t_data *data)
{
    int player_x = -1;
    int player_y = -1;
    int player_found = 0;
    int exit_found = 0;
    int collect_count = 0;
    int exit_is_accessable = 0;
    
    
    for (int y = 0; y < data->height; y++)
    {
        for (int x = 0; x < data->width; x++)
        {
            if (data->mp[y][x] == 'P')
            {
                if (player_found)
                {
                    printf("Error: Multiple players (P) found!\n");
                    return 0;
                }
                player_x = x;
                player_y = y;
                player_found = 1;
            }
            else if (data->mp[y][x] == 'E')
            {
                if (exit_found)
                {
                    printf("Error: Multiple exits (E) found!\n");
                    return 0;
                }
                exit_found = 1;
            }
        }
    }
    get_collect_count(data, &collect_count);
   // printf("\ncollect count = %d\n", collect_count);
   
    if (!player_found)
    {
        printf("Error: Player (P) not found!\n");
        return 0;
    }
    if (!exit_found)
    {
        printf("Error: Exit (E) not found!\n");
        return 0;
    }
    if (flood_fill(data, player_x, player_y, &exit_is_accessable) != collect_count || !exit_is_accessable)
    {
        printf("Invalid map, collectables are not accessible or exit is blocked\n");
        exit(1);
    }
    return 1;
}
