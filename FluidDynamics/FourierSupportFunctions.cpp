#include"FourierSupportFunctions.h"

Fluid::Fluid(int _sizeX,int _sizeY):sizeOfX(_sizeX),sizeOfY(_sizeY)
{
	for (int i = 0; i < _sizeX; i++)
		for (int j = 0; j < _sizeY; j++)
			points.push_back(glm::vec3(0.0f));
}

float Fluid::SolveFunction(float x, float y)
{
	return 1.0f;
}

float Fluid::CalculateFourierCoefficients()
{
	float ans = 0.0f;
	for (int i = 0; i < sizeOfX; i++)
	{
		for (int j = 0; j < sizeOfY; j++)
		{
			int x = i;
			int y = j;
			ans += SolveFunction(i, j) * sin((M * PI * x) / A) * sin((N * PI * y) / B) * delX * delY;
		}
	}
	ans *= 4 / (A * B);
	return ans;
}
