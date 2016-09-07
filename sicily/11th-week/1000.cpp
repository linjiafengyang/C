#include <string.h>
int parseBinary(const char * const binaryString) {
  int decimal = binaryString[0] - '0';
  int i;
  for (i = 1; i < strlen(binaryString); i++)
  {
    decimal = decimal * 2 + binaryString[i] - '0';
  }
  return decimal;
}
