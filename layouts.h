/* Key binding functions */
#include "vanitygaps.c"

#if 0
extern void defaultgaps(const Arg *arg);
extern void incrgaps(const Arg *arg);
extern void incrigaps(const Arg *arg);
extern void incrogaps(const Arg *arg);
extern void incrohgaps(const Arg *arg);
extern void incrovgaps(const Arg *arg);
extern void incrihgaps(const Arg *arg);
extern void incrivgaps(const Arg *arg);
extern void togglegaps(const Arg *arg);
#endif
/* Layouts (delete the ones you do not need) */
extern void bstack(Monitor *m);
extern void bstackhoriz(Monitor *m);
extern void centeredmaster(Monitor *m);
extern void centeredfloatingmaster(Monitor *m);
extern void deck(Monitor *m);
extern void dwindle(Monitor *m);
extern void fibonacci(Monitor *m, int s);
extern void grid(Monitor *m);
extern void nrowgrid(Monitor *m);
extern void spiral(Monitor *m);
extern void tile(Monitor *m);
/* Internals */
extern void getgaps(Monitor *m, int *oh, int *ov, int *ih, int *iv, unsigned int *nc);
extern void getfacts(Monitor *m, int msize, int ssize, float *mf, float *sf, int *mr, int *sr);
extern void setgaps(int oh, int ov, int ih, int iv);
