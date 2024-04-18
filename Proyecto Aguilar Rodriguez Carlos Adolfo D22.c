#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
struct datos_clientes
	{
	char codigo[5];
	char nombre[40];
	char calle[50];
	char colonia[40];
	char telefono[11];
	}clientes;

struct datos_factura
	{
	char codigo[5];
	char fecha[15];
	char clave_cliente[4];
	char clave_producto[4];
	char cantidad[5];
	}facturas;

struct datos_productos
	{
	char codigo[5];
	char producto[20];
	char descripcion[40];
	char precio[10];
	}productos;

// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22

void main()
	{
	int opcion=9;
	int cantidadproducto;
	char opcion_seg[2];
	char clavebuscar[4];
	FILE *archivo, *auxiliar;
	float precioproducto;
	char variablecompra;
	int cont;
	float totalpagar;

	if((archivo=fopen("c:datosclientes.txt","a+b"))==NULL)
		{

		printf("n\imposible abrir el archivo");
		getch();
		exit(1);
		}
	if((auxiliar=fopen("c:borrador.txt","a+b"))==NULL)
		{

		printf("n\imposible abrir el archivo");
		getch();
		exit(1);
		}
	do
		{


// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
        printf("\nPrimer Proyecto de programacion en lenguaje C Aguilar Rodriguez Carlos Adolfo\n");
        Sleep(3000);
         printf("\nPrograma que almacena,modifica,busca y muestra datos \n");
        Sleep(3000);

		printf("\n\n   Registros de tienda de electronica");
        Sleep(200);
		printf("\n\n1.- Consultar facturas de ventas");
		Sleep(200);
		printf("\n\n2.- Registrar producto");
		Sleep(200);
		printf("\n\n3.- Registrar cliente");
		Sleep(200);
		printf("\n\n4.- Buscar facturas ");
		Sleep(200);
		printf("\n\n5.- Buscar producto");
		Sleep(200);
		printf("\n\n6.- Buscar cliente");
		Sleep(200);
		printf("\n\n7.- Salir");
        Sleep(200);
        printf("\n\nSeleccione la opcion que desee realizar y presione enter : ");
		gets(opcion_seg);
		opcion=atoi(opcion_seg);
		switch(opcion)
			{
			case 1:
// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22

				freopen("c:datosfactura.txt","a+b",archivo);
				printf("n\codigo de la factura:  ");fflush(stdin);
				gets(facturas.codigo);
				printf("n\ fecha: ");fflush(stdin);
				gets(facturas.fecha);
				printf("n\codigo del cliente: ");fflush(stdin);
				gets(facturas.clave_cliente);
				freopen("c:datosclientes.txt","a+b",archivo);
				rewind(archivo);
				variablecompra=fgetc(archivo);
				fseek(archivo,0L,SEEK_SET);
				while(variablecompra!=EOF)
					{
					if(fread(&clientes,sizeof(clientes),1,archivo)!=1)
						{
						printf("n\ Errror al leer producto");
						getch();
						exit(3);
						}

					if(strcmp(facturas.clave_cliente,clientes.codigo)==0)
						{
						cont=2;
						printf("n\ Nombre:  %s",clientes.nombre);
						}
					variablecompra=fgetc(archivo);
					fseek(archivo,0L,SEEK_SET);
					}
				if (cont!=2)
					{
					printf("n\ Clave del cliente no existe");
					getch();
					}
				printf("n\codigo del producto:   ");fflush(stdin);
				gets(facturas.clave_producto);
				freopen("c:datosproducto.txt","a+b",archivo);
				rewind(archivo);
				variablecompra=fgetc(archivo);
				fseek(archivo,0L,SEEK_SET);
				while(variablecompra!=EOF)
					{
					if(fread(&productos,sizeof(productos),1,archivo)!=1)
						{
						printf("n\ Errror al leer producto");
						getch();
						exit(3);
						}
// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
					if(strcmp(facturas.clave_producto,productos.codigo)==0)
						{
						cont=2;
						precioproducto=atof(productos.precio);
						printf("n\%s",productos.producto);
						printf("n\precio :     %s",productos.precio);
						printf("n\ cantidad de productos:   ");
						gets(facturas.cantidad);
						cantidadproducto=atoi(facturas.cantidad);
						totalpagar=(precioproducto)*(cantidadproducto);
						printf("n\ total a pagar= %f ", totalpagar);
						getch();
						}
					variablecompra=fgetc(archivo);
					fseek(archivo,0L,SEEK_SET);
					}
				if (cont!=2)
					{
					printf("n\ El codigo que ingresaste no existe");
					getch();
					}
// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
				freopen("c:datosfactura.txt","a+b",archivo);
				if(fwrite(&facturas,sizeof(facturas),1,archivo)!=1)
					{
					printf("n\Error al escribir sobre el archivo");
					getch();
					}

				break;



			case 2:

// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
				freopen("c:datosproducto.txt","a+b",archivo);
				printf("n\ingresa codigo del producto:   ");fflush(stdin);
				gets(productos.codigo);
				printf("n\ingresa nombre del producto:   ");fflush(stdin);
				gets(productos.producto);
				printf("n\ingresa descripcion del producto:   ");fflush(stdin);
				gets(productos.descripcion);fflush(stdin);
				printf("n\ingresa precio:   ");fflush(stdin);
				gets(productos.precio);
				if(fwrite(&productos,sizeof(productos),1,archivo)!=1)
					{
					printf("Error al escribir sobre el archivo");
					getch();
					}
				printf("n\ %s",productos.precio);
				getch();
				break;

			case 3:


// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
				freopen("c:datosclientes.txt","a+b",archivo);
				printf("n\ ingresa codigo del cliente:  ");fflush(stdin);
				gets(clientes.codigo);
				printf("n\ ingresa nombre: ");fflush(stdin);
				gets(clientes.nombre);
				printf("n\ ingresa calle: ");fflush(stdin);
				gets(clientes.calle);
				printf("n\ ingresa colonia: ");fflush(stdin);
				gets(clientes.colonia);
				printf("n\ ingresa telefono: ");fflush(stdin);
				gets(clientes.telefono);

				if(fwrite(&clientes,sizeof(clientes),1,archivo)!=1)
					{
					printf("n\ Error al escribir sobre el archivo");
					getch();
					exit(2);
					}
				break;

			case 4:
// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22

				freopen("c:datosfactura.txt","a+b",archivo);
				printf("n\ Ingresa el codigo de la factura");fflush(stdin);
				scanf("%s", & clavebuscar);
				rewind(archivo);
				variablecompra=fgetc(archivo);
				fseek(archivo,0L,SEEK_SET);
				while(variablecompra!=EOF)
					{
					if(fread(&facturas,sizeof(facturas),1,archivo)!=1)
						{
						printf("n\Falla al leer factura de venta");
						getch();
						exit(3);
						}

					if(strcmp(facturas.codigo,clavebuscar)==0)
						{
						cont=2;
						printf("n\ codigo: %s", facturas.codigo);
						printf("n\ fecha: %s", facturas.fecha);
						freopen("c:datoscliente.txt","a+b",auxiliar);
						rewind(auxiliar);
						variablecompra=fgetc(auxiliar);
						fseek(auxiliar,0L,SEEK_SET);
						while(variablecompra!=EOF)
							{
							if(fread(&clientes,sizeof(clientes),1,auxiliar)!=1)
								{
								printf("n\Error al leer cliente");
								getch();
								exit(3);
								}

							if(strcmp(facturas.clave_cliente,clientes.codigo)==0)
								{
								cont=2;
								printf("n\ Nombre: %s",clientes.nombre);
								}
							;variablecompra=fgetc(auxiliar);
							fseek(auxiliar,0L,SEEK_SET);
							}
						if (cont!=2)
							{
							printf("n\ Clave del cliente no existe");
							getch();
							}
// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
						freopen("c:datosproducto.txt","a+b",auxiliar);
						rewind(auxiliar);
						variablecompra=fgetc(auxiliar);
						fseek(auxiliar,0L,SEEK_SET);
						while(variablecompra!=EOF)
							{
							if(fread(&productos,sizeof(productos),1,auxiliar)!=1)
								{
								printf("n\ Falla al leer producto");
								getch();
								exit(3);
								}

							if(strcmp(facturas.clave_producto,productos.codigo)==0)
								{
								cont=2;
								printf("n\ Producto: %s",productos.producto);
								printf("n\ Precio: %s", productos.precio);
								precioproducto=atof(productos.precio);
								}
							variablecompra=fgetc(auxiliar);
							fseek(auxiliar,0L,SEEK_SET);
							}
						if (cont!=2)
							{
							printf("n\ Clave del cliente no existe");
							getch();
							}

// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
						printf("n\ cantidad: %s", facturas.cantidad);
						cantidadproducto=atoi(facturas.cantidad);
						totalpagar=(precioproducto)*(cantidadproducto);
						printf("n\ total: %f", totalpagar);
						getch();
						}
					variablecompra=fgetc(archivo);
					fseek(archivo,0L,SEEK_SET);
					}
				if (cont!=2)
					{
					printf("n\ El codigo que ingresaste no existe");
					getch();
					}
				break;


			case 5:

// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
				freopen("c:datosproducto.txt","a+b",archivo);
				printf("n\ Ingresa el codigo del producto: ");fflush(stdin);
				gets(clavebuscar);
				rewind(archivo);
				variablecompra=fgetc(archivo);
				fseek(archivo,0L,SEEK_SET);
				while(variablecompra!=EOF)
					{
					if(fread(&productos,sizeof(productos),1,archivo)!=1)
						{
						printf("n\ Errror al leer producto");
						getch();
						exit(3);
						}

					if(strcmp(clavebuscar,productos.codigo)==0)
						{
						cont=2;
						printf("n\ codigo: %s",productos.codigo);
						printf("n\ producto: %s",productos.producto);
						printf("n\ Descripcion: %s",productos.descripcion);
						printf("n\ precio : %s",productos.precio);
						getch();
						}
					variablecompra=fgetc(archivo);
					fseek(archivo,0L,SEEK_SET);
					}

				if (cont!=2)
					{
					printf("n\ El codigo que ingresaste no existe");
					getch();
					}
				break;
			case 6:

// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
				printf("n\ codigo de cliente a buscar: ");fflush(stdin);
				gets(clavebuscar);
				freopen("c:datoscliente.txt","a+b",archivo);
				rewind(archivo);
				variablecompra=fgetc(archivo);
				fseek(archivo,0L,SEEK_SET);
				while(variablecompra!=EOF)
					{
					if(fread(&clientes,sizeof(clientes),1,archivo)!=1)
						{
						printf("n\ Errror al leer producto");
						getch();
						exit(3);
						}

					if(strcmp(clavebuscar,clientes.codigo)==0)
						{
						cont=2;
						printf("n\ Clave: %s",clientes.codigo);
						printf("n\ Nombre:  %s",clientes.nombre);   fflush(stdin);
						printf("n\ Calle: %s", clientes.calle);
						printf("n\ Colonia: %s",clientes.colonia);
						printf("n\ Telefono: %s",clientes.telefono);
						getch();
						}
					fflush(stdin);variablecompra=fgetc(archivo);
					fseek(archivo,0L,SEEK_SET);
					}
				if (cont!=2)
					{
					printf("n\ el codigo que ingresaste no existe");
					getch();
					}
				break;
// Proyecto programacion en c Aguilar Rodriguez Carlos Adolfo D22
			case 7:

				printf(" Proyecto Aguilar Rodriguez Carlos Adolfo \n Presione cualquier tecla para salir");
				getch();
				break;

			default:

				printf("n\ esta opcion no es valida");
				getch();
				break;
			}
		}
		while(opcion!=7);
	if(fclose(archivo)!=0)
		{

		printf("n\ error al ejecutar archivo");
		getch();
		exit(4);
		}
	}
