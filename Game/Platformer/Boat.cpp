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

#include "Boat.h"
#include "frogger.h"

// ---------------------------------------------------------------------------------
Boat::Boat()
{
    tileset = new TileSet("Resources/boat.png", 91, 40, 1, 1);
    anim = new Animation(tileset, 0.120f, true);
    
    BBox(new Rect(-15,
        -1,
        15,
        0
    ));
    type = BOAT;
}

// ---------------------------------------------------------------------------------

Boat::~Boat()
{
    delete tileset;
    delete anim;
}

// ---------------------------------------------------------------------------------

void Boat::OnCollision(Object* obj)
{
    //Translate(0, -100);
    //Platformer::scene->Remove();

}

// ---------------------------------------------------------------------------------

void Boat::Update()
{
    Translate(velX * gameTime, 0);

    if (X() + tileset->Width() <= 0) {
        MoveTo(window->Width() + tileset->Width()/2.0f, Y());
    }
}

// ---------------------------------------------------------------------------------