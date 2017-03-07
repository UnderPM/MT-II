#include <iostream>
#include <math.h>

int main() {
	using namespace std;
	
	float pi = 4 * atan(1.0);
	float third = 1.0 / 3.0;
	
	float displacement = 3.0e-3f;
	int cylinders = 6;
	
	int rpm = 3600;
	int rps = rpm / 60;

	float compressionRatio = 9.5f;
	float displacedVolume = displacement / cylinders;
	float combustionVolume = displacedVolume / (compressionRatio - 1);
	float volumeAtAngle = 0.0f;
	
	int intAngle = 0;
	float angleDeg = 20.0f;
	float angleRad = angleDeg * pi / 180;

	float bore = 0.0f;
	float stroke = 0.0f;
	float rodLength = 16.6e-2f;
	//float boreStrokeRatio = bore / stroke;

	float avgPistonSpeed = 0.0f;
	float pistonSpeed = 0.0f;
	float position = 0.0f;
	float delta_pos = 0.0f;
	
	bool isSquare = true;
	bool isUnderSquare = false;
	bool isOverSquare = false;

	//main loop here
	//main menu
	cout << "MT-II" << endl;
	cout << "1 - Run Functions" << endl;
	cout << "2 - Exit" << endl;
	enum option_t {RUN_FUNCTIONS = 1, EXIT = 2};
	int option;
	cin >> option;

	switch (option)
	{
	case RUN_FUNCTIONS:
		//call secondary menu
		//test start
		if (isSquare) {
			bore = pow(float(4 * displacedVolume / pi),third);
			stroke = bore;
			cout << "bore" << endl << bore << endl;
		}
		avgPistonSpeed = 2 * stroke * rps;
		pistonSpeed = (pi / 2.0f) * sin(angleRad) * (1 + (cos(angleRad) / sqrt(pow(2 * rodLength / stroke, 2.0f) -
			pow(sin(angleRad), 2.0f)))) * avgPistonSpeed;
		position = (stroke / 2.0f) * cos(angleRad) + sqrt(pow(rodLength, 2.0f) - pow(stroke / 2.0f, 2.0f) * 
			pow(sin(angleRad), 2.0f));
		delta_pos = rodLength + (stroke / 2.0f) - position;
		volumeAtAngle = combustionVolume + (pi * pow(bore, 2.0f) / 4) * (rodLength + (stroke / 2.0f) - position);
		break;
	case EXIT:
		return 0;
		break;
	default:
		break;
	}
	/*
	if (boreStrokeRatio > 1) {
		isOverSquare = true;
		isSquare = false;
		isUnderSquare = false;
	}
	else if (boreStrokeRatio < 1) {
		isUnderSquare = true;
		isSquare = false;
		isOverSquare = false;
	}
	else if(boreStrokeRatio == 1){
		isUnderSquare = false;
		isSquare = true;
		isOverSquare = false;
	}
	*/
	
}