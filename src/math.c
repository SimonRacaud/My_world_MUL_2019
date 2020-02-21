/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** math
*/

#include "my_world.h"

static float vectorial_product(sfVector2f p1, sfVector2f p2, sfVector2f m)
{
    float nb = (p1.x - m.x) * (p2.y - m.y) - (p1.y - m.y) * (p2.x - m.x);

    return nb;
}

bool point_is_on_triangle(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f p)
{
    float nb1 = vectorial_product(a, b, p);
    float nb2 = vectorial_product(b, c, p);
    float nb3 = vectorial_product(c, a, p);

    if (nb1 < 0 && nb2 < 0 && nb3 < 0)
        return true;
    if (nb1 >= 0 && nb2 >= 0 && nb3 >= 0)
        return true;
    return false;
}