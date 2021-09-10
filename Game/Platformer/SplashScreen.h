#ifndef _SplashScreen_H_
#define _SplashScreen_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "BackgroundSplashScreen.h"

// ------------------------------------------------------------------------------

class SplashScreen : public Game
{
private:
    BackgroundSplashScreen* bg = nullptr;   // pano de fundo
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