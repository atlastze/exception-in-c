#include <stdio.h>
#include "exception.h"

void foo(void)
{
    printf(".. In function: %s\n", __FUNCTION__);
    printf(".. In function: %s, throw exception, error code: %d\n",
           __FUNCTION__, 1);
    throw(1);
}

void bar(void)
{
    printf(".. In function: %s\n", __FUNCTION__);
    try {
        foo();
    } catch(1) {
        printf(".. In function: %s, exception is detected, error code: %d!\n",
               __FUNCTION__, 1);
        printf(".. In function: %s, rethrow exception, error code: %d\n",
               __FUNCTION__, 2);
        throw(2);
    }
}

int main(void)
{
    printf(".. In function: %s\n", __FUNCTION__);

    // begin detecting exception
    try {
        bar();
        // the bellowing code is unreachable,
        // because process always throws error
        printf(".. Unreachable code!\n");
    }

#if 0
    // exception (1) caught
    catch(1) {
        printf(".. In function: %s, exception is detected, error code: %d!\n",
               __FUNCTION__, 1);
    }
#endif

    // exception (2) caught
    catch(2) {
        printf(".. In function: %s, exception is detected, error code: %d!\n",
               __FUNCTION__, 2);
    }

    // others exceptions caught
    finally {
        printf(".. In function: %s, unkown exception is detected!\n",
               __FUNCTION__);
    }

    printf(".. End of program.\n");

    return 0;
}
