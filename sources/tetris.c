#include "fonction.h"


int tetris()
{
  /*FILE *fic;*/
  t_game				game;
  t_block				block, next_block;
  t_block				temp_block;
  float					x, y;
  int					block_can_be_placed, deleted_y, acc, i, score, speed, a ;
  MLV_Button_state state ;
  MLV_Keyboard_button	key;	
  srand(time(NULL));	
																					
  MLV_create_window("tetris", "tetris", 1200, 900);												/* Création de la fenêtre */
  init_game(&game, 10, 20);																		/* Initialise le jeu */
  init_block_generator_array(&game);

  speed = 100;																					/* Vitesse du jeu */
  a = 1;																						/* Variable qui indique si la vitesse doit augmenter */
  next_block = get_random_block(&game);															/* Définit le prochain block pour la 1ère itération */
  game.score = 0;																				/* Initialise le score de la partie en cours à 0 */
  acc = 0;																						/* Accumulateur qui va compter combien de ligne ont été supprimé même temps */
  score = 0;																					/* Enregistre le score pour pouvoir le stocker après dans le score du jeu */
  MLV_change_frame_rate(24);

  do
    {
	  score = game.score ;
      block = next_block;																		
      next_block = get_random_block(&game);
      x = 5;																					/* coordonée x pour */
      y = 1;
      if (block.type == I_BLOCK || block.type == O_BLOCK)										/* Si le block est un I block ou un O block alors on définit le centre du block */
	{
	  x -= 0.5f;
	  y += 0.5f;
	}

      block_can_be_placed = can_place_block(&game, block, x, y);
      if (!block_can_be_placed)
	{
	  printf("Fin jeu\n");
	  printf("%d\n",game.score);
	  write_score(&game);
	  return 1;
	}
		
    while (block_can_be_placed)
	{
	  MLV_clear_window(MLV_COLOR_BLACK);
	  display_background();
	  for (i = 0 ; i < speed ; i++ )
	  {
		  MLV_get_event(&key, NULL, NULL, NULL, NULL,NULL, NULL, NULL, &state);

	
	      if (key == MLV_KEYBOARD_UP && state == MLV_PRESSED)
	       {
	        temp_block = rotation_block(block);
	        if (can_place_block(&game, temp_block, x, y))
			{
		      block = temp_block;
	        }
	       }
		   else if( key == MLV_KEYBOARD_DOWN && state == MLV_PRESSED)
		   {
			 if (can_place_block(&game, temp_block, x, y + 2))
			{
		      y = y + 2 ;
	        }
		   }

	   		else if (key == MLV_KEYBOARD_LEFT && can_place_block(&game, block, x - 1, y) && state == MLV_PRESSED)
	    	{
	      		x--;
	    	}
	  		else if (key == MLV_KEYBOARD_RIGHT && can_place_block(&game, block, x + 1, y) && state == MLV_PRESSED)
	    	{
	      		x++;
	    	}
			display_grid(&game);
			display_score(&game);
			display_block(next_block, 13, 5);
			display_block(block, x, y);
			key = MLV_KEYBOARD_NONE ;
			state = MLV_NONE ;
			MLV_actualise_window();
	  }
	  
	  block_can_be_placed = can_place_block(&game, block, x, y + 1);
	  if (block_can_be_placed)
	  {
	      y++;
	  }
	  else
	    {
	      set_block(&game, block, x, y);
	      game.score = score + 10;
	      deleted_y = delete_line(&game);
		  acc = 0;
	      while (deleted_y != -1)
		  {
		   grid_move(&game, deleted_y);
		   deleted_y = delete_line(&game);
		   acc += 1;
		  }

	      if(acc == 1)
		  {
		   game.score = score + 100 ;
		  }
	      else if(acc == 2)
		  {
		    game.score = score + 200;
		  }
	      else if(acc == 3 )
		  {
		  	game.score = score + 500;
		  }
	      else if(acc == 4)
		  {
		  	game.score = score + 1500 ;
		  }
		  else if(game.score >= 1000 && game.score < 3000 && a == 1)
  		  {
	 		speed = speed/2;
	 		a = 2;
          }
  		  else if (game.score >= 3000 && game.score < 6000 && a == 2)
 		  {
		    speed = speed-20;
			a = 3;
  		  }
		  else if (game.score >= 3000 && game.score < 6000 && a == 3)
 		  {
		    speed = speed-10;
			a = 4;
  		  }
	    }	
	}
		
      MLV_delay_according_to_frame_rate();
    } while (1);
  return 1;
}
