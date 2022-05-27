#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define H 45
#define V 13
#define N 12

typedef struct
{
    char nombre[20];
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
    int juegomillonario();
    int juegocompletoporteria();
    int juegooperaciones();
    int ahorcado();
    int juegomemory();
    int juegoaleatorios();
    void espacios();

    char op1,op2,c;
    char principo[N],destino[N],p1[N]={'1'},p2[N]={'2'},p3[N]={'3'},p4[N]={'4'},p5[N]={'5'},p6[N]={'6'};
    int cont1=0,cont2=0,contj=0,prp,fn,x;
    jugador jugadores[100];

    FILE *pf;
    printf(" BIENVENIDO AL METRO!!\n ");
    printf("\n\n MENU PRINCIPAL\n\n 1. Instrucciones\n\n 2. Jugar \n\n 3. Salir\n\n Opcion: ");
    do
    {
        scanf(" %c",&op1);
        if(op1=='2')
        {
            printf("Introduzca su nombre:");
            scanf("%s",jugadores[contj].nombre);
            printf("Introduzca su edad:");
            scanf("%d",&jugadores[contj].edad);
        }

        switch(op1)
        {
             case '1':
                printf("\n Instrucciones\nA continuacion el usuario tendra que elegir la parada en la que se encuentra");
                printf("y el nivel dificultad con el que desee jugar.\npor cada etacion tendra que superar una prueba hasta llegar a la parada de destino \n");
                printf("\nelija otra opcion(1.Instrucciones,2.Jugar,3.Salir)");
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
                    printf("\n seleccione la parada en la que se encunetra(numero): ");
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

            printf("\n seleccione la parada a la que quiere llegar(numero): ");
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
            printf("\n\nEnhorabuena %s a tus %d anos de edad has superado todas las pruebas,has llegado a tu destino",jugadores[contj].nombre,jugadores[contj].edad);
            if(contj>0)
            {
                printf("\n\nEl anterior jugador fue %s con una edad de %d",jugadores[contj-1].nombre,jugadores[contj-1].edad);
            }
        }
        else
        {
            printf("\n\nVaya %s no has superado todas las pruebas",jugadores[contj].nombre);
        }
        //scanf("%c",&op2);
//          if(op2=='S' || op2=='s')
//            {
//                x=0;
//            }
//            else
//            {
        contj++;
        printf("\nelija otra opcion(1.Instrucciones,2.Jugar,3.Salir)");
        x=3;
 //           }
    break;

    case '3':
        printf("\n    Estas seguro de que quieres salir (S o N)?: ");
        scanf(" %c",&op2);
        //if ((op2!='S')||(op2!='s')||(op2!='N')||(op2!='n'))
        if(op2=='S' || op2=='s')
        {
            x=0;
        }
        else
        {
            printf("\nelija otra opcion(1.Instrucciones,2.Jugar ,3.Salir)");
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
void espacios()
{
    char x='p';
    do
    {
    printf("Por favor pulse espacio para continuar...\n\n");
    x=getch();
    }
    while(x!=' ');
}

int juegomillonario()
{
    printf("ESTO ES QUIEN QUIERE SER MILLONARIO!!!A quien no le gustaria ser millonario y no viajar en metro\n");
    printf("Ya nos imaginamos que le suena esta prueba. Tendra que superar una pregunta de cultura general, para continuar con su viaje\n");
    char x='º',j;
    do
    {
        printf("Por favor pulse espacio para continuar...\n");
        x=getch();
    }
    while(x!=' ');

    printf("PRIMERA PREGUNTA\n");
    printf("Cual es el rio mas largo del mundo?\n");
    printf("A.Amazonas\nB.Nilo\nC.Rio Misisipi\nD.Mekong\n");

    j=getch();
    if(j=='b'||j=='B')
    {
        printf("\nEnhorabuena ha pasado la prueba, su viaje continua viaje\n\n");
        return 1;
    }
    else
    {
        printf("\nSe ha equivocado\n\n");
        return 0;
    }
}
int juegocompletoporteria()
{
    void printc (char campo[V][H]);
    int juego(char campo[V][H],int *bx,int *by,int *inp,int *finp);
    int bx,by,inp,finp;
    char campo[V][H];
    bx=6;//posicion x de la bola
    by=1;//posicion y de la bola
    inp=4;//fila de inicio de la porteria
    finp=7;//fila de fin de la porteria
    int i,j;
    printf("\nEn este juego tienes que intentar meter gol.\n");
    char avance;
    do
    {
        printf("Por favor pulse espacio para empezar...\n");
        avance=getch();
    }
    while(avance!=' ');
    for(i=0;i<V;i++)//bucle de los limites
    {
        for(j=0;j<H;j++)
        {
            if(i==0||i==V-1)
            {
                campo[i][j]='-';
            }
            else if(j==0||j==H-1)
            {
                campo[i][j]='|';
            }
            else
            {
                campo[i][j]=' ';
            }
        }
    }
    for(i=inp;i<=finp;i++)//bucle porteria
    {
        for(j=42;j<=43;j++)
        {
            if(i==inp||i==finp)
            {
                    campo[i][j]='-';
            }
            else
                if(j==43)
            {
                campo[i][j]='|';
            }
        }
    }
    return juego(campo,&bx,&by,&inp,&finp);
}
void printc (char campo[V][H])//funcion que imprime la matriz
{
    system("cls");
    int i,j;
    for(i=0;i<V;i++)
    {
        for(j=0;j<H;j++)
        {
            printf("%c",campo[i][j]);
        }
        printf("\n");
    }
}
int juego(char campo[V][H],int *bx,int *by,int *inp,int *finp)
{
    char enter;
    int cont=0,aux=-3;
    int puntuacion=0;
    setbuf(stdin,NULL);//reset del buffer del teclado
    while(kbhit()!=1)//kbhit(mientras no se pulsa ninguna tecla se ejecuta el bucle)
    {
        campo[*bx][*by]='o';
        printc(campo);
        if(aux<0||cont>6)//movimiento hacia arriba de la porteria
        {
            for(int i=1;i<11;i++)
            {
                campo[i][43]=campo[i+1][43];
                campo[i][42]=campo[i+1][42];
                campo[i+1][42]=' ';
                campo[i+1][43]=' ';
            }
            aux=aux+1;
            if(aux==7)
            {
                cont=0;
                aux=0;
            }
            *inp=*inp-1;
            *finp=*finp-1;
        }
        else//movimiento hacia abajo de la porteria
        {
            for(int i=11;i>1;i--)
            {
                campo[i][43]=campo[i-1][43];
                campo[i][42]=campo[i-1][42];
                campo[i-1][42]=' ';
                campo[i-1][43]=' ';
            }
            cont=cont+1;
            *inp=*inp+1;
            *finp=*finp+1;
        }
        printf("pulsa x para disparar\n");
        printf("Si pulsas otra tecla que no sea x se te penalizara y la porteria dejara de moverse");
        Sleep(10);//retardo 10ms
    }
    do//mismo codigo de movimiento de la porteria pero despues de haber pulsado una tecla(se podria haber hecho en otra funcion)
    {
        campo[*bx][*by]='o';
        printc(campo);
        if(aux<0||cont>6)
        {
            for(int i=1;i<11;i++)
            {
                campo[i][43]=campo[i+1][43];
                campo[i][42]=campo[i+1][42];
                campo[i+1][42]=' ';
                campo[i+1][43]=' ';
            }
            aux=aux+1;
            if(aux==7)
            {
                cont=0;
                aux=0;
            }
            *inp=*inp-1;
            *finp=*finp-1;
        }
        else
        {
            for(int i=11;i>1;i--)
            {
                campo[i][43]=campo[i-1][43];
                campo[i][42]=campo[i-1][42];
                campo[i-1][42]=' ';
                campo[i-1][43]=' ';
            }
            cont=cont+1;
            *inp=*inp+1;
            *finp=*finp+1;
        }
        if(enter!='x')
        {
            printf("pulsa x para disparar\n");
            enter=getch();//scanf sin pulsar enter
        }
        if(enter=='x')//movimiento de la pelota
        {
            *by=*by+1;
            campo[*bx][*by -1]=' ';
        }
        if((campo[*inp+1][42]=='o')||(campo[*finp-1][42]=='o'))//gol
            puntuacion=1;

        if((campo[*inp][42]=='o')||(campo[*finp][42]=='o'))//palo
            puntuacion=2;

        if(campo[6][43]=='o'||campo[5][43]=='o'||campo[7][43]=='o')//fuera
            puntuacion=3;

        Sleep(10);
    }while(puntuacion==0);

    int valorfinal;

    if(puntuacion==1)
    {
        printf("\nEnhorabuena has pasado la prueba\n");
        valorfinal=1;
    }
    if(puntuacion==2)
    {
        printf("\nVaya diste al palo no has pasado la prueba\n");
        valorfinal=0;
    }
    if(puntuacion==3)
    {
        printf("\nVaya fallaste no has pasado la prueba\n");
        valorfinal=0;
    }
    return valorfinal;
}
int juegooperaciones()
{
    int sol,solu;
    char op1,op2;
    srand(time(NULL));
    int x=1+rand() % 15,y=1+rand() % 15,z=1+rand() %15;
    int orden=rand() % 4;

    printf("\n\nLA CALCULADORA HUMANA!!!\nVamos a poner a prueba tu destraza matematica.\n");
    printf("\nTendras que realizar la operacion \n");
    printf("\nTen en cuenta que esta prueba es aleatoria cambiara si vuelves a jugar\n");
    printf("\nTambien tienes que tener en cuenta la jerarquia de las operaciones\n");
    espacios();
    if(orden==0)
    {
        sol=x+y+z;
        op1='+';
        op2='+';
    }
    else if(orden==1)
    {
        sol=x+y*z;
        op1='+';
        op2='*';
    }
    else if(orden==2)
    {
        sol=x*y+z;
        op1='*';
        op2='+';
    }
    else
    {
        sol=x*y*z;
        op1='*';
        op2='*';
    }
    printf("\nRealice la siguiente operacion:%d%c%d%c%d\n",x,op1,y,op2,z);
    printf("Mi solucion es:");
    scanf("%d",&solu);
    if(sol==solu)
    {
        printf("\nENHORABUENA HAS PASADO LA PRUEBA\n");
        return 1;
    }
    else
    {
         printf("\nNO HAS PASADO LA PRUEBA\n");
         return 0;
    }
}
int ahorcado()
{
    char palabra[20]="calcetin",rep[100],espacios[100];
    char pal;
    int longitud,a,b,inicial,bien=0,temp=0,intentos=5;
    int repetido=0,gano=0;
    printf("\tJuego del Ahorcado\n");
    printf("\njuega en letras minusculas\n");
    char x='p';
    do
    {
    printf("Por favor pulse espacio para continuar...\n\n");
    x=getch();
    }
    while(x!=' ');
    system("cls");
    longitud=0;
    inicial=0;
    b=0;
    rep[0]=' ';
    rep[1]='\0';
    do {
        system("cls");
        temp=0;
        if(inicial == 0)
        {
            for(a=0;a<strlen(palabra);a++)
            {
                if(palabra[a] == ' ')
                {
                    espacios[a] = ' ';
                    longitud++;
                }
                else
                {
                    espacios[a] = '_';
                    longitud++;
                }
            }
        }
        inicial = 1;
        espacios[longitud] = '\0';
        for(a=0;a<strlen(rep);a++)
        {
            if(rep[a] == pal)
            {
                repetido = 1;
                break;
            }
            else
            {
                repetido = 0;
            }
        }
        if(repetido==0)
        {
            for(a=0;a<strlen(palabra);a++)
            {
                if(palabra[a] == pal)
                {
                    espacios[a] = pal;
                    bien++;
                    temp=1;
                }
            }
        }
        if(repetido==0)
        {
            if(temp==0)
            {
                intentos-=1;
            }
        }
        else
        {
            printf("Ya se ha introducido esta letra");
            printf("\n\n");
        }

        printf("\n");
        for(a=0;a<strlen(espacios);a++)
        {
            printf(" %c ",espacios[a]);
        }
        printf("\n");
        if(strcmp(palabra,espacios) == 0)
        {
            gano = 1;
            break;
        }
        printf("\n");
        printf("Letras Acertadas: %d",bien);
        printf("\n");
        printf("Intentos: %d",intentos);
        printf("\n");
        rep[b] = pal;
        b++;

        if (intentos==0)
        {
            break;
        }

        printf("Introduzca una letra:");
        scanf("\n%c",&pal);

    }while(intentos!= 0);
    int valorfinal;

    if(gano)
    {
        printf("\n\n");
        printf("Enhorabuena, has ganado.");
        valorfinal=1;
    }
    else
    {
        printf("\n\n");
        printf("Has perdido.");
        valorfinal=0;
    }

    printf("\n\n");
    system("PAUSE");
    return valorfinal;
}
int juegomemory()
{
    void ejecucion(char m[3][3]);
    void primera(char m[3][3]);
    void tablero(char m[3][3]);
    void vacio(char c[3][3]);
    void insertar(char c[3][3]);
    int comprobar(char c[3][3],char sol[3][3]);
    char op;
    char c[3][3],m[3][3]={{'%','2','t'},{'#','%','&'},{'?','/','0'}};

    for(int i=0;i<3;i++)
        {
        for(int j=0;j<3;j++)
        {
            if(j<2)
            {
            printf(" %c |",m[i][j]);
            }
            else
            {
            printf(" %c ",m[i][j]);
            }
        }
        if(i<2)
        {
            printf("\n-------------\n");
        }
        }
        printf("\n\n");
    do
    {
    printf("Estas jugando al memory,tienes que memorizar los caracteres, cuando lo hayas hecho pulsa s:");
    scanf(" %c",&op);
    }while(op!='s'&&op!='S');
        system("cls");
        vacio(c);
        insertar(c);
        printf("\n\n");
         printf("matriz introducida por jugador\n__________________________\n");
     for(int i=0;i<3;i++)
     {
        for(int j=0;j<3;j++)
        {
            if(j<2)
            {
            printf(" %c |",c[i][j]);
            }
        else
        {
        printf(" %c ",c[i][j]);
        }
        }
      if(i<2)
      {
        printf("\n-------------\n");
      }
    }
    printf("\n\n\n");
    printf("\nmatriz solucion\n__________________________\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
        if(j<2)
        {
        printf(" %c |",m[i][j]);
        }
        else
        {
        printf(" %c ",m[i][j]);
        }
        }
        if(i<2)
        {
            printf("\n-------------\n");
        }
    }
    return comprobar(c,m);
}
void vacio(char c[3][3])
{
        for(int i=0;i<3;i++)
        {
        for(int j=0;j<3;j++)
        {
            if(j<2)
            {
            printf("  |");
            }
            else
            {
            printf("  ");
            }
        }
            if(i<2)
            {
            printf("\n---------\n");
            }
        }
        printf("\n\n");
}
void insertar(char c[3][3])
{
    int i,j;
    printf("introduce los valores de la matriz\nPara un juego responsable no mire la matriz solucion\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
        printf("introduce[%i][%i]:",i+1,j+1);
        scanf("   %c",&c[i][j]);
        }
    }
}
int comprobar(char c[3][3],char sol[3][3]){
    int cont=0;
    printf("\n\n");
    for(int i=0;i<3;i++)
    {
     for(int j=0;j<3;j++)
    {
         if(c[i][j]==sol[i][j])
         {
            printf("posicion[%i][%i] correcta\n",i+1,j+1);
            cont++;
         }
         else
        {
        printf("posicion[%i][%i] incorrecta\n",i+1,j+1);
        cont=0;
        }
    }
   }
    int valorfinal;
    if(cont==9)
    {
       printf("\n\nHAS GANADO");
        valorfinal=1;

    }
    else
    {
         printf("\n\nHAS PERDIDIO");
        valorfinal=0;
    }
    return valorfinal;

}
int juegoaleatorios()
{
    int n,a,i;
    printf("Bienvenido al juego tienes que adiviar un numerodel 0 al 50\n");
    printf(".................... \n");
    srand(time(NULL));
    n = rand() % 50 +1;

    for(i=5;i>=1;i--)
    {
        printf("\n te quedan %i intentos \n", i);
        printf("es un número(0-50) : ");
        scanf("%i",&a);
        if(a<n)
        {
            printf("\nte quedas corto \n\n");
        }
        else if(a>n)
        {
            printf("\nte pasas \n\n");
        }
        else;
        if(a==n)
        {
            printf("GANASTE!!!! ");
            return 1;
        }
        else;
    }
    printf("\n perdiste el numero es %i", n);
    return 0;
}


