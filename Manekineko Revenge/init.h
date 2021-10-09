#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
//INIT
void init()
{
    al_init();
    al_init_acodec_addon();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
};

#endif // INIT_H_INCLUDED
