
#ifndef __HJQ_ELEMENTS__
#define  __HJQ_ELEMENTS__

class point
{
public:
	double x, y, z;
	double nx, ny, nz;
	double faceAmount;
	int IR, IG, IB;
	point();
protected:
private:
};


struct PolygonYListElement
{
	int IP;
	double Ymax;
};

struct ETElement
{
	double Ymax;
	double dx;
	double x, z;
};
typedef CArray<CList<ETElement*>*> ET;
struct AETElement
{
	double xl, dxl, ylmax, xr, dxr, yrmax;
	double zl, dzx, dzy;

	double crl, dcrx, dcry;
	double cgl, dcgx, dcgy;
	double cbl, dcbx, dcby;

	double nxl, dnxx, dnxy;
	double nyl, dnyx, dnyy;
	double nzl, dnzx, dnzy;

	int IP;
	point left, right;
};

typedef CList<AETElement*> AET;

class face
{
public:
	ET et;
	byte r, g, b;
	long p1, p2, p3;
	double nx, ny, nz;

	double minx, miny, minz, maxx, maxy, maxz;

	face();
protected:
private:
};

class shape
{
public:
	face* faces;
	point* points;

	double minx, miny, minz, maxx, maxy, maxz;

	long pointAmount, faceAmount;
	shape();

protected:
private:
};

#endif