//#pragma once
//#include "ImageRenderer.h"
//#include "TimeManager.h" //Lo subiran en clase
//
//class AnimatedImageRenderer : public ImageRenderer
//{
//private:
//    int frameCount;
//    int columnsCount; //SpriteSheets
//    int currentFrame;
//    float frameWidth , frameHeight; //Tamaño de la celda de cada sprite de spriteSHeet
//
//    bool looping;
//    float currentFrameTime;
//public:
//    AnimatedImageRenderer ( Transform * transform , string sourcePath , Vector2 sourceOffset , Vector2 sourceSize ) : ImageRenderer ( transform , sourcePath , sourceOffset , sourceSize ) { }
//    virtual void Update ( float dt ) override
//    {
//        //1) Actualizar el destRect
//        ImageRenderer::Update ( dt );
//        //2) Actualizar el tiempo que ha pasado desde el inicio del frame
//        currentFrameTime += dt;
//        //3) Comprobar si la duracion de este frame es mayor que la duracion maxima
//        if ( currentFrameTime >= TIME.GetFrameTime ( ) ) //De la clase timemanager
//        {
//            //4) Incrementar el numero del frame actual
//            currentFrame++;
//            //5) Resetear la duracion del nuevo frame
//            currentFrameTime = 0;
//            if ( currentFrame >= frameCount )
//            {
//                //6) Comprobar si el anterior era el ultimo frame
//                    //7.a) Si se reproduce en bucle -> reiniciar el ciclo de la animacion
//                if ( looping ) currentFrame = 0;
//                    //7.b) Si no se reproduce en bucle -> congelar y quedarse en  el ultimo frame
//                else currentFrame = frameCount-1;
//
//            }
//        }
//        //8) Calcular la celda en la spritesheet del frame actual
//        int currentRow = currentFrame / columnsCount;
//        int currentColumn = currentFrame / columnsCount;
//        //9) Poner en el sourceRect los pixeles de la 
//        _sourceRect.x = currentColumn * frameWidth;
//        _sourceRect.y = currentRow * frameHeight;
//    }
//    virtual void Render ( )
//    {
//        ImageRenderer::Render ( );
//        
//    }
//
//    AnimatedImageRenderer ( Transform * transform , string sourcePath , Vector2 sourceOffset , Vector2 sourceSize, int frameCount , int columnsCount , 
//        float frameWidth , float frameHeight , bool looping )
//        : ImageRenderer ( transform , sourcePath , sourceOffset , sourceSize ), frameCount ( frameCount ) , columnsCount ( columnsCount ) , currentFrame ( 0 ) , frameWidth ( frameWidth ) , frameHeight ( frameHeight ) , looping ( looping ) , currentFrameTime ( 0.0f )
//    {
//        _sourceRect = SDL_FRect {
//            sourceOffset.x,
//            sourceOffset.y,
//            frameWidth,
//            frameHeight
//        }
//    }
//};
