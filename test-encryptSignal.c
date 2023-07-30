// test_encryptSignal.c

#include <assert.h>

// Remove encryptSignal.c include to avoid duplicate definition
// #include "encryptSignal.c"  

// Keep prototype
void encryptSignal(double*, int);

int main() {

  double signal = 1.5;
  int key = 15;

  encryptSignal(&signal, key);

  return 0;

}