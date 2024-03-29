#ifndef GEOMETRY_H
#define GEOMETRY_H

class Point{
    public:
        Point(int x_ = 0, int y_ = 0);
        Point(Point const &pnt);
        Point& operator=(const  Point& other);
        
        int getX()const;
        int getY()const;
        
    private:
        int x, y;
};

class PolygonalChain{
    public:
        PolygonalChain(int sz_, Point *pnt_);
        PolygonalChain(PolygonalChain const &other);
        
        PolygonalChain& operator=(const PolygonalChain& other);
        
        int getN()const;
        Point getPoint(int ind)const;
        
        //fixed they should be virtual
        virtual double perimeter()const;
        virtual void setClosed(bool val);
        virtual bool getClosed() const;
	//fixed and its too        
        virtual ~PolygonalChain();
    	
    protected:
        int sz;
        Point *pnt;
        bool closed;
};

class ClosedPolygonalChain: public PolygonalChain{
    public:
        ClosedPolygonalChain(int sz, Point *pnt);
        
    	~ClosedPolygonalChain();
};

class Polygon: public ClosedPolygonalChain{
    public:
        Polygon(int sz, Point *pnt);
        
        double area()const;
        
        ~Polygon();
        
    private:
        double s_triangle(Point a, Point b, Point c)const;
};

class Triangle: public Polygon{
    public:
        Triangle(int sz, Point *pnt);
        
        bool hasRightAngle()const;
        
        ~Triangle();
        
};

class Trapezoid: public Polygon{
    public:
        Trapezoid(int sz, Point *pnt);
        
        int height()const;
        
        ~Trapezoid();
};

class RegularPolygon: public Polygon{
    public:
        RegularPolygon(int sz, Point* pnt);
        
	    double perimeter()const;
        double area()const;
	
        ~RegularPolygon();
};

double dist(const Point& a, const Point& b);

int dist2(const Point& a, const Point& b);

#endif
