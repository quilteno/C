#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{ int i,j,k;
  double a,b,E,P;
  double T;
  double R;
  int L=30;
  int N=20000;
  double arr[30][30];
  FILE *fp;
  fp=fopen("ising_mode.txt","w");
 
  for(i=0;i<30;i++)
  {
	  for(j=0;j<30;j++)
	  {
		  arr[i][j] = rand()%2==0?-1:1;
	  }
  }
  double m;
  for(T=0.1;T<5;T += 0.05)
  {
     m=0;
      for(k=1;k<=N;k++)
	  {
          for(i=0;i<L;i++)
		  {
              for(j=0;j<L;j++)
			  {
	              a=arr[i][j]*(arr[i][j+1]+arr[i-1][j]+arr[i][j-1]+arr[i+1][j]);
                  b=-arr[i][j]*(arr[i][j+1]+arr[i-1][j]+arr[i][j-1]+arr[i+1][j]);
                  E=a-b;
		         if(E<=0)
		               arr[i][j]=-arr[i][j];
		        else
				{
		           P=exp(-E/T);  
			       R=rand()/(RAND_MAX+1.0);
			       if(P>=R)
			           arr[i][j]=-arr[i][j];
				}
			  }
		  }

         if(k > (N/2))
		 {
             double sum=0;
              for(i=0;i<30;i++)
			  {
                   for(j=0;j<30;j++)
				   {
                      sum = (double)(sum + arr[i][j]);
				   }
			  }
             sum = (double)sum/(L*L);
             m += fabs(sum);
		 }
		 
	  }
         
         if(T>=0.1)
		 {
             printf("%1f %1f\n",T,m/(N/2));
             fprintf(fp,"%1f %1f\n",T,m/(N/2));
		 }
  }
return 0;
getchar();
}