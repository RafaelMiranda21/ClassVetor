#include <iostream>
#include "vetores.h"

using namespace std;


vetor::vetor(int x)
{
    vet = new int[x];
    tam = x;
    n=0;
}

bool vetor::lervetor(int q)
{
    if(q > tam)
        return false;

    for(int i=0;i<q;i++)
    {
        cin>>vet[i];
    }
    n=q;
    return true;
}

int vetor::imprimir()
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<vet[i]<<"\t";
    }
}

bool vetor::vazio()
{
    if(n == 0)
 	{
 	  return true;
	}
      return false;

}

void vetor::uniao(vetor x,vetor y)
{
    int i,j,k;

    for(k=0;k<x.n;k++)
    {
      vet[k] = x.vet[k];
    }

   for(i=0;i<y.n;i++)
   {
	 for(j=0;j<x.n && y.vet[i] != x.vet[j]; j++);
     {}
     if(j == x.n)
		{
		  vet[k] = y.vet[i];
		  k++;
		}

   }
      n = k;

}

void vetor::iguais(vetor x, vetor y)
{
    int i,j,nd = 0;

	for(i=0;i<x.n;i++)
	{
		for(j=0;j<y.n;j++)
		{
			if(x.vet[i] == y.vet[j])
			{
				vet[nd++] = x.vet[i];
			}
		}
	}
	 n = nd;
}

void vetor::subtracao(vetor x, vetor y)
{
    int i,j,ne = 0;

	for(i=0;i<x.n;i++)
	{
		for(j=0;j<y.n && x.vet[i] != y.vet[j]; j++);
		 {
		 }
		 if(j == y.n)
		 {
		   vet[ne++] = x.vet[i];
		 }
	}
    n = ne;
}


bool vetor::subconjunto(vetor x)
{
    int i,j,cont=0;

	for(i=0;i<n;i++)
    {
        for(j=0;j<x.n;j++)
        {
          if(vet[i] == x.vet[j])
          {
              cont++;
          }
        }
    }

	if(cont == n)
	{
		return true;
	}
	    return false;
}

bool vetor::identico(vetor x, vetor y)
{
   int i,j,cont;
   if(x.n == y.n)
   {
	for(i=0;i<x.n;i++)
	{
		for(j=0;j<y.n;j++)
		{
			if(x.vet[i] == y.vet[j])
			{
				cont++;
			}
	    }
	}
      n = cont;
	  if(cont == n)
	  {
		return true;
	  }
   }
	    return false;

}

bool vetor::disjunto(vetor x, vetor y)
{
     int i,j;

	for(i=0;i<x.n;i++)
	{
		for(j=0;j<y.n;j++)
		{
			if(x.vet[i] == y.vet[j])
			{
				return false;
			}
	    }
	}
	return true;

}



int vetor::apl(vetor x)
{
    int i,maior=0, menor = x.vet[0];

	for(i=0;i<x.n;i++)
	{
		if(x.vet[i] > maior)
		{
			maior = x.vet[i];
		}
	}

	for(i=1;i<x.n;i++)
	{
		if(x.vet[i] < menor)
		{
			menor = x.vet[i];
		}
	}

	return maior - menor;
}


int vetor::produtoescalar(vetor x, vetor y)
{
    int i,soma;
	if(x.n == y.n)
	{
		for(soma=0,i=0;i<x.n;i++)
		{
			 soma += x.vet[i] * y.vet[i];
		}
		return soma;
	}
	return 0;
}

void vetor::cres(vetor x)
{
    int i,cont = 1,k=0;

	   vet[k] = x.vet[k];
	for(i=1;i<x.n;i++)
	{
		if(x.vet[i] > x.vet[k])
		{
		  vet[i] = x.vet[i];
		  cont++;
		  k++;
		}
		else
		{
			i = x.n;
		}
	}

	n = cont;
}


void vetor::desc(vetor x)
{
    int i,cont = 1,k=0;

	   vet[k] = x.vet[k];
	for(i=1;i<x.n;i++)
	{
		if(x.vet[i] < x.vet[k])
		{
		  vet[i] = x.vet[i];
		  cont++;
		  k++;
		}
		else
		{
			i = x.n;
		}
	}
	  n = cont;
}


void vetor::intercalar(vetor x, vetor y)
{
    int i,j,ni;
	n=y.n+x.n;
	if(x.n == y.n)
	{

	  for(i=0,j=0;i<2*x.n;i++,j++)
	  {
	  	vet[i]  = x.vet[j];
	  	i++;
	  	vet[i] = y.vet[j];
	  }

	}

	if(x.n<y.n)
	{
		for(i=0,j=0;i<2*x.n;i++,j++)
	  {
	  	vet[i]  = x.vet[j];
	  	i++;
	  	vet[i] = y.vet[j];
	  }
	  for(i=i,j=n;i<ni;i++,j++)
	  {
	  	vet[i] = y.vet[j];
	  }

   }
   if(x.n>y.n)
	{
		for(i=0,j=0;i<2*y.n;i++,j++)
	  {
	  	vet[i]  = x.vet[j];
	  	i++;
	  	vet[i] = y.vet[j];
	  }
	  for(i=i,j=y.n;i<n;i++,j++)
	  {
	  	vet[i] = x.vet[j];
	  }

   }
}
