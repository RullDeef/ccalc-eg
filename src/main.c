#include <stdio.h>
#include "callocs.h"
#include "uki.h"
#include "calc.h"

int main(void)
{
    if (callocs_init(5 * (2U << 10)) != 0)
    {
        fprintf(stderr, "Could not initialize heap for uki.\n");
        return -1;
    }

    if (uki_init() != 0)
    {
        fprintf(stderr, "Could not initialize uki library.\n");
        callocs_destroy();
        return -2;
    }

    if (run_calc() != 0)
        fprintf(stderr, "Abnormal exit from calc.\n");

    uki_destroy();
    callocs_destroy();
    return 0;
}
