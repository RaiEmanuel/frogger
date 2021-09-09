#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "BackgroundGameOver.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
    BackgroundGameOver* bg = nullptr;   // pano de fundo
    bool keyCtrlReturn = false;      // controle do pressionamento da barra de espa�o

public:
    static Scene* scene;           // gerenciador de cena

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif