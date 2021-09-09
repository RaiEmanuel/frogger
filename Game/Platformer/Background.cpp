/**********************************************************************************
// Background (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"
#include "frogger.h"
#include "engine.h"
#include "GameOver.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
    bg = new Sprite("Resources/bg.png");
    BBox(new Rect(0.0f,155.0f,bg->Width(), 330.0f));
    type = WATER;
    /*MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = xB = x;

    // carrega imagens
    imgF = new Image("Resources/BackgFront.png");
    imgB = new Image("Resources/BackgBack.png");

    // cria sprites do plano de fundo
    sky     = new Sprite("Resources/Sky.png");    
    backgF1 = new Sprite(imgF);
    backgF2 = new Sprite(imgF);
    backgB1 = new Sprite(imgB);
    backgB2 = new Sprite(imgB);*/
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete bg;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    //Engine::Next<GameOver>();
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    bg->Draw(208, 312, Layer::BACK);
}

void Background::OnCollision(Object* obj)
{
    //Engine::Next<GameOver>();
}

// -------------------------------------------------------------------------------

