//
//  pomelo_cocos2dxchatAppDelegate.cpp
//  pomelo-cocos2dxchat
//
//  Created by netcanis on 13. 8. 12..
//  Copyright __MyCompanyName__ 2013년. All rights reserved.
//

#include "AppDelegate.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "LoginScene.h"



USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    
    // screen size
    CCSize screenSize  = CCEGLView::sharedOpenGLView()->getFrameSize();
    // texture size
    CCSize textureSize = CCSizeMake ( 640, 960 );
    // game resolution size
    CCSize designSize  = CCSizeMake ( 640, 960 );
    
    pDirector->setContentScaleFactor ( textureSize.width / designSize.width );
    
    
    //std::vector<std::string> searchPaths;
    //searchPaths.reserve ( 32 );
    
    //CCFileUtils::sharedFileUtils()->setSearchPaths ( searchPaths );
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize( designSize.width,
                                                           designSize.height,
                                                           kResolutionShowAll );//kResolutionExactFit );
    
    
    // turn on display FPS
    pDirector->setDisplayStats ( false );
    
    

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = Login::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
