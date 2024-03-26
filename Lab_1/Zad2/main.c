#include "stdio.h"
#include "stdlib.h"

typedef struct Unary_Function Unary_Function;
typedef double (*PTRFUN)(Unary_Function*, double);

struct Unary_Function{
    int lower_bound;
    int upper_bound;
    PTRFUN *virtualna_tablica;
};


typedef struct{
    Unary_Function base;
    double a;
    double b;
}Linear;

typedef struct {
    Unary_Function base;
} Square;

void unary_function_constructor(int lb, int ub, PTRFUN *virtualna_tablica, Unary_Function *func){
    func->lower_bound=lb;
    func->upper_bound=ub;
    func->virtualna_tablica=virtualna_tablica;
};

double negative_value_at(Unary_Function *u, double x){
    return -u->virtualna_tablica[0](u,x);
};

void tabulate(Unary_Function *u){
    for(int x = u->lower_bound; x <= u->upper_bound; x++) {
        printf("f(%d)=%lf\n", x, u->virtualna_tablica[0](u,x));
      }
};

double square_value_at(Unary_Function *u, double x) {
    return x * x;
};

double linear_value_at(Unary_Function *u, double x) {
    Linear *linear = (Linear *)u;
    return linear->a * x + linear->b;
};



PTRFUN virtualna_tablica_linear[]={linear_value_at,negative_value_at};

void linear_constructor(Linear *linear, int lb, int ub, double a, double b) {
    unary_function_constructor(lb, ub, virtualna_tablica_linear, &(linear->base));
    linear->a = a;
    linear->b = b;
};

PTRFUN virtualna_tablica_square[]={square_value_at,negative_value_at};

void square_constructor(Unary_Function *square, int lb, int ub) {
    unary_function_constructor(lb, ub, virtualna_tablica_square, (Unary_Function *)square);
};

int same_functions_for_ints(Unary_Function *f1, Unary_Function *f2, double tolerance){
    if(f1->lower_bound != f2->lower_bound) return 0;
      if(f1->upper_bound != f2->upper_bound) return 0;
      for(int x = f1->lower_bound; x <= f1->upper_bound; x++) {
        double delta = f1->virtualna_tablica[0](f1,x) - f2->virtualna_tablica[0](f2,x);
        if(delta < 0) delta = -delta;
        if(delta > tolerance) return 0;
      }
      return 1;
};
Unary_Function* create_linear(int lb, int ub, double a, double b){
    Linear *linear =(Linear*)malloc(sizeof(Linear));
    linear_constructor(linear,lb,ub,a,b);
    return (Unary_Function*) linear;
};
Unary_Function* create_square(int lb, int ub){
    Unary_Function *square =(Unary_Function*)malloc(sizeof(Square));
    square_constructor(square,lb,ub);
    return square;
} ;

int main() {
    Unary_Function *f1 = create_square(-2, 2);
	printf("Square function: f1(x) = x * x\n");
	tabulate(f1);

	printf("\nLinear function: f2(x) = 5 * x - 2\n");
	Unary_Function *f2 = create_linear(-2, 2, 5, -2);
    printf("UB LB %d %d\n",f2->lower_bound,f2->upper_bound);
	tabulate(f2);

	printf("\nf1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6) ? "DA" : "NE");
	printf("neg_val f1(1) = %.3lf\n", f1->virtualna_tablica[1](f1, 1.0));
  	printf("neg_val f2(1) = %.3lf\n", f2->virtualna_tablica[1](f2, 1.0));
	free(f1);
	free(f2);
	return 0;

}
