/*
** EPITECH PROJECT, 2022
** My_hunter
** File description:
** help for hunter
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"

void help_analyse_event (sfEvent *event,
    sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2f beginning = {-250, rand() % 580};
    int spriteposx = sfSprite_getPosition(sprite).x;
    int spriteposy = sfSprite_getPosition(sprite).y;
    int mouseposx = sfMouse_getPositionRenderWindow(window).x;
    int mouseposy = sfMouse_getPositionRenderWindow(window).y;
    if (110 + spriteposx >= mouseposx && spriteposx <= mouseposx &&
            110 + spriteposy >= mouseposy && spriteposy <= mouseposy) {
        sfSprite_setPosition(sprite, beginning);
    }
}

void analyse_events(sfRenderWindow *window, sfSprite *sprite)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            help_analyse_event(&event,  window, sprite);
        }
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}
