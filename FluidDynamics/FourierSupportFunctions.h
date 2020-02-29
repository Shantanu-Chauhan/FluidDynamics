#pragma once
#include<vector>
#include<glm.hpp>

const float PI = 3.141f;
class Fluid {
public:
	Fluid(int,int);
	~Fluid() { ; }
	std::vector<glm::vec3> points;
	float SolveFunction(float x, float y);
	std::vector<float> a_m_n;
	float CalculateFourierCoefficients();
	int sizeOfX;
	int sizeOfY;
	float A;
	float B;
	float M;
	float N;
	float delX;
	float delY;
};