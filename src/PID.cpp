#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;

}

void PID::UpdateError(double cte) {

	//  // The derivative of the error is simply the difference between the current error and the previous error.
	d_error = cte - p_error;

	// The proportional error is simply the current crosstrack error (CTE)
	p_error = cte;

	// The integral error term is simply the running sum of crosstrack errors (CTE)
	i_error += cte;

	std::cout << "P = " << d_error << " | I = " << i_error << " | D = " << d_error << std::endl;

}

double PID::TotalError() {
	return Kp_*p_error + Ki_*i_error + Kd_*d_error;
}

