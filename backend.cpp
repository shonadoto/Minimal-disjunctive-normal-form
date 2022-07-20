#include "backend.h"

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
uint64_t number, vars;

int bits_num;
std::vector<std::vector<std::string>> table;
std::vector<std::string> combs;
std::vector<int> func;
std::vector<std::vector<int>> used;
std::vector<std::string> OIL; // one in line
std::vector<std::string> not_OIL; // not one in line
std::vector<std::vector<std::string>> mdnf;
std::vector <int> mdnf_lens;
int min_len = 1e9;

const int out_size = 7;

void find_combs(int len, int cur, std::string comb) {
  if (comb.size() == len) {
      combs.push_back(comb);
      for (auto& v : table)
        v.push_back("");
      return;
    }
  for (int i = cur; i < vars; ++i) {
      std::string c = comb + char('A' + i);
      find_combs(len, i + 1, c);
    }
}

void fill_table() {
  func.resize(bits_num);
  for (int i = 0; i < bits_num; ++i) {
      func[bits_num - 1 - i] = number >> i & 1;
    }

  for (int i = 0; i < vars; ++i) {
      std::string s = "A";
      s[0] += i;
      combs.push_back(s);
    }

  table.resize(bits_num);
  for (int i = 0; i < bits_num; ++i) {
      for (int j = 0; j < vars; ++j) {
          table[i].push_back("");
          table[i][j] += char((i >> (vars - j - 1) & 1) + '0');
        }
    }
  for (int i = 2; i <= vars; ++i)
    find_combs(i);
  for (int i = 0; i < bits_num; ++i)
    for (int j = vars; j < table[i].size(); ++j) {
        for (auto& c : combs[j]) {
            table[i][j] += table[i][c - 'A'];
          }
      }

  used.resize(table.size());
  for (auto& v : used) {
      v.resize(table[0].size());
      std::fill(v.begin(), v.end(), 1);
    }
  return;
}

void delete_zero_f() {
  for (int i = 0; i < bits_num; ++i) {
      if (func[i] == 0) {
          for (int j = 0; j < used[i].size(); ++j) {
              used[i][j] = -1;
            }
        }
    }
}

void delete_bad_duplicats() {
  for (int j = 0; j < table[0].size(); ++j) {
      for (int i = 0; i < bits_num; ++i) {
          if (used[i][j] == -1) {
              for (int k = 0; k < bits_num; ++k) {
                  if (used[k][j] == 1 && table[i][j] == table[k][j]) {
                      used[k][j] = -2;
                    }
                }
            }
        }
    }
}

void delete_worse_cases() {
  for (int i = 0; i < bits_num; ++i) {
      for (int j = 0; j < table[i].size(); ++j) {
          if (used[i][j] == 1) {
              for (int k = j + 1; k < table[i].size(); ++k) {
                  bool can = true;
                  for (auto& c : combs[j]) {
                      can = can && std::find(combs[k].begin(), combs[k].end(), c) != combs[k].end();
                    }
                  if (can) {
                      used[i][k] = -3;
                    }
                }
            }
        }
    }
}

void delete_good_duplicats() {
  for (int j = 0; j < table[0].size(); ++j) {
      for (int i = 0; i < bits_num; ++i) {
          if (used[i][j] == 1) {
              for (int k = i + 1; k < bits_num; ++k) {
                  if (table[i][j] == table[k][j])
                    used[k][j] = -4;
                }
            }
        }
    }
}

void find_OIL() {
  for (int i = 0; i < bits_num; ++i) {
      int counter = 0;
      for (int j = 0; j < table[i].size(); ++j) {
          if (used[i][j] == 1 && used[i][j] == -4) ++counter;
        }
      for (int j = 0; j < table[i].size(); ++j) {
          if (used[i][j] == 1) {
              std::string con = "";
              for (int k = 0; k < combs[j].size(); ++k) {
                  if (table[i][j][k] == '0')
                    con += '!';
                  con += combs[j][k];
                }
              if (counter == 1)
                OIL.push_back(con);
              else
                not_OIL.push_back(con);
            }
        }
    }
}

int calc(std::vector<std::string>& dnf) {
  std::vector<int> variables(vars);
  for (int var = 0; var < bits_num; ++var) {
      for (int i = 0; i < vars; ++i) {
          variables[i] = var >> i & 1;
        }
      int ans = 0;
      for (auto& con : dnf) {
          int cur_ans = 1;
          for (int c = 0; c < con.size(); ++c) {
              if (con[c] == '!') {
                  ++c;
                  for (int i = 0; i < vars; ++i) {
                      if (con[c] - 'A' == i) {
                          cur_ans = cur_ans && !variables[vars - i - 1];
                        }
                    }
                }
              else {
                  for (int i = 0; i < vars; ++i) {
                      if (con[c] - 'A' == i) {
                          cur_ans = cur_ans && variables[vars - i - 1];
                        }
                    }
                }
            }
          ans = ans || cur_ans;
        }
      if (ans != func[var]) {
          return false;
        }
    }
  return true;
}
void brute_force() {
  find_OIL();
  int nOIL_size = not_OIL.size();
  for (int t = 0; t < 1 << nOIL_size; ++t) {
      int cur_len = 0;
      std::vector<std::string> cur = OIL;

      for (int i = 0; i < nOIL_size; ++i) {
          if (t >> i & 1) {
              cur.push_back(not_OIL[i]);
            }
        }

      for (auto& v : cur) {
          int counter = 0;
          for (int j = 0; j < v.size(); ++j) {
              if (std::isalpha(v[j]))
                ++counter;
            }
          cur_len += counter;
        }
      if (cur_len <= min_len) {
          if (calc(cur) && std::find(mdnf.begin(), mdnf.end(), cur) == mdnf.end()) {
              mdnf.push_back(cur);
              mdnf_lens.push_back(cur_len);
              min_len = cur_len;
            }
        }
    }
}

void print_table() {
  std::cout << std::setw(out_size) << "F";
  for (auto& c : combs)
    std::cout << std::setw(out_size) << c;
  std::cout << '\n';
  for (int i = 0; i < bits_num; ++i) {
      std::cout << std::setw(out_size) << func[i];
      for (int j = 0; j < table[i].size(); ++j) {
          if (used[i][j] == 1) {
              std::cout << std::setw(out_size) << table[i][j];
            }
          else {
              std::cout << std::setw(out_size) << used[i][j];
            }
        }
      std::cout << '\n';
    }

  std::cout << "\n\n\n";
  for (int i = 0; i < mdnf.size(); ++i) {
      if (mdnf_lens[i] == min_len) {
          for (int j = 0; j < mdnf[i].size(); ++j) {
              std::cout << mdnf[i][j];
              if (j != mdnf[i].size() - 1)
                std::cout << " v ";
            }
          std::cout << '\n';
        }
    }
}
