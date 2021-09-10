#ifndef _BACKGROUNDSPLASHSCREEN_H_
#define _BACKGROUNDSPLASHSCREEN_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class BackgroundSplashScreen : public Object
{
private:
    Sprite* bgSprite;

public:
    BackgroundSplashScreen(string fileName);                       // construtor
    ~BackgroundSplashScreen();                      // destrutor

    void setSprite(string fileName);                   // atualiza o sprite com nova imagem
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void OnCollision(Object* obj);     // resolu��o da colis�o
};
// ---------------------------------------------------------------------------------
#endif