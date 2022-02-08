#include <stdio.h>
#include <stdlib.h>

#include "gethostname.h"
#include "os-detector.h"
#include "private-ip.h"

#define SYSTEM_INFORMATION

int main(){
    printhostname();
    //print public ip and tor status
    system("python3 ./getip.py");
    private_ip_list();
    os_detector();
    print_current_time();
}
