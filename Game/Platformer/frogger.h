/**********************************************************************************
// Platformer (Arquivo de Cabe�alho)
//
// Cria��o:     05 Out 2011
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exemplo de jogo estilo platforma
//
**********************************************************************************/

#ifndef _PLATFORMER_H_
#define _PLATFORMER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fruit.h"
#include "Boat.h"

// ------------------------------------------------------------------------------

enum TYPEOBJECT { PLAYER, FRUIT, BOAT, BALL, WATER };

class Platformer : public Game
{
private:
    Player * player = nullptr;      // jogador
    Fruit* fruit = nullptr;      // jogador
    Fruit* fruit2 = nullptr;      // jogador
    Fruit* fruit3 = nullptr;      // jogador
    Fruit* fruit4 = nullptr;      // jogador
    Boat* boat = nullptr;
    Boat* boat2 = nullptr;
    Boat* boat3 = nullptr;
    Boat* boat4 = nullptr;
    Background * backg = nullptr;   // pano de fundo
    bool keyCtrlReturn = false;      // controle do pressionamento da barra de espa�o

public:
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif