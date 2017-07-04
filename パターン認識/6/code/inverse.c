
//mat:行列
//inv:matの逆行列
//n  :次元
void inverse(double** mat, double** inv, int n){
  int i, j, k;

  for( i = 0; i < n; i++ ){
    for( j = i+1; j < n; j++ ){
      mat[j][i] /= mat[i][i];
      for( k = i + 1; k < n; k++ ){
	mat[j][k] -= mat[i][k] * mat[j][i];
      }
    }
  }

  /* 逆行列を求める */
  for( k = 0; k < n; k++ ){
    /* 初期化 */
    for( i = 0; i < n; i++ ){
      if( i == k ){ 
	inv[i][k] = 1; 
      }
      else{ 
	inv[i][k] = 0; 
      }	
    }
    /* 解を求める */
    for( i = 0; i < n; i++ ){
      for( j = i + 1; j < n; j++ ){
	inv[j][k] -= inv[i][k] * mat[j][i];
      }
    }
    for( i = n-1; i >= 0; i-- ){
      for( j = i+1; j < n; j++ ){
	inv[i][k] -= mat[i][j] * inv[j][k];
      }
      inv[i][k] /= mat[i][i];
    }
  }
}

