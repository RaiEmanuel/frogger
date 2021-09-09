/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"
#include "frogger.h"
#include "engine.h"
#include "GameOver.h"

// ---------------------------------------------------------------------------------

/*
RUN - jogo rodando normal

*/

Player::Player()
{
    //type = TYPEOBJ
    tileset = new TileSet("Resources/player.png", 40, 60, 1, 1);
    anim = new Animation(tileset, 0.120f, true);
    MoveTo(window->CenterX(), window->CenterY() + 250);
    BBox(new Rect(-20, 10, 20,30));
    type = PLAYER;
    //statePlayer = RUN;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->type == FRUIT)
        Platformer::scene->Remove(obj, STATIC);

    if (obj->type == BOAT) {
        boat = (Boat*)obj;
    }

    if (obj->type == WATER && boat == nullptr) {
        statePlayer = LOSE;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    /* verifica se está colindindo com bote e desloca junto*/
    if (boat != nullptr) {
        Translate(boat->velX * gameTime, 0);
    }
    boat = nullptr;//garante que só tem o bote se estiver colidindo

    /* Controla tecla para cima */
    if (keyCtrlUp && window->KeyDown(VK_UP)) {
        keyCtrlUp = false;
        Translate(0, -40, 0);
    }
    if (window->KeyUp(VK_UP)) keyCtrlUp = true;
    /* Controla tecla para baixo */
    if (keyCtrlDown && window->KeyDown(VK_DOWN)) {
        keyCtrlDown = false;
        Translate(0, 40, 0);
    }
    if (window->KeyUp(VK_DOWN)) keyCtrlDown = true;
    /* Controla tecla para baixo */
    if (keyCtrlLeft && window->KeyDown(VK_LEFT)) {
        keyCtrlLeft = false;
        Translate(-40, 0, 0);
    }
    if (window->KeyUp(VK_LEFT)) keyCtrlLeft = true;
    /* Controla tecla para direita */
    if (keyCtrlRight && window->KeyDown(VK_RIGHT)) {
        keyCtrlRight = false;
        Translate(40, 0, 0);
    }
    if (window->KeyUp(VK_RIGHT)) keyCtrlRight = true;
}

// ---------------------------------------------------------------------------------
