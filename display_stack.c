#include <stdio.h>
#include <stdlib.h>

static unsigned int bos;
static unsigned int tos;

void dipslay_stack(unsigned int ebp, unsigned int esp)
{  
  printf("ebp: 0x%08x\nesp: 0x%08x\n\n", ebp, esp);
}

int f(int n)
{
  asm("movl %%ebp, %0"
      "\n\t"
      "movl %%esp, %1"
    : "=r" (bos),
      "=r" (tos)::);
  printf("Appel à la onction f(%d)\n",n );
  dipslay_stack(bos, tos);
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return n * f(n-1);
  }
}

int main (void)
{
  int i;
  asm("movl %%ebp, %0"
      "\n\t"
      "movl %%esp, %1"
    : "=r" (bos),
      "=r" (tos)::);
  printf("Appel à la onction main\n" );
  dipslay_stack(bos, tos);
  for (i = 0; i < 2; ++i)
  {
    f(4);
    printf("\n");
  }

  return 0; 
}
