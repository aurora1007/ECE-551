#include <stdio.h>
#include <stdlib.h>

struct retire_info_tag {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct retire_info_tag retire_info_t;

void retirement(int startAge,           //in months
                double initial,         //initial savings in dollars
                retire_info_t working,  //info about working
                retire_info_t retired)  //info about retired

{
  double total;
  total = initial;
  int i;
  int months = startAge;
  for (i = 0; i < working.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", months / 12, months % 12, total);
    total = total * (1 + working.rate_of_return);
    total = total + working.contribution;
    months++;
  }
  for (i = 0; i < retired.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", months / 12, months % 12, total);
    total = total * (1 + retired.rate_of_return);
    total = total + retired.contribution;
    months++;
  }
}

int main(void) {
  //Working:
  retire_info_t work;
  work.months = 489;
  work.contribution = 1000;
  work.rate_of_return = 0.045 / 12;

  //Retired:
  retire_info_t retire;
  retire.months = 384;
  retire.contribution = -4000;
  retire.rate_of_return = 0.01 / 12;

  //Starting conditions :
  int startAge = 327;
  // (27 years, 3 months)
  double initial = 21345;

  retirement(startAge, initial, work, retire);

  return 0;
}
