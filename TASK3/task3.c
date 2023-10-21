#include <stdio.h>

int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char *inputString = NULL;
    size_t bufferSize = 0;

    printf("Please enter a string: ");
    getline(&inputString, &bufferSize, stdin);

    printf("You entered: %s", inputString);
    const int shift = 32;
    for (int i = 0; i < stringLength(inputString); i++){
      char ch = inputString[i];
      //only for big LETTERS from england
      if ((int)ch >=65 && (int)ch <=90){
        ch+=shift;
      }
      inputString[i] = ch;
      printf("Symbol - %c, code - %d.\n", ch,ch);
    };
    printf("%s", inputString);
    return 0;
}

