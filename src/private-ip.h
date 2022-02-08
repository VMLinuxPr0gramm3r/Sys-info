#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>

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
