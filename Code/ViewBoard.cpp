#include "ViewBoard.h"
#include "Game.h"

extern Game* game;

void ViewBoard::placeTiles(int x, int y, int size){
    for (int i = 0; i < size; i++){
        QVector<ViewTile*> tmp;
        for (int j = 0; j < size; j++){
            ViewTile* vtile = new ViewTile();
            if(i==size/2 && j==size/2){ //put starting Tile
                vtile = new ViewTile(game->controller->piocher());
                vtile->setIsPlaced(true);
                game->controller->getPlateau().ajouter(vtile->tile,i,j);
            }
            vtile->setPos(x+102*j,y+102*i);
            tmp.append(vtile);
        }
        tiles.append(tmp);
    }
}
