#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

#define OFFSET_X 150 
#define OFFSET_Y 75
#define TILE_WIDTH 40
#define TILE_HEIGHT 40

typedef struct {                                    /* Type tuile d'un block */
  float x;
  float y;
} t_tile;







typedef enum {                                       /* Type block */
  NO_BLOCK = 0,
  O_BLOCK = 1,
  I_BLOCK = 2,
  S_BLOCK = 3,
  Z_BLOCK = 4,
  L_BLOCK = 5,
  J_BLOCK = 6,
  T_BLOCK = 7
}  t_block_type;


typedef struct {                                      /* Block avec ses tuiles et son type */
  t_tile tile1;
  t_tile tile2;
  t_tile tile3;
  t_tile tile4;
  t_block_type type;
} t_block;


typedef struct {
  int width;
  int height;
  int grid[MAX_HEIGHT][MAX_WIDTH];
  t_block (*block_generator_array[7])(void);
  int score;

} t_game;
