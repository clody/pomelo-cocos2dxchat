//
//  pomelo_cocos2dxchatAppController.h
//  pomelo-cocos2dxchat
//
//  Created by netcanis on 13. 8. 12..
//  Copyright __MyCompanyName__ 2013년. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;

@end

