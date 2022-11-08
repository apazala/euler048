#include <inttypes.h>
#include <stdio.h>

#define MOD 10000000000ull

uint64_t modmul(const uint64_t x, const uint64_t y) {
  if (x > (1<<30) && y > (1 << 30))
    return ((x >> 30)*((y << 30) % MOD) + y*(x & ((1 << 30) - 1))) % MOD;
  uint64_t z = x*y;
  if (z >= MOD)
    z %= MOD;
  return z;
}

uint64_t modpow(uint64_t base, int exp)
{
    uint64_t result = 1;
    for (;;)
    {
        if (exp & 1)
            result = modmul(result, base);
        exp >>= 1;
        if (!exp)
            break;
        base = modmul(base, base);
    }

    return result;
}

#define TARGET 1000
int main()
{
    uint64_t summod = 0;
    for(int i = 1; i <= TARGET; i++){
        summod += modpow(i, i);
        while(summod>=MOD)
            summod-=MOD; 
    }

    printf("%" PRId64 "\n", summod);
}