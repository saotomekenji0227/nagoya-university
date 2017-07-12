#ifndef _GLUCKSMAN

/*16ŸŒ³‚ÌGlucksman‚Ì“Á’¥‚ğ‹‚ß‚éê‡‚Í2*/
/*81ŸŒ³‚ÌGlucksman‚Ì“Á’¥‚ğ‹‚ß‚éê‡‚Í3*/
#define DIM 2


#define ELM_SIZE (DIM*DIM*DIM*DIM)

typedef struct {
  double **data;
  int width;
  int height;
} MojiData;

void getGlucksmanVector(MojiData *mojiData, int data[]);

#endif /*_GLUCKSMAN*/
