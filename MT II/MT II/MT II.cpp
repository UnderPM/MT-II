#include <iostream>
#include <math.h>

float getPi();
void mainMenu();
void runFunctionsMenu();

class Geometry {
public:
	float AngleRad(float deg_angle)const {
		if (deg_angle > 0) {
			deg_angle = 360 - deg_angle;
		}
		deg_angle * getPi() / 180;
	}
	float GetDisplacedVolume()const {
		return displacement / cylinders;
	}
	float GetCombChamberVolume()const {
		return GetDisplacedVolume() / (compressionRatio - 1);
	}

	Geometry(const float disp_in, const int cyl_in, const float rod_in, const float cr_in, const int underSq_Sq_OverSq) {
		displacement = disp_in;
		cylinders = cyl_in;
		rodLength = rod_in;
		compressionRatio = cr_in;
		enum square_t {UNDER_SQ = -1, SQUARE = 0, OVER_SQ = 1};
		switch (underSq_Sq_OverSq)
		{
		case UNDER_SQ:
			isSquare = false;
			isUnderSquare = true;
			isOverSquare = false;
			break;
		case SQUARE:
			isSquare = true;
			isUnderSquare = false;
			isOverSquare = false;
			break;
		case OVER_SQ:
			isSquare = false;
			isUnderSquare = false;
			isOverSquare = true;
			break;
		}
	}

private:
	float displacement;
	int cylinders;
	float compressionRatio;
	float bore;
	float stroke;
	float rodLength;
	bool isSquare = false;
	bool isUnderSquare = false;
	bool isOverSquare = false;
};

int main() {
	using namespace std;

	int rpm = 3600;
	int rps = rpm / 60;

	//float boreStrokeRatio = bore / stroke;

	float avgPistonSpeed = 0.0f;
	float pistonSpeed = 0.0f;
	float position = 0.0f;
	float delta_pos = 0.0f;
	

	//main loop here
	

	
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

float getPi() {
	return 4 * atan(1.0);
}

void mainMenu() {
	using namespace std;
	
	bool isFinished = false;
	do {
		cout << "MT-II" << endl;
		cout << "1 - Run Functions" << endl;
		cout << "2 - Exit" << endl;
		enum option_t { RUN_FUNCTIONS = 1, EXIT = 2 };
		int option;
		cin >> option;

		switch (option)
		{
		case RUN_FUNCTIONS:
			//call secondary menu

			break;
		case EXIT:
			isFinished = true;
			break;
		default:
			break;
		}
	} while (!isFinished);
}

void runFunctionsMenu() {
	using namespace std;
	bool isFinished = false;

	do {

		cout << "1 - Geometry" << endl;
		cout << "2 - Cinematic" << endl;
		enum option_t { GEOMETRIC = 1, CINEMATIC = 2, BACK = 3 };
		int option;
		cin >> option;

		switch (option) {
		case GEOMETRIC:
			// call geometricMenu
			break;
		case CINEMATIC:
			// call cinematicMenu
			break;
		case BACK:
			isFinished = true;
			break;
		default:
			break;
		}
	} while (!isFinished);
}

void geometricMenu() {
	using namespace std;
	bool isFinished = false;
}



/*//test start
if (isSquare) {
bore = cbrt(4.0 * displacedVolume / getPi());
stroke = bore;
cout << "bore" << endl << bore << endl;
}
avgPistonSpeed = 2 * stroke * rps;
pistonSpeed = (getPi() / 2.0f) * sin(angleRad) * (1 + (cos(angleRad) / sqrt(pow(2 * rodLength / stroke, 2.0f) -
pow(sin(angleRad), 2.0f)))) * avgPistonSpeed;
position = (stroke / 2.0f) * cos(angleRad) + sqrt(pow(rodLength, 2.0f) - pow(stroke / 2.0f, 2.0f) *
pow(sin(angleRad), 2.0f));
delta_pos = rodLength + (stroke / 2.0f) - position;
volumeAtAngle = combustionVolume + (getPi() * pow(bore, 2.0f) / 4) * (rodLength + (stroke / 2.0f) - position);*/