/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** start
*/

#include "transfer.h"

int start(int ac, char **av)
{
    coef_t *co;

    if (ac == 2 && my_strcmp(av[1], "-h")) {
        help_display();
        return (SUCCESS);
    }
    if (error_handling(ac, av))
        return (ERROR);
    co = fill_struct(co, av);
    if (check_div(co, ac, av) == ERROR) {
        free(co);
        write_error(STR_ERROR_DIV);
        return (ERROR);
    }
    compute(co, ac, av);
    free(co);
    return (SUCCESS);
}
