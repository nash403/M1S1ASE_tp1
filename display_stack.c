#include <stdio.h>
#include <stdlib.h>

static int * bos;
static int * tos;

void dipslay_stack(char* name)
{
  int * i;
  asm("movl %%ebp, %0"
      "\n\t"
      "movl %%esp, %1"
    : "=r" (bos),
      "=r" (tos)::);
  
  printf("Fonction %s:\nebp: addr:0x%08x, value:%08x\nesp: addr:0x%08x, value:%08x\n\n", name, bos, *bos, tos, *tos);
  printf("Sommet de Pile :\n");
  for (i=tos;i<=bos;i+=1)
    printf("\t-> 0x%08x\t: %08x\n",i,*i);
  printf("Base de pile\n\n");
}

void f1()
{
  int i;
  dipslay_stack("f1");
  for (i = 0; i < 3; i++)
  {
    printf("boucle tour %d\n", i+1);
    dipslay_stack("f1");
  }
  dipslay_stack("f1");
}

void f2()
{
  dipslay_stack("f2");
  f1();
  dipslay_stack("f2");
}

int main (void)
{
  dipslay_stack("main");
  f1();
  dipslay_stack("main");
  f2();
  dipslay_stack("main");

  return 0; 
}
