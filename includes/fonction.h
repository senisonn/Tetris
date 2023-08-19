#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"





/*block.c*/

void init_block_generator_array(t_game *game);
t_block get_o_block();
t_block get_i_block();
t_block get_s_block();
t_block get_z_block();
t_block get_l_block();
t_block get_j_block();
t_block get_t_block();
t_block get_random_block();
t_block rotation_block(t_block t);



/*grille.c*/

void	init_game(t_game *game, int largeur, int hauteur);
void	init_grid(t_game *game, int largeur, int hauteur);
int		delete_line(t_game *game);
void	grid_move(t_game *game, int indice);
int		is_in_grid(t_game *game, float x, float y);
int		can_place_tile(t_game *game, float x, float y);
int		can_place_block(t_game *game, t_block b, float x, float y);
void	set_block(t_game *game, t_block b, float x, float y);
void	unset_block(t_game *game, t_block b, float x, float y);
int		game_over(t_game *game,  t_block b, float x, float y);




/*affichage.c*/

MLV_Color	get_color(t_block_type type);
void		display_tile(t_tile tile, float x, float y, MLV_Color color);
void		display_block(t_block block, float x, float y);
void        display_background();
void 		display_grid(t_game *game);
void        display_score(t_game *game);
void        display_pause();

/*menu.c*/

void menu();
void button(int x, int y, int longueur, int hauteur, char* chemin);

/*tetris*/

int tetris();

/*score.c*/
int read_score();
void write_score(t_game * game);
void display_best_score();