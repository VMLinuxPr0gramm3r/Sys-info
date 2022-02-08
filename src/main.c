#include <stdio.h>
#include <stdlib.h>

#include "gethostname.h"
#include "os-detector.h"
#include "private-ip.h"

#define SYSTEM_INFORMATION

int private_ip_list(){
    int n;
    struct ifreq ifr;
    char inter[] = "wlan0";
    n = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name , inter , IFNAMSIZ - 1);
    ioctl(n, SIOCGIFADDR, &ifr);
    close(n);
    printf("%s - %s\n" , inter, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
    return 0;
}

int main(){
    printhostname();
    //print public ip and tor status
    system("python3 ./getip.py");
    private_ip_list();
    os_detector();
    print_current_time();
}
