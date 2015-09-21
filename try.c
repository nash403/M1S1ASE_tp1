#include "try.h"

int try(struct ctx_s * pctx, func_t * f, int arg)
{
  /*asm("movl %%ebp, %0"
      "\n\t"
      "movl %%esp, %1"
    : "=r" (*pctx->ctx_ebp),
      "=r" (*pctx->ctx_esp));*/
  asm("movl %%esp, %0" : "=r" (pctx->ctx_esp));
  asm("movl %%ebp, %0" : "=r" (pctx->ctx_ebp));

  return f(arg);
}

int throw(struct ctx_s * pctx, int r)
{
  static int res;
  res = r;
    /*asm("movl %0, %%ebp"
    "\n\t"
    "movl %1, %%esp"
  :
  : "r" (*pctx->ctx_ebp),
    "r" (*pctx->ctx_esp));*/
  
  asm("movl %0, %%ebp" :: "r" (pctx->ctx_ebp));
  asm("movl %0, %%esp" :: "r" (pctx->ctx_esp));

  return res;
}