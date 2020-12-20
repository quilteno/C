#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

const int L = 51;                          
const int MCS = 500;            
const int MS = 20;             
const double J = 0;
             
double Sum(int Spin[][L])
{
	double sum = 0;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			sum =sum+ Spin[i][j];           
		}       
	}

	return sum;
}

int main()
{
	FILE *fp;
    fp=fopen("ising.txt","w");
	srand((unsigned)time(NULL));  
    int Spin[51][51];  
	double m,E1,E2,p,r;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
            Spin[i][j]=1;      
	for (double T = 1.0; T <2.5; T += 0.01)
	{       
        for (int mcs =MCS ; mcs > 0; mcs--)
		{
			for(int i=0;i<L;i++)
			{
				for(int j=0;j<L;j++)
				{
			     E1=J*Spin[i][j]*(Spin[(i+1)%L][j]+Spin[(i-1+L)%L][j]+Spin[i][(j+1)%L]+Spin[i][(j-1+L)%L]);
				    E2=-J*Spin[i][j]*(Spin[(i+1)%L][j]+Spin[(i-1+L)%L][j]+Spin[i][(j+1)%L]+Spin[i][(j-1+L)%L]);
					if(E2<=E1)
					Spin[i][j]=-Spin[i][j];
	                else
		           {
			       	 p=1.0*rand()/ RAND_MAX;
				     r=exp(1.0*(E1-E2)/T);
					 if(r>p)
                 		Spin[i][j]=-Spin[i][j];
			       }
           
				}
			}
			if (mcs < MS)
			{     
				m=0;
				m = Sum(Spin) / L / L;        
			}
		}         
		fprintf(fp,"%2.2f\n",fabs(m));
		printf("T=%2.2f\t  mT=%2.2f\n",T,fabs(m));
	}
	return 0;
}