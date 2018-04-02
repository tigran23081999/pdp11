#include <stdio.h>
#include <assert.h>

typedef unsigned char byte;
typedef int word;
typedef int adr;

byte mem[56*1024];

#define LO(x) (x & 0xFF);
#define HI(x) (((x>>8) & 0xFF));

byte b_read  (adr a);
void b_write (adr a, byte val);
word w_read  (adr a);
void w_write (adr a, word val);

byte b_read  (adr a)
{
    return mem[a];
}

void b_write (adr a, byte val)
{
    mem[a] = val;
}

void test() {
    byte b0, b1;
    word w;
}

void w_write (adr a, word val)
{
    assert (a % 2 == 0);
    mem[a] = LO(val);
    mem[a+1] = HI(val);
}

void halt() {
    print("THE END!!!!\n");
    exit(0);
}
