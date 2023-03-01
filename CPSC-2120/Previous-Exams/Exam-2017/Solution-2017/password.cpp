#include <iostream>
#include <fstream>
#include "stringintmap.h"
using namespace std;

string *unames, *passwords;
int *prev; // prev[i] is the index of the previous valid password change before the one at index i
StringIntMap lastchange, num_invalids; 
// lastchange[name] is the index of name's last valid password change
// num_invalids[name] is a count of how many invalid password changes were made by name

bool valid(int i)
{
  if (!lastchange.find(unames[i])) return true;
  for (int j = lastchange[unames[i]], count = 0; count < 3 && j != -1; count++, j = prev[j])
    if (passwords[j] == passwords[i]) return false;
  return true;
}

int main(void)
{
  ifstream fin("password_changes.txt");
  int N, max_invalid = 0, total_invalid = 0;
  fin >> N;
  unames = new string[N];
  passwords = new string[N];
  prev = new int[N];
  for (int i=0; i<N; i++) {
    fin >> unames[i] >> passwords[i];
    if (!valid(i)) {
      prev[i] = -1;
      total_invalid++;
      num_invalids[unames[i]]++;
      max_invalid = max(max_invalid, num_invalids[unames[i]]);
    } else {
      prev[i] = lastchange[unames[i]];
      lastchange[unames[i]] = i;
    }
  }
  cout << total_invalid << "\n";
  for (int i=0; i<N; i++) {
    if (num_invalids[unames[i]] == max_invalid) {
      num_invalids[unames[i]] = -1;
      cout << unames[i] << "\n";
    }
  }
  return 0;
}
