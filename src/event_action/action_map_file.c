/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** action => map files
*/

#include "event_action.h"

extern const char *MAP_EXTENSION;

void action_map_save(window_t *w)
{
    char *filename = w->map.map_name;
    char *map_file = my_str_concat(filename, MAP_EXTENSION);

    if (!filename || !map_file) {
        my_putstr_error("action_map_save() : file name error\n");
        return;
    }
    if (save_map(map_file, &w->map) == EXIT_FAILURE) {
        my_putstr_error("action_map_save() : save_map() error\n");
    }
    free(map_file);
}

void action_map_load(window_t *w)
{
    char *map_file = NULL;
    char *map_name = NULL;

    text_input_run(&w->ui.load_map_file, w->window);
    map_name = text_input_get_input(&w->ui.load_map_file);
    map_file = my_str_concat(map_name, MAP_EXTENSION);
    if (map_name && map_file) {
        if (load_map(map_file, &w->map) == EXIT_FAILURE) {
            my_printf("Error : fail to load map file :: (%s)\n", map_file);
            free(map_file);
        } else {
            free(w->map.map_name);
            w->map.map_name = map_name;
            text_input_set_content(&w->ui.edit_map_name, w->map.map_name);
        }
    } else {
        my_putstr_error("action_map_load() : error: map file name\n");
        free(map_file);
    }
}