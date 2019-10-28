#include "stdafx.h"
#include "Controller.h"

// Calculate the shot speed to hit the target, given the following information.
//   tankPos: the position from which the bullet will be fired, in pixels relative to the top left corner of the screen
//   enemyPos: the target position to hit, in pixels relative to the top left corner of the screen
//   shotAngleRadians: the angle of the shot, in radians from horizontal (positive angles are upwards)
//   gravity: the acceleration due to gravity in pixels/second^2 (positive is downwards)
//   wind: the acceleration due to wind in pixels/second^2 (positive is rightwards)
float Controller::calculateShotSpeed(const Vector2& tankPos, const Vector2& enemyPos, float shotAngleRadians, float gravity, float wind)
{
	//formula to calculate the shootspeed 
	//					¬ -------;
	//             u =   v  xg
	//                     -----
	//                     sin20
	                            

  	float x = enemyPos.x - tankPos.x; //calculate distance x between the tanks
	float xg = x * gravity; //calculate the distance to travel regarding the gravity 

	//to find Sin2Theta we are going to need sin and cos of theta 
	float thetaSin = sin(shotAngleRadians); //grab the sin 
	float thetaCos = cos(shotAngleRadians); //grab the cos 
  	float sin2Theta = 2 * thetaSin * thetaCos; // calculate the Sin2Theta

	//shootspeed u = squareroot x * g / sin2 theta
  	float u = sqrt(xg / sin2Theta);

	//part 2// calculate y


	//so to compute y, we have y = uy * t - gt2^2 /2
	//in this case our t = y/uSinTheta
	//through derivation, we arrive at the conclusion that u = squareroot of gy/2*SinTheta

	//compute this only if y is not equal 
	if ((enemyPos - tankPos).y != 0)
	{
 		float y = fabs(enemyPos.y - tankPos.y);

 		float gy = y * gravity;

		float u2 = sqrt(gy /3* thetaSin );

		//u += u2;
		//tried to make it work but my formula faults
	}

 	return u;
}

// Calculate the shot angle to hit the target, given the following information.
//   tankPos: the position from which the bullet will be fired, in pixels relative to the top left corner of the screen
//   enemyPos: the target position to hit, in pixels relative to the top left corner of the screen
//   shotSpeed: the speed of the shot, in pixels per second
//   gravity: the acceleration due to gravity in pixels/second^2 (positive is downwards)
//   wind: the acceleration due to wind in pixels/second^2 (positive is rightwards)
float Controller::calculateShotAngle(const Vector2& tankPos, const Vector2& enemyPos, float shotSpeed, float gravity, float wind)
{
	// TODO: calculate the required shot angle (in radians) and return it
	return M_PI * 0.25f;
}

