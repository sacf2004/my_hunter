/*
** EPITECH PROJECT, 2022
** My_hunter
** File description:
** hunting ducks
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"

void help_analyse_event (sfEvent *event,
    sfRenderWindow *window, sfSprite *sprite);
void analyse_events(sfRenderWindow *window, sfSprite *sprite);

void auxiliar_analyse_event (sfSprite *sprite,
    sfRenderWindow *window, sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    analyse_events(window, sprite);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void move_duck (sfSprite *sprite,
    sfTexture *texture, sfClock *clock, sfIntRect *rect)
{
    sfTime time;
    float seconds;
    sfVector2f ducks = {25, 0};
    sfVector2f limit = {1390, 0};
    sfVector2f beginning = {-250, rand() % 580};
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100000.0;
        if (seconds > 1) {
            sfSprite_move(sprite, ducks);
            rect->left = rect->left + 110;
            if (rect->left == 330){
                rect->left = 0;
            }
            sfClock_restart(clock);
        }
        if (sfSprite_getPosition(sprite).x >= limit.x)
            sfSprite_setPosition(sprite, beginning);
}

void open_window_events(sfRenderWindow *window,
    sfSprite *sprite, sfTexture *texture, sfIntRect rect)
{
    sfSprite *background = sfSprite_create();
    sfTexture *background2 = sfTexture_createFromFile("background.jpg", NULL);
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setTexture(background, background2, sfFalse);
        sfSprite_setTextureRect(sprite, rect);
        move_duck(sprite, texture, clock, &rect);
        auxiliar_analyse_event(sprite, window, texture);
        sfRenderWindow_drawSprite(window, background, NULL);
    }
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

char *fs_open_and_read_file (char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return (NULL);
    }
    struct stat buffer;
    stat(filepath, &buffer);
    char *str = malloc (buffer.st_size * sizeof(char));
    if (read(fd, str, buffer.st_size) == -1){
        return (NULL);
    }
    return (str);
}

int main(int ac, char *av[])
{
    if (ac == 2 && my_strcmp (av[1], "-h") == 0) {
        char *str = fs_open_and_read_file("information.txt");
        write (1, str, my_strlen(str));
        free (str);
        my_putchar('\n');
        return (0);
    }
    sfVideoMode mode = {1280, 750, 32};
    sfIntRect rect = {0, 0, 110, 110};
    sfTexture *texture = sfTexture_createFromFile("patosvolando.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfRenderWindow* window = sfRenderWindow_create(
        mode, "MY_HUNTER", sfDefaultStyle, NULL);
    open_window_events (window, sprite, texture, rect);
}
