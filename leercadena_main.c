/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Modificado por: Sara María Eraso y Juan Sebastián Estupiñán
 * Fecha: 2021-12-17
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char **vector;
  char salida[5] = "quit";
  int i;
  pid_t pid;
  
  while(strcmp(comando,salida) !=0) {
          printf("> ");
          leer_de_teclado(BUFSIZ,comando);
          pid = fork();
          if (pid < 0) {
                  printf("No pude crear un proceso\n");
                  return 2;
          } else if (pid == 0) {
                vector = de_cadena_a_vector(comando);
                execvp(vector[0],vector);
          } else {
                  wait(NULL);
          }
  }

  return 0;
}
