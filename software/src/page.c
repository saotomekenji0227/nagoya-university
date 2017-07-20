#include <stdio.h>
#include "txtfmt.h"
#include "page.h"

void page(){
  static int pagenum = 1;
  pagenum++;
  printf("f\n%%%%Page: %d %d\nb\n", pagenum, pagenum);
  header(pagenum);
}
