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
