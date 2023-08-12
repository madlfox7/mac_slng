#include "so_long.h"


void image_load_checker(t_data *data)
{

    if (!data->player_frames[0][0] || !data->player_frames[0][1] || !data->player_frames[1][0] || !data->player_frames[1][1] || !data->player_frames[2][0] || !data->player_frames[2][1] || !data->player_frames[3][0] || !data->player_frames[3][1])
    {
        printf("Error: Failed to load images.\n");
        exit(1);
    }
    if (!data->player || !data->wall || !data->free_space || !data->collectable || !data->exit || !data->enemy)
    {
        printf("Error: Failed to load images.\n");
        exit(1);
    }  
}

void	load_image(t_data *data)
{

   int size_h = (data->win_h) / 64;
   int size_w = (data->win_w) / 64;
   data->player_frames[0][0] = mlx_xpm_file_to_image(data->mlx, "assets/f1.xpm", &size_h, &size_w);
   data->player_frames[0][1] = mlx_xpm_file_to_image(data->mlx, "assets/f2.xpm", &size_h, &size_w);
   data->player_frames[1][0] = mlx_xpm_file_to_image(data->mlx, "assets/b1.xpm", &size_h, &size_w);
   data->player_frames[1][1] = mlx_xpm_file_to_image(data->mlx, "assets/b2.xpm", &size_h, &size_w);
   data->player_frames[2][0] = mlx_xpm_file_to_image(data->mlx, "assets/l1_1.xpm", &size_h, &size_w);
   data->player_frames[2][1] = mlx_xpm_file_to_image(data->mlx, "assets/l2.xpm", &size_h, &size_w);
   data->player_frames[3][0] = mlx_xpm_file_to_image(data->mlx, "assets/r1.xpm", &size_h, &size_w);
   data->player_frames[3][1] = mlx_xpm_file_to_image(data->mlx, "assets/r2.xpm", &size_h, &size_w);
     data->player = mlx_xpm_file_to_image(data->mlx, "assets/pl.xpm", &size_h, &size_w);
    data->wall = mlx_xpm_file_to_image(data->mlx, "assets/wall_1.xpm", &size_h, &size_w);
    data->free_space = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm", &size_h, &size_w);
    data->collectable =  mlx_xpm_file_to_image(data->mlx, "assets/collectable.xpm", &size_h, &size_w);
    data->exit =  mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm", &size_h, &size_w);
    data->enemy =  mlx_xpm_file_to_image(data->mlx, "assets/enemy.xpm", &size_h, &size_w);
image_load_checker(data);
    data->moves = 0;
}

void ft_image(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
   // printf("___data height %d\n", data->height);
    while (i < data->height)
    {
       // printf("___data height %d\n", data->height);
        j = 0;
        while (j < data->width)
        {
            if (data->mapp[i][j] == '1')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 64, i * 64);
            }
            else if (data->mapp[i][j] == 'P')
            {
		            int frame_index = 0;
		            if (data->current_direction == BACK)
		                frame_index = 1;
	 	            else if (data->current_direction == LEFT)
		                frame_index = 2;
		            else if (data->current_direction == RIGHT)
			            frame_index = 3;
///in other function????
	                mlx_put_image_to_window(data->mlx, data->win, data->player_frames[frame_index][data->animation_frame - 1], j * 64, i * 64);
                }
                else if (data->mapp[i][j] == '0')
                        mlx_put_image_to_window(data->mlx, data->win, data->free_space, j * 64, i * 64);
                     else if (data->mapp[i][j] == 'C')
                        mlx_put_image_to_window(data->mlx, data->win, data->collectable, j * 64, i * 64);
                    else if (data->mapp[i][j] == 'E')
                         mlx_put_image_to_window(data->mlx, data->win, data->exit, j * 64, i * 64);
                    else if (data->mapp[i][j] == 'T')
                         mlx_put_image_to_window(data->mlx, data->win, data->enemy, j * 64, i * 64);
                 j++;
         }
        i++;
    }
 }

 int handle_key(int keycode, t_data *data)
{
    find_player_coordinates(data);
    if (keycode == 53)
    {
        printf("Techie is tired and decided to go on vacation, work will wait ✈️\n");
        exit(0);  
    } //into_another close function  
    else if (keycode == 13 && data->mapp[data->player_x - 1][data->player_y] != '1') //not wall w is pressed
    {	
    	data->current_direction = FRONT;	    
	    w_is_pressed(data);
    }
    else if (keycode == 1 && data->mapp[data->player_x + 1][data->player_y] != '1')
    {	   
	    data->current_direction = BACK;
	    s_is_pressed(data);
    }
    else if (keycode == 0 && data->mapp[data->player_x][data->player_y - 1] != '1')
    {
	    data->current_direction = LEFT;
    	    a_is_pressed(data);
    }
    else if (keycode == 2 && data->mapp[data->player_x][data->player_y + 1] != '1')
    {
	    data->current_direction = RIGHT;
    	    d_is_pressed(data);
    }
     mlx_clear_window(data->mlx, data->win);
    ft_image(data);
	 return (0); 
}


void graphics(t_data *data)
{
    data->win_h = (data->height) * 64;
    data->win_w = (data->width) * 64;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, "so_long");
    load_image(data); 
    data->animation_frame = 1;
    data->current_direction = FRONT;
    ft_image(data);
    mlx_hook(data->win, 2, 0,  handle_key, data);
     mlx_hook(data->win, 17, 0, close_with_x, data);
    mlx_loop_hook(data->mlx, write_moves, data);

    mlx_loop(data->mlx);
}