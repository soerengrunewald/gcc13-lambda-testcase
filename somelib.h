#ifndef SOMELIB_H
#define SOMELIB_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef void SOMETYPE;

SOMETYPE* sometype_create(void);
void sometype_destroy(SOMETYPE*);

int sometype_do_something(SOMETYPE*, int);

#ifdef  __cplusplus
}
#endif

#endif
