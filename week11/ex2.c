
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   DIR *dir;
   struct dirent *ent;

   dir = opendir("/");
   while ((ent = readdir(dir)) != NULL) {
      printf(" %s \n", ent->d_name);
   }
   closedir(dir);

   return 0;
}
