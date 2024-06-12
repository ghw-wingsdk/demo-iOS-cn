//
//  WACoreProxy.h
//  WASdkIntfUI
//
//  Created by wuyx on 16/3/1.
//  Copyright © 2016年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WACore.h"
#import "WAIPush.h"
NS_ASSUME_NONNULL_BEGIN

@class WACoreProxy;

#define WALog(fmt,...) {\
if([WACoreProxy displayLog]){\
NSLog((@"WASDK LOG [(version %@) %s ]:" fmt), [WACoreProxy getSdkVer],__FUNCTION__, ##__VA_ARGS__);\
[WACoreProxy addLogWithString:[NSString stringWithFormat:(@"(version %@) %s ]:" fmt),[WACoreProxy getSdkVer],__FUNCTION__, ##__VA_ARGS__]];\
}\
}

#define WALogNb(fmt,...) {\
if([WACoreProxy displayLog]){\
NSLog((@"WASDK LOG [(version %@) %s ]:" fmt), [WACoreProxy getSdkVer],__FUNCTION__, ##__VA_ARGS__);\
[WACoreProxy addLogWithString:[NSString stringWithFormat:(@"(version %@) %s ]:" fmt),[WACoreProxy getSdkVer],__FUNCTION__, ##__VA_ARGS__]];\
}\
}

#define WALogImpt(fmt,...) {\
NSLog((@"WASDK LOG [(version %@) %s ]:" fmt), [WACoreProxy getSdkVer],__FUNCTION__, ##__VA_ARGS__);\
if([WACoreProxy isDebugMode]){\
[WACoreProxy addLogWithString:[NSString stringWithFormat:(@"(version %@) %s ]:" fmt),[WACoreProxy getSdkVer],__FUNCTION__, ##__VA_ARGS__]];\
}\
}

#define WAEventLog(fmt,...) {\
if([WACoreProxy displayLog]){\
NSLog((@"WASDK LOG [(version %@) %s ]:" fmt), [WACoreProxy getSdkVer],__FUNCTION__, ##__VA_ARGS__);\
[WACoreProxy addEventContentWithString:[NSString stringWithFormat:(@"" fmt),##__VA_ARGS__]];\
}\
}
/*!
 @discussion WACoreProxy
 - - -
 */
@interface WACoreProxy : NSObject
/*!
 @abstract 初始化
 */
+(void)init;


/*!
 @abstract 初始化(20221202新增初始化回调)
 */

+(void)initWithCompletionHandler:(void (^_Nullable)())completionHandler;


/*!
 @abstract 设置sdk类型 0 国外，1 国内
 */
+ (void)setSDKType:(NSInteger)sdkType;
/*!
 @abstract 获取sdk类型 0 国外，1 国内
 */
+ (NSInteger)getSDKType;
/*!
 @abstract 开启数据收集
 */
+(void)initAppEventTracker;
/*!
 @abstract 是否调试模式
 */
+(BOOL)isDebugMode;
/*!
 @abstract 设置调试模式
 */
+(void)setDebugMode:(BOOL)isDebugMode;

/*!
 @abstract 是否显示Log按钮
 */
+(BOOL)displayLog;
/*!
 @abstract 设置clientId
 */
+(void)setClientId:(NSString*)clientId;
/*!
 @abstract 获取userId
 */
+(NSString*)getUserId;
/*!
 @abstract 设置serverId
 @param serverId 服务器id
 */
+(void)setServerId:(NSString *)serverId;
/*!
 @abstract 获取serverId
 */

+(NSString*)getServerId;
/*!
 @abstract 设置level
 @param level 等级
 */
+(void)setLevel:(int)level;
/*!
 @abstract 获取level
 */
+(int)getLevel;
/*!
 @abstract 设置gameUserId
 @param gameUserId 游戏userId
 */
+(void)setGameUserId:(NSString*)gameUserId;
/*!
 @abstract 获取gameUserId
 */
+(NSString*)getGameUserId;
/*!
 @abstract 设置nickName
 @param nickName 游戏角色名
 */
+(void)setNickName:(NSString*)nickName;
/*!
 @abstract 获取nickName
 */
+(NSString*)getNickName;
/*!
 @abstract 获取userFlag
 */
+(void)setUserFlag:(NSString*)userFlag;
/*!
 @abstract 获取userFlag
 */
+(NSString*)getUserFlag;
/*!
 @abstract 获取WA Server url
 */
+(NSString*)getWaSdkServerUrl;
/*!
 @abstract 获取appKey
 */
+(NSString*)getAppKey;
/*!
 @abstract 获取Publish Channel
 */
+(NSString*)getPublishChannel;
/*!
 @abstract 获取Channel
 */
+(NSString*)getChannel;
/*!
 @abstract 获取appId
 */
+(NSString*)getAppID;
/*!
 @abstract 获取os
 */
+(NSString*)getOS;
/*!
 @abstract 获取SDK版本
 */
+(NSString*)getSdkVer;
/*!
 @abstract 获取SDK ID
 */
+(NSString *)getSdkId;
/*!
 @abstract 获取配置文件版本
 */
+(NSString*)getXmlConfigVer;
/*!
 @abstract 获取抽象层版本
 */
+(NSString*)getIntfVer;
/*!
 @abstract 获取SessionId
 */
+(NSString*)getSessionId;
/*!
 @abstract 隐私政策URL地址
 */
+(NSString *)getPrivacyUrl;
/*!
 @abstract 隐私政策更新时间
 */
+(NSString *)getPrivacyUpdateTime;
/*!
 @abstract 隐私政策内容界面
 */
+(void)showPrivacyUI:(void(^)(void))privacyUIClosedHandler;
+(void)showPrivacyUITitle:(NSString*)title url:(NSString*)url handle:(void(^)(void))privacyUIClosedHandler;

/*!
 @abstract 下面两个方法是关于Facebook deeplink, CP不用关注
 */
-(NSString*)getDeepLinkWithUrl:(NSURL*)url;

+(void)fetchDeferredAppLink:(void(^)(NSURL *url, NSError *error))handler;
/*!
 @abstract 获取后台配置参数
 */
+(WAParamConfigObj*)getParamConfig;
/*!
 @abstract 下面四个方法是关于打印日志的,CP不用关注
 */
+(void)addLogWithString:(NSString*)string;

+(void)addLogWithoutBtn:(NSString*)string;

+(void)addEventContentWithString:(NSString*)string;

+(void)eventLogWithPlatform:(NSString*)platform eventName:(NSString*)eventName parameters:(NSDictionary*)parameters color:(UIColor*)color;

/*!
 @discussion 处理UIApplicationDelegate的方法[-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions]传递过来的参数。
 */
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

#pragma mark 消息通知
/*!
@abstract 注册通知
*/
+ (void)application:(UIApplication *)application initPushWithDelegate:(id<UNUserNotificationCenterDelegate>)delegate API_AVAILABLE(ios(10.0));

/*!
 @abstract 调用过用户注册通知方法之后执行
 */
+ (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings API_AVAILABLE(ios(8.0));

/*!
 @abstract 获取deviceToken
 */
+ (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/*!
 @abstract 注册失败
 */
+ (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

#pragma mark IOS8 IOS9 Push Notification Receive
/*!
 @abstract 接收本地通知
 */
+ (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification;

/*!
 @abstract 接收远程通知
 */
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;

#pragma mark IOS10 Push Notification Receive
/*!
 @abstractApp 处于前台接收通知时
 */
+ (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler API_AVAILABLE(ios(10.0)) API_AVAILABLE(ios(10.0)) API_AVAILABLE(ios(10.0));

/*!
 @abstract 通知的点击事件
 */
+ (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler API_AVAILABLE(ios(10.0)) API_AVAILABLE(ios(10.0));

/*!
 程序进入后台
 @discussion 处理UIApplicationDelegate的方法[- (void)applicationDidEnterBackground:(UIApplication *)application]传递过来的参数。
 */
+ (void)applicationDidEnterBackground:(UIApplication *)application;

/*!
 程序将进入前台
 @discussion 处理UIApplicationDelegate的方法[- (void)applicationWillEnterForeground:(UIApplication *)application]传递过来的参数。
 */
+ (void)applicationWillEnterForeground:(UIApplication *)application;

/*!
 程序进入前台
 @discussion 处理UIApplicationDelegate的方法[- (void)applicationDidBecomeActive:(UIApplication *)application]传递过来的参数。
 */
+ (void)applicationDidBecomeActive:(UIApplication *)application;

/*!
 @discussion 处理UIApplicationDelegate的方法[-(BOOL)application:(UIApplication *)application
 openURL:(NSURL *)url
 sourceApplication:(NSString *)sourceApplication
 annotation:(id)annotation]传递过来的参数。
 */
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

+ (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray * _Nullable))restorationHandler API_AVAILABLE(ios(8.0));

//当一个新的场景被创建时调用，可以在这个方法中配置场景。
+ (void)scene:(UIScene *_Nonnull)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *_Nonnull)connectionOptions API_AVAILABLE(ios(13.0));
// 当场景被销毁时调用。
+ (void)sceneDidDisconnect:(UIScene *_Nonnull)scene  API_AVAILABLE(ios(13.0));
//当场景变成活跃状态时调用。
+ (void)sceneDidBecomeActive:(UIScene *_Nonnull)scene API_AVAILABLE(ios(13.0));
//当场景将要变成非活跃状态时调用。
+ (void)sceneWillResignActive:(UIScene *_Nonnull)scene API_AVAILABLE(ios(13.0));
//当应用程序即将进入前台时调用。
+ (void)sceneWillEnterForeground:(UIScene *_Nonnull)scene  API_AVAILABLE(ios(13.0));
//当应用程序进入后台时调用。
+ (void)sceneDidEnterBackground:(UIScene *_Nonnull)scene API_AVAILABLE(ios(13.0));
//当别的APP通过URL地址，打开我们的app时调用
+  (void)scene:(UIScene *_Nonnull)scene openURLContexts:(NSSet<UIOpenURLContext *> *_Nonnull)URLContexts API_AVAILABLE(ios(13.0));
+ (void)scene:(UIScene *)scene continueUserActivity:(NSUserActivity *)userActivity API_AVAILABLE(ios(13.0));

/*!
 @abstract 设备是否越狱
 */
+ (BOOL)isJailBreak;



@end
NS_ASSUME_NONNULL_END
