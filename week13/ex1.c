#include <stdio.h>
void read_file(char *filename) {

    //we can calculate the length of the string, must be same for all strings, except \n strings
    // also we calculate the number of lines, due to that there is a special input format
    // we can calculate the number of lines
    // the task is not about parcing, so I did it very trivial just for this input format
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file");
    }
    char symbol[256] ;

    int checker = 0;
    
    int E [256]; //Resources in existence
    int A[256]; //Available resources
    int C[256][256]; //Current allocation matrix
    int R [256][256]; //Request matrix

    int counter_resources = 0;
    char temp;
    while ((temp = fgetc(fp)) != '\n'){     
        if (temp == ' ') counter_resources++;
    }
    counter_resources++; // calculate the last resourse
    fclose(fp);
    fp = fopen(filename, "r");
    // let us calculate the number of lines without \n strings
    int counter_processes = 0;
    int str_len_counter = 0;
    while ((temp = fgetc(fp)) != EOF){
        if (temp != '\n') str_len_counter++;
        if (temp == '\n') {
            if (str_len_counter > 0){
            counter_processes++;
            }
            str_len_counter = 0;
    }
    }
    fclose(fp);

    counter_processes = (counter_processes - 2)/2;
   
    fp = fopen(filename, "r");

    for (int i =0; i < counter_resources; i++){
        fscanf(fp, "%d", &E[i]);
 
    }
   
      for (int i =0; i < counter_resources; i++){
        fscanf(fp, "%d", &A[i]);
   
    }
    printf(" p = %d  r = %d", counter_processes, counter_resources);
    printf("\n");
    for (int i =0; i < counter_processes; i++){
        for (int j =0; j < counter_resources; j++){
            fscanf(fp, "%d", &C[i][j]);
 
        }
     
    }
    for (int i =0; i < counter_processes; i++){
        for (int j =0; j < counter_resources; j++){
            fscanf(fp, "%d", &R[i][j]);
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    fclose(fp);

    // now we can start the algorithm


    int changes = 1;
    int process_finished [counter_processes];
       for (int i =0; i < counter_processes; i++)
        process_finished[i] = 0;
        
    int n_proc = 0;
      while (changes == 1 && n_proc < counter_processes){
        changes = 0;
        for (int i = 0; i < counter_processes; i++){
            if (process_finished[i] == 1) continue;;
            int processable = 1;
            for (int j = 0; j < counter_resources; j++){
                if (R[i][j] > C[i][j] && A[j] < R[i][j] - C[i][j]){
                    processable = 0;
                    break;
                }
            }
            if (processable == 1){
               changes = 1;
               n_proc++;
               process_finished[i] = 1;

               for (int j = 0; j < counter_resources; j++){
                   A[j] += C[i][j];
               }
            }
        }
}

char output_name[] = "output_ok.txt";
FILE *fo= fopen(output_name, "w");
if (changes == 1){
    fprintf(fo, "No deadlock here! \n");
} else {
    fprintf(fo, "Deadlock detected!\n");
    for (int i = 0; i < counter_processes; i++){
        if (process_finished[i] == 0){
            fprintf(fo, "%d ", i);
        }
    }
}
fclose(fo);
}
int main(int argc, char *argv[]) {
    char input_name [] = "input_ok.txt";
    read_file(input_name);
    return 0;
}


