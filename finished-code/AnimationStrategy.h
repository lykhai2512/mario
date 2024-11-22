#pragma once

class AnimationStrategy{
private:
	float time;
	float dyingTime;
public:
	virtual ~AnimationStrategy() = default;

	virtual void die();
	virtual void moveleft();
	virtual void moveright();

};

