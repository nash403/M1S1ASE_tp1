/*
 * try.h
 * Authors: Honoré NINTUNZE
 *
 */


/* Struct for saving a context */
struct ctx_s {
    void * ctx_ebp;
    void * ctx_esp;
};

/* 
 * Saves the context inside the specified struct, and calls the specified function
 * ctx_s: the struct where to save the context
 * f: the functon to call
 * arg: the argument
 */
int try(struct ctx_s * pctx, func_t * f, int arg);


/*
 * Restores the context previously saved.
 */
int throw(struct ctx_s * pctx, int r);