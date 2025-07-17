#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 10240

int femtoshell_main(int argc, char *argv[]) {
  char buff[BUF_SIZE];
  ssize_t len;
  int exStat = 0;
  while (1) {
    // write(1,"Femto Shell > ",sizeof("Femto Shell > "));
    if (fgets(buff, BUF_SIZE, stdin)) {
      if (!strcmp("exit\n", buff)) {
        write(1, "Good Bye\n", sizeof("Good Bye\n"));
        exit(0);
      } else if (!strncmp("echo ", buff, 5)) {
        len = strlen(buff);
        write(1, buff + 5, len - 5);
      } else if (!strcmp("\n", buff)) {
      } else {
        write(2, "Invalid command\n", sizeof("Invalid command\n"));
        exStat = -1;
      }
    } else {
      exit(exStat);
    }
  }
  return 0;
}