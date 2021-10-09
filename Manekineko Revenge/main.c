#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "variables.h"
#include "audio.h"
#include "init.h"
#include "Neko.h"
#include "history.h"
#include "status.h"
//Main Function
void cameraUpdate(float *cameraPosition)
{
    cameraPosition[0] = -(screenwidth/2) + (neko.x + neko.w/2);
    cameraPosition[1] = -(screenheight/2) + (neko.y + neko.h/2);
    if(cameraPosition[0]< 0)
    {
        cameraPosition[0] = 0;
    }
    if(cameraPosition[1]<0)
    {
        cameraPosition[1] = 0;
    }
}
bool isred(float neko_pos_x, float neko_pos_y)
{
    unsigned char r, g, b;
    if(temple_bool == true)
    {
        red = al_get_pixel(temple_collision, neko_pos_x, neko_pos_y);
    }
    else if(florest_bool == true)
    {
        red = al_get_pixel(florest_collision, neko_pos_x, neko_pos_y);
    }
    else if(dungeon_bool == true)
    {
        red = al_get_pixel(dungeon_collision, neko_pos_x, neko_pos_y);
    }
    else if(village == true)
    {
        red = al_get_pixel(city_collision, neko_pos_x, neko_pos_y);
    }
    else if(house == true)
    {
        red = al_get_pixel(living_room_collision, neko_pos_x, neko_pos_y);
    }
    else if(house_bedroom == true)
    {
        red = al_get_pixel(bedroom_collision, neko_pos_x, neko_pos_y);
    }
    al_unmap_rgb(red, &r, &g, &b);
    return (r == 255, g == 0, b == 0);
    }
bool collision()
{
    if(isred(neko.x+15, neko.y+neko.h/2)){return true;}
    if(isred(neko.x+neko.w/2, neko.y)){return true;}
    if(isred((neko.x+neko.w-15),neko.y+neko.h/2)){return true;}
    if(isred(neko.x+neko.w/2, neko.y+neko.h)){return true;}
    return false;
}
bool wolf_collision()
{
    if(florest_bool == true)
    {
        if(wolf_spawn == true)
        {
            if(wolf.x+wolf.w/2 > neko.x-neko.w/2 && wolf.x < neko.x+neko.w/2 && wolf.y+wolf.h/2 > neko.y-neko.h/2 && wolf.y < neko.y+neko.h/2){return true;}
            return false;
        }
    }
}
bool wolf_wall_collision()
{
    if(florest_bool == true)
    {
        if(isred(wolf.x+wolf.w/2, wolf.y+wolf.h)){return true;};
        if(isred(wolf.x+wolf.w/2, wolf.y)){return true;};
        if(isred(wolf.x+wolf.w, wolf.y+wolf.h/2)){return true;};
        if(isred(wolf.x, wolf.y+wolf.h/2)){return true;}
        return false;
    }
}
bool snake_collision()
{
    if(dungeon_bool == true)
    {
        if(snake_spawn == true)
        {
            if(snake.x+snake.w/2 > neko.x-10-neko.w/2 && snake.x-snake.w/2 < neko.x-10+neko.w/2 && snake.y+snake.h/2 > neko.y+10-neko.h/2 && snake.y-snake.h/2 < neko.y+10+neko.h/2) {return true;}
            return false;
        }
    }

}
bool snake_wall_collision()
{
    if(temple_bool == true)
    {
        if(isred(snake.x+snake.w/2, snake.y+snake.h)){return true;};
        if(isred(snake.x+snake.w/2, snake.y)){return true;};
        if(isred(snake.x+snake.w, snake.y+snake.h/2)){return true;};
        if(isred(snake.x, snake.y+snake.h/2)){return true;}
        return false;
    }
}
bool kitsune_collision()
{
    if(temple_bool == true)
    {
        if(kitsune.x+kitsune.w/2 > neko.x-neko.w/2 && kitsune.x < neko.x+neko.w/2 && kitsune.y+kitsune.h/2 > neko.y-neko.h/2 && kitsune.y < neko.y+neko.h/2) {return true;}
    }
    return false;
}
bool man_collision()
{
    if(house == true)
    {
        if(man_spawn == true)
        {
            if(man.x+man.w/2 > neko.x-neko.w/2 && man.x < neko.x+neko.w/2 && man.y+man.h/2 > neko.y-neko.h/2 && man.y < neko.y+neko.h/2) {return true;}
        }

        return false;
    }
}
int main()
{
    init();
    //Local Variables
    display = al_create_display(screenwidth, screenheight);
    events = al_create_event_queue();
    menu_background = al_load_bitmap("imagens/menu.jpg");
    menu_arrow = al_load_bitmap("imagens/arrow.png");
    help = al_load_bitmap("imagens/help.jpg");
    timer = al_create_timer(1.0 / FPS);
    attacktimer = al_create_timer(1.0/attackFPS);
    ALLEGRO_EVENT ev;
    neko_movement_sprite = al_load_bitmap("imagens/neko_movement.png");
    neko_movement_collision = al_load_bitmap("imagens/neko_movement_collision.png");
    neko_attack_sprite = al_load_bitmap("imagens/neko_attack.png");
    snake_sprite = al_load_bitmap("imagens/snake.png");
    wolf_sprites = al_load_bitmap("imagens/wolf.png");
    man_sprites = al_load_bitmap("imagens/man.png");
    kitsune_npc = al_load_bitmap("imagens/kitsune.png");
    life0 = al_load_bitmap("imagens/life0.png");
    life1 = al_load_bitmap("imagens/life1.png");
    life2 = al_load_bitmap("imagens/life2.png");
    life3 = al_load_bitmap("imagens/life3.png");
    life4 = al_load_bitmap("imagens/life4.png");
    life5 = al_load_bitmap("imagens/life5.png");
    life6 = al_load_bitmap("imagens/life6.png");
    life7 = al_load_bitmap("imagens/life7.png");
    life8 = al_load_bitmap("imagens/life8.png");
    life9 = al_load_bitmap("imagens/life9.png");
    life10 = al_load_bitmap("imagens/life10.png");
    history_background = al_load_bitmap("imagens/menu_historia.jpg");
    history_text = al_load_bitmap("imagens/historia.png");
    press_enter = al_load_bitmap("imagens/press_enter.png");
    sword = al_load_bitmap("imagens/espada.png");
    armor = al_load_bitmap("imagens/armadura_samurai.png");
    inventory = al_load_bitmap("imagens/inventario.png");
    damage10 = al_load_bitmap("imagens/dano.png");
    damage20 = al_load_bitmap("imagens/dano1.png");
    defense0 = al_load_bitmap("imagens/defesa.png");
    defense1 = al_load_bitmap("imagens/defesa1.png");
    LVL = al_load_bitmap("imagens/LVL.png");
    get_mission = al_load_bitmap("imagens/missao.bmp");
    missoes0 = al_load_bitmap("imagens/missoes0.png");
    missoes1 = al_load_bitmap("imagens/missoes1.png");
    missoes2 = al_load_bitmap("imagens/missoes2.png");
    missoes3 = al_load_bitmap("imagens/missoes3.png");
    lvl_font = al_load_font("fontes/arial.ttf", 16, 0);
    temple = al_load_bitmap("imagens/templo.jpg");
    temple_collision = al_load_bitmap("imagens/templo_collision.jpg");
    florest = al_load_bitmap("imagens/floresta.jpg");
    florest_collision = al_load_bitmap("imagens/floresta_collision.jpg");
    dungeon = al_load_bitmap("imagens/masmorra.jpg");
    dungeon_collision = al_load_bitmap("imagens/masmorra_collision.jpg");
    city = al_load_bitmap("imagens/city.png");
    city_collision = al_load_bitmap("imagens/city_collision.png");
    living_room = al_load_bitmap("imagens/sala.jpg");
    living_room_collision = al_load_bitmap("imagens/sala_collision.jpg");
    bedroom = al_load_bitmap("imagens/quarto.png");
    bedroom_collision = al_load_bitmap("imagens/quarto_collision.png");
    armor = al_load_bitmap("imagens/armadura_samurai.png");
    sword = al_load_bitmap("imagens/espada.png");
    //Init
    al_set_window_title(display, "Manekineko Revenge");

    //Source Register
    al_register_event_source(events, al_get_display_event_source(display));
    al_register_event_source(events, al_get_timer_event_source(timer));
    al_register_event_source(events,al_get_timer_event_source(attacktimer));
    al_register_event_source(events, al_get_keyboard_event_source());
    al_register_event_source(events, al_get_mouse_event_source());


    faudio();
    //LOGIC
    while(!finish)
    {
        int level = exp/100;
        float life_regen = 0.03*level;
        float ax;
        float ay;
        ax = neko.x;
        ay = neko.y;
        al_start_timer(timer);
        al_start_timer(attacktimer);
        al_wait_for_event(events, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            finish = true;
        }
            else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                {
                    finish = true;
                }
                else if(history == false)
                {
                    if(ev.keyboard.keycode == ALLEGRO_KEY_S)
                    {
                        if(py[0] == c_y){menu_select_key = true;c_x = px[0]; c_y = py[1]; }
                        else if(py[1] == c_y){menu_select_key = true;c_x = px[1]; c_y = py[2]; }

                    }
                    else if(ev.keyboard.keycode == ALLEGRO_KEY_W)
                    {
                        if(py[2] == c_y){menu_select_key = true;c_x = px[0]; c_y = py[1]; }
                        else if(py[1] == c_y){menu_select_key = true;c_x = px[0]; c_y = py[0]; }
                    }
                    else if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    {
                        if(history == false && c_y == py[0] && c_x == px[0])
                        {
                        history = true;
                        al_stop_sample_instance(inst_select_key_sound);
                        al_play_sample_instance(inst_select_key_sound);
                        }
                        else if(c_y == py[1] && c_x == px[0])
                        {
                        history = false;
                        }
                        else if(c_y == py[2] && c_x == px[1])
                        {
                            history = true;
                            help_bool = true;
                            al_stop_sample_instance(inst_select_key_sound);
                            al_play_sample_instance(inst_select_key_sound);
                        }
                    }
                }
                else if(history == true)
                {
                    if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    {
                        if(!start_game && help_bool == false)
                        {
                            al_stop_sample_instance(inst_select_key_sound);
                            al_play_sample_instance(inst_select_key_sound);
                            start_game = true;
                        }
                        else if(help_bool == true)
                        {
                            al_stop_sample_instance(inst_select_key_sound);
                            al_play_sample_instance(inst_select_key_sound);
                            history = false;
                            help_bool = false;
                        }
                    }
                    else if(start_game == true)
                    {
                        switch(ev.keyboard.keycode)
                        {
                            case ALLEGRO_KEY_W:
                                keys[W] = true;
                                break;
                            case ALLEGRO_KEY_S:
                                keys[S] = true;
                                break;
                            case ALLEGRO_KEY_A:
                                keys[A] = true;
                                break;
                            case ALLEGRO_KEY_D:
                                keys[D] = true;
                                break;
                            }
                        if(ev.keyboard.keycode == ALLEGRO_KEY_I)
                        {
                            al_play_sample_instance(inst_menu_select);
                            if(!open_inventory)
                            {
                                open_inventory = true;
                            }
                            else if(open_inventory == true)
                            {
                                open_inventory = false;
                            }
                        }
                        if(temple_bool == true)
                        {
                            if(neko.x >= 760 && neko.x<= 800 && neko.y >= 470 && neko.y <= 570)
                            {
                                temple_bool = false;
                                florest_bool = true;
                                wolf_spawn = true;
                                neko.x = neko.x -720;
                                neko.y = neko.y -100;
                            }

                        }
                        if(florest_bool == true)
                        {
                            if(neko.x >= -10 && neko.x <= 30 && neko.y >= 390 && neko.y <= 470)
                            {
                                florest_bool = false;
                                temple_bool = true;
                                neko.x = neko.x +740;
                                neko.y = neko.y + 80;
                            }
                            else if(neko.x >= 625 && neko.x <= 685 && neko.y >= 65 && neko.y <= 100)
                            {
                                florest_bool = false;
                                dungeon_bool = true;
                                snake_spawn = true;
                                neko.x = neko.x - 260;
                                neko.y = neko.y + 440;
                            }
                            else if(neko.x+neko.w >= 770 && neko.x+neko.w <= 820 && neko.y >= 200 && neko.y <= 310)
                            {
                                florest_bool = false;
                                village = true;
                                neko.x = neko.x - 660;
                                neko.y = neko.y + 100;
                            }
                        }
                        if(dungeon_bool == true)
                        {
                            if(neko.x >= 360 && neko.x <= 450 && neko.y+neko.h >= 565 && neko.y+neko.h <= 600)
                            {
                                dungeon_bool = false;
                                florest_bool = true;
                                neko.x = neko.x + 270;
                                neko.y = neko.y - 440;
                            }
                        }
                        if(village == true)
                        {
                            if(neko.x >= 320 && neko.x <= 385 && neko.y >= 208 && neko.y <= 220)
                            {
                                village = false;
                                house = true;
                                neko.x = neko.x + 30;
                                neko.y = neko.y + 300;
                            }
                            if(neko.x >= 0 && neko.x <= 10 && neko.y >= 308 && neko.y <= 372)
                            {
                                village = false;
                                florest_bool = true;
                                neko.x = neko.x + 720;
                                neko.y = neko.y - 100 ;
                            }
                        }
                        if(house == true)
                        {
                            if(neko.x >= 330 && neko.x <= 470 && neko.y >= 540 && neko.y <= 600)
                            {
                                house = false;
                                village = true;
                                neko.x = neko.x - 70;
                                neko.y = neko.y - 330;
                            }
                            if(neko.x >= 700 && neko.x <= 787 && neko.y >= 10 && neko.y <= 50)
                            {
                                house = false;
                                house_bedroom = true;
                                neko.x = neko.x -120;
                                neko.y = neko.y +300;
                            }
                        }
                        if(house_bedroom == true)
                        {
                            if(neko.x >= 595 && neko.x <= 660 && neko.y+neko.h >= 460 && neko.y+neko.h <= 475)
                            {
                                house_bedroom == false;
                                house = true;
                                neko.x = neko.x + 100;
                                neko.y = neko.y - 280;
                            }
                        }
                    }
                }
            }
            if(ev.type == ALLEGRO_EVENT_KEY_UP)
            {
                if(start_game == true)
                {
                     switch(ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_W:
                            keys[W] = false;
                            nTile = 0;
                            break;
                        case ALLEGRO_KEY_S:
                            keys[S] = false;
                            nTile = 0;
                            break;
                        case ALLEGRO_KEY_A:
                            keys[A] = false;
                            nTile = 0;
                            break;
                        case ALLEGRO_KEY_D:
                            keys[D] = false;
                            nTile = 0;
                            break;
                    }
                }
            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 1 && open_inventory == false)
                {
                    attack = true;
                }
                else if(ev.mouse.button & 1 && open_inventory == true)
                {
                    if(ev.mouse.x >= 410 && ev.mouse.x <= 450 && ev.mouse.y >= 205 && ev.mouse.y <= 240)
                    {
                        sword_equip = true;
                    }
                    if(ev.mouse.x >= 455 && ev.mouse.x <= 500 && ev.mouse.y >= 205 && ev.mouse.y <= 240)
                    {
                        armor_equip = true;
                    }
                    if(ev.mouse.x >= 242 && ev.mouse.x <= 278 && ev.mouse.y >= 374 && ev.mouse.y <= 407)
                    {
                        sword_equip = false;
                        atk = atk-10;
                    }
                    if(ev.mouse.x >= 180 && ev.mouse.x <= 220 && ev.mouse.y >= 290 && ev.mouse.y <= 325)
                    {
                        armor_equip = false;
                        def = def-8;
                    }
                }
            }
            else if(ev.type == ALLEGRO_EVENT_TIMER)
            {
                if(ev.timer.source == timer)
                {
                    if(player_movement == true)
                    {
                        if(keys[A])
                        {
                            neko.x -= keys[A] *10;
                            dir = 1;
                            nTile++;
                        }
                        else if(keys[D])
                        {
                            neko.x += keys[D] * 10;
                            dir = 3;
                            nTile++;
                        }
                        else if(keys[W])
                        {
                            neko.y -= keys[W] * 10;
                            dir = 2;
                            nTile++;
                        }
                        else if(keys[S])
                        {
                            neko.y += keys[S] * 10;
                            dir = 0;
                            nTile++;
                        }

                        if(nTile < 0)
                        {
                            nTile = 2;
                        }
                        if(nTile>2)
                        {
                            nTile = 0;
                        }
                    }
                    if(start_game == true)
                    {
                        if(life < 100)
                        {
                            life = life+life_regen;
                        }
                        else life = 100;
                        cameraUpdate(cameraPosition);
                        al_identity_transform(&camera);
                        al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
                        al_use_transform(&camera);
                        if(neko.x != ax || neko.y != ay)
                        {
                            if(collision() == true || snake_collision() == true || kitsune_collision() == true || man_collision() == true || wolf_collision() == true)
                            {
                                neko.x = ax;
                                neko.y = ay;
                            }
                        }
                    }
                }
                if(ev.timer.source == attacktimer)
                {
                    if(attack == true)
                    {
                        if(attack_timer >= 0 && attack_timer < 7)
                        {
                            attack_timer++;
                        }
                    }
                    if(!attack)
                    {
                    attack_timer = 0;
                    }
                    if(snake_movement == true && snake_movement_timer < 3)
                    {
                        snake_movement_timer++;
                    }
                    if(snake_movement_timer == 3)
                    {
                        snake_movement_timer = 0;
                    }
                    if(snake_movement == true && snake_attack_timer < 6)
                    {
                        snake_attack_timer++;
                    }
                    if(wolf_movement == true && wolf_movement_timer < 3)
                    {
                        wolf_movement_timer++;
                    }
                    if(wolf_movement == true && wolf_movement_timer == 3)
                    {
                        wolf_movement_timer = 0;
                    }
                    if(wolf_movement == true && wolf_attack_timer < 6)
                    {
                        wolf_attack_timer++;
                    }
                    if(neko.x < man.x+man.y-150 && neko.x+neko.w > man.x-10 && neko.y+neko.h > man.y-10 && neko.y < man.y+man.h+10)
                    {
                        man_attack = true;
                    }
                    else
                    {
                        man_attack = false;
                    }
                    if(man_attack == true && man_attack_timer < 9)
                    {
                        man_attack_timer++;
                    }
                }
                if(wolf_attack_timer == 6)
                {
                    wolf_attack_timer = 0;
                }
                if(snake_attack_timer == 6)
                {
                    snake_attack_timer = 0;
                }
                if(man_attack == false || man_attack_timer >= 9)
                {
                        man_attack_timer = 0;
                }
            }
            switch(ev.mouse.button)
            {
                case 1:
                printf("coordenadada x = %d\n", ev.mouse.x);
                printf("coordenada y = %d\n", ev.mouse.y);
                break;
            }
        //DRAW
        if(!history)
        {
            al_play_sample_instance(inst_trilha_sonora_menu);
            al_draw_bitmap(menu_background, 0 , 0, NULL);
            al_draw_bitmap(menu_arrow, c_x, c_y, NULL);
            if(menu_select_key == true)
            {
                al_play_sample_instance(inst_menu_select);
                menu_select_key = false;
            }
        }
        else if(!start_game)
        {
            fhistory();
        }
        if(help_bool == true)
            {
                al_draw_bitmap(help, 0, 0, NULL);
            }
        else if(start_game == true)
        {
            al_stop_sample_instance(inst_trilha_sonora_menu);
            if(temple_bool == true)
            {
                al_draw_bitmap(temple_collision, 0, 0, NULL);
                al_draw_bitmap(temple, 0, 0, NULL);
                al_draw_bitmap(kitsune_npc, kitsune.x, kitsune.y, NULL);
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
                {
                    if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER && neko.x > 180 && neko.x < 250 && neko.y > 450 && neko.y < 570)
                    {
                        kitsune_text = true;
                        kill_the_snake = true;
                    }
                    else kitsune_text = false;
                }
                if(!attack)
                {
                    al_draw_bitmap_region(neko_movement_sprite, neko.wx+nTile*50, neko.wy+dir*41.6, neko.w, neko.h, neko.x, neko.y, NULL);
                }
            }
            else if(florest_bool == true)
            {
                al_draw_bitmap(florest_collision, 0, 0, NULL);
                al_draw_bitmap(florest, 0, 0, NULL);
                fwolf();
                if(!attack)
                {
                    al_draw_bitmap_region(neko_movement_sprite, neko.wx+nTile*50, neko.wy+dir*41.6, neko.w, neko.h, neko.x, neko.y, NULL);
                }
            }
            else if(dungeon_bool == true)
            {
                al_draw_bitmap(dungeon_collision, 0, 0, NULL);
                al_draw_bitmap(dungeon, 0, 0, NULL);
                fsnake();
                if(!attack)
                {
                    al_draw_bitmap_region(neko_movement_sprite, neko.wx+nTile*50, neko.wy+dir*41.6, neko.w, neko.h, neko.x, neko.y, NULL);
                }
            }
            else if(village == true)
            {

                al_draw_bitmap(city_collision, 0, 0, NULL);
                al_draw_bitmap(city, 0, 0, NULL);
                if(!attack)
                {
                    al_draw_bitmap_region(neko_movement_sprite, neko.wx+nTile*50, neko.wy+dir*41.6, neko.w, neko.h, neko.x, neko.y, NULL);
                }
            }
            else if(house == true)
            {
                al_draw_bitmap(living_room_collision, 0, 0, NULL);
                al_draw_bitmap(living_room, 0, 0, NULL);
                fman();
                if(!attack)
                {
                    al_draw_bitmap_region(neko_movement_sprite, neko.wx+nTile*50, neko.wy+dir*41.6, neko.w, neko.h, neko.x, neko.y, NULL);
                }
            }
            else if(house_bedroom == true)
            {
                al_draw_bitmap(bedroom_collision, 0, 0, NULL);
                al_draw_bitmap(bedroom, 0, 0, NULL);
                if(!attack)
                {
                    al_draw_bitmap_region(neko_movement_sprite, neko.wx+nTile*50, neko.wy+dir*41.6, neko.w, neko.h, neko.x, neko.y, NULL);
                }
            }
            flife();
            fdamage();
            fdefense();
            al_draw_bitmap(LVL, cameraPosition[0]+95, cameraPosition[1]+40, NULL);
            al_draw_textf(lvl_font, al_map_rgb(255, 255, 255), cameraPosition[0]+111, cameraPosition[1]+60, NULL,  "%d", level);
            if(attack == true)
            {
                if(dir == 3)
                {
                    if(attack_timer == 0)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+0*75, neko_attack.wy+0*41.6,neko_attack.w-10, neko_attack.h, neko.x-24, neko.y-8, NULL);
                    }
                    else if(attack_timer == 1)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+0*41.6,neko_attack.w, neko_attack.h, neko.x-24, neko.y-8, NULL);
                    }
                    else if(attack_timer == 2)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+0*41.6,neko_attack.w, neko_attack.h, neko.x-24, neko.y-8, NULL);
                    }
                    else if(attack_timer == 3)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+355, neko_attack.wy+0*41.6,neko_attack.w, neko_attack.h, neko.x-24, neko.y-8, NULL);
                    }
                    else if(attack_timer == 4)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+0*41.6,neko_attack.w, neko_attack.h, neko.x-24, neko.y-8, NULL);
                    }
                    else if(attack_timer == 5)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+0*41.6,neko_attack.w, neko_attack.h, neko.x-24, neko.y-8, NULL);
                    }
                    else if(attack_timer == 6)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+75, neko_attack.wy+0*41.6,neko_attack.w, neko_attack.h, neko.x-24, neko.y-8, NULL);
                    }
                    else
                    {
                        attack = false;
                    }
                }
                else if(dir == 1)
                {
                    if(attack_timer == 0)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+0*75, neko_attack.wy+1*60,neko_attack.w-10, neko_attack.h, neko.x-16, neko.y-5, NULL);
                    }
                    else if(attack_timer == 1)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-28, neko.y-9, NULL);
                    }
                    else if(attack_timer == 2)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-16, neko.y-9, NULL);
                    }
                    else if(attack_timer == 3)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+355, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-38, neko.y-9, NULL);
                    }
                    else if(attack_timer == 4)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-16, neko.y-9, NULL);
                    }
                    else if(attack_timer == 5)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-28, neko.y-9, NULL);
                    }
                    else if(attack_timer == 6)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+75, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-16, neko.y-9, NULL);
                    }
                    else
                    {
                        attack = false;
                    }
                }
                else if(dir == 2)
                {
                    if(attack_timer == 0)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+0*75, neko_attack.wy+2*60,neko_attack.w-10, neko_attack.h, neko.x-8, neko.y-10, NULL);
                    }
                    else if(attack_timer == 1)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+2*60,neko_attack.w, neko_attack.h, neko.x, neko.y-9, NULL);
                    }
                    else if(attack_timer == 2)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+2*60,neko_attack.w, neko_attack.h, neko.x-1, neko.y-9, NULL);
                    }
                    else if(attack_timer == 3)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+355, neko_attack.wy+2*60,neko_attack.w, neko_attack.h, neko.x-13, neko.y-9, NULL);
                    }
                    else if(attack_timer == 4)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+2*60,neko_attack.w, neko_attack.h, neko.x-1, neko.y-9, NULL);
                    }
                    else if(attack_timer == 5)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+2*60,neko_attack.w, neko_attack.h, neko.x, neko.y-9, NULL);
                    }
                    else if(attack_timer == 6)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+75, neko_attack.wy+2*60,neko_attack.w, neko_attack.h, neko.x-15, neko.y-9, NULL);
                    }
                    else
                    {
                        attack = false;
                    }
                }
                else if(dir == 1)
                {
                    if(attack_timer == 0)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+0*75, neko_attack.wy+1*60,neko_attack.w-10, neko_attack.h, neko.x-16, neko.y-5, NULL);
                    }
                    else if(attack_timer == 0)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+75, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-16, neko.y-5, NULL);
                    }
                    else if(attack_timer == 1)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-28, neko.y-9, NULL);
                    }
                    else if(attack_timer == 2)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-16, neko.y-9, NULL);
                    }
                    else if(attack_timer == 3)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+355, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-38, neko.y-9, NULL);
                    }
                    else if(attack_timer == 4)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-16, neko.y-9, NULL);
                    }
                    else if(attack_timer == 5)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-28, neko.y-9, NULL);
                    }
                    else if(attack_timer == 6)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+75, neko_attack.wy+1*60,neko_attack.w, neko_attack.h, neko.x-16, neko.y-9, NULL);
                    }
                    else
                    {
                        attack = false;
                    }
                }
                else if(dir == 0)
                {
                    if(attack_timer == 0)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+0*75, neko_attack.wy+3*60,neko_attack.w-10, neko_attack.h+10, neko.x-14, neko.y-14, NULL);
                    }
                    else if(attack_timer == 1)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+3*60,neko_attack.w, neko_attack.h+10, neko.x-8, neko.y-30, NULL);
                    }
                    else if(attack_timer == 2)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+3*60,neko_attack.w, neko_attack.h+10, neko.x-6, neko.y-30, NULL);
                    }
                    else if(attack_timer == 3)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+355, neko_attack.wy+3*60,neko_attack.w, neko_attack.h+10, neko.x-6, neko.y-30, NULL);
                    }
                    else if(attack_timer == 4)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+260, neko_attack.wy+3*60,neko_attack.w, neko_attack.h+10, neko.x-6, neko.y-30, NULL);
                    }
                    else if(attack_timer == 5)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+165, neko_attack.wy+3*60,neko_attack.w, neko_attack.h+10, neko.x-8, neko.y-30, NULL);
                    }
                    else if(attack_timer == 6)
                    {
                        al_draw_bitmap_region(neko_attack_sprite, neko_attack.wx+75, neko_attack.wy+3*60,neko_attack.w, neko_attack.h+10, neko.x-14, neko.y-14, NULL);
                    }
                    else
                    {
                        attack = false;
                    }
                }
            }

            if(open_inventory == true)
            {
                al_draw_bitmap(inventory, cameraPosition[0]+150, cameraPosition[1]+125, NULL);
                if(armor_bool == true && armor_equip == false)
                {
                    al_draw_bitmap(armor, 450+cameraPosition[0], 185+cameraPosition[1], NULL);
                }
                if(sword_bool == true && sword_equip == false)
                {
                    al_draw_bitmap(sword, 411+cameraPosition[0], 206+cameraPosition[1], NULL);
                }
                else if(sword_equip == true)
                {
                    al_draw_bitmap(sword, 245+cameraPosition[0], 374+cameraPosition[1], NULL);

                }
                else if(armor_equip == true)
                {
                    al_draw_bitmap(armor, 180+cameraPosition[0], 270+cameraPosition[1], NULL);
                }
            }
            if(armor_equip == true)
            {
                def = 8;
            }
            if(sword_equip == true)
            {
                atk = 20;
            }
            if(kill_the_snake == true)
            {
                al_draw_bitmap(missoes0, cameraPosition[0], cameraPosition[1]+200, NULL);
            }
            else if(kill_the_man == true)
            {
                al_draw_bitmap(missoes3, cameraPosition[0], cameraPosition[1]+200, NULL);
            }

            if(kitsune_text == true)
            {
                al_draw_bitmap(get_mission,(200)+cameraPosition[0], (200)+cameraPosition[1], NULL);
            }
            if(life<=0)
            {
                finish = true;
            }
            if(house == true && man_spawn == false)
            {
                finish = true;
            }
        }
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_timer(attacktimer);
    al_destroy_bitmap(menu_background);
    al_destroy_bitmap(menu_arrow);
    al_destroy_bitmap(city);
    al_destroy_bitmap(neko_movement_sprite);
    al_destroy_bitmap(neko_attack_sprite);
    al_destroy_bitmap(snake_sprite);
    al_destroy_bitmap(wolf_sprites);
    al_destroy_bitmap(life0);
    al_destroy_bitmap(life1);
    al_destroy_bitmap(life2);
    al_destroy_bitmap(life3);
    al_destroy_bitmap(life4);
    al_destroy_bitmap(life5);
    al_destroy_bitmap(life6);
    al_destroy_bitmap(life7);
    al_destroy_bitmap(life8);
    al_destroy_bitmap(life9);
    al_destroy_bitmap(life10);
    al_destroy_bitmap(history_background);
    al_destroy_bitmap(history_text);
    al_destroy_bitmap(press_enter);
    al_destroy_bitmap(sword);
    al_destroy_bitmap(armor);
    al_destroy_bitmap(inventory);
    al_destroy_bitmap(temple);
    al_destroy_bitmap(temple_collision);
    al_destroy_bitmap(florest);
    al_destroy_bitmap(florest_collision);
    al_destroy_bitmap(dungeon);
    al_destroy_bitmap(dungeon_collision);
    al_destroy_bitmap(city);
    al_destroy_bitmap(city_collision);
    al_destroy_bitmap(living_room);
    al_destroy_bitmap(living_room_collision);
    al_destroy_bitmap(bedroom);
    al_destroy_bitmap(bedroom_collision);
    al_destroy_bitmap(get_mission);
    al_destroy_sample(trilha_sonora_menu);
    al_destroy_sample_instance(inst_trilha_sonora_menu);
    al_destroy_sample(menu_select);
    al_destroy_sample_instance(inst_menu_select);
    al_destroy_sample(select_key_sound);
    al_destroy_sample_instance(inst_select_key_sound);

    return 0;
}
void fsnake()
{
    float sx;
    float sy;
    sx = snake.x;
    sy = snake.y;
    if(snake_spawn == true)
    {
        if(neko.x >= snake_rectangle.x && neko.x <= snake_rectangle.x+snake_rectangle.w)
        {
            if(neko.y >= snake_rectangle.y && neko.y <= snake_rectangle.y+snake_rectangle.h)
            {
                snake_movement = true;
                if(snake.x+snake.w/2 > neko.x+neko.w/2 && snake.y+snake.h/2 > neko.y+neko.h/2)
                {
                    snake_dir = 2;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                    al_draw_bitmap_region(snake_sprite, 255, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.x = snake.x - 2;
                        snake.y = snake.y - 2;
                    }
                }
                else if(snake.x+snake.w/2 > neko.x+neko.w && snake.y+snake.h/2 < neko.y+neko.h/2)
                {
                    snake_dir = 2;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                        al_draw_bitmap_region(snake_sprite, 255, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.x = snake.x - 2;
                        snake.y = snake.y + 2;
                    }
                }
                else if(snake.x+snake.w/2 < neko.x+neko.w/2 && snake.y+snake.h/2 < neko.y+neko.h/2)
                {
                    snake_dir = 1;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                        al_draw_bitmap_region(snake_sprite, 255, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.x = snake.x + 2;
                        snake.y = snake.y + 2;
                    }
                }
                else if(snake.x+snake.w/2 < neko.x+neko.w/2 && snake.y+snake.h/2 > neko.y+neko.h/2)
                {
                    snake_dir = 1;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                        al_draw_bitmap_region(snake_sprite, 255, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.x = snake.x + 2;
                        snake.y = snake.y - 2;
                    }
                }
                else if(snake.x+snake.w/2 == neko.x+neko.w/2 && snake.y+snake.h/2 < neko.y+neko.h/2)
                {
                    snake_dir = 4;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                        al_draw_bitmap_region(snake_sprite, 255, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.y = snake.y + 2;
                    }
                }
                else if(snake.x+snake.w/2 == neko.x+neko.w/2 && snake.y+snake.h/2 > neko.y+neko.h/2)
                {
                    snake_dir = 0;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                        al_draw_bitmap_region(snake_sprite, 255, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.y = snake.y - 2;
                    }
                }
                else if(snake.x+snake.w/2 < neko.x+neko.w/2 && snake.y+snake.h/2 == neko.y+neko.h/2)
                {
                    snake_dir = 1;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                        al_draw_bitmap_region(snake_sprite, 255, 75, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.x = snake.x + 2;
                    }
                }
                else if(snake.x+snake.w/2 > neko.x+neko.w/2 && snake.y+snake.h/2 == neko.y+neko.h/2)
                {
                    snake_dir = 2;
                    if(snake_movement_timer == 0)
                    {
                        al_draw_bitmap_region(snake_sprite, 0, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 1)
                    {
                        al_draw_bitmap_region(snake_sprite, 125, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    else if(snake_movement_timer == 2)
                    {
                        al_draw_bitmap_region(snake_sprite, 255, 155, snake.w, snake.h, snake.x, snake.y, NULL);
                    }
                    if(snake_collision() == false)
                    {
                        snake.x = snake.x - 2;
                    }
                }
            }
            if(snake.x != sx || snake.y != sy)
            {
                if(snake_wall_collision() == true)
                {
                    snake.x = sx;
                    snake.y = sy;
                }
            }
        }
    }
    if(snake_collision() == true && attack == true && dir == 1 && attack_timer == 3)
    {
        snake.x = snake.x-40;
        snake_life = snake_life-atk;
    }
    else if(snake_collision() == true && attack == true && dir == 3 && attack_timer == 3)
    {
        snake.x = snake.x+40;
        snake_life = snake_life-atk;
    }
    else if(snake_collision() == true && attack == true && dir == 2 && attack_timer == 3)
    {
        snake.y = snake.y-40;
        snake_life = snake_life-atk;
    }
    else if(snake_collision() == true && attack == true && dir == 0 && attack_timer == 3)
    {
        snake.y = snake.y+40;
        snake_life = snake_life-atk;
    }
    else if(snake_collision() == true && snake_dir == 1 && snake_attack_timer == 3)
    {
        neko.x = neko.x+7;
        life = life -6+def;
    }
    else if(snake_collision() == true && snake_dir == 2 && snake_attack_timer == 3)
    {
        neko.x = neko.x-7;
        life = life -6+def;
    }
    else if(snake_collision() == true && snake_dir == 0 && snake_attack_timer == 3)
    {
        neko.y = neko.y-7;
        life = life -6+def;
    }
    else if(snake_collision() == true && snake_dir == 3 && snake_attack_timer == 3)
    {
        neko.y = neko.y+7;
        life = life -6+def;
    }
    if(snake_life <= 0)
    {
        snake_spawn = false;
        kill_the_snake = false;
        armor_bool = true;
        sword_bool = true;
        kill_the_man = true;
        exp = exp+400;
        snake_life = 150;
    }
}
void fwolf()
{
    float wx;
    float wy;
    wx = wolf.x;
    wy = wolf.y;
    if(wolf_spawn == true)
    {
        if(neko.x >= wolf_rectangle.x && neko.x <= wolf_rectangle.x+wolf_rectangle.w)
        {
            if(neko.y >= wolf_rectangle.y && neko.y <= wolf_rectangle.y+wolf_rectangle.h)
            {
                wolf_movement = true;
                if(wolf.x+wolf.w/2> neko.x+neko.w/2 && wolf.y+wolf.h/2 > neko.y+neko.h/2)
                {
                    wolf_dir = 1;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                    al_draw_bitmap_region(wolf_sprites, 230, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.x = wolf.x - 1;
                        wolf.y = wolf.y - 1;
                    }
                }
                else if(wolf.x+wolf.w/2 > neko.x+neko.w && wolf.y+wolf.h/2 < neko.y+neko.h/2)
                {
                    wolf_dir = 1;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                        al_draw_bitmap_region(wolf_sprites, 230, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.x = wolf.x - 1;
                        wolf.y = wolf.y + 1;
                    }
                }
                else if(wolf.x+wolf.w/2 < neko.x+neko.w/2 && wolf.y+wolf.h/2 < neko.y+neko.h/2)
                {
                    wolf_dir = 0;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                        al_draw_bitmap_region(wolf_sprites, 230, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.x = wolf.x + 1;
                        wolf.y = wolf.y + 1;
                    }
                }
                else if(wolf.x+wolf.w/2 < neko.x+neko.w/2 && wolf.y+wolf.h/2 > neko.y+neko.h/2)
                {
                    wolf_dir = 0;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                        al_draw_bitmap_region(wolf_sprites, 230, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.x = wolf.x + 1;
                        wolf.y = wolf.y - 1;
                    }
                }
                else if(wolf.x+wolf.w/2 == neko.x+neko.w/2 && wolf.y+wolf.h/2 < neko.y+neko.h/2)
                {
                    wolf_dir = 2;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                        al_draw_bitmap_region(wolf_sprites, 230, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.y = wolf.y + 1;
                    }
                }
                else if(wolf.x+wolf.w/2 == neko.x+neko.w/2 && wolf.y+wolf.h/2 > neko.y+neko.h/2)
                {
                    wolf_dir = 3;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                        al_draw_bitmap_region(wolf_sprites, 230, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.y = wolf.y - 1;
                    }
                }
                else if(wolf.x+wolf.w/2 < neko.x+neko.w/2 && wolf.y+wolf.h/2 == neko.y+neko.h/2)
                {
                    wolf_dir = 0;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                        al_draw_bitmap_region(wolf_sprites, 230, 0, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.x = wolf.x + 1;
                    }
                }
                else if(wolf.x+wolf.w/2 > neko.x+neko.w/2 && wolf.y+wolf.h/2 == neko.y+neko.h/2)
                {
                    wolf_dir = 1;
                    if(wolf_movement_timer == 0)
                    {
                        al_draw_bitmap_region(wolf_sprites, 0, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 1)
                    {
                        al_draw_bitmap_region(wolf_sprites, 115, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    else if(wolf_movement_timer == 2)
                    {
                        al_draw_bitmap_region(wolf_sprites, 230, 85, wolf.w, wolf.h, wolf.x, wolf.y, NULL);
                    }
                    if(wolf_collision() == false)
                    {
                        wolf.x = wolf.x - 1;
                    }
                }
            }
            if(wolf.x != wx || wolf.y != wy)
            {
                if(wolf_wall_collision() == true)
                {
                    wolf.x = wx;
                    wolf.y = wy;
                }
            }
        }
        if(wolf_collision() == true && attack == true && dir == 3 && attack_timer == 3)
        {
            wolf.x = wolf.x+10;
            wolf_life = wolf_life-atk;

        }
        if(wolf_collision() == true && attack == true && dir == 1 && attack_timer == 3)
        {
            wolf.x = wolf.x-10;
            wolf_life = wolf_life-atk;

        }
        if(wolf_collision() == true && attack == true && dir == 0 && attack_timer == 3)
        {
            wolf.y = wolf.y+10;
            wolf_life = wolf_life-atk;
        }
        if(wolf_collision() == true && attack == true && dir == 2 && attack_timer == 3)
        {
            wolf.y = wolf.y+10;
            wolf_life = wolf_life-atk;
        }
        if(wolf_collision() == true && wolf_dir == 1 && wolf_attack_timer == 3)
        {
            neko.x = neko.x-5;
            life = life-atk+def;
        }
        if(wolf_collision() == true && wolf_dir == 0 && wolf_attack_timer == 3)
        {
            neko.x = neko.x+5;
            life = life-atk+def;
        }
        if(wolf_collision() == true && wolf_dir == 2 && wolf_attack_timer == 3)
        {
            neko.y = neko.y+5;
            life = life-atk+def;
        }
        if(wolf_collision() == true && wolf_dir == 3 && wolf_attack_timer == 3)
        {
            neko.y = neko.y-5;
            life = life-atk+def;
        }
        if(wolf_life <= 0)
        {
            wolf_spawn = false;
            exp = exp+100;
        }
    }
}
void fman()
{
    if(man_spawn == true)
    {
      man.x = 260;
    if(man.x+man.w/2 < neko.x+neko.w/2)
    {
        man.w = 90;
        if(man_attack == false || man_attack_timer < 8)
        {
            al_draw_bitmap_region(man_sprites, 0, 0, man.w, man.h, man.x, man.y, NULL);
        }
        if(man_attack == true && man_attack_timer == 8)
        {
            man.w = 140;
            al_draw_bitmap_region(man_sprites, 155, 0, man.w, man.h, man.x, man.y, NULL);
            neko.x = neko.x+20;
            life = life-14+def;
        }
    }
    else if(man.x+man.w/2 > neko.x+neko.w/2)
    {
        man.w = 90;
        if(man_attack == false || man_attack_timer < 8)
        {
            al_draw_bitmap_region(man_sprites, 0, 140, man.w, man.h, man.x, man.y, NULL);
        }
        if(man_attack == true && man_attack_timer == 8)
        {
            man.w = 140;
            man.x = 210;
            al_draw_bitmap_region(man_sprites, 112, 140, man.w, man.h, man.x, man.y, NULL);
            neko.x = neko.x - 20;
            life = life-14+def;
            player_movement = false;
        }
    }
    if(man_attack_timer == 0)
    {
        player_movement = true;
    }
    }
    if(man_attack == true && attack_timer == 3)
        {
            man_life = man_life-atk;
        }
       if(man_life <= 0)
        {
            man_spawn = false;
        }
}


