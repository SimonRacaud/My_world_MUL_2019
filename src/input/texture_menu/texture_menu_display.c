/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** texture menu
*/

#include "my_world.h"

static void update_sprite(texture_menu_t *self, map_t *map)
{
    self->map = map;
    self->select_idx = &map->selected_texture;
    for (int i = 0; i < self->count_sprite; i++) {
        sfSprite_setTexture(self->spr_available[i], self->map->textures[i],
        sfTrue);
    }
    sfSprite_setTexture(self->spr_selected,
    self->map->textures[*(self->select_idx)], sfFalse);
}

static void switch_selected_texture(texture_menu_t *self, int sens)
{
    if (sens != -1 && sens != 1)
        return;
    *(self->select_idx) += sens;
    if (*(self->select_idx) < 0)
        *(self->select_idx) = (self->count_sprite - 1);
    else if (*(self->select_idx) >= self->count_sprite)
        *(self->select_idx) = 0;
    sfSprite_setTexture(self->spr_selected,
    self->map->textures[*(self->select_idx)], sfFalse);
}

static void texture_menu_event_manager(texture_menu_t *self, sfEvent *event,
sfBool *is_active)
{
    if (event->type == sfEvtClosed) {
        texture_menu_status(self, is_active);
    } else if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyEscape || event->key.code == 58)
            texture_menu_status(self, is_active);
        if (event->key.code == sfKeyLeft) {
            switch_selected_texture(self, -1);
        } else if (event->key.code == sfKeyRight) {
            switch_selected_texture(self, 1);
        }
    }
}

int texture_menu_display(texture_menu_t *self, map_t *map, sfBool *is_active)
{
    sfEvent event;

    if (!self || !is_active)
        return EXIT_FAILURE;
    update_sprite(self, map);
    while (sfRenderWindow_pollEvent(self->window, &event))
        texture_menu_event_manager(self, &event, is_active);
    sfRenderWindow_clear(self->window, self->color_bg);
    sfRenderWindow_drawSprite(self->window, self->spr_selected, NULL);
    for (int i = 0; i < self->count_sprite; i++) {
        sfRenderWindow_drawSprite(self->window, self->spr_available[i], NULL);
    }
    sfRenderWindow_drawText(self->window, self->txt_info, NULL);
    sfRenderWindow_display(self->window);
    return EXIT_SUCCESS;
}
