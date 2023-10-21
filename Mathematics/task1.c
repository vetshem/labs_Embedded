#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
double calculate_z1(double m, double n);
double calculate_z2(double m, double n);
bool check_enter(double m, double n);
bool get_valid_double(const char *prompt, double *value);
double dividing(double divident, double divisor);
int main(void) {
  double m, n, z1, z2;

  do {

    get_valid_double("Enter m: ", &m) && get_valid_double("Enter n: ", &n);

  } while (!check_enter(m, n));

  z1 = calculate_z1(m, n);
  printf("z1 = %.4lf", z1);

  z2 = calculate_z2(m, n);
  printf("z2 = %.4lf \n", z2);
  return 0;
}
bool get_valid_double(const char *prompt, double *value) {
  while (true) {
    printf("%s", prompt);
    if (scanf("%lf", value) == 1) {
      // Input is a valid double
      while (getchar() != '\n'); // Clear input buffer
      return true;
    } else {
      printf("Invalid input. Please enter a valid number.\n");
      while (getchar() != '\n'); // Clear input buffer
    }
  }
}
bool check_enter(double m, double n) {
  if (m >= 0 && n >= 0) {
    return true;
  } else {
    fprintf(stderr,
            "Error: Square root is not searched for numbers less than 0.\n");
    return false;
  }
}

double dividing(double divident, double divisor) {
  if (divisor == 0) {
    fprintf(stderr, "Error: Division by zero is not allowed.\n");
    exit(-1); // Exit the program with a non-zero status code to indicate an
              // error
  } else {
    printf("\nRESULT: ");
    return divident / divisor;
  }
}
double calculate_z1(double m, double n) {
  double divident = (m - 1) * sqrt(m) - (n - 1) * sqrt(n);
  double divisor = sqrt(pow(m, 3) * n) + n * m + pow(m, 2) - m;
  return dividing(divident, divisor);
}
double calculate_z2(double m, double n) {
  double divident = sqrt(m) - sqrt(n);
  double divisor = m;
  return dividing(divident, divisor);
}
