#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <locale.h>

void minimosquadrados(); 
void regratrapezios();
float funcao(float valor, float *multi);
void imprimeTabela(float *valoresX, float *valoresY, int pontos); 
void parabola(float *valoresX, float *valoresY, int pontos); 
void reta(float *valoresX, float *valoresY, int pontos); 
void imprimeParabola(float *tabelaX, float *tabelaY); 
void imprimeReta(float *tabelaX, float *tabelaY);

int grau;

int main()
{ 
    int op;
    setlocale(LC_ALL, "Portuguese");

  do{ 

    printf("\t\tBem vindo a nossa calculadora, selecione a sua op o:\n\
n"); 
    printf("\t\t[1] - M nimos Quadrados\n\t\t[2] - Regra dos Trap zios\n\t\	
t[3] - Sair\n\t\t--> ");
    scanf("%i", &op);

   switch (op) 
   { 
    case 1:
          system("cls"); 
          minimosquadrados();
    
    break;
    
    case 2:
          system("cls"); 
          regratrapezios();
    break;

      }
    } while(op != 3);
}

void regratrapezios(){ 
    int i;
    float *multi = NULL;
 printf("\n\n\n\t\t\t\tGrau da fun o: ");     
 scanf("%i", &grau);     
 fflush(stdin);
 multi = (float*)realloc(multi, grau*sizeof(float));
   
    for(i=grau; i>=0; i--)
    {
        printf("\n\t\t\t\tMultiplicador de x^%i: ", i);         
        scanf("%f", (multi+i));         
        fflush(stdin);
    }
    printf("\n\n\t\t\t\tA funcao recebida foi: ");     
    for(i=grau; i>=0; i--)
    {
        printf("%.2fx^%i", *(multi+i), i);
        if(i>0)
          printf(" + ");
        else
          printf(" = 0");    
     }

printf("\n\n\n\t\t\t\tInsira o valor inicial [A]: "); 
float a, b, n, h, integral;
scanf("%f", &a); 
fflush(stdin);
printf("\t\t\t\tInsira o valor final da fun o [B]: "); 
scanf("%f", &b); 
fflush(stdin);
printf("\t\t\t\tInsira o numero de subdivis es [N]: "); 
scanf("%f", &n); 
fflush(stdin);
h = (b-a)/n;
printf("\n\t\t\t\tValor de H: %.2f\n", h);
integral = 0;
integral += funcao(a, multi); 

for(i=1; i<=(n-1); i++){ 
    
    
    integral = integral + 2*funcao(a+(i*h), multi);
}
integral = integral + funcao(b, multi);
integral = integral * h/2;
printf("\t\t\t\tIntegral = %.2f\n\n", integral);
printf("\t\t\t\t");
system("pause");     
system("cls");
 }

void minimosquadrados(){ 
    int pontos, i;
    float *valoresX = NULL, *valoresY = NULL; 
    char op;

    printf("\n\n\n\t\t\t\tDigite a quantidade de pontos da funcao: "); 
    scanf("%d", &pontos); 
    fflush(stdin);
    valoresX = (float*)realloc(valoresX, pontos*sizeof(float)); 
    valoresY = (float*)realloc(valoresY, pontos*sizeof(float)); 
    if(valoresX == NULL || valoresY == NULL) 
    exit(1); 
    
    printf("\n");
  for(i=0; i<pontos; i++){ 
    printf("\t\t\t\tDetermine o valor de X(%i): ", i);
    scanf("%f", (valoresX+i)); 
    fflush(stdin);
    } 
printf("\n"); 

for(i=0; i<pontos; i++){ 
    printf("\t\t\t\tDetermine o valor de Y(%i): ", i); 
    scanf("%f", (valoresY+i));
    fflush(stdin);
    } 

printf("\n");
imprimeTabela(valoresX, valoresY, pontos);
printf("\n");
printf("\t\t\t\tDeseja calcular uma par bola ou reta?\n\t\t\t\t[p/r] -> "); 
scanf("%c", &op); 
fflush(stdin); 
if(op == 'p'){ 
    system("cls");
    parabola(valoresX, valoresY, pontos);
}
else if(op == 'r'){ 
    system("cls");
    reta(valoresX, valoresY, pontos);

} 
else{ 
    system("cls");
    printf("Opcao nao encontrada, reiniciando o programa...\n"); 
    system("PAUSE"); 
    system("cls");
}
free(valoresX); 
free(valoresY);
}
float funcao(float valor, float* multi){
    int i;     
    float resultado;     
    resultado = 0;
    for(i=0; i<=grau; i++){
        resultado = resultado + (*(multi+i) * pow(valor, i));     
        }
    
    return resultado; 
    }
void imprimeTabela(float *valoresX, float *valoresY, int pontos){ 
    int i;
    printf("\t\t\t\t\t X\t\t Y\n"); 
    for(i=0; i<pontos; i++){ 
        printf("\t\t\t\t\t%.2f\t\t%.2f\n", *(valoresX+i), *(valoresY+i));
    } 
}
void parabola(float *valoresX, float *valoresY, int pontos){
     int i;
     float *tabelaX = NULL, *tabelaY = NULL, pivo, m21, m31, m32, a1, a2, a0; 
     tabelaX = (float*)realloc(tabelaX, 9*sizeof(float)); 
     tabelaY = (float*)realloc(tabelaY, 3*sizeof(float));
  
   for(i=0; i<pontos; i++){
   *(tabelaX+i) = 0;
  }

   for(i=0; i<3; i++){
*(tabelaY+i) = 0;
  }

  for(i=0; i<pontos; i++){
    *(tabelaX+0) = pontos;
    *(tabelaX+1) += *(valoresX+i);
    *(tabelaX+2) += pow(*(valoresX+i), 2); 
    *(tabelaX+5) += pow(*(valoresX+i), 3);
    *(tabelaX+8) += pow(*(valoresX+i), 4);
}
*(tabelaX+4) = *(tabelaX+2);
*(tabelaX+6) = *(tabelaX+2);
*(tabelaX+3) = *(tabelaX+1); 
*(tabelaX+7) = *(tabelaX+5);

  for(i=0; i<pontos; i++){ 
     *(tabelaY+0) += *(valoresY+i);
     *(tabelaY+1) += *(valoresY+i) * *(valoresX+i);
     *(tabelaY+2) += *(valoresY+i) * pow(*(valoresX+i), 2);
}
imprimeParabola(tabelaX, tabelaY);
pivo = *(tabelaX+0); 
m21 = *(tabelaX+3) / pivo; 
m31 = *(tabelaX+6) / pivo; 
printf("\n\t\tPivo: %.2f\n", pivo); 
printf("\t\tM21: %.2f\n", m21); 
printf("\t\tM31: %.2f\n\n", m31);
for(i=3; i<9; i++){ 
    if(i<6)
       *(tabelaX+i) = *(tabelaX+i) - (m21**(tabelaX+(i-3))); 
       else
       *(tabelaX+i) = *(tabelaX+i) - (m31**(tabelaX+(i-6)));
}
*(tabelaY+1) = *(tabelaY+1) - (m21 **(tabelaY+0)); 
*(tabelaY+2) = *(tabelaY+2) - (m31 **(tabelaY+0));
printf("\n\n");
imprimeParabola(tabelaX, tabelaY);
pivo = *(tabelaX+4); 
m32 = *(tabelaX+7)/pivo; 
printf("\n\n\t\tPivo: %.2f\n", pivo); 
printf("\t\tM32: %.2f\n\n\n", m32);
for(i=6; i<9; i++){
      *(tabelaX+i) = *(tabelaX+i) - (m32**(tabelaX+(i-3)));
}
*(tabelaY+2) = *(tabelaY+2) - (m32**(tabelaY+1));
imprimeParabola(tabelaX, tabelaY); 
printf("\n\n");
a2 = *(tabelaY+2) / *(tabelaX+8);
a1 = (*(tabelaY+1) - *(tabelaX+5)*a2) / *(tabelaX+4);
a0 = (*(tabelaY+0) - *(tabelaX+1)*a1 - *(tabelaX+2)*a2) / *(tabelaX+0); 
printf("\tA0: %.2f\n", a0); 
printf("\tA1: %.2f\n", a1); 
printf("\tA2: %.2f\n", a2);

free(tabelaX); 
free(tabelaY); 
printf("\n\n"); 
system("PAUSE"); 
system("cls");

}

void imprimeParabola(float *tabelaX, float *tabelaY){ 
    int i; 
    for(i=0; i<9; i++){ 
          if(i==3)
          { 
              printf("\tA0\t%.2f\n", *(tabelaY+0)); 
              printf("\n");
          } 
          if(i==6)
          { 
            printf("\tA1\t%.2f\n", *(tabelaY+1));
            printf("\n");
          }
          printf("%.2f\t", *(tabelaX+i)); 
          if(i==8){ 
            printf("\tA2\t%.2f\n", *(tabelaY+2)); 
            printf("\n");
          }
    }
}
void reta(float *valoresX, float *valoresY, int pontos){
     int i;
     float *tabelaX = NULL, *tabelaY = NULL, pivo, m21, a1, a0; 
     tabelaX = (float*)realloc(tabelaX, 4*sizeof(float)); 
     tabelaY = (float*)realloc(tabelaY, 2*sizeof(float));
     for(i=0; i<4; i++){
           *(tabelaX+i) = 0;
     }
  for(i=0; i<2; i++)
        *(tabelaY+i) = 0;

  for(i=0; i<pontos; i++){
        *(tabelaX+0) = pontos;
        *(tabelaX+1) += *(valoresX+i);
        *(tabelaX+3) += pow(*(valoresX+i),2);
}
*(tabelaX+2) = *(tabelaX+1); 
for(i=0; i<pontos; i++){
      *(tabelaY+0) += *(valoresY+i);
      *(tabelaY+1) += *(valoresY+i) * *(valoresX+i);
} 
printf("\n\n"); 
imprimeReta(tabelaX, tabelaY); 
pivo = *(tabelaX+0); 
m21 = *(tabelaX+2)/pivo; 
printf("\n\n\t\tPivo: %.2f\n", pivo); 
printf("\t\tM21: %.2f\n", m21); 
for(i=2; i<4; i++){
      *(tabelaX+i) = *(tabelaX+i) - (*(tabelaX+(i-2))*m21);
}
*(tabelaY+1) = *(tabelaY+1) - (*(tabelaY+0)*m21);
printf("\n\n");
imprimeReta(tabelaX, tabelaY); 
printf("\n\n"); a1 = *(tabelaY+1) / *(tabelaX+3);
a0 = (*(tabelaY+0) - *(tabelaX+1)*a1) / *(tabelaX+0);
printf("\tA0: %.2f\n", a0); 
printf("\tA1: %.2f\n", a1); 
free(tabelaX); 
free(tabelaY); 
printf("\n\n"); 
system("PAUSE"); 
system("cls");

}

void imprimeReta(float *tabelaX, float *tabelaY){ 
    int i;

    for(i=0; i<4; i++){ 
        if(i==2)
        { 
             printf("\tA0\t%.2f\n", *(tabelaY+0));
             printf("\n");
         }
        printf("%.2f\t", *(tabelaX+i)); 
        if(i==3)
        { 
          printf("\tA1\t%.2f\n", *(tabelaY+1));
          printf("\n");
        }
    }
}
