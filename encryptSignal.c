// encryptSignal.c 

#include <stdio.h>

void encryptSignal(double* signal, int key) {

  // Convert signal to byte array
  unsigned char byteSignal[8];

  for(int i=0; i<8; i++) {
    
    int signal_int = (int)*signal;
    
    byteSignal[i] = signal_int >> (i*8) & 0xFF;

  }

  // Simple XOR encryption
  for(int i=0; i<8; i++) {

    byteSignal[i] ^= key;

  }

  // Convert back to double 
  *signal = 0;

  for(int i=7; i>=0; i--) {

    *signal += (double)((int)byteSignal[i] << (i*8));

  }

  printf("Encrypted signal: %lf\n", *signal);

}