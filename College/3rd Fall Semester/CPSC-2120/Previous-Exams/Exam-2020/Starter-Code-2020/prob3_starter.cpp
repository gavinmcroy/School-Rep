// Guaranteed to output a hash value in the range 0 ... 999,999
unsigned int myhash(int x)
{
  return ((unsigned)x * 123147 + 293871) % 100 + 900000;
}
