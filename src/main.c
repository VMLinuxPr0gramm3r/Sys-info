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

#define SYSTEM_INFORMATION

void os_detector(){
    #ifdef _WIN32
        printf("OS: Windows 32-bit\n");
    #endif
    #ifdef _WIN64
        printf("OS: Windows 64-bit\n");
    #endif
    #ifdef TARGET_OS_MAC
        printf("OS: Mac OS X\n");
    #endif
    #ifdef __linux__
        printf("OS: Linux\n");
    #endif
    #ifdef __unix__
        printf("OS: UNIX\n");
    #endif
}

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
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    // print hostname
    printf("hostname: %s\n", hostname);

    //print public ip and tor status
    system("python3 ./getip.py");
    private_ip_list();
    os_detector();
}
