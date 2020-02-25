/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** state_t
*/

#ifndef STATE_T_H_
#define STATE_T_H_

enum view_mode {
    NONE_V,
    SCALE,
    TRANSLATE,
    ROTATE
};

enum tools {
    NONE_T,
    RAISE,
    LOWER,
    LEVEL,
    TEXTURE
};

enum select_modes {
    TILE,
    CORNER,
    AREA
};

enum status {
    NONE_S,
    MORE,
    LESS
};

typedef struct software_status {
    enum view_mode vmode;
    sfBool show_help_menu;
    sfBool map_random_gen;
    sfBool map_edit_name;
    enum tools tool;
    enum select_modes select_mode;
} state_t;

#endif
