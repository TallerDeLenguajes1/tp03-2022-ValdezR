#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

int cantNombres;
char *Buff; //variable auxiliar
char **vector;

puts("Ingrese la cantidad de nombres: ");
scanf("%d",&cantNombres);
fflush(stdin);

Buff= (char *) malloc(100*sizeof(char));
vector=(char **) malloc(cantNombres*sizeof(char*));


for (int i = 0; i < cantNombres; i++)
{
    printf("Ingrese el %d nombre: ",(i+1));
    gets(Buff);
    vector[i]= (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(vector[i],Buff);
}

for (int i = 0; i < cantNombres; i++)
{
    printf("el %d nombre ingresado es: ",i+1);
    puts(vector[i]);
}
for (int j = 0; j < cantNombres; j++)
{
    free(vector[j]);
}
free(Buff);

return 0;
}