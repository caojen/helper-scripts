#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void usage(const char* program_name);

int main(int argc, char** argv) {
  if (argc <= 1) {
    // show current timestamp
    time_t t = time(NULL);
    printf("current           : %s", ctime(&t));
    printf("timestamp         : %ld\n", (long int)t);
    printf("timestamp in milli: %ld\n", (long int)t * 1000);
  } else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
    usage(argv[0]);
  } else {
    // convert string into timestamp
    time_t t = atol(argv[1]);
    if ((long int) t > (long int)9999999999) {
      t = t / 1000;
    }

    printf("accepted          : %s", ctime(&t));
    printf("timestamp         : %ld\n", (long int)t);
    printf("timestamp in milli: %ld\n", (long int)t * 1000);
  }

  return 0;
}

void usage(const char* program_name) {
  printf("[%s] convert timestamp and print.\n", program_name);
  printf("\n");
  printf("Usage:\n");
  printf("\t%s              show current timestamp\n", program_name);
  printf("\t%s timestamp    try to format string `timestamp` into `time`, and print time\n", program_name);
  printf("\n");
  printf("example:\n");
  printf("\t%s 1659339930000\n", program_name);

  return;
}
