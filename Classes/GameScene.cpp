#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "GameScene.h"
#include "../../CocosDenshion/include/SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

CCScene* GameScene::scene()
{
	CCScene* scene = CCScene::create();
	GameScene* layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if( !CCLayer::init())
	{
		return false;
	}

	//タッチイベント
	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	drawPlayer();
	drawEnemy();

	srand((unsigned int)time(NULL));

	enemy_v = 10.0;
	playerLife = 3;

	this->schedule( schedule_selector(GameScene::sTimer), 2.0 );
	this->scheduleUpdate();
	return true;
}

void GameScene::drawPlayer(){
	//画面サイズの取得
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	player = CCSprite::create( "player.png" );
	player->setPosition( ccp( size.width * 0.5, 2.0 ) );
	this->addChild(player);
}

void GameScene::drawEnemy()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	ball = CCSprite::create( "ball.png" );
	ball->setPosition( ccp( rand() % (int)size.width, size.height * 1.0 ) );
	this->addChild(ball);
}

bool GameScene::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
	touchPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView() );
	playerRect = player->boundingBox();

	if( playerRect.containsPoint(touchPoint) )
		return true;
	return false;
}

void GameScene::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent)
{
	CCPoint currentPos = CCDirector::sharedDirector()->convertToGL(( pTouch->getLocationInView()));
	CCPoint previousPos = CCDirector::sharedDirector()->convertToGL(pTouch->getPreviousLocationInView());

	CCPoint difference = ccpSub( currentPos, previousPos );

	player->setPosition( ccpAdd( player->getPosition(), difference));
}

void GameScene::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent)
{

}

void GameScene::update(float dt){
	float enemy_y = ball->getPositionY();
	enemy_y -= enemy_v;
//	if( enemy_y < 0 )
//		ball->removeFromParentAndCleanup(true);
//	else
	ball->setPositionY(enemy_y);
	enemyRect = ball->boundingBox();
	if( playerRect.intersectsRect(enemyRect) ){
		this->removeChild( ball );
		playerLife--;
	}
}

void GameScene::sTimer(float time){
	drawEnemy();
}

