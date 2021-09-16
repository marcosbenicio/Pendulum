#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define g      9.80   //gravidade (m/s²)
#define l      2.00   //tamanho da corda (m)
#define Vo     5.0 //velocidade incial (m/s)
#define time   10     //tempo total (s)
#define dt     0.0001  //intervalo de tempo (s)
#define gamma  10.0   //amortecido 1/s         
#define pi     180
#define w      sqrt(g/l)
#define OA     Vo/sqrt(g*l)

int main()
{
   
   int n;
      
   double N,t,Ot,Ot_1,Ot_2;
   
   double O,Oa,T;
   
   FILE *fpm;
   
   fpm=fopen("pendulo_amortecido_v5_b10.txt","w");
   if(!fpm) exit(0);
   
   //fprintf(fpm,"#tempo\t\t\t\t #teta\t\t\t\t\t#Periodo\t\t\t\t\t\t#Amplitude");
   fprintf(fpm,"#tempo\t\t\t\t #teta");
   Ot=0.0; 
   t=0.0;     
   
   //T=2.0*3.1415926*sqrt(l/g);
   
   Oa=Vo/sqrt(g*l);
   
   //fprintf(fpm,"\n%.6f\t\t\t\t%.6f\t\t\t\t%.6f\t\t\t\t\t\t%.6f",t,Ot,T,Oa);
   fprintf(fpm,"\n%.6f\t\t\t\t%.6f",t,Ot);     
   
   Ot_1=(Vo*dt)/l;
   fprintf(fpm,"\n%.6f\t\t\t\t%.6f",dt,Ot_1);
   N=time/dt; //número de iterações
   for(n=1;n<=N;n++){
  	  t=n*dt; //contator de tempo
	  	  
	  //O=OA*sin(w*(n+1)*dt);//solução analítica pequenas oscilações do pendulo simples
	  
	  
	  //O=OA*exp(-(gamma/2.0)*t)sin(w*(n+1)*dt)
	  Ot_2=((2.0+gamma*dt)*Ot_1-(g/l)*(dt*dt)*sin(Ot_1)-Ot)/(1.0+dt*gamma);
	   
	  fprintf(fpm,"\n%.6lf\t\t\t\t%.6lf",(n+1)*dt,Ot_2); 
	  Ot=Ot_1;
	  Ot_1=Ot_2;      

   }
   fclose(fpm);
   
}   





