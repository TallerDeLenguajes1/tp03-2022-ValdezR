#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 


struct Producto{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

//void cargarCliente(Cliente *clientes, char *tiposProductos[], int cantClientes);
//void mostrarClientes(Cliente *Clientes, int cantClientes);
int costoProducto(Producto p);

int main(){

    srand(time(NULL));
    char *aux;
    char *tiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantClientes;
    struct Cliente *clientes;

    puts("ingrese la cantidad de clientes (hasta un maximo de 5): ");
    scanf("%d",&cantClientes);
    fflush(stdin);
    clientes=(struct Cliente*)malloc(sizeof(struct Cliente) * cantClientes);

    aux = (char *)malloc(sizeof(char)*50);
    puts("\nProceda a cargar la informacion de cada cliente");

    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].ClienteID=i+1;
        printf("Ingrese el nombre del cliente %d", i+1);
        gets(aux);
        clientes[i].NombreCliente=(char *)malloc(sizeof(char)*(strlen(aux)+1));
        strcpy(clientes[i].NombreCliente,aux);
        clientes[i].CantidadProductosAPedir=rand()%5+1;

        clientes[i].Productos=( Producto *)malloc(sizeof(Producto)*clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir ; j++)
        {
            clientes[i].Productos[j].ProductoID=j+1;
            clientes[i].Productos[j].Cantidad=rand()%10+1;
            strcpy(clientes[i].Productos[j].TipoProducto, tiposProductos[rand()%4]);
            clientes[i].Productos[j].PrecioUnitario=rand()%90+10;
        }
        
    }
    
        return 0;
}

int costoProducto(Producto p){
    return p.Cantidad*p.PrecioUnitario;
}
