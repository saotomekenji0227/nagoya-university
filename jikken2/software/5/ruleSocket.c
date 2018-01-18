#include "gomokurule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in addr;
  int    fd;
  int    buflen;
  int   buf[1024];
  int board1[BOARDSIZE*BOARDSIZE];
  int board2[BOARDSIZE][BOARDSIZE];
  int te,teban,result;
  int i;

  if ( argc != 2 ) {
    fprintf( stderr, "Usage: %s <IP Address>\n", argv[0] );
    exit(1);
  }

  /* ソケット作成 */
  if ( ( fd = socket( PF_INET, SOCK_STREAM, 0 ) ) < 0 ) {
    perror("*** gomoku-rule: socket ***");
    exit(1);
  }

  bzero( (char *)&addr, sizeof(addr) );
  addr.sin_family = PF_INET;
  addr.sin_addr.s_addr = inet_addr(argv[1]);
  addr.sin_port = htons(RULEPORT);

  /* ソケット接続要求 */
  if ( connect( fd, (struct sockaddr *)&addr, sizeof(addr) ) < 0 ) {
    perror("*** gomoku-rule: connect ***");
    close(fd);
    exit(1);
  }

  /* データの送受信 */
  while (1) {
    if( read( fd, buf, sizeof(buf) - 1 ) < 0 )
      break;
    for(i = 0; i < BOARDSIZE * BOARDSIZE; i++)
      board1[i] = buf[i];
    boardTypeCast1to2(board1,board2);
    te = buf[BOARDSIZE * BOARDSIZE];
    teban = buf[BOARDSIZE * BOARDSIZE+1];
    result = gomokuRule(board2,te,teban);
    if ( write( fd, result , sizeof(int) ) < 0 ) {
      break;
    }
  }
  
  /* ソケット切断 */
  exit( close(fd) );
}
