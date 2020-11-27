#include <stdio.h>
#include "calc.h"
#include "uki.h"

int run_calc(void)
{
    uki_menu_t menu = uki_menu_create_ctx();
    int status = 0;

    uki_menu_ctx_info_set(menu, "Select one of the available calc types:");

    uki_menu_ctx_opt_add(menu, "simple", NULL);
    uki_menu_ctx_opt_add(menu, "scientific", NULL);

    int (*func)(void);
    uki_menu_ctx_run(menu, (void **)&func);

    if (func != NULL)
        status = func();
    else
        printf("invalid calc type.\n");

    uki_menu_destroy(menu);
    return status;
}
