/*!
    @file   LoadingWorld.h
    @author numata
    @date   10/02/13
    
    Please write the description of this world.
 */

#pragma once

#include <Karakuri/Karakuri.h>


class LoadingWorld : public KRWorld {
    
    int         mDirection;
    int         mCount;
    
public:
    virtual void    becameActive();
    virtual void    resignedActive();
    virtual void    updateModel(KRInput* input);
    virtual void    drawView(KRGraphics* g);

};
