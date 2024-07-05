#include "g_obj.h"
#include "frame.h"
#include "setting.h"

void GObj::GOBJDisable(){
    GOBJenabled = false;
}
void GObj::GOBJEnable(){
    GOBJenabled = true;
}
bool GObj::isGOBJEnabled(){
    return  GOBJenabled;
}
Frame GObj::render(){
    return Frame();
}
Setting& GObj::get_setting(){
    return *setting;
}
void GObj::set_setting(Setting& setting){
    this->setting = &setting;
}