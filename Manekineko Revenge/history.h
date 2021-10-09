#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED
void fhistory()
{
    float text_cameraPosition[2] = {0, 0};
    float history_x = 8;
    float history_y =4;
    al_draw_bitmap(history_background, 0, 0, NULL);
    al_draw_bitmap(history_text, history_x, history_y, NULL);
    al_draw_bitmap(press_enter, 600, 470, NULL);
}
#endif // HISTORY_H_INCLUDED
