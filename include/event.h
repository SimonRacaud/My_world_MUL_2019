/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "my_world.h"

void manage_events(window_t *w, sfEvent *event);

void event_mouse_click(window_t *w, sfEvent *event);
void event_mouse_wheel_scroll(window_t *w, sfEvent *event);

#endif
