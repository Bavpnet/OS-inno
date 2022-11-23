
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main() {
   DIR *dir;
   struct dirent *entry;

   dir = opendir("/");
   while ((entry = readdir(dir)) != NULL) {
      printf("name = %s\n", entry->d_name);
   }
   closedir(dir);

   return 0;
}
