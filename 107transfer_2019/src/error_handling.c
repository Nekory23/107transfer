/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** error_handling
*/

#include "transfer.h"

int check_strings(int ac, char **av)
{
    for (int i = 1; i != ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '*' || av[i][j] == '-')
                continue;
            else if ((av[i][j] < '0' || av[i][j] > '9')) {
                write_error(STR_ERROR_STRING);
                write_error(STR_HELP);
                return (TRUE);
            }
        }
    }
    return (FALSE);
}

int error_handling(int ac, char **av)
{
    if (ac < 3) {
        write_error(STR_ERROR_ARGNBR);
        write_error(STR_HELP);
        return (TRUE);
    }
    if (ac % 2 != 1) {
        write_error(STR_ERROR_DEN);
        write_error(STR_HELP);
        return (TRUE);
    }
    if (check_strings(ac, av))
        return (TRUE);
    return (FALSE);
}
