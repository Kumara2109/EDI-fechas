#include <stdio.h>

//Utilicen una struct para modelar la información de las fechas
//Creen funciones para:
//     1. imprimir la fecha DD/MM/AAAA
//     2. sumar días, meses o años a una fecha
           // La función debe recibir la fecha inicial
           // El tipo que va a sumar (DIA/MES/ANNIO)
           // Regresar la nueva fecha
//     3. restar días, meses o años a una fecha
           // La función debe recibir la fecha inicial
           // El tipo que va a restar (DIA/MES/ANNIO)
           // Regresar la nueva fecha
//     4. comparar una fecha con otra
//         a. Si la primer fecha es menor que la segunda regresará un 1
//         b. Si son iguales regresará un 0
//         c. Si la primer fecha es mayor que la segunda regresará un -1
//     5. función capturar una fecha, validaciones
//         Regrese un 1 si la fecha es válida o 0 si no

#define DIA 1
#define MES 2
#define ANNIO 3
#define FECHA 4

struct struct_fecha
{
    int dia;
    int mes;
    int annio;
};

typedef struct struct_fecha Fecha;

int menu(void);
void capturaFecha(Fecha *fecha);
int SeleccionaDMAF(int op, int *cant);
Fecha sumaFecha(Fecha fecha, int tipo, int cantidadS);
Fecha restaFecha(Fecha fecha, int tipo, int cantidadR);
int compararFechas(Fecha fecha1, Fecha *fecha2);
void imprimeFecha(Fecha fecha);

int main()
{
    Fecha fecha,fechaComp;
    int op = 0,tipo = 0,cantidadS = 0,cantidadR = 0,res;
    
    
    printf("Ingresa la nueva fecha\n");
    capturaFecha(&fecha);
    while(op!=4)
    {
        op=menu();
        switch(op)
        {
            case 1:
                printf("\n¿Qué desea sumar?\n");
                tipo=SeleccionaDMAF(1,&cantidadS);//1=Suma
                fecha=sumaFecha(fecha,tipo,cantidadS);
                printf("La fecha resultante es:\n");
                imprimeFecha(fecha);
                break;
            case 2:
                printf("\n¿Qué desea restar?\n");
                tipo=SeleccionaDMAF(0,&cantidadR);//0=Resta
                fecha=restaFecha(fecha,tipo,cantidadR);
                printf("La fecha resultante es:\n");
                imprimeFecha(fecha);
                break;
            case 3:
                res=compararFechas(fecha,&fechaComp);
                if(res==1)
                    printf("%d/%d/%d es menor a %d/%d/%d\n",fecha.dia,fecha.mes,fecha.annio,fechaComp.dia,fechaComp.mes,fechaComp.annio);
                if(res==0)
                    printf("%d/%d/%d es igual a %d/%d/%d\n",fecha.dia,fecha.mes,fecha.annio,fechaComp.dia,fechaComp.mes,fechaComp.annio);
                if(res==-1)
                    printf("%d/%d/%d es mayor a %d/%d/%d\n",fecha.dia,fecha.mes,fecha.annio,fechaComp.dia,fechaComp.mes,fechaComp.annio);
                break;
            case 4:
                printf("Programa finalizado\n\n");
                break;
            default:
                printf("Opción inválida\n");
                
        }
    }
    
    return 0;
}

int compararFechas(Fecha fecha1, Fecha *fecha2)
{
    int resultado;
    
    printf("\nFecha actual: ");
    imprimeFecha(fecha1);
    printf("Ingresa fecha a comparar: ");
    capturaFecha(&*fecha2);
    if(fecha1.annio<fecha2->annio)
        resultado=1;
    if(fecha1.annio>fecha2->annio)
        resultado=-1;
    if(fecha1.annio==fecha2->annio)
    {
        if(fecha1.mes<fecha2->mes)
            resultado=1;
        if(fecha1.mes>fecha2->mes)
            resultado=-1;
        if(fecha1.mes==fecha2->mes)
        {
            if(fecha1.dia<fecha2->dia)
                resultado=1;
            if(fecha1.dia>fecha2->dia)
                resultado=-1;
            if(fecha1.dia==fecha2->dia)
            {
                resultado=0;
            }
        }
    }
    return resultado;
}

void capturaFecha(Fecha *fecha)
{
    int band;
    
    printf("Mes (1-12): ");
    do
    {
        band=1;
        scanf("%d",&fecha->mes);
        if(fecha->mes<1 || fecha->mes>12)
        {
            printf("Opción inválida, Ingresa un mes válido: ");
            band=0;
        }
    }while(band==0);
    if (fecha->mes==2)
    {
        printf("Día (1-28): ");
        do
        {
            band=1;
            scanf("%d",&fecha->dia);
            if(fecha->dia<1 || fecha->dia>28)
            {
                printf("Opción inválida, Ingresa un día válido: ");
                band=0;
            }
        }while(band==0);
    }
    if (fecha->mes==1 || fecha->mes==3 || fecha->mes==5 || fecha->mes==7 || fecha->mes==8 || fecha->mes==10 || fecha->mes==12)
    {
        printf("Día (1-31): ");
        do
        {
            band=1;
            scanf("%d",&fecha->dia);
            if(fecha->dia<1 || fecha->dia>31)
            {
                printf("Opción inválida, Ingresa un día válido: ");
                band=0;
            }
        }while(band==0);
    }
    if (fecha->mes==4 || fecha->mes==6 || fecha->mes==9 || fecha->mes==11)
    {
        printf("Día (1-30): ");
        do
        {
            band=1;
            scanf("%d",&fecha->dia);
            if(fecha->dia<1 || fecha->dia>30)
            {
                printf("Opción inválida, Ingresa un día válido: ");
                band=0;
            }
                
        }while(band==0);
    }
    printf("Año (1500-3000): ");
    do
    {
        band=1;
        scanf("%d",&fecha->annio);
        if(fecha->annio<1500 || fecha->annio>3000)
        {
            printf("Opción inválida, Ingresa un año válido: ");
            band=0;
        }
    }while(band==0);
    printf("Fecha ingresada: ");
    imprimeFecha(*fecha);
}

void imprimeFecha(Fecha fecha)
{
    printf("%d/%d/%d\n",fecha.dia,fecha.mes,fecha.annio);
}

Fecha restaFecha(Fecha fecha, int tipo, int cantidadR)
{
    int dd,mm,aa;
    
    if(tipo==DIA)
    {
        while(cantidadR>0)
        {
            if (fecha.mes==2)
            {
                for(;fecha.dia>1 && cantidadR>0;fecha.dia--,cantidadR--);
                if(cantidadR>=1)
                {
                    fecha.mes--;
                    cantidadR--;
                    fecha.dia=31;
                }
            }
            if (fecha.mes==1 || fecha.mes==3 || fecha.mes==5 || fecha.mes==7 || fecha.mes==8 || fecha.mes==10 || fecha.mes==12)
            {
                for(;fecha.dia>1 && cantidadR>0;fecha.dia--,cantidadR--);
                if(cantidadR>=1)
                {
                    fecha.mes--;
                    cantidadR--;
                    fecha.dia=30;
                    if(fecha.mes==2)
                        fecha.dia=28;
                    if(fecha.mes==0)
                    {
                        fecha.mes=12;
                        fecha.annio--;
                        cantidadR--;
                        fecha.dia=31;
                    }
                        
                }
            }
            if (fecha.mes==4 || fecha.mes==6 || fecha.mes==9 || fecha.mes==11)
            {
                for(;fecha.dia>1 && cantidadR>0;fecha.dia--,cantidadR--);
                if(cantidadR>=1)
                {
                    fecha.mes--;
                    cantidadR--;
                    fecha.dia=31;
                }
            }
        }
    }
    if(tipo==MES)
    {
        fecha.mes-=(cantidadR%12);
        if (fecha.mes<1)
        {
            fecha.mes=12;
            fecha.annio--;
        }
        fecha.annio-=(cantidadR/12);
    }
    if(tipo==ANNIO)
        fecha.annio-=cantidadR;
    if(tipo==FECHA)
    {
        dd=fecha.dia;
        mm=fecha.mes;
        aa=fecha.annio;
        capturaFecha(&fecha);
        tipo=DIA;
        restaFecha(fecha,tipo,dd);
        tipo=MES;
        restaFecha(fecha,tipo,mm);
        tipo=ANNIO;
        restaFecha(fecha,tipo,aa);
    }
    
    return fecha;
}

Fecha sumaFecha(Fecha fecha, int tipo, int cantidadS)
{
    int dd,mm,aa;
    
    if(tipo==DIA)
    {
        while(cantidadS>0)
        {
            if (fecha.mes==2)
            {
                
                for(;fecha.dia<28 && cantidadS>0;fecha.dia++,cantidadS--);
                if(cantidadS>=1)
                {
                    fecha.mes++;
                    cantidadS--;
                    fecha.dia=1;
                }
            }
            if (fecha.mes==1 || fecha.mes==3 || fecha.mes==5 || fecha.mes==7 || fecha.mes==8 || fecha.mes==10 || fecha.mes==12)
            {
                for(;fecha.dia<31 && cantidadS>0;fecha.dia++,cantidadS--);
                if(cantidadS>=1)
                {
                    fecha.mes++;
                    if(fecha.mes==13)
                    {
                        fecha.mes=1;
                        fecha.annio++;
                    }
                    cantidadS--;
                    fecha.dia=1;
                }
            }
            if (fecha.mes==4 || fecha.mes==6 || fecha.mes==9 || fecha.mes==11)
            {
                for(;fecha.dia<30 && cantidadS>0;fecha.dia++,cantidadS--);
                if(cantidadS>=1)
                {
                    fecha.mes++;
                    cantidadS--;
                    fecha.dia=1;
                }
            }
        }
    }
    if(tipo==MES)
    {
        fecha.mes+=(cantidadS%12);
        if (fecha.mes>12)
        {
            fecha.mes=1;
            fecha.annio++;
        }
        fecha.annio+=(cantidadS/12);
    }
    if(tipo==ANNIO)
        fecha.annio+=cantidadS;
    if(tipo==FECHA)
    {
        int dd,mm,aa;
        dd=fecha.dia;
        mm=fecha.mes;
        aa=fecha.annio;
        capturaFecha(&fecha);
        tipo=DIA;
        fecha=sumaFecha(fecha,tipo,dd);
        tipo=MES;
        fecha=sumaFecha(fecha,tipo,mm);
        tipo=ANNIO;
        fecha=sumaFecha(fecha,tipo,aa);
    }
    
    return fecha;
}

int SeleccionaDMAF(int op, int *cant)
{
    int tipo;
    char opcion;
    
    do
    {
        printf("a) Día(s)\n");
        printf("b) Mes(es)\n");
        printf("c) Año(s)\n");
        printf("d) Fecha\n");
        printf("Ingresa una opción (a-d): ");
        fflush(stdin);
        scanf("%c",&opcion);
        if(opcion!='a' && opcion!='b' && opcion!='c' && opcion!='d')
            printf("Opción inválida\n");
    }while(opcion!='a' && opcion!='b' && opcion!='c' && opcion!='d');
    
    switch(opcion)
    {
        case 'a':
            tipo=DIA;
            do
            {
                printf("Ingresa la cantidad de días que desea ");
                if(op==1)
                    printf("sumar: ");
                if(op==0)
                    printf("restar: ");
                scanf("%d",&*cant);
                if(*cant<0)
                    printf("No se aceptan números negativos");
            }while(*cant<0);
            break;
        case 'b':
            tipo=MES;
            do
            {
                printf("Ingresa la cantidad de meses que desea ");
                if(op==1)
                    printf("sumar: ");
                if(op==0)
                    printf("restar: ");
                scanf("%d",&*cant);
                if(*cant<0)
                    printf("No se aceptan números negativos");
            }while(*cant<0);
            break;
        case 'c':
            tipo=ANNIO;
            do
            {
                printf("Ingresa la cantidad de años que desea ");
                if(op==1)
                    printf("sumar: ");
                if(op==0)
                    printf("restar: ");
                scanf("%d",&*cant);
                if(*cant<0)
                    printf("No se aceptan números negativos");
            }while(*cant<0);
            break;
        case 'd':
            tipo=FECHA;
            printf("Ingresa la fecha que desea ");
            if(op==1)
                printf("sumar\n");
            if(op==0)
                printf("restar\n");
            break;
    }

    return tipo;
}

int menu()
{
    int op;
    
        printf("\nMenú\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Comparar\n");
        printf("4. Finalizar\n");
        printf("Ingresa una opción (1-4): ");
        scanf("%d",&op);
    
    return op;
}
