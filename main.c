#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
//to make your codename
void ash_codename(char **args){
	if(args[1] == NULL){
	 printf("Usage:codename <yourname>\n");
	return;
      }
	
	char path[256];
	snprintf(path, sizeof(path), "%s/.ashrc",getenv("HOME"));
	FILE *f = fopen(path, "w");
        if(f == NULL){
	   printf("ash: could not save codename\n");
           return;
        }
	fprintf(f,"%s", args[1]);
	fclose(f);
	printf("Codename set to: %s\n", args[1]);
}
 
int main(){
  char *line = NULL;
  size_t bufsize = 0;
  char *args[64];
  int i;
  char codename[64] = "";
  char path[256];
  
snprintf(path,sizeof(path), "%s/.ashrc",getenv("HOME"));
  FILE *f=fopen(path,"r");
  if (f !=NULL){
     fscanf(f, "%s", codename);
     fclose(f);
     printf("Welcome back,%s!\n",codename);
}

  while (1) {
    // Show the prompt
    printf("ash> ");

    // Read what the user typed
    getline(&line, &bufsize, stdin);

    // Split it into words
    args[0] = strtok(line, " \t\n");
    i = 1;
    while ((args[i] = strtok(NULL, " \t\n")) != NULL) {
      i++;
    }

    // Skip if nothing was typed
    if (args[0] == NULL) continue;

    // Exit if user types exit
    if (strcmp(args[0], "exit") == 0) break;

    if(strcmp(args[0],"codename")==0){
      ash_codename(args);
      continue;
      }

    // Run the command
    if (fork() == 0) {
     execvp(args[0], args);
      printf("ash: command not found\n");
      exit(1);
    }
    wait(NULL);
  }

  return 0;
}
 
