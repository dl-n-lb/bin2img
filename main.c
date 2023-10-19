#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

float image[256 * 256];

int main(int argc, char **argv) {
  assert(argc >= 2);
  const char *fp = argv[1];
  FILE *f = fopen(fp, "rb");
  if (f == NULL) {
    printf("Oops file not open\n");
    return 1;
  }

  for (size_t i = 0; i < 256 * 256; ++i) {
    image[i] = 0;
  }

  for (int x = 0, y = 0; (x = getc(f)) != EOF && (y = getc(f)) != EOF;) {
    image[x + 256 * y] += 1;
  }

  fclose(f);

  float highest = 0;
  for (size_t i = 0; i < 256 * 256; ++i) {
    if (image[i] == 0) continue;
    float ln = logf(image[i]);
    if (ln > highest) { highest = ln; }
  }

  printf("P3\n256 256\n255\n");
  for (size_t i = 0; i < 256 * 256; ++i) {
    // just verbatim - highs are too emphasised
    // int c = image[i];
    // cbrt ruins png version, sqrt is a bit better but not clear on x86_64
    // logging in the max algorithm + here works best (so far)
    // idea stolen from tsoding https://github.com/tsoding/binviz
    float inter = logf(image[i]) / highest;
    unsigned int c = inter * 255.f;
    printf("%d %d %d\n", c, c, c);
  }
  
  return 0;
}
