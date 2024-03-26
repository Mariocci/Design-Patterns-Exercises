#include "stdio.h"
#include "stdlib.h"
typedef char const* (*PTRFUN)();

struct Animal{
  PTRFUN *virtualnaTablica;
  char const *name;
};

void animalPrintGreeting(struct Animal* animal){
  printf("%s pozdravlja: %s!\n",animal->name,animal->virtualnaTablica[0]());
};

void animalPrintMenu(struct Animal *animal){
  printf("%s voli %s.\n",animal->name,animal->virtualnaTablica[1]());
};

char const* dogGreet(void){
  return "vau!";
}
char const* dogMenu(void){
  return "kuhanu govedinu";
}
char const* catGreet(void){
  return "mijau!";
}
char const* catMenu(void){
  return "konzerviranu tunjevinu";
}



PTRFUN virtualnaTablicaDog[]={dogGreet,dogMenu};
PTRFUN virtualnaTablicaCat[]={catGreet,catMenu};
void constructDog(struct Animal *animal,const char *ime){
  animal->name = ime;
  animal->virtualnaTablica = virtualnaTablicaDog;
};
void constructCat(struct Animal *animal,const char *ime){
  animal->name = ime;
  animal->virtualnaTablica = virtualnaTablicaCat;
};


struct Animal* createCat(const char* ime){
  struct Animal* cat = ( struct Animal*) malloc(sizeof(struct Animal));
  constructCat(cat,ime);
  return cat;
};
struct Animal* createDog(const char* ime){
  struct Animal* dog = (struct Animal*) malloc(sizeof(struct Animal));
  constructDog(dog,ime);
  return dog;
};

void testAnimals(void){
  struct Animal* p1=createDog("Hamlet");
  struct Animal* p2=createCat("Ofelija");
  struct Animal* p3=createDog("Polonije");

  animalPrintGreeting(p1);
  animalPrintGreeting(p2);
  animalPrintGreeting(p3);

  animalPrintMenu(p1);
  animalPrintMenu(p2);
  animalPrintMenu(p3);

  free(p1); free(p2); free(p3);
}

void stack(){
struct Animal dog;
struct Animal cat;

constructCat(&cat,"Luna");
constructDog(&dog,"Šime");

animalPrintGreeting(&dog);
animalPrintGreeting(&cat);
animalPrintMenu(&dog);
animalPrintMenu(&cat);
};



struct Animal** stvoriNPasa(int n){
  struct Animal** psi = (struct Animal**) malloc(sizeof(struct Animal*)*n);
      for (int i = 0; i < n; i ++) {
        char name[20];
        sprintf(name, "Pas %d", i);
        psi[i] = createDog(name);
    }
    return psi;

};

void testNPasa(int n){
  struct Animal** psi = stvoriNPasa(n);
  
    for (int i = 0; i < n; i ++) {
        animalPrintGreeting(psi[i]);
    }
    free(psi);
};

int main() {

    testAnimals();

    stack();

    printf("Koliko zeliute stvoriti pasa?\n");
    int n;
    scanf("%d",&n);
    testNPasa(n);

    return 0;
}