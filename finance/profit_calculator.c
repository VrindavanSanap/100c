#include <stdio.h>
#include <stdlib.h>

long long get_profit_paise(long long buy_price, long long sell_price,
                           long long num_units) {
  return (sell_price - buy_price) * num_units;
}
long long parse_rupees_to_paise(const char* s) {
  long long rupees = 0, paise = 0;
  sscanf(s, "%lld.%lld", &rupees, &paise);
  return rupees * 100 + paise;
}

char* get_profit(const char* buy_price, const char* sell_price,
                 long long num_units) {
  long long profit_paise =
      get_profit_paise(parse_rupees_to_paise(buy_price),
                       parse_rupees_to_paise(sell_price), num_units);
  long long whole = profit_paise / 100;
  long long frac = profit_paise % 100;
  if (frac < 0) frac = -frac;
  int len = snprintf(NULL, 0, "%lld.%02lld", whole, frac);
  char* profit = malloc(len + 1);
  snprintf(profit, len + 1, "%lld.%02lld", whole, frac);
  return profit;
}

int main() {
  char* buy_price = "1312.00";
  char* sell_price = "1317.00";
  int units = 20;

  char* profit = get_profit(buy_price, sell_price, units);
  printf("%s", profit);
  return 0;
}
