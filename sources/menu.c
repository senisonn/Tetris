#include "fonction.h"

void button(int x, int y, int width, int height, char* path)              /* Créer un bouton aux coordonnés x y d'une image */
{
  MLV_Image *img;
  img = MLV_load_image(path);
  MLV_resize_image_with_proportions(img, width, height);
  MLV_draw_image(img, x, y);
}




void menu()                                                                                   /* Fonction du menu */
{
  MLV_Image *image;
  MLV_Event event_type = MLV_NONE ;                                                          /* Initialise l'event */
  MLV_Keyboard_button key;
  int mx,my, tet;
  mx = 0;
  my = 0;
  tet = 0;
  
  MLV_create_window( "Menu", "Menu", 1200, 900 );
  image = MLV_load_image("image/fond.jpg" );   
    
  MLV_draw_image( image, 0, 0 );

  button(400, 225, 800, 400, "image/jouer.png");
  button(100, 30, 250, 250, "image/score.png");

  while(key != MLV_KEYBOARD_ESCAPE && tet == 0  )
  {   
    MLV_actualise_window();
    event_type = MLV_wait_keyboard_or_mouse( &key, NULL, NULL, &mx, &my );                      /* Retourne la touche appuyé ou les coordonnées du click de la souris */

    if (mx <= 800 && mx > 400 && my <= 625 && my > 225 && event_type == MLV_MOUSE_BUTTON)
    {
      MLV_free_window();
      tet = tetris();
    }
    if (mx <= 350 && mx > 100 && my <= 270 && my > 30 && event_type == MLV_MOUSE_BUTTON)
    {
      MLV_free_window();
      display_best_score();
    }
  }
  MLV_free_window();
}
