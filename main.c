#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

const int SCREEN_WIDTH = 200;
const int SCREEN_HEIGHT = 100;

struct piece{
  Vector2 cube[4];
  int vel;
};
typedef struct piece piece;
void restart_piece(piece *active, piece *start){
  for(int i = 0; i < 4; i++){
    (active->cube)[i].x = (start->cube)[i].x;
    (active->cube)[i].y = (start->cube)[i].y;
  }
}
void move(piece *piece, int map[20][10]){
  bool flag = false;
  for(int i = 0; i < 4; i++){
    if(map[(piece->cube[i]).y][(piece->cube[i]).x + piece->vel]) || (piece->cube[i]).x + piece->vel < 1 || (piece->cube[i]).x + piece->vel > 18){
      flag = true;
      break;
    }
  }
  if(!flag){
    for(int i = 0; i < 4; i++){
      (piece->cube[i]).x += piece->vel;
    }
  }
  piece->vel = 0;
  return;
}
int main(){
  int count = 0;
  bool map[20][10];
  for(int y = 0; y < 20; y++){
    for(int x = 0; x < 10; x++){
      map[y][x] = false;
    }
  }
  piece start_piece[7];
  InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "tetris");
  unsigned int rng = 0;
  SetTargetFPS(60);
  piece piece;
  piece.vel = 0;
  restart_piece(&piece, &start_piece[rng]);
  bool gamewin = false;
  bool gameover = false;
  while(!WindowsShouldClose()){
    while(!gamewin && !gameover){
      count += 1;
      for(int i = 0; i < 4; i++){
        if(mapa[piece.cube[i].y + 1][piece.cube[i].x]){
          for(int a = 0; a < 4; a++){
            mapa[piece.cube[a].y][piece.cube[a].x] = true;
          }
          restart_piece(&piece, &start_piece[rng]);
          if(rng == 7){
            rng = 0;
          } else {
            rng += 1;
          }
          break;
        }
      }
      if(IsKeyDown(KEY_LEFT)){
        piece.vel = -1;
      }
      if(IsKeyDown(KEY_LEFT)){
        piece.vel = 1;
      }
      move(&piece, map);
      








      
    }
  }
  
  return 0;
}
