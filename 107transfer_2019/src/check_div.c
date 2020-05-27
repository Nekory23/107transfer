/*
** EPITECH PROJECT, 2020
** transfer
** File description:
** check_div
*/

#include "transfer.h"

double check_get_result(coef_t *co, double x)
{
    double res = 0;
    double p0 = co->tab_a[co->max_a - 1];

    for (int i = (co->max_a - 2); i != -1; i--) {
        co->res_a = (p0 * x) + co->tab_a[i];
        p0 = co->res_a;
    }
    p0 = co->tab_b[co->max_b];
    for (int i = (co->max_b - 1); i != -1; i--) {
        co->res_b = (p0 * x) + co->tab_b[i];
        p0 = co->res_b;
    }
    if (co->res_b == 0)
        return  (ERROR);
    res = co->res_a / co->res_b;
    return (res);
}

int check_compute_complex(coef_t *co, int ac, char **av)
{
    int nbr_loop = (ac - 1) / 2;
    double res = 0;

    for (double x = 0; x <= 1.001; x += 0.001) {
        co = fill_struct(co, av);
        res = 0;
        res = check_get_result(co, x);
        for (int i = 1, j = 3; i != nbr_loop; i++, j += 2) {
            co = fill_sec_struct(co, av[j], av[j + 1]);
            if (check_get_result(co, x) == ERROR)
                return (ERROR);
            res *= check_get_result(co, x);
        }
    }
    return (SUCCESS);
}

int check_compute_simple(coef_t *co)
{
    double p0 = 0;

    for (double x = 0; x <= 1.001; x += 0.001) {
        p0 = co->tab_a[co->max_a - 1];
        for (int i = (co->max_a - 2); i != -1; i--) {
            co->res_a = (p0 * x) + co->tab_a[i];
            p0 = co->res_a;
        }
        p0 = co->tab_b[co->max_b];
        for (int i = (co->max_b - 1); i != -1; i--) {
            co->res_b = (p0 * x) + co->tab_b[i];
            p0 = co->res_b;
        }
        if (co->res_b == 0)
            return (ERROR);
        else
            return (SUCCESS);
    }
}

int check_div(coef_t *co, int ac, char **av)
{
    if (ac == 3)
        return (check_compute_simple(co));
    else
        return (check_compute_complex(co, ac, av));
}
