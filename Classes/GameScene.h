#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class GameScene: public cocos2d::CCLayer
{

private:
	void drawPlayer();
	void drawEnemy();

	CCSprite* player;
	CCSprite* ball;

	CCRect playerRect;
	CCRect enemyRect;
	CCPoint touchPoint;

	float enemy_v;

	int playerLife;

public:
	virtual bool init();
	static cocos2d::CCScene* scene();

	cocos2d::CCArray enemys;

	void sTimer(float time);
	void update(float dt);

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	CREATE_FUNC(GameScene);
};

#endif /* GAMESCENE_H_ */
