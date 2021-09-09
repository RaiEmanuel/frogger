/**********************************************************************************
// Platformer (Código Fonte)
//
// Criação:     05 Out 2011
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Exemplo de jogo estilo platforma
//
**********************************************************************************/

#include "Engine.h"
#include "Resources.h"
#include "GameOver.h"
#include "Frogger.h"
#include "Frogger.h"

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

void GameOver::Init()
{
    bg = new Sprite("Resources/gameover.png");

}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    if (keyCtrlReturn && window->KeyDown(VK_RETURN)) {
        Engine::Next<Platformer>();
        keyCtrlReturn = false;
    }
    if (window->KeyUp(VK_RETURN)) keyCtrlReturn = true;
    

}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    bg->Draw(bg->Width()/2.0f, bg->Height() / 2.0f, Layer::BACK);
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete bg;
}


