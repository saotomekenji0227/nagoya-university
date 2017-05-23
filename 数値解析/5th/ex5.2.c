#include<stdio.h>
#include<math.h>

void equation(double a[],double b[],double c[],double x[],double y[],int n);
void twicespline(double first[],double second[],int size);

void main(int argc,char *argv[]){
  int ow,oh; //original width,original height
  int i,j;
  int tmp;
  char *c;
  float h=1.0; //等感覚なので幅は1と仮定
  FILE *fp1=fopen("ae.pgm","r");
  FILE *fp2=fopen("ae2.pgm","w");
  fscanf(fp1,"%s",&c); //P2を破棄
  fscanf(fp1,"%d",&ow);
  fscanf(fp1,"%d",&oh);
  fscanf(fp1,"%d",&tmp);
  double ae[oh][ow];
  double ae2[oh*2-1][ow*2-1];
  for(i=0;i<oh;i++){
    for(j=0;j<ow;j++){
      fscanf(fp1,"%d",&tmp);
      ae[i][j]=tmp;
    }
  }
  double *first,*second;
  first=(double*)malloc(sizeof(double)*ow);
  second=(double*)malloc(sizeof(double)*(ow*2-1));
  for(i=0;i<oh;i++){
    for(j=0;j<ow;j++)
      first[j]=ae[i][j];
    twicespline(first,second,ow);
    for(j=0;j<ow*2-1;j++)
      ae2[i*2][j]=second[j];
  }
  free(first);
  free(second);
  first=(double*)malloc(sizeof(double)*oh);
  second=(double*)malloc(sizeof(double)*(oh*2-1));
  for(i=0;i<ow*2-1;i++){
    for(j=0;j<oh;j++)
      first[j]=ae2[j*2][i];
    twicespline(first,second,oh);
    for(j=0;j<oh*2-1;j++)
      ae2[j][i]=second[j];
  }
  free(first);
  free(second);
  fprintf(fp2,"P2\n");
  fprintf(fp2,"%d %d\n255\n",ow*2-1,oh*2-1);
  for(i=0;i<oh*2-1;i++){
    for(j=0;j<ow*2-1;j++){
      tmp=ae2[i][j];
      if(tmp<0)
	fprintf(fp2,"%d ",0);
      else if(tmp>255)
	fprintf(fp2,"%d ",255);
      else
	fprintf(fp2,"%d ",tmp);
    }
    fprintf(fp2,"\n");
  }
  return;
}
void twicespline(double first[],double second[],int size){
  int i;
  double h=1.0;
  double a[size],b[size],c[size],d[size];
  double u[size],v[size];
  for(i=1;i<size-1;i++){
    v[i]=6.*((first[i+1]-2*first[i]+first[i-1])/h);
    a[i]=4.*h;
    b[i]=h;
    c[i]=h;
  }
  u[0]=0;
  u[size]=0;
  equation(a,b,c,u,v,size-1);
  for(i=0;i<size-1;i++){
    a[i]=(u[i+1]-u[i])/(6*h);
    b[i]=u[i]/2;
    c[i]=(first[i+1]-first[i])/h-1./6.*h*(2*u[i]+u[i+1]);
    d[i]=first[i];
  }
  double l=h/2;
  for(i=0;i<size*2-1;i++){
    if(i%2==0){
      second[i]=first[i/2];
    }else{
      second[i]=a[i/2]*l*l*l+b[i/2]*l*l+c[i/2]*l+d[i/2];
    }
  }
}
void equation(double a[],double b[],double c[],double x[],double y[],int n){
  int i;
  double d[n+1],l[n+1],z[n+1];
  d[1]=a[1];
  for(i=2;i<=n;i++){
    l[i]=b[i]/d[i-1];
    d[i]=a[i]-l[i]*c[i-1];
  }
  z[1]=y[1];
  for(i=2;i<=n;i++){
    z[i]=y[i]-l[i]*z[i-1];
  }
  x[n]=z[n]/d[n];
  for(i=n-1;i>=1;i--){
    x[i]=(z[i]-c[i]*x[i+1])/d[i];
  }
}
