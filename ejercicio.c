/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ejercicio.c
* Creation Date : 21-01-2016
* Last Modified : Thu 21 Jan 2016 10:48:07 AM CST
* Created By : shiro-saber

KNOW LEARN        .==.
C LANGUAGE       ()''()-.
      .---.       ;--; /
    .'_:___". _..'.  __'.
    |__ --==|'-''' \'...;
   [  ]  :[|       |---\
    |__| I=[|     .'    '.
    / / ____|     :       '._
   |-/.____.'      | :       :
  /___\ /___\      '-'._----'
_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char asc(char a, char b)
{
    return a < b;
}

void ordenamela(char *palabra, char criterio(char, char), int lon)
{
  int i, j;
  char temp;

  for(i = 0;  i < lon; ++i)
  {
    for(j = lon-1; j > i; --j)
    {
      if(criterio(palabra[j], palabra[j-1]))
      {
        temp = palabra[j-1];
        palabra[j-1] = palabra[j];
        palabra[j] = temp;
      }
    }
  }
}

int contar(char *palabra, char *caracter, int lon)
{
  char *aux;
  int cuantos;
  aux = palabra;
  for(; aux < palabra; ++aux)
    if(aux == caracter)
      cuantos++;

  return cuantos;
}

int main()
{
  int lon, i;
  char *palabra, *aux, *evaluadas;
  int *guarda;
  
  i = 0;

  printf("Máximo de caracteres\n");
  scanf("%d", &lon);
  
  palabra = (char*)malloc(sizeof(char)*lon);
  evaluadas = (char*)malloc(sizeof(char)*lon);

  printf("Dame una palabra \n");
  scanf("\n%[^\n]", palabra);

  for(aux = palabra; aux > palabra; --aux)
  {
    if(aux != (evaluadas+i))
    {
      *(evaluadas+i) = aux;
      *(guarda+i) = contar(palabra, aux, lon);
      i++;
    }
  }
  
  ordenamela(palabra, asc, lon);

  for(aux = palabra; aux > palabra; --aux)
    printf("La letra %s, se repite %d veces\n", aux, guarda);
  
  free(palabra);
  free(guarda);
  return 0;
}

