#include<stdio.h>/*  I have */
#include<assert.h>/*  space */
#include<math.h>/* for some */
#define C 1<<16/*  comments */
#define F for(i=0;i<C;++i)/**/
#define M(x,y)(x>y)?x:y/*now*/
float a[C];int main(int c,char
**v){int i,x=0,y=0;float h,b;\
assert(c>1);char*p=v[1];FILE*f
=fopen(p,"rb");if(!f)return 1;
F a[i]=0;for(;(x=getc(f))!=EOF
&&(y=getc(f))!=EOF;)a[x+256*y]
+=1;F if((b=logf(a[i]))>0)h=M(
b,h);printf("P3\n256 256\n255\
\n");F printf("%d %d %d\n",x=\
M(logf(a[i])/h*255,0),x,x);}//
