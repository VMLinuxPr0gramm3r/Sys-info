#include <unistd.h>
#include <stdio.h>
void printhostname() {
  char hostname[1024];
  hostname[1023] = '\0';
  gethostname(hostname, 1023);
  printf("hosntame: %s\n", hostname);
}
