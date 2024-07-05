#include "setting.h"
#include "coordinates.h"

Setting::Setting(int x, int y, int enemies):
size(Coordinates(x, y)),
enemies(enemies){}