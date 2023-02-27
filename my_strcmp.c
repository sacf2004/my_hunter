/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

int my_strlen(char const *str);
int my_strcmp (char const *s1 , char const *s2)
{
    int index = 0;
    int length1 = my_strlen(s1);
    int length2 = my_strlen(s2);
    if (length1 != length2) {
        return (length1 < length2 ? length2 - length1 : length1 - length1);
    }
    while (s1[index] != '\0') {
        if (s1[index] != s2[index]) {
            return (s1[index] - s2[index]);
        }
        index = index +1 ;
    }
    return (0);
}
