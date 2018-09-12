//
//  WACore.h
//  WASdkIntfUI
//
//  Created by wuyx on 16/3/1.
//  Copyright © 2016年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class WAParamConfigObj;
@interface WACore : NSObject
-(void)initialize;
-(void)initAppEventTracker;
-(void)setSDKType:(NSInteger)sdkType;
-(NSInteger)getSDKType;
-(BOOL)isDebugMode;
-(void)setDebugMode:(BOOL)isDebugMode;
-(BOOL)displayLog;
-(void)setClientId:(NSString*)clientId;
-(NSString*)getUserId;
-(void)setServerId:(NSString *)serverId;
-(NSString*)getGameUserId;
-(NSString*)getServerId;
-(void)setLevel:(int)level;
-(int)getLevel;
-(void)setGameUserId:(NSString*)gameUserId;
-(void)setNickName:(NSString*)nikeName;
-(void)setPuserName:(NSString *)puserName;
-(void)setUserFlag:(NSString*)userFlag;
-(NSString*)getPuserName;
-(NSString*)getNickName;
-(NSString*)getUserFlag;
-(void)addLogWithString:(NSString*)string;
-(void)addLogWithoutBtn:(NSString*)string;
-(NSString*)getSdkVersion;
-(NSString*)getWaSdkServerUrl;
-(NSString*)getAppKey;
-(NSString*)getPublishChannel;
-(NSString*)getChannel;
-(NSString*)getAppID;
-(NSString*)getOS;
-(NSString*)getSdkVer;
-(NSString*)getSdkId;
-(NSString*)getSessionId;
-(NSString *)getPrivacyUrl;
-(NSString *)getPrivacyUpdateTime;
-(void)showPrivacyUI:(void(^)(BOOL isClose))handler;
-(NSString*)getDeepLinkWithUrl:(NSURL*)url;
-(WAParamConfigObj*)getParamConfig;
-(void)fetchDeferredAppLink:(void(^)(NSURL *url, NSError *error))handler;
-(void)addEventContentWithString:(NSString*)string;
-(void)eventLogWithPlatform:(NSString*)platform eventName:(NSString*)eventName parameters:(NSDictionary*)parameters color:(UIColor*)color;
/** 检测设备是否越狱 */
- (BOOL)isJailBreak;
@end
