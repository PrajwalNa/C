// checks for the OS and executes the code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *os = getenv("OS");
  if (os == NULL) {
    printf("OS not found\n");
    return 1;
  }
  if (strcmp(os, "Windows_NT") == 0) {
    printf("Windows\n");
    system("dir");
    system("echo %SHELL%");
    system("echo %PATH% && echo 'Hello World'");
  } else if (strcmp(os, "Linux") == 0) {
    printf("Linux\n");
    system("ls");
    system("echo $SHELL && echo $PATH && echo 'Hello World'");
  } else {
    printf("Unknown OS\n");
  }
  return 0;
}