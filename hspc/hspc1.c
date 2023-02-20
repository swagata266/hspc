#include<stdio.h>
#include<math.h>

int input_n()
{
  int n;
  scanf("%d",&n);
  return n;
}

int input_values(float *x1,float *y1,float *x2,float *y2,float *x3,float *y3)
{
  scanf("%f%f%f%f%f%f",x1,y1,x2,y2,x3,y3);
  return 0;
}

void compute_area(float x1,float y1,float x2,float y2,float x3,float y3,float *area)
{
  *area = 0.5 * ( (x1 * (y2 - y3)) + (x2 * (y3 -y1)) + (x3 * (y1 -y2)) ) ;
  *area = fabsf(*area * 2);
}

void output(float x1,float y1,float x2,float y2,float x3,float y3,float area)
{
  printf("The area of rectangle with the co-ordinates (%.2f,%.2f),(%.2f,%.2f) and (%.2f,%.2f) is %.2f \n",x1,y1,x2,y2,x3,y3,area);
}
int main()
{
  float x1,x2,x3,y1,y2,y3,area;
  int n=input_n();
  for(int i=0;i<n;i++)
    {
      input_values(&x1,&y1,&x2,&y2,&x3,&y3);
      compute_area(x1,y1,x2,y2,x3,y3,&area);
      output(x1,y1,x2,y2,x3,y3,area);
    }
}