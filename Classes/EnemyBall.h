#ifndef ENEMYBALL_H_
#define ENEMYBALL_H_

#include "cocos2d.h"

class EnemyBall : public cocos2d::CCSprite
{
public:
	EnemyBall();

	cocos2d::CCRect getRect();
	bool isTouchPoint( cocos2d::CCPoint);
};


#endif /* ENEMYBALL_H_ */
