//
//  AppDelegate.m
//  GHWSDKDemo
//
//  Created by wuyx on 16/2/23.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import "WADemoAppDelegate.h"
#import <WASdkIntf/WASdkIntf.h>
#import <WACommon/WAHelper.h>

@interface WADemoAppDelegate () <UNUserNotificationCenterDelegate>

@end

@implementation WADemoAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
//    [WACoreProxy init];
    [WACoreProxy initWithCompletionHandler:^{
        NSLog(@"初始化完成====");

        [WACoreProxy setDebugMode:YES];
        [WACoreProxy setSDKType:WA_SDK_TYPE_CN];
        [WACoreProxy initAppEventTracker];
        [WAPayProxy init4Iap];

        [WACoreProxy application:application didFinishLaunchingWithOptions:launchOptions];
        
        
        NSLog(@"国内读取==WAFinishTransactionTime==%@",[WAHelper loadObjFromKeyChainWithKey:@"WAFinishTransactionTime"]);

        
    }];


    
    
    /*!
    @discussion 隐私协议弹框
     error 不为空时
        status  -1  弹出了协议框，用户点击了拒绝
                
     error 为空
        status 1 弹出了协议框，用户点击了同意
        status 2 没有弹出协议框，用户之前点击过同意，无需再弹
     */
    
//    [WAUserProxy openPrivacyAgreementWindow:^(NSError *error, NSUInteger status) {
//        if (error) {
//            WALog(@"拒绝======")
////            [self showToastMessage:@"弹出了协议框，用户点击了拒绝"];
//        }else{
//            if (status==1) {
//                
//                // status状态与 ATTrackingManagerAuthorizationStatus 一致
//                [WAUserProxy openTTAAuthorizationWithCompletionHandler:^(NSError *error, NSUInteger status) {
//                    if (error) {
////                        [self showToastMessage:error.localizedDescription];
//                    }else{
//                        
//                        if (status==0) {
////                            [self showToastMessage:@"ATTrackingManagerAuthorizationStatusNotDetermined(不确定)"];
//
//                        }else if(status==1){
////                            [self showToastMessage:@"ATTrackingManagerAuthorizationStatusRestricted(限制)"];
//
//                        }else if(status==2){
////                            [self showToastMessage:@"ATTrackingManagerAuthorizationStatusDenied(拒绝)"];
//
//                        }else if(status==3){
////                            [self showToastMessage:@"ATTrackingManagerAuthorizationStatusAuthorized(已同意)"];
//
//                        }
//                        
//
//                        
//                    }
//                }];
//                
//                
////                [self showToastMessage:@"弹出了协议框，用户点击了同意"];
//
//            }else if(status==2){
////                [self showToastMessage:@"没有弹出协议框，用户之前点击过同意，无需再弹"];
//
//            }
//
//        }
//        
//    }];

    
    return YES;
    
}

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler {
    if ([userActivity.activityType isEqualToString:NSUserActivityTypeBrowsingWeb]) {
        NSURL *url = userActivity.webpageURL;
       // TODO 根据需求进行处理
    }
      // TODO 根据需求进行处理
	
	return [WACoreProxy application:application continueUserActivity:userActivity restorationHandler:restorationHandler];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [WACoreProxy application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save us er data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    [WACoreProxy applicationDidEnterBackground:application];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [WACoreProxy applicationWillEnterForeground:application];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [WACoreProxy applicationDidBecomeActive:application];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}
//
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    
    return [WACoreProxy application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    return [WACoreProxy application:app openURL:url options:options];
}

//- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window {
//    return UIInterfaceOrientationMaskAll;
//}


@end
