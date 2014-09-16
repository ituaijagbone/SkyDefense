//
//  SkyDefense2AppDelegate.cpp
//  SkyDefense2
//
//  Created by Itua Ijagbone on 6/8/14.
//  Copyright __MyCompanyName__ 2014. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "GameLayer.h"

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
    
    CCSize screenSize = pDirector->getOpenGLView()->getFrameSize();
    CCSize designSize = CCSize(2048, 1536);
    
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionExactFit);
    
    std::vector<std::string> searchPaths;
    if (screenSize.height > 768) {
        searchPaths.push_back("ipadhd");
    } else if (screenSize.height > 320) {
        searchPaths.push_back("ipad");
    } else {
        searchPaths.push_back("iphone");
    }
    
    pDirector->setContentScaleFactor(screenSize.height/designSize.height);
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
    
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename("background3.mp3").c_str());
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("bombFail.wav").c_str() );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("bombRelease.wav").c_str() );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("boom.wav").c_str() );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("health.wav").c_str() );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("pew.wav").c_str() );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("fire_truck.wav").c_str() );
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5f);
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5f);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // turn on display FPS
    pDirector->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    CCScene *pScene = GameLayer::scene();
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
