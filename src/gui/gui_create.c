/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui_create
*/

#include "my_world.h"

static void create_headbar(window_t *w)
{
    button_create(&(w->ui.save), " Save", &button_sizes[SMALL_B],
                                            &(sfVector2f){400, 0});
    button_create(&(w->ui.reset), "Reset", &button_sizes[SMALL_B],
                                            &(sfVector2f){470, 0});
    button_create(&(w->ui.load), " Load", &button_sizes[SMALL_B],
                                            &(sfVector2f){540, 0});
    button_create(&(w->ui.generate_random), "  Generate random",
                &(sfVector2f){200, 35}, &(sfVector2f){1300, 0});
}

static void create_viewbar(window_t *w)
{
    button_create(&(w->ui.scale), "     Scale", &button_sizes[MEDIUM_B],
                                                &(sfVector2f){1800, 450});
    button_create(&(w->ui.translate), "Translate", &button_sizes[MEDIUM_B],
                                                &(sfVector2f){1800, 500});
    button_create(&(w->ui.rotate), "     Rotate", &button_sizes[MEDIUM_B],
                                                &(sfVector2f){1800, 550});
}

static void create_toolbar(window_t *w)
{
    button_create(&(w->ui.raise), "Raise", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 450});
    button_create(&(w->ui.lower), "Lower", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 500});
    button_create(&(w->ui.level), "Level", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 550});
    button_create(&(w->ui.texture), "Texture", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 600});
}

static void create_other(window_t *w)
{
    button_create(&(w->ui.help_menu), " Help Menu", &button_sizes[MEDIUM_B],
                                                    &(sfVector2f){1800, 0});
    button_create(&(w->ui.map_x_m), "map x -", &button_sizes[SQUARE_B],
                                                &(sfVector2f){0, 600});
    button_create(&(w->ui.map_x_p), "map x +", &button_sizes[SQUARE_B],
                                                &(sfVector2f){135, 600});
    button_create(&(w->ui.map_y_m), "map y -", &button_sizes[SQUARE_B],
                                                &(sfVector2f){0, 735});
    button_create(&(w->ui.map_y_p), "map y +", &button_sizes[SQUARE_B],
                                                &(sfVector2f){135, 735});
    button_create(&(w->ui.menu_texture), "Menu Texture", &button_sizes[LARGE_B],
                                                &(sfVector2f){0, 875});
    button_create(&(w->ui.select_mode), "Select Mode", &button_sizes[LARGE_B],
                                                &(sfVector2f){0, 920});
}

int gui_create(window_t *w)
{
    create_toolbar(w);
    create_viewbar(w);
    create_headbar(w);
    create_other(w);
    return 0;
}