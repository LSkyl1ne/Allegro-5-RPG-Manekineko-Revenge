#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED
#include "variables.h"
void faudio()
{
    al_reserve_samples(3);
    trilha_sonora_menu = al_load_sample("audio/TrilhaSonoraMenu.ogg");
    menu_select = al_load_sample("audio/menuselect.ogg");
    select_key_sound = al_load_sample("audio/enterkey.ogg");
    inst_trilha_sonora_menu = al_create_sample_instance(trilha_sonora_menu);
    inst_menu_select = al_create_sample_instance(menu_select);
    inst_select_key_sound = al_create_sample_instance(select_key_sound);
    al_attach_sample_instance_to_mixer(inst_trilha_sonora_menu, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(inst_menu_select, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(inst_select_key_sound, al_get_default_mixer());
    al_set_sample_instance_playmode(inst_trilha_sonora_menu, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_gain(inst_trilha_sonora_menu, 0.5);
}

#endif // AUDIO_H_INCLUDED
