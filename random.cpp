#include "random.h"
#include "food0.h"
#include "food1.h"
#include "food2.h"
#include "setting.h"
#include <cstdlib>
#include <ctime>


Random::Random(Setting& setting):
setting(setting){
    std::srand(std::time(0));
}

int Random::Next(int a, int b){
    return rand() % (b-a) + a;
}

Coordinates* Random::randomCoordinates(){
    return new Coordinates(Next(0,setting.size.x),Next(0,setting.size.y));
}


Food* Random::randomFood(){
    int rand = Next(0, 3);
    if(rand==0){
        auto coord = randomCoordinates();
        Food0* f = new Food0(*coord);
        return f;
    }else if(rand==1){
        auto coord = randomCoordinates();
        Food1* f1 = new Food1(*coord);
        return f1;
    }else {
        auto coord = randomCoordinates();
        Food2* f2 = new Food2(*coord);
        return f2;
    }
}