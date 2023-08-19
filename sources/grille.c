#include "fonction.h"

void init_grid(t_game *game, int width, int height)										/* Initialise la grille */
{
	int x, y;

	game->width = width;
	game->height = height;

	for (y = 0; y < height; y++)
		for (x = 0; x < width; x++)
			game->grid[y][x] = NO_BLOCK;
}

void init_game(t_game *game, int width, int height)										/* Initialise le jeu */
{
	init_grid(game, width, height);
	init_block_generator_array(game);
}

int	is_full_line(t_game *game, int y)													/* Vérifie si la ligne est complète */
{
	int	x;

	for (x = 0; x < game->width; x++)
		if (game->grid[y][x] == NO_BLOCK)
			return 0;
	return 1;
}

int	delete_line(t_game *game)															/* Supprime la ligne si elle est complète */
{
	int x, y;

	for (y = 0; y < game->height; y++)
	{
		if (is_full_line(game, y))
		{
			for (x = 0; x < game->width; x++)
				game->grid[y][x] = 0;
			return (y);
		}
	}

	return -1;
}

void grid_move(t_game *game, int index)													/* Déplace la grille pour le cas où une ligne a été supprimée */
{
	int y, x;

	for (y = index; y > 0; y--)
		for (x = 0; x < game->width; x++)
			game->grid[y][x] = game->grid[y - 1][x];
}


int is_in_grid(t_game *game, float x, float y)											/* Vérifie si le x et y est dans la grille */
{
	return !(x < 0 || x >= game->width || y < 0 || y >= game->height);					/* Si x est dans la grille du jeu retourne 1, retourne 0 si ce n'est pas la cas */
}


int can_place_tile(t_game *game, float x, float y){										/* Vérifie si la tuile d'un block peut être placé */
  return (is_in_grid(game, x, y) && game->grid[(int)y][(int)x] == NO_BLOCK );			/* Si le x et y est dans la grille et qu'il n'y a pas de tuile retourne 1 */
}



int can_place_block(t_game *game, t_block b, float x, float y){							/* Vérifie si chaque tuile d'un block peut être placé */
  return (can_place_tile(game, x + b.tile1.x, y+b.tile1.y)
          && can_place_tile(game, x + b.tile2.x, y+b.tile2.y)
          && can_place_tile(game, x + b.tile3.x, y+b.tile3.y)
          && can_place_tile(game, x + b.tile4.x, y+b.tile4.y)) ;
}


void set_block(t_game *game, t_block b, float x, float y)								/* Place le block */
{
	game->grid[(int)(y + b.tile1.y)][(int)(x + b.tile1.x)] = b.type;
	game->grid[(int)(y + b.tile2.y)][(int)(x + b.tile2.x)] = b.type;
	game->grid[(int)(y + b.tile3.y)][(int)(x + b.tile3.x)] = b.type;
	game->grid[(int)(y + b.tile4.y)][(int)(x + b.tile4.x)] = b.type;
}

void unset_block(t_game *game, t_block b, float x, float y){							/* Enlève le block / Change le type block en NO_BLOCK */
  b.type = NO_BLOCK;
  set_block(game,b,x,y);
}



int game_over(t_game *game,  t_block b, float x, float y){								/* Jeu terminé */
  if ( !can_place_block(game, b, x, y) && ( b.tile1.y < 0 || b.tile2.y < 0 || b.tile3.y < 0 || b.tile4.y < 0)){
    return 1;
  }
  else return 0;
}
