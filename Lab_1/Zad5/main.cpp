#include <stdio.h>
#include <stdlib.h>

class B{
public:
  virtual int  prva()=0;
  virtual int  druga(int)=0;
};

class D: public B{
public:
  virtual int  prva(){return 42;}
  virtual int  druga(int x){return prva()+x;}
};

typedef int (*PTRFUN1)(void*);
typedef int (*PTRFUN2)(void*,int);

void function (B* b){
    unsigned long *vptr =  *(unsigned long**)b; // int ne radi dobije se seg fault
	  printf("%d\n", ((PTRFUN1)vptr[0])(b));
	  printf("%d\n", ((PTRFUN2)vptr[1])(b, 1));
}

int main(void){
    B *b = new D();
    function(b);
    free(b);
}
