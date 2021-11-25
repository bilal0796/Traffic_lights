#ifndef __TRAFFIC_CONTROL__
#define __TRAFFIC_CONTROL__

#include <string>

enum LightColor
{
	RED,
	GREEN,
	AMBER
};

class TrafficLight
{
private:	
	LightColor status;

public:
	TrafficLight()
	{
		status = RED;
	}

	LightColor getStatus()
	{
		return status;
	}

	void setStatus(LightColor s)
	{
		status = s;
	}
};


#endif
