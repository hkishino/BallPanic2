#include "EnemyBall.h"

using namespace cocos2d;

EnemyBall::EnemyBall(){}

CCRect EnemyBall::getRect(){
	CCPoint point = this->getPosition();

	int width = this->getContentSize().width;
	int height = this->getContentSize().height;

	return CCRectMake(point.x - (width/2), point.y - (height/2.0), width, height );
}

bool EnemyBall::isTouchPoint( CCPoint point )
{
	return this->getRect().containsPoint(point);
}
