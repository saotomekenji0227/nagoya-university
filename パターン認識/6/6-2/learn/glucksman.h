#ifndef _GLUCKSMAN

/*16������Glucksman�̓��������߂�ꍇ��2*/
/*81������Glucksman�̓��������߂�ꍇ��3*/
#define DIM 2


#define ELM_SIZE (DIM*DIM*DIM*DIM)

typedef struct {
  double **data;
  int width;
  int height;
} MojiData;

void getGlucksmanVector(MojiData *mojiData, int data[]);

#endif /*_GLUCKSMAN*/
