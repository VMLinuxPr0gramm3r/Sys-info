#include<stdio.h>
#include<time.h>

int print_current_time()
{
    time_t t;   // not a primitive datatype
    time(&t);
    printf("\nTime and Date :%s", ctime(&t));
    return 0;
}
