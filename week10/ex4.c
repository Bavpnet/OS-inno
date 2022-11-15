#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include<string.h>



void task(){
    struct dirent *entry;
    struct dirent *links[10];
    //open dir
    DIR *dir = opendir("tmp");
    int c = 0;
    while((entry = readdir(dir)) != NULL){      
            links[c] = entry;
            c++;
        
    }
    closedir(dir);
    int flag = 0;
    for (int i = 0; i < c; i++){
        int l = 0;
        for (int j =0; j < c; j++){
            if(links[i]->d_ino == links[j]->d_ino){
                l++;
            }
        }
        if (l >= 2){
            if (flag == 0) {printf("%lu i-node\n", links[i]->d_ino);
            flag = 1;}
             printf("%s --- ", links[i]->d_name);
                for (int j = 0; j < c; j++){
                    if(links[i]->d_ino == links[j]->d_ino){
                        printf("%s ", links[j]->d_name);
                    }
                }
        printf("\n");
        }
    }
    

}

int main(int argc, char *argv[]) {
task();
return 0;
}