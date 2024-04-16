#include <iostream>
#include <list>

class Shape {
public :
    virtual void draw ()=0;
    virtual void move(int, int) = 0;
};
struct Point{
    int x; int y;
};

class Circle : public Shape {
public:
	virtual void draw() {
		std::cerr <<"in drawCircle\n";
	}
	virtual void move(int dx, int dy){
    center_.x +=dx;
    center_.y +=dy;
    std::cerr << "in moveCircle by dx = " << dx << ", dy = " << dy << '\n';
    }
private:
	double radius_;
	struct Point center_;
};

class Square : public Shape {
public:
	virtual void draw() {
		std::cerr <<"in drawSquare\n";
	}
	virtual void move(int dx, int dy){
    center_.x +=dx;
    center_.y +=dy;
    std::cerr << "in moveSquare by dx = " << dx << ", dy = " << dy << '\n';
    }
private:
	double radius_;
	struct Point center_;
};

class Rhomb : public Shape {
public:
	virtual void draw() {
		std::cerr <<"in drawRhomb\n";
	}
	virtual void move(int dx, int dy){
    center_.x +=dx;
    center_.y +=dy;
    std::cerr << "in moveRhomb by dx = " << dx << ", dy = " << dy << '\n';
    }
private:
	double radius_;
	struct Point center_;
};

void drawShapes ( const std :: list < Shape * >& fig ){
    std :: list < Shape * >:: const_iterator it ;
    for ( it = fig . begin (); it != fig . end (); ++ it ){
        (* it )->draw();
    }   
}   
void moveShapes(const std::list<Shape*>& fig, int dx, int dy) {
	std::list<Shape*>:: const_iterator it;
	for (it=fig.begin(); it!=fig.end(); ++it) {
		(*it)->move(dx, dy);
	}
}

int main() {
	std::list<Shape*> l = {new Circle, new Square, new Square, new Circle, new Rhomb};
	drawShapes(l);
	moveShapes(l, 2, 2);
	return 0;
}