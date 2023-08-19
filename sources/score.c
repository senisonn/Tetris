#include "fonction.h"

int read_score()
{
    FILE *file;
    int score;
    file = fopen("scoreboard.txt", "r");
    if (file==NULL)
    {
        printf("erreur fichier vide\n");
    }
    if(fscanf(file,"%d",&score) == 1)
    {
        fclose(file);
    }
    return score;
}

void write_score(t_game * game)
{
    FILE * file;
    int previous_score;

    previous_score = read_score();
    file = fopen("scoreboard.txt", "w");

    if (previous_score < game->score)
    {
        fprintf(file,"%d",game->score);
    }
    else 
    {
        fprintf(file,"%d",previous_score);
    }
    fclose(file);
}


