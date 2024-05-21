#include <stdlib.h>

typedef char const* (*PTRFUN)();

typedef struct {
	PTRFUN* vtable;
	char const* name;
} Parrot;

char const* name(Parrot* p) { return p->name; }
char const* greet(void) { return "ka ka!"; }
char const* menu(void) { return "sjemenke"; }

PTRFUN vtable[] = {(PTRFUN)name, greet, menu};

void* create(char const* name) {
	Parrot* p = (Parrot*)malloc(sizeof(Parrot));
	p->vtable = vtable;
	p->name = name;
	return p;
}
size_t size_of() {
    return sizeof(Parrot);
}

void* construct(void* memory, char const* name) {
    Parrot* p = (Parrot*)memory;
    p->vtable = vtable;
    p->name = name;
    return p;
}