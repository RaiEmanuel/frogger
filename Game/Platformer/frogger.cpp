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
#include "frogger.h"
#include "Resources.h"
#include "GameOver.h"

// -----------------------------------------------------------------------------

Scene * Platformer::scene = nullptr;

// -----------------------------------------------------------------------------

void Platformer::Init()
{
    // cria cena do jogo
    scene = new Scene();
    
   
    
    //bote primeiro para ter prioridade na colisão
    boat = new Boat();
    boat->MoveTo(window->Width() + 45.0f, 310-45-45-45);
    scene->Add(boat, STATIC);
    boat->velX = -50;
    
    //segundo bote
    boat2 = new Boat();
    boat2->MoveTo(window->Width() + 45.0f, 310-45-45);
    boat2->velX = -45;
    scene->Add(boat2, STATIC);

    //terceiro bote
    boat3 = new Boat();
    boat3->MoveTo(window->Width() + 45.0f, 310-45);
    boat3->velX = -55;
    scene->Add(boat3, STATIC);

    //quarto bote
    boat4 = new Boat();
    boat4->MoveTo(window->Width() + 45.0f, 310);
    boat4->velX = -60;
    scene->Add(boat4, STATIC);

    //fica depois dos botes para preferência na colisão
    backg = new Background();
    scene->Add(backg, STATIC);

    /* obs: deletar tudo no destrutor*/
    
    //maça
    fruit = new Fruit("Resources/apple.png");
    scene->Add(fruit, STATIC);

    //hamburguer
    fruit2 = new Fruit("Resources/hamb.png");
    scene->Add(fruit2, STATIC);
    fruit2->MoveTo(100, 500);

    //hamburguer
    fruit3 = new Fruit("Resources/cake.png");
    scene->Add(fruit3, STATIC);
    fruit3->MoveTo(100, 400);

    //hamburguer
    fruit4 = new Fruit("Resources/soup.png");
    scene->Add(fruit4, STATIC);
    fruit4->MoveTo(300, 400);

    player = new Player();
    scene->Add(player, MOVING);
    // pano de fundo do jogo
    /*
    

    */
}

// ------------------------------------------------------------------------------

void Platformer::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
    
    scene->CollisionDetection();
    // atualiza cena do jogo
    scene->Update();

   if (keyCtrlReturn && window->KeyDown(VK_RETURN)) {
       Engine::Next<GameOver>();
       keyCtrlReturn = false;
   }
    if (window->KeyUp(VK_RETURN)) keyCtrlReturn = true;
    if (player->statePlayer == LOSE) {
        Engine::Next<GameOver>();
     }
    
} 

// ------------------------------------------------------------------------------

void Platformer::Draw()
{
    scene->Draw();
    scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Platformer::Finalize()
{
    delete scene;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(417, 625);
    engine->window->Color(150, 200, 230);
    engine->window->Title("Frogger");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    //int status = engine->Start(new Platformer());
    int status = engine->Start(new Platformer());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

