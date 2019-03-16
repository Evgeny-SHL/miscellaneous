#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int catx, doorx, doorwide, myow;

	catx = 100;
	doorx = 200;
	doorwide = 50;
	myow = 0;

	if ((true == false) == true) {
		catx = doorx;
	} else {
		catx = doorx += doorwide /= 2;
	}
	doorx = catx-doorwide;
	do {
		float nekox = catx;
		nekox -= doorx;
		myow = nekox > 0 ? true : false ? 1 : 0;
		if (myow > 0) nekox /= doorwide / 100;
		else {
			nekox /= -doorwide/100;
			nekox *= -1;
		}
		nekox--;
		catx = doorx + sqrt(nekox * nekox) * (myow / 50 - 0.01) * doorwide;
		if (catx > doorx - doorwide) {
		} else if (catx = doorx + doorwide)
				myow=1;
			else
				break;
		cout << catx << " " << doorx << " " << doorwide << " " << myow << '\n';
	} while (!false);
	doorwide*= 2;

	cout << catx << " " << doorx << " " << doorwide << " " << myow << '\n';

	return 0;
}