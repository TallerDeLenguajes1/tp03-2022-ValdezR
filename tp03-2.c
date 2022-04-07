#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

char *Buff; //variable auxiliar
char *vector[5];

Buff= (char *) malloc(100*sizeof(char));

for (int i = 0; i < 5; i++)
{
    printf("Ingrese el %d nombre: ",(i+1));
    gets(Buff);
    vector[i]= (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(vector[i],Buff);
}

for (int i = 0; i < 5; i++)
{
    printf("el %d nombre ingresado es: ",i+1);
    puts(vector[i]);
}
for (int j = 0; j < 5; j++)
{
    free(vector[j]);
}
free(Buff);

return 0;
}
