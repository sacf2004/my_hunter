/*
** EPITECH PROJECT, 2022
** task03
** File description:
** count and return nomber of character
*/
int my_strlen ( char const * str )
{
    int index = 0;

    while (str[index] != '\0') {
    index = index +1;
    }
    return (index);
}
