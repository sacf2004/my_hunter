/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** ...
*/
#ifndef MY_H
    #define MY_H

void my_putchar (char c);

int my_put_nbr (int nb);

int my_put_nbr_positive (unsigned int nb);

int my_putstr(char const *str );

void my_revstr (char *str, int length);

char *my_strcpy (char *dest, char const *src);

void decimal_to_hexadecimal_may(int nb);

int decimal_to_hexadecimal_min(unsigned int nb);

void decimal_to_octal(unsigned int nb);

void decimal_to_binary(int nb);

int my_strlen (char const *str);

int my_count_nbr(unsigned int nb);

int my_printf(const char* format, ...);

int my_strcmp (char const *s1 , char const *s2);

#endif
