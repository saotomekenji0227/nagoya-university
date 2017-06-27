#include <stdio.h>
#include <math.h>
#define EPS 1E-6
int jacobi(double A[4][4],double B[4],double x[4],double xtmp[4]);
int gaussSeidel(double A[4][4],double B[4],double x[4],double xtmp[4]);
void main(){
  double A[4][4]={{1,1,1,1},{1,7,-2,1},{1,-1,5,-2},{1,-2,-1,6}};
  double B[4]={1,6,3,14};
  double x[4]={1,1,1,1};
  double xtmp[4];
  int count = 1;
  while(jacobi(A,B,x,xtmp)==1){
    printf("%d&%.7f&%.7f&%.7f\\\\\\hline\n",count,x[1]-1,x[2]-2,x[3]-3);
    count++;
  }
    printf("%d&%.7f&%.7f&%.7f\\\\\\hline\n",count,x[1]-1,x[2]-2,x[3]-3);
    printf("x1=%.7f\nx2=%.7f\nx3=%.7f\ncount=%d\n",x[1],x[2],x[3],count);
  x[1]=1; x[2]=1; x[3]=1; count=1;
  while(gaussSeidel(A,B,x,xtmp)==1){
    printf("%d&%.7f&%.7f&%.7f\\\\\\hline\n",count,x[1]-1,x[2]-2,x[3]-3);
   count++;
  }
 printf("%d&%.7f&%.7f&%.7f\\\\\\hline\n",count,x[1]-1,x[2]-2,x[3]-3);
}

int jacobi(double A[4][4],double B[4],double x[4],double xtmp[4]){
  int flag=0;
  int i;
  xtmp[1]=(-A[1][2]*x[2]-A[1][3]*x[3]+B[1])/A[1][1];
  xtmp[2]=(-A[2][1]*x[1]-A[2][3]*x[3]+B[2])/A[2][2];
  xtmp[3]=(-A[3][1]*x[1]-A[3][2]*x[2]+B[3])/A[3][3];
  for(i=1;i<4;i++){
    if(fabs(x[i]-xtmp[i])>EPS) flag=1;
    x[i]=xtmp[i];
  }
  return flag;
}

int gaussSeidel(double A[4][4],double B[4],double x[4],double xtmp[4]){
  int flag=0;
  int i;
  xtmp[1]=(-A[1][2]*x[2]-A[1][3]*x[3]+B[1])/A[1][1];
  xtmp[2]=(-A[2][1]*xtmp[1]-A[2][3]*x[3]+B[2])/A[2][2];
  xtmp[3]=(-A[3][1]*xtmp[1]-A[3][2]*xtmp[2]+B[3])/A[3][3];
  for(i=1;i<4;i++){
    if(fabs(x[i]-xtmp[i])>EPS) flag=1;
    x[i]=xtmp[i];
  }
  return flag;
}
