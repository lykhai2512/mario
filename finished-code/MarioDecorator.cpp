#include "MarioDecorator.h"
#include "MarioDecorator.h"

MarioDecorator::MarioDecorator(Mario* mario) : mario(mario){}

MarioDecorator::~MarioDecorator(){
	delete this->mario;
}
