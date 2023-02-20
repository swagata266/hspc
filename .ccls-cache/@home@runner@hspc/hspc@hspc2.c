#include<stdio.h>

typedef struct fract{
int num,den;
} fraction;

int input_n()
{
  int n;
  scanf("%d",&n);
  return n;
}

int input_num()
{
  int n;
  scanf("%d",&n);
  return n;
}

void init_fractions(int n,fraction a[n])
{
  for(int i=0;i<n;i++)
    {
      a[i].num=1;
      scanf("%d",&a[i].den);
    }
}

fraction calc_fract(fraction a,fraction b)
{
  fraction res;
  if(a.den == b.den)
  {
    res.num=a.num+b.num;
    res.den=a.den;
  }
  if(a.den != b.den)
  {
    res.num=(a.num*b.den) + (b.num*a.den);
    res.den= a.den * b.den;
  }
  return res;
}

fraction calc_n_fractions(int n,fraction a[n])
{
  fraction res={0,1};
  for(int i=0;i<n;i++)
    {
      res = calc_fract(res,a[i]);
    }
  return res;
}

int find_gcd(int a,int b)
{
  while( a != b)
  {  
    if(a > b)
      a = a-b;
    else
      b = b-a;
  }
  return a;
}

void _output(int n,fraction a[n],fraction res)
{
  int gcd=find_gcd(res.num,res.den);
  res.num=res.num/gcd;
  res.den=res.den/gcd;

  for(int i=0;i<n-1;i++)
    {
      printf("%d/%d + ",a[i].num,a[i].den);
    }
  printf("%d/%d = %d/%d\n",a[n-1].num,a[n-1].den,res.num,res.den);
}

int main()
{
  int x=input_n();
  for(int i=0;i<x;i++)
    {
    int n=input_num();
    fraction a[n];
    init_fractions(n,a);
    fraction res=calc_n_fractions(n,a);
    _output(n,a,res);
    }
  return 0;
}