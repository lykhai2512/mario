#pragma once
#include "Mario.h"

class MarioDecorator : public Mario{
protected:
	Mario* mario;
public:
	MarioDecorator(Mario* mario);
	~MarioDecorator();
};

