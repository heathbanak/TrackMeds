//
//  Scene.h
//  MedCheck1.3
//
//  Created by Heath Banak on 7/8/22.
//

#ifndef Scene_h
#define Scene_h

#include <string>

using namespace std;

#include "Date.h"

class Scene {
public:
    Scene();
    Scene(string title);
    void printTitleDate();
    void endScene();
private:
    Date* today_;
    string title_;
    int titleLength_;
    int dateLength_;
};


#endif /* Scene_h */
