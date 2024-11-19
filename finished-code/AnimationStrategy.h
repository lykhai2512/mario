#pragma once

class AnimationStrategy{
private:
	float time;
	float dyingTime;
public:
	virtual void die();
	virtual void moveleft();
	virtual void moveright();

};

