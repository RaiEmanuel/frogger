
#include "Engine.h"
#include "frogger.h"
#include "Resources.h"
#include "GameOver.h"

// -----------------------------------------------------------------------------

Scene* GameOver::scene = nullptr;

// -----------------------------------------------------------------------------

void GameOver::Init()
{
    // cria cena do jogo
    scene = new Scene();
    //fica depois dos botes para preferência na colisão
    bg = new BackgroundGameOver("Resources/bggameover.png");
    scene->Add(bg, STATIC);
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();

    if (keyCtrlReturn && window->KeyDown(VK_RETURN)) {
        keyCtrlReturn = false;
        Engine::Next<Frogger>();
    }
    if (window->KeyUp(VK_RETURN)) keyCtrlReturn = true;
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    scene->Draw();
    scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete scene;
}

