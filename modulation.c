#include <math.h>
#include <stdio.h>

// Constants in header file
#include "/home/kali/Desktop/C/modulation.h" 

// Function declarations
void modulateSignal(double, double, double*);
void demodulateSignal(double, double, double*);  
void processSignal(double, double, double*);
void encryptSignal(double*, int);

int main() {

  // Initialize variables
  double freq = 100.0;
  double phase = 0.0;
  double sensitivity = 0.5;
  double received = 0.0;
  double demod = 0.0;
  double output = 0.0;

  // Modulation
  double vibration = 1.0;
  modulateSignal(vibration, freq, &received);

  // Encryption
  encryptSignal(&received, 15);

  // Demodulation
  demodulateSignal(received, freq, &demod);

  // Processing
  processSignal(demod, sensitivity, &output);

  // Output
  printf("Output: %lf\n", output);

  return 0;
}

// Function definitions
void encryptSignal(double* signal, int key) {

  // Encryption algorithm
  int i;
  unsigned char* byteSignal = (unsigned char*)signal;

  for(i = 0; i < sizeof(signal); i++) {
     
    // XOR operation
    byteSignal[i] = byteSignal[i] ^ (key >> (i % 8));
  }

  *signal = *(double*)byteSignal;

}

void modulateSignal(double vibration, double freq, double* signal) {

  // FM modulation
  double carrierFreq = 1000.0;
  double freqDeviation = 500.0 * vibration;
  double modIndex = freqDeviation / freq; 
  double t = 0.0;
  double dt = 1.0 / freq;

  *signal = 0.0;

  while(t < 1.0) {
    // Generate FM signal
    t += dt;
  }

}

void demodulateSignal(double receivedSignal, double generatorFrequency, double *demodulatedInfo) {
  
  double envelope = fabs(receivedSignal);
  
  double cutoffFrequency = 50.0;
  double dt = 1.0 / generatorFrequency;
  double alpha = dt * 2 * PI * cutoffFrequency;  

  double filteredEnvelope = 0.0;

  for (double t = 0.0; t < 1.0; t += dt) {
    filteredEnvelope += alpha * (envelope - filteredEnvelope);
  }

  *demodulatedInfo = filteredEnvelope;

}

void processSignal(double receivedSignal, double receiverSensitivity, double *soundOutput) {

  double compressedSignal = tanh(receivedSignal);  

  double normalizedSignal = compressedSignal / receiverSensitivity;

  *soundOutput = normalizedSignal;

}