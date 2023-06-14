#pragma once
class LightDriver
{
	//Funktioner
	public:
	LightDriver();
	void setFrontLight(int);
	void setBackLight(int);
	
	//variabler
	private:
	int frontLight;
	int backLight;

}; 
