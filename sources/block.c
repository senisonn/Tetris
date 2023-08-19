#include "fonction.h"

void init_block_generator_array(t_game *game)									/* Place les block dans le tableau de générateur de block*/								
{
	game->block_generator_array[0] = get_o_block;
	game->block_generator_array[1] = get_i_block;
	game->block_generator_array[2] = get_s_block;
	game->block_generator_array[3] = get_z_block;
	game->block_generator_array[4] = get_l_block;
	game->block_generator_array[5] = get_j_block;
	game->block_generator_array[6] = get_t_block;
}

t_block get_o_block()															/* Crée le block o */
{
	t_block block;

	block.tile1.x = -0.5;
	block.tile1.y = -0.5;

	block.tile2.x = 0.5;
	block.tile2.y = -0.5;

	block.tile3.x = 0.5;
	block.tile3.y = 0.5;

	block.tile4.x = -0.5;
	block.tile4.y =  0.5;

	block.type = O_BLOCK;
	
	return block;
}

t_block get_i_block()															/* Crée le block i */
{
	t_block block;

	block.tile1.x = -1.5;
	block.tile1.y = -0.5;
	
	block.tile2.x = -0.5;
	block.tile2.y = -0.5;
	
	block.tile3.x = 0.5;
	block.tile3.y = -0.5;
	
	block.tile4.x = 1.5;
	block.tile4.y = -0.5;
	
	block.type = I_BLOCK;

	return block;
}

t_block get_s_block()															/* Crée le block s */
{
	t_block block;

	block.tile1.x = -1.0;
	block.tile1.y = 0.0;
	
	block.tile2.x = 0.0;
	block.tile2.y = 0.0;
	
	block.tile3.x = 0.0;
	block.tile3.y = -1.0;
	
	block.tile4.x = 1.0;
	block.tile4.y = -1.0;

	block.type = S_BLOCK;
	
	return block;
}

t_block get_z_block(){															/* Crée le block z */
	t_block block;
	
	block.tile1.x = -1.0;
	block.tile1.y = -1.0;
	
	block.tile2.x = 0.0;
	block.tile2.y = -1.0;
	
	block.tile3.x = 0.0;
	block.tile3.y = 0.0;
	
	block.tile4.x = 1.0;
	block.tile4.y = 0.0;

	block.type = Z_BLOCK;
		
	return block;
}

t_block get_l_block(){															/* Crée le block l */
	t_block block;

	block.tile1.x = 1.0;
	block.tile1.y = -1.0;
	
	block.tile2.x = -1.0;
	block.tile2.y = 0.0;
	
	block.tile3.x = 0.0;
	block.tile3.y = 0.0;
	
	block.tile4.x = 1.0;
	block.tile4.y = 0.0;
	block.type = L_BLOCK;

	return block;
}

t_block get_j_block()															/* Crée le block j */
{
	t_block block;

	block.tile1.x = -1.0;
	block.tile1.y = -1.0;

	block.tile2.x = -1.0;
	block.tile2.y = 0.0;

	block.tile3.x = 0.0;
	block.tile3.y = 0.0;

	block.tile4.x = 1.0;
	block.tile4.y = 0.0;

	block.type = J_BLOCK;
	return block;
}

t_block get_t_block()															/* Crée le block t */
{
	t_block block;

	block.tile1.x = 0.0;
	block.tile1.y = -1.0;
	
	block.tile2.x = -1.0;
	block.tile2.y = 0.0;
	
	block.tile3.x = 0.0;
	block.tile3.y = 0.0;
	
	block.tile4.x = 1.0;
	block.tile4.y = 0.0;

	block.type = T_BLOCK;

	return block;
}

t_block	get_random_block(t_game *game)											/* Retourne un block aléatoire du tableau générateur de block */
{
	return game->block_generator_array[rand() % 7]();
}

t_block rotation_block(t_block t)
{
	float tmp1, tmp2, tmp3, tmp4;

	tmp1 = t.tile1.x;

	t.tile1.x = -t.tile1.y;
	t.tile1.y = tmp1 ;

	tmp2 = t.tile2.x;

	t.tile2.x = -t.tile2.y;
	t.tile2.y = tmp2 ;

	tmp3 = t.tile3.x;

	t.tile3.x = -t.tile3.y;
	t.tile3.y = tmp3 ;

	tmp4 = t.tile4.x;

	t.tile4.x = -t.tile4.y;
	t.tile4.y = tmp4 ;

	return t;
}
