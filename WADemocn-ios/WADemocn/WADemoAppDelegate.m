//
//  AppDelegate.m
//  GHWSDKDemo
//
//  Created by wuyx on 16/2/23.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import "WADemoAppDelegate.h"
#import <WASdkIntf/WASdkIntf.h>
@interface WADemoAppDelegate ()

@end

@implementation WADemoAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [WACoreProxy init];
    [WACoreProxy setSDKType:WA_SDK_TYPE_CN];
    [WACoreProxy setDebugMode:YES];
    [WACoreProxy initAppEventTracker];
    [WAPayProxy init4Iap];
    [WACoreProxy setServerId:@"China"];
    [WACoreProxy setLevel:10];
    [WACoreProxy setGameUserId:@"12345"];
    [WAUserProxy setLoginFlowType:WA_LOGIN_FLOW_TYPE_REBIND];
    
    return [WAUserProxy application:application didFinishLaunchingWithOptions:launchOptions];
    
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save us er data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    [WAUserProxy applicationDidEnterBackground:application];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [WAUserProxy applicationWillEnterForeground:application];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [WAUserProxy applicationDidBecomeActive:application];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}
//
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    
    return [WAUserProxy application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}

@end
