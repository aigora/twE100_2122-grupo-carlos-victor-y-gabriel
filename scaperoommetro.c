#include "lib.h"
#define N 12

typedef struct
{
    char nombre[N];
    int edad;
}jugador;

void juegoentero();

int main ()
{
    juegoentero();
    return 0;
}
void juegoentero()
{

    char op1,op2,c;
    char principo[N],destino[N],p1[N]={'1'},p2[N]={'2'},p3[N]={'3'},p4[N]={'4'},p5[N]={'5'},p6[N]={'6'};
    int cont1=0,cont2=0,prp,fn,x;
    jugador jugador1;

    FILE *pf;
    printf(" BIENVENIDO AL METRO!!\n ");
    printf("\n\n MENU PRINCIPAL\n\n 1. Instrucciones\n\n 2. Jugar \n\n 3. Salir\n\n Opcion: ");
    do
    {
        scanf(" %c",&op1);
        if(op1=='2'&&cont1==0)
        {
            printf("Introduzca su nombre:");
            scanf("%s",jugador1.nombre);
            printf("Introduzca su edad:");
            scanf("%d",&jugador1.edad);
        }

        switch(op1)
        {
             case '1':
                printf("\n Instrucciones\nA continuacion el usuario tendra que elegir la parada en la que se encuentra, ");
                printf("tendras que ir superando pruebas segun vaya avanzando el tren.\n");
                printf("\nElija otra opcion(1.Instrucciones,2.Jugar,3.Salir)");
                x=3;
             break;
             case '2':
                    pf=fopen("Mapa_metro.txt","r");
                    if(pf == NULL)
                    {
                    printf("Error al abrir el mapa");
                    }
                    else
                    {
                    while (fscanf(pf, "%c", &c) != EOF)
                        {
                            printf("%c", c);
                        }
                    pclose(pf);
                    }
                    printf("\nSeleccione la parada en la que se encuentra(numero): ");
        do
        {
            scanf("  %11s",principo);
            if(strcmp(p1,principo)==0)
                prp=1;
            else if(strcmp(p2,principo)==0)
                prp=2;
            else if(strcmp(p3,principo)==0)
                prp=3;
            else if(strcmp(p4,principo)==0)
                prp=4;
            else if(strcmp(p5,principo)==0)
                prp=5;
            else if(strcmp(p6,principo)==0)
                prp=6;

            if(strcmp(p1,principo)==0||strcmp(p2,principo)==0||strcmp(p3,principo)==0
               ||strcmp(p4,principo)==0||strcmp(p5,principo)==0||strcmp(p6,principo)==0)
                cont1++;
            else
            {
                cont1=0;
                printf("Seleccione una parada:");
            }
        }while(cont1==0);

            printf("\nSeleccione la parada a la que quiere llegar(numero): ");
        do
        {
                scanf("  %11s",destino);
                if(strcmp(p1,destino)==0)
                    fn=1;
                else if(strcmp(p2,destino)==0)
                    fn=2;
                else if(strcmp(p3,destino)==0)
                    fn=3;
                else if(strcmp(p4,destino)==0)
                    fn=4;
                else if(strcmp(p5,destino)==0)
                    fn=5;
                else if(strcmp(p6,destino)==0)
                    fn=6;

                if(strcmp(p1,destino)==0||strcmp(p2,destino)==0||strcmp(p3,destino)==0||strcmp(p4,destino)==0
                    ||strcmp(p5,destino)==0||strcmp(p6,destino)==0)
                {
                    cont2++;
                }
                if(strcmp(p1,destino)!=0&&strcmp(p2,destino)!=0&&strcmp(p3,destino)!=0&&strcmp(p4,destino)!=0&&strcmp(p5,destino)!=0
                    &&strcmp(p6,destino)!=0)
                {
                    cont2=0;
                    printf("opcion no valida\n");
                    printf("Seleccione una parada:");
                }
                else if(prp==fn)
                {
                    cont2=0;
                    printf("te quedas en el mismo sitio\n");
                    printf("Seleccione una parada:");
                }

        }while(cont2==0);

        printf("\nSu trayecto sera de la parada numero %s hasta la parada numero %s\n",principo,destino);
        int contv=1;//contador victorias
        if(prp<fn)//tren va hacia la derecha
        {
            for(int j=prp;j<=fn;j++)
            {
                if(j==1&&contv==1)
                {
                    printf("\nEstas en Zaragoza\n");
                    espacios();//da warning no sabemos por que
                    contv=juegomillonario();
                }
                else if(j==2&&contv==1)
                {
                    printf("\nEstas en La Rioja\n");
                    espacios();
                    contv=juegooperaciones();
                }
                else if(j==3&&contv==1)
                {
                    printf("\nEstas en Madrid\n");
                    espacios();
                    contv=ahorcado();

                }
                else if(j==4&&contv==1)
                {
                    printf("\nEstas en Granada\n");
                    espacios();
                    contv=juegocompletoporteria();
                }
                else if(j==5&&contv==1)
                {
                    printf("\nEstas en Sevilla\n");
                    espacios();
                    contv=juegomemory();
                }
                else if (j==6&&contv==1)
                {
                    printf("\nEstas en Valladolid\n");
                    espacios();
                    contv=juegoaleatorios();
                }
            }
        }

        else if(prp>fn)//tren va hacia la izquierda
        {
            for(int j=prp;j>=fn;j--)
            {
                if(j==1&&contv==1)
                {
                    printf("\nEstas en Zaragoza\n");
                    espacios();
                    contv=juegomillonario();
                }
                else if(j==2&&contv==1)
                {
                    printf("\nEstas en La Rioja\n");
                    espacios();
                    contv=juegooperaciones();
                }
                else if(j==3&&contv==1)
                {
                    printf("\nEstas en Madrid\n");
                    espacios();
                    contv=ahorcado();

                }
                else if(j==4&&contv==1)
                {
                    printf("\nEstas en Granada\n");
                    espacios();
                    contv=juegocompletoporteria();
                }
                else if(j==5&&contv==1)
                {
                    printf("\nEstas en Sevilla\n");
                    espacios();
                    contv=juegomemory();
                }
                else if (j==6&&contv==1)
                {
                    printf("\nEstas en Valladolid\n");
                    espacios();
                    contv=juegoaleatorios();
                }
            }
        }
        if(contv==1)
        {
            printf("\n\nEnhorabuena %s a tus %d anos de edad has superado todas las pruebas,has llegado a tu destino",jugador1.nombre,jugador1.edad);
            pf=fopen("Mapa_metro.txt","a");
            if (pf == NULL)
                {
                printf("Error al abrir el fichero.\n");
                }
            else
                {
                fprintf(pf,"%s con %d anos de edad \n",jugador1.nombre,jugador1.edad);
                }
            fclose(pf);
        }
        else
        {
            printf("\n\nVaya %s no has superado todas las pruebas",jugador1.nombre);
        }
        printf("\nElija otra opcion(1.Instrucciones,2.Jugar,3.Salir)");
        x=3;

    break;

    case '3':
        printf("\n    Estas seguro de que quieres salir (S o N)?: ");
        scanf(" %c",&op2);
        if(op2=='S' || op2=='s')
        {
            x=0;
        }
        else
        {
            printf("\nElija otra opcion(1.Instrucciones,2.Jugar ,3.Salir)");
            x=3;
        }
        break;

    default:
        printf("\n    Opcion no valida, elija un numero\n");
        x=3;
    break;
        }
    }
    while((op2!='S' || op2!='s')&&x!=0);
}

