#include<cmath>

#define G 9.8//Gravity m/s^2
#define K 0.01//Drag Constant

double distanceCalc(double x0, double y0, double x1, double y1)
{
	double distance = 0.0;
	distance = x1 - x0;
	return distance;
}
double velocityX(double vx, double t)//If the velocity was time dependent use t in the eq
{
	return vx;
} 

double velocityXCheck(double vx, double t0, double ax)
{
	return vx + t0 * ax;
}

double velocityYCheck(double vy, double t0, double ay)
{
	return vy + t0 * ay;
}

double accelerationX(double vx, double windX)
{
	return -K*(vx+windX);
}

double velocityY(double vy, double t)//If the velocity was time dependent use t in the eq
{
	return vy;
}

double accelerationY(double vy, double windY)
{
	return  -G-(K * (vy + windY));
}