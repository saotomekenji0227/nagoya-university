#include<stdio.h>
#include<math.h>

void equation(double a[],double b[],double c[],double x[],double y[],int n);

void main(int argc,char *argv[]){
  int ow,oh; //original width,original height
  int i,j;
  float h=1.0; //等感覚なので幅は1と仮定
  FILE *fp1=fopen(argv[1],"r");
  FILE *fp2=fopen("ae2.pgm","w");
  fscanf(fp1,"%d",&ow); //P2を破棄

  fscanf(fp1,"%d",&ow);
  fscanf(fp1,"%d",&oh);
  double ae[oh][ow];
  double ae2[oh*2-1][ow*2-1];
  for(i=0;i<oh;i++){
    for(j=0;j<ow;j++){
      fscanf(fp1,"%d",&ae[i][j]);
    }
  }

  double a1[oh][ow+1],b1[oh][ow+1],c1[oh][ow+1],d1[oh][ow];
  double u1[oh][ow+1],v1[oh][ow+1],y1[oh][ow];
  double a2[ow*2][oh+1],b2[ow*2][oh+1],c2[ow*2][oh+1],d2[ow*2][oh];
  double u2[ow*2][oh+1],v2[ow*2][oh+1],y2[ow*2][oh];
  
  //横向きに補完
  for(i=0;i<oh;i++){
    for(j=1;j<ow;j++){
      v1[i][j]=6.*((ae[i][j+1]-2*ae[i][j+1]+ae[i][j-1])/h);
      a1[i][j]=4.*h;
      b1[i][j]=h;
      c1[i][j]=h;
    }
    u1[i][0]=0;
    u1[i][ow]=0;
    equation(a1[i],b1[i],c1[i],u1[i],v1[i],ow-1);
    for(j=0;j<ow;j++){
      a1[i][j]=(u1[i][j+1]-u1[i][j])/(6.*h);
      b1[i][j]=u1[i][j]/2;
      c1[i][j]=(ae[i][j+1]-ae[i][j])/h-1./6.*h*(2.*u1[i][j]+u1[i][j+1]);
      d1[i][j]=ae[i][j];
    }
    for(j=0;j<ow*2-1;j++){
      if(j%2==0){
	ae2[i][j]=ae[i][j/2];
      }else{
	ae2[i][j]=a1[i][j/2]/(2*2*2)+b1[i][j/2]/(2*2)+c1[i][j/2]/2+d1[i][j/2];
      }
    }
  }
  /*
  //縦向き補完
  for(i=0;i<ow*2-1;i++){
    for(j=1;j<oh;j++){
      v2[i][j]=6.*((ae[j+1][i]-2*ae[j][i]+ae[j-1][i])/h);
      a2[i][j]=4.*h;
      b2[i][j]=h;
      c2[i][j]=h;
    }
    u2[i][0]=0;
    u2[i][oh]=0;
    equation(a2[i],b2[i],c2[i],u2[i],v2[i],oh-1);
    for(j=0;j<oh;j++){
      a2[i][j]=(u2[i][j+1]-u2[i][j])/(6.*h);
      b2[i][j]=u2[i][j]/2;
      c2[i][j]=(ae[j+1][i]-ae[j][i])/h-1./6.*h*(2.*u2[i][j]+u2[i][j+1]);
      d2[i][j]=ae[j][i];
    }
    for(j=0;j<oh*2-1;j++){
      if(j%2==1){
	ae2[j][i]=a1[i][j/2]/(2*2*2)+b1[i][j/2]/(2*2)+c1[i][j/2]/2+d1[i][j/2];
      }
    }
  }
*/
  /*
  fprintf(fp2,"P2\n");
  fprintf(fp2,"%d %d/n",ow*2-1,oh*2-1);
  for(i=0;i<oh*2-1;i++){
    for(j=0;j<ow*2-1;j++){
      fprintf(fp2,"%d ",(int)ae2[i][j]);
    }
    fprintf(fp2,"\n");
  }
    */
  return;
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
