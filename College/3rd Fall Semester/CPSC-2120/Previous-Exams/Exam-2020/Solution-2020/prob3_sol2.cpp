// O(n) solution for just the "average" part
#include <iostream>
#include <iomanip>
using namespace std;

// Guaranteed to output a hash value in the range 0 ... 999,999
unsigned int myhash(int x)
{
  return ((unsigned)x * 123147 + 293871) % 100 + 900000;
}

const int N = 1000000;
int A[N], used[N];

int main(void)
{
  double total=0.0, excess=0.0;
  for (int i=1; i<=N; i++) A[myhash(i)]++;
  for (int i=0; i<2*N; i++) {
    excess += i<N ? A[i] : 0;
    total += excess;
    if (excess && !used[i%N]) { used[i%N]=1; excess--; }
  }
  cout << "Average " << setprecision(15) << total/N << "\n";
}
