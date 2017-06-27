#ifndef _GLUCKSMAN

/*16次元のGlucksmanの特徴を求める場合は2*/
/*81次元のGlucksmanの特徴を求める場合は3*/
#define DIM 3


#define ELM_SIZE (DIM*DIM*DIM*DIM)

typedef struct {
  double **data;
  int width;
  int height;
} MojiData;

void getGlucksmanVector(MojiData *mojiData, int data[]);

#endif /*_GLUCKSMAN*/
