#include "fonction.h"


MLV_Color get_color(t_block_type type)														/* Associe à chaque type de block une couleur*/
{
	switch (type)                                  
	{
	case NO_BLOCK:
		return MLV_COLOR_BLACK;
	case O_BLOCK :
		return MLV_COLOR_BLUE;
	case I_BLOCK :
		return MLV_COLOR_RED;
	case S_BLOCK :
		return MLV_COLOR_GREEN;
	case Z_BLOCK :
		return MLV_COLOR_DARKSALMON;
	case L_BLOCK :
		return MLV_COLOR_PINK;
	case J_BLOCK :
		return MLV_COLOR_BROWN;
	case T_BLOCK :
		return MLV_COLOR_CYAN;
	}
	return MLV_COLOR_BLACK;
}

void	display_tile(t_tile tile, float x, float y, MLV_Color color)						/* Affiche une tuile d'un block*/
{
	MLV_draw_filled_rectangle(OFFSET_X + x * TILE_WIDTH + tile.x * TILE_WIDTH,
							OFFSET_Y + y * TILE_HEIGHT + tile.y * TILE_HEIGHT,	
							TILE_WIDTH,
							TILE_HEIGHT,
							color);
}

void	display_block(t_block block, float x, float y)										/* Affiche un block entier */
{
	MLV_Color block_color;

	block_color = get_color(block.type);
	display_tile(block.tile1, x, y, block_color);											/*dessine le block*/
	display_tile(block.tile2, x, y, block_color);
	display_tile(block.tile3, x, y, block_color);
	display_tile(block.tile4, x, y, block_color);
}


void display_background()																	/* Affiche le fond du jeu */
{
	MLV_Image *image;
	image = MLV_load_image("image/fond_in_game.jpg" ); 
	MLV_draw_image( image, 0, 0 );
}


void	display_grid(t_game *game)															/* Affiche la grille */
{
	int x, y;
	for (y = 0; y < game->height; y++)
	{
		for (x = 0; x < game->width; x++)
		{
            if (game->grid[y][x] != NO_BLOCK)
			{
				MLV_draw_filled_rectangle(x * TILE_WIDTH + OFFSET_X,
											y * TILE_HEIGHT + OFFSET_Y,				
											TILE_WIDTH,
											TILE_HEIGHT,
											get_color(game->grid[y][x]));
			}
            else
			{
				MLV_draw_filled_rectangle(x * TILE_WIDTH + OFFSET_X,
									y * TILE_HEIGHT + OFFSET_Y,
									TILE_WIDTH,
									TILE_HEIGHT,							
									MLV_COLOR_BLACK);
				MLV_draw_rectangle(x * TILE_WIDTH + OFFSET_X,
									y * TILE_HEIGHT + OFFSET_Y,
									TILE_WIDTH,
									TILE_HEIGHT,
									MLV_COLOR_WHITE);
			}
		}
	}

}


void display_score(t_game *game)															/* Affiche le score */
{
	int gap_x;
	MLV_Font* font;
	char text[20];
	gap_x = game->width * TILE_WIDTH + OFFSET_X*2;
	font = MLV_load_font( "font/pixel.ttf" , 60 );
	sprintf(text, "%d", game->score);
	MLV_draw_filled_rectangle(gap_x,
						510,
						180,
						60,							
						MLV_COLOR_BLACK);
	MLV_draw_text_with_font(gap_x, 510, text, font, MLV_COLOR_WHITE); 
	MLV_free_font(font);
}

void display_pause()																		/* Affichage le bouton pause*/
{
	MLV_Button_state state ;
	MLV_Keyboard_button	key;	
	MLV_Event event;
	int mx,my;
	mx = 0;
	my = 0;
	button(1000,100,100,100,"image/pause.png");
	key = MLV_KEYBOARD_NONE;
	event = MLV_get_event(&key, NULL, NULL, NULL, NULL,&mx, &my, NULL, &state);
    if ((mx <= 1100 && mx > 100 && my <= 200 && my > 100) && event == MLV_MOUSE_BUTTON)
    {		
		MLV_free_window();
      	menu();
    }
	
}


void display_best_score()
{
	MLV_Font* font;
	MLV_Font* font2;
	MLV_Event event_type = MLV_NONE ;
	MLV_Keyboard_button key;
    FILE * file;
	int mx, my;
    char score[20];
    file = fopen("scoreboard.txt", "r");
	if (fgets(score,10,file) == NULL)
    {
		printf("erreur aucun score.\n");
    } 
	MLV_create_window("score", "score", 1200, 900);
	font = MLV_load_font( "font/pixel.ttf" , 300 );
	font2 = MLV_load_font( "font/pixel.ttf" , 125 );
	MLV_draw_text_with_font(225, 225, score, font, MLV_COLOR_WHITE);
	MLV_draw_text_with_font(175, 50, "BEST SCORE:", font2, MLV_COLOR_WHITE);
	MLV_draw_rectangle(0, 225, 1200, 400, MLV_COLOR_WHITE);
	button(1000, 700, 100, 100, "image/retourner_au_menu.png");
	MLV_free_font(font);
	MLV_free_font(font2);
	MLV_actualise_window();
    fclose(file);
	while(key != MLV_KEYBOARD_ESCAPE)
	{
		event_type = MLV_wait_keyboard_or_mouse( &key, NULL, NULL, &mx, &my );
		if (mx <= 1100 && mx > 1000 && my <= 800 && my > 700 && event_type == MLV_MOUSE_BUTTON)
    	{
      		MLV_free_window();
      		menu();
    	}

	} 
}