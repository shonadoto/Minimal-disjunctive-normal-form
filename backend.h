#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

extern uint64_t number, vars;

extern int bits_num;
extern std::vector<std::vector<std::string>> table;
extern std::vector<std::string> combs;
extern std::vector<int> func;
extern std::vector<std::vector<int>> used;
extern std::vector<std::string> OIL; // one in line
extern std::vector<std::string> not_OIL; // not one in line
extern std::vector<std::vector<std::string>> mdnf;
extern std::vector <int> mdnf_lens;
extern int min_len;

extern const int out_size;


void find_combs(int len, int cur = 0, std::string comb = "");
void fill_table();
void delete_zero_f();
void delete_bad_duplicats();
void delete_worse_cases();
void delete_good_duplicats();
void find_OIL();
int calc(std::vector<std::string>& dnf);
void brute_force();
void print_table();

#endif // BACKEND_H
