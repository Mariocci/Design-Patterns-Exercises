#include <stdio.h>
#include <stdlib.h>

typedef char const* (*PTRFUN)();

typedef struct {
	PTRFUN* vtable;
	char const* name;
} Tiger;

char const* name(Tiger* t) { return t->name; }
char const* greet(void) { return "ragr!"; }
char const* menu(void) { return "meso"; }

PTRFUN vtable[] = {(PTRFUN)name, greet, menu};

void* create(char const* name) {
	Tiger* t = (Tiger*)malloc(sizeof(Tiger));
	t->vtable = vtable;
	t->name = name;
	return t;
}
size_t size_of() {
    return sizeof(Tiger);
}

void* construct(void* memory, char const* name) {
    Tiger* t = (Tiger*)memory;
    t->vtable = vtable;
    t->name = name;
    return t;
}