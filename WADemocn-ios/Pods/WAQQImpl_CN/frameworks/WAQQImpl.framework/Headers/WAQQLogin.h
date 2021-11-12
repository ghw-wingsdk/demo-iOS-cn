//
//  WAQQLogin.h
//  WAQQImpl
//
//  Created by LPW on 2020/3/9.
//  Copyright © 2020 LPW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WASdkIntf/WASdkIntf.h>
#import <TencentOpenAPI/TencentOAuth.h>



NS_ASSUME_NONNULL_BEGIN

@interface WAQQLogin : NSObject

@property (nonatomic, retain)TencentOAuth *oauth;

@property (nonatomic) BOOL boundQQ;




+(instancetype)shareInstance;

-(void)loginWithExtInfo:(NSString *)extInfo delegate:(id<WALoginDelegate>)delegate;
- (void)bindingAccountWithExtInfo:(NSString *)extInfo delegate:(id<WAAccountBindingDelegate>)delegate;


-(void)logout;

-(void)applicationDidBecomeActive:(UIApplication *)application;

-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url;



@end

NS_ASSUME_NONNULL_END
