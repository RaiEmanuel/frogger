
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    Sprite* bgSprite;

public:
    bool activeWater = true; //se �gua ativa ent�o ela pode fazer player perder quando em contato
    Background(string fileName);                       // construtor
    ~Background();                      // destrutor

    void setSprite(string fileName);      // atualiza o sprite com nova imagem
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void OnCollision(Object* obj);     // resolu��o da colis�o
}; 

// ---------------------------------------------------------------------------------

#endif