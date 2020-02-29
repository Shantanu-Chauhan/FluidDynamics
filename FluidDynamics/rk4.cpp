#include<iostream>
#include<fstream>
double accelerationX(double, double);
double velocityX(double, double);
double accelerationY(double, double);
double velocityY(double, double);
double distanceCalc(double, double, double, double);
double velocityXCheck(double vx, double t0, double ax);
double velocityYCheck(double vy, double t0, double ay);
#define filename   "data.txt"

bool rk4(double Vx, double Vy, double objVelX, double objVelY, double objPosX, double objPosY, double windX, double windY, double tEnd, double time_step, double angle, bool flag)
{
	std::ofstream data(filename);
	double t0 = 0.0;
	int N = (int)((tEnd - t0) / time_step);

	double initialX = 0.0;//This is projectiles initial location X
	double initialY = 0.0;//This is projectiles initial location Y

	double initialobjX = objPosX;//This is objects initial location X
	double initialobjY = objPosY;//This is objects initial location Y

	double objvx = objVelX;//This is objects velocity Object only moves on the ground so Y is considered 0

	double objx = initialobjX;//This is objects current location X
	double objy = 0.0;//This is objects current location Y


	double ax, ay;//Acceleration of the projectile

	double vx = Vx;
	double vy = Vy;
	double vx1,vx2, vx3, vx4;
	double vy1,vy2, vy3, vy4;
	double ax1,ax2, ax3, ax4;
	double ay1,ay2, ay3, ay4;

	double x = 0.0;
	double y = 0.0;
	if (flag)//This ensures that data is only being written in the second pass
	{
		data << x << "," << 0 << "," << y << "," << 0 << "," << t0 << std::endl;
		data << objx << "," << 0 << "," << objy << "," << 2 << "," << t0 << std::endl;     //Moving balls wrt time
		/*data << x << "," << 0 << "," << y << std::endl;
		data << objx << "," << 0 << "," << objy << std::endl;*/
	}
	for (int j = 0; j <= N; j++)
	{
		ax = accelerationX(vx, windX);
		vx = velocityXCheck(vx, time_step, ax);
		ay = accelerationY(vy, windY);
		vy = velocityYCheck(vy, time_step, ay);
		x = x + vx * time_step;
		y = y + vy * time_step;
		
		/*
		ax1 = accelerationX(vx, windX);
		vx1 = velocityXCheck(vx, t0, ax1);

		ax2 = accelerationX(vx1, windX);
		vx2 = velocityXCheck(vx1, t0 + time_step / 2, ax2);

		ax3 = accelerationX(vx2, windX);
		vx3 = velocityXCheck(vx2, t0 + time_step / 2, ax3);

		ax4 = accelerationX(vx3, windX);
		vx4 = velocityXCheck(vx3, t0 + time_step / 2, ax4);
	
		ay1 = accelerationY(vy, windY);
		vy1 = velocityYCheck(vy, t0, ay1);

		ay2 = accelerationY(vy1, windY);
		vy2 = velocityYCheck(vy1, t0 + time_step / 2, ay2);

		ay3 = accelerationY(vy2, windY);
		vy3 = velocityYCheck(vy2, t0 + time_step / 2, ay3);

		ay4 = accelerationY(vy3, windY);
		vy4 = velocityYCheck(vy3, t0 + time_step / 2, ay4);
		
		x = x + t0/6.0*(vx1 + 2*vx2 + 2*vx3 + vx4);
		y = y + t0/6.0*(vy1 + 2 * vy2 + 2 * vy3 + vy4)/6.0;*/
		


		objx = objx + objvx * time_step;


		if (flag)//This ensures that data is only being written in the second pass
		{
			data << x << "," << 0 << "," << y << "," << 0 << "," << t0 << std::endl;
			data << objx << "," << 0 << "," << objy << "," << 2 << "," << t0 << std::endl;
			/*data << x << "," << 0 << "," << y << std::endl;
			data << objx << "," << 0 << "," << objy << std::endl;*/
		}
		if (y < 0.001 && t0 > 0.001)
		{
			//find the distance of the obj in current timestep
			double distance;
			distance = distanceCalc(initialX, initialY, initialobjX, initialobjY) + objvx * t0;
			if (x >= distance - 1.0 && x <= distance + 1.0)
			{
				data.close();
				std::cout << "HIT" << std::endl;
				std::cout << x << "<-This is the range(m) for launch angle(degrees)->" << angle << " | Total time(sec) taken to hit the ground->" << t0 << std::endl;
				return true;
			}
		}

		if (y < 0.000001 && t0>0.001)
		{
			//std::cout << "broke here:"<<y <<"angle"<<angle1<<"time"<<t0<< std::endl;
			break;
		}
		t0 = t0 + time_step;
	}
	data.close();
	return false;
}































/*    k2 = f(v + 0.5*k*l1,t0 + 0.5*k);
	  l2 = g(v + 0.5*k*l1, t0 + 0.5*k);

	  k3 = f(v + 0.5*k*l2,t0 + 0.5*k);
	  l3 = g(v + 0.5*k*l2, t0 + 0.5*k);

	  k4 = f(v + k*l3,t0 + k);
	  l4 = g(v + k*l3, t0 + k);
	 */
	 // Propagate solution forward to next time step 
	/* y = y + (k/6.0)*(k1 + 2*k2 + 2*k3 + k4);
	 v = v + (k/6.0)*(l1 + 2*l2 + 2*l3 + l4);*/
	 // ans = analytic(t0);
	  //y = y + (k / 6.0)*(k1 + 2 * k2 + 2 * k3 + k4);
	  // Update next value of t 