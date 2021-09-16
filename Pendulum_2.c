#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define g      9.8  // m/s²
#define L      2.0   //m
#define Vo     8.8  //m/s
#define Dt     0.05   //intervalo de tempo
#define T      100       //tempo total





#define pi    (double)acos(-1.0)
#define Dpi   (double)2*pi

int main()
{
   int n,N;
   double t,teta,tetaA,tetaAA,fator;

   FILE *fpm;
   
   fpm=fopen("pendulo_livro.txt","w");
   if(!fpm) exit(0);

   fprintf(fpm,"#tempo\t\t\t\t #teta\t\n");
   fator=g*Dt*Dt/L;
   N=T/Dt;
   t=0.0;
   tetaAA=0.0;
   fprintf(fpm,"\n%.6f\t\t\t\t%.6f",t,tetaAA);
   
   t=Dt;
   tetaA=Vo*Dt/L;   
   fprintf(fpm,"\n%.6f\t\t\t\t%.6f",t,tetaA);

   for(n=2;n<=N;n++){
      t=n*Dt;
       
      teta=2*tetaA-fator*sin(tetaA)-tetaAA;
      
      if(teta>pi){
		teta-=Dpi;
        tetaA-=Dpi;
        tetaAA-=Dpi;
      }
      fprintf(fpm,"\n%.6f\t\t\t\t%.6f",t,teta);
      tetaAA=tetaA;
      tetaA=teta;
   }
  
     
            
}   

