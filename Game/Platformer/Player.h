/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     20 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _PLATFORMER_PLAYER_H_
#define _PLATFORMER_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
#include "Boat.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum Gravity {NORMAL,INVERTED};         // tipo da gravidade
enum StatePlayer { RUN, LOSE };         // estado do jogador, jogando ou perdeu e chama gameover
// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet * tileset = nullptr;        // folha de sprites do personagem
    Animation * anim = nullptr;         // anima��o do personagem
    bool keyCtrl = false;               // controle do pressionamento da barra de espa�o
    bool keyCtrlUp = false;               // controle do pressionamento da barra de espa�o
    bool keyCtrlDown = false;               // controle do pressionamento da barra de espa�o
    bool keyCtrlLeft = false;               // controle do pressionamento da barra de espa�o
    bool keyCtrlRight = false;               // controle do pressionamento da barra de espa�o
    bool keyCtrlReturn = false;               // controle do pressionamento da barra de espa�o
    

public:
    Boat* boat = nullptr;                  //bote diferente de nulo quando colidindo com um. saiu do bote zera. isso serve para pode andar ambos juntos
    StatePlayer statePlayer = RUN;
    Player();                           // construtor
    ~Player();                          // destrutor

    void OnCollision(Object * obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Player::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif