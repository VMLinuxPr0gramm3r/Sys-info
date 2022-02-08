#include <stdio.h>
#include <stdlib.h>

int getpublicip(){
    printf("Public IP adress\n");
    system("curl 'https://api64.ipify.org?format=xml'");
}
