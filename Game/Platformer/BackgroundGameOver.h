
#ifndef _BACKGROUNDGAMEOVER_H_
#define _BACKGROUNDGAMEOVER_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class BackgroundGameOver : public Object
{
private:
    Sprite* bgSprite;

public:
    BackgroundGameOver(string fileName);                       // construtor
    ~BackgroundGameOver();                      // destrutor

    void setSprite(string fileName);                   // atualiza o sprite com nova imagem
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void OnCollision(Object* obj);     // resolu��o da colis�o
};

// ---------------------------------------------------------------------------------

#endif