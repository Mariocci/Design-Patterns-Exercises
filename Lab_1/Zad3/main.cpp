#include <stdio.h>
#include <stdlib.h>

class CoolClass{
public:
  virtual void set(int x){x_=x;};
  virtual int get(){return x_;};
private:
  int x_;
};
class PlainOldClass{
public:
  void set(int x){x_=x;};
  int get(){return x_;};
private:
  int x_;
};

int main(){
    //CoolClass je 16,a plain je 4, zbog pokazivača na vTable koji koristi 8 bajtova, na int koji je inače 4 bajta se dodaje 4 zbog paddinga
    //dok u plain old class nema pokazivača na vTable stoga je veličina 4 bajta zbog integera
    printf("sizeof(CoolClass) = %ld\n",sizeof(CoolClass));
    printf("sizeof(PlainOldClass) = %ld\n",sizeof(PlainOldClass));
    return 0;
}