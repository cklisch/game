#include <stdlib.h>
#include <stdio.h>

#define BLACK 1
#define WHITE 2

struct Tile {
  int player;
};

struct Game {
  struct Tile* board;
  int size;
};

typedef struct Game Game;
typedef struct Tile Tile;

int error = 0;

void reset_tile(Tile* tile) {
  tile->player = 0;
}

void set_game(Game* game) {
  int n = game->size * game->size;
  for (int i = 0; i < n; i++) {
    reset_tile(game->board + i);
  }
}
/* 1.) All right, first comment. I want to try making it easier to understand this code.
My goal is to explaining how the program works.
Here is the first important function. I pass a pointer to modify the game struct.
Next comment on line 72
*/
void init_game(Game* game, int size) {
  game->board = (Tile*)malloc(size * size * sizeof(Tile*));
  game->size = size;
}
/* 4.) Returns pointer to the requested tile. If out of bound it sets the error
and returns valid tile.
Next comment on line 52
*/
Tile* get_tile(Game* game, int x, int y) {
  int size = game->size;
  if (x < size && x >= 0 && y < size && y >= 0) {
    return &game->board[(y * size) + x];
  }
  error = 1;
  return &game->board[0];
}
/* 5.) Prints the game board.
Because malloc doesn't allocate empty memory the output might look random.
To prevent this set the game!
*/
void print_game(Game* game) {
  for (int i = 0; i < game->size; i++) {
    for (int j = 0; j < game->size; j++) {
      Tile* t = get_tile(game, i, j);
      printf("%d ", t->player);
    }
    printf("\n");
  }
}
/* 3.) Here we get the tile pointer and mark it with the players id
Next comment on line 40
*/
void place_stone(Game* game, int id, int x, int y) {
  Tile* tile = get_tile(game, x, y);
  tile-> player = id;
}
/* 2.) Here the program starts running
It will print a representation of the board on the screen after one stone is placed.
Next comment on line 65
*/
int main() {
  Game game;
  init_game(&game, 19);
  place_stone(&game, BLACK, 0, 0);
  print_game(&game);
  return error;
}
