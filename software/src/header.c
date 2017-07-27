#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>

#define FILEMAX 40

static char dating[15];
static char fileName[45];
static char *username;


void initheader(char *filename){
  int i = 0;
  int len;
  struct passwd *pwd;
  time_t timer;
  struct tm *t_st;
  char s[FILEMAX] = {'\0'};
  char f[FILEMAX+5];
  char *over = "...";

  /* ファイル名の長さを取得 */
  len = strlen(filename);
  
  /* 40文字目までを一時配列に格納 */
  for(i = 0; i < 40; i++){
    f[i] = *filename;
    filename++;
  }
  f[i] = '\0';

  /* ファイル名を静的変数に格納 */
  for(i = 0; i <= 40; i++){
    fileName[i] = f[i];
  }
  
  /* ファイル名が40文字を超えたら"..."を出力 */
  if(len > 40){
    strcat(fileName, over);
  }
  
  /* ユーザIDの取得 */
  pwd = getpwuid(getuid());
  /* ユーザID(full name)を静的変数に格納 */
  username = pwd->pw_gecos;
  /* 現在時刻の取得 */
  time(&timer);
  /* 現在時刻を構造体に変換 */
  t_st = localtime(&timer);
  /* 日付の書式変換 */
  strftime(s, FILEMAX, "%Y/%m/%d", t_st);
  /* 日付を静的変数に格納 */
  for(i = 0; i < 10; i++){
    dating[i] = s[i];
  }

  /* ヘッダを出力 */
  printf("%%%%Page: 1 1\nb\n");
  printf("(%s) C s n(Page 1, %s, %s) C s n n", fileName, dating, username);
 
}

void header(int pagenum){
  
  printf("(%s) C s n(Page %d, %s, %s) C s n n", fileName, pagenum, dating, username);

}

