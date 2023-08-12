#ifndef SO_LONG_H
# define SO_LONG_H

#define FRONT 0
#define BACK 1
#define LEFT 2
#define RIGHT 3
#include <stdio.h> //test
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//#include "get_next_line.h"
#include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
//# include <X11/X.h>
//#include <X11/keysym.h>

typedef struct
{
    int player_x;
    int player_y;
    int player_found;
    int exit_found;
    int collect_count;
    int exit_is_accessible;
    int y;
    int x;
} MapValidationData;


typedef struct s_data
{
    int width;  //lines of text
    int height; //numbers in a line
    char **mp; //matrix of height * width 
    char **mapp;
    int moves;
    int win_h;
    int win_w;
    int enemy_count;
  //  int exit_x;
//    int exit_y;
    int animation_frame;
    int player_x;
    int player_y;
   //getting from the file with gnl and split and atoi and assigning to matrix elements;
    void	*player;
    void	*player_frames[4][2];
	void	*exit;
	int current_direction;
    void    *collectable;
    void    *wall;
    void    *free_space;
    void    *enemy;
    void *mlx; //connection ptr
    void *win; //window ptr
    char **original_map;
     int player_x_v;
    int player_y_v;
    int player_found;
    int exit_found;
    int collect_count;
    int exit_accs;
} t_data;



//main.c

//void print_matrix(const t_data *data); //delete later
void free_map(t_data *data);
void free_data(t_data *data);
void print_processed_map(char *processed_map);
void get_map1(char *filename, t_data *data);
int valid_char(char c);
int valid(t_data *data);
int counter(t_data *data, int *player_count, int *exit_count, int *collectable);
void borders(t_data *data);
int fl_fill(t_data *data, int x, int y, int *exit_accs);
int is_map_valid(t_data *data);
void  map_validation(t_data *data);


//file_pars_utils.c
int	ft_strncmp(const char *s1, const char *s2, size_t	n);
char	*ft_strchr_v(const char	*str, int c);
size_t	ft_strlen_v(const char *str);
void check_filename(char *filename);


//get_next_line_utils.c 
char	*ft_itoa(int n);
char	*handle_zero(int n);
int	count_digits(int n);
char	*ft_strdup_itoa(const char *str);
size_t	ft_strlen(char	*s);

//get_next_line.c

char *get_next_line(int fd);

//join_lines.c 
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin2(char *s1, char *s2);

//ft_split.c
size_t	ft_strlen_spl(const char *str);
void	*ft_memcpy(void	*dst, const void	*src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_memory(char **ptr_ss, long index);
long	count_of_words(char const *s, char c);
long	word_len(char const *s, char c, long i);
char	**ft_split(char const *s, char c, int *size, long *i);
char	**call_split(char *res, int *size);

//trim_nl.c
char	*ft_strtrim(char const *s1, char const *set);
void	split_clean(char **split_res);
void nl_in_between(char *str);
void get_width(char **res, int *width);
int ft_strlen_excl(const char *str);


void alloc_mp(t_data *data);
void allocate_map(t_data *data);
void init_vals(char **res, t_data *data);
void check_lines_len(char **res);
void trim(t_data *data, char *str, int *height, int *width);

int close_with_x(t_data *data);
void w_is_pressed(t_data *data);
void s_is_pressed(t_data *data);
void a_is_pressed(t_data *data);
void d_is_pressed(t_data *data);

int win_case(t_data *data);
void graphics(t_data *data);
int handle_key(int keycode, t_data *data);
int write_moves(t_data *data);
void find_player_coordinates(t_data *data);
void ft_image(t_data *data);
void	load_image(t_data *data);
void  map_validation(t_data *data);
int is_map_valid(t_data *data);
void get_collect_count(t_data *data, int *collect_count);
int fl_fill(t_data *data, int x, int y, int *exit_accs);
void borders(t_data *data);
int obj_count(t_data *data, int *player_count, int *exit_count, int *collectable);
int valid(t_data *data);
int valid_char(char c);
void get_map1(char *filename, t_data *data);
void file_error_msg(int fd, char *line, int flag);
void get_map2(int fd, char *res, char *str, t_data *data);
void free_data(t_data *data);
void free_map(t_data *data);
void free_map_j(t_data *data, int i);
void ternary_to_ord_if(t_data *data);
void oh_dear_norm(t_data *data);
#endif
