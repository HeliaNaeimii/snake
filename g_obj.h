#ifndef G_OBJ_H
#define G_OBJ_H

#include "frame.h"
#include "pixel.h"
#include "setting.h"
#include <vector>
class GObj {
    private:
    bool GOBJenabled=true;
    Setting* setting;
    public:
    void GOBJDisable();
    void GOBJEnable();
    bool isGOBJEnabled();
    virtual Frame render();
    void set_setting(Setting& setting);
    Setting& get_setting();
};

#endif