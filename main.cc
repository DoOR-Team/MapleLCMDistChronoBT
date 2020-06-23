//
// Created by jpbirdy on 2020-06-22.
//


#include <stdio.h>
#include <zlib.h>

int main() {
  printf("aaabbb");
  gzFile in;
  unsigned char buf[1000];
  auto size = gzread(in, buf, sizeof(buf));
  return 0;
}
