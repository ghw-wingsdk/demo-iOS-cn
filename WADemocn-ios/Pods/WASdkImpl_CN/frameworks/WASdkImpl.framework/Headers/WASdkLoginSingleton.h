//
//  WASDKSingletonHandler.h
//  WASdkImplUI
//
//  Created by wuyx on 16/3/4.
//  Copyright © 2016年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WASdkIntf/WASdkIntf.h>
#import <WACommon/WACommon.h>
@interface WASdkLoginSingleton : NSObject

//创建单例
+(instancetype)shareInstance;
//获取示例 有可能为空
+(instancetype)getInstance;
//设置当前登录结果
-(void)setCurrentLoginResult:(WALoginResult*)loginResult;
//获取当前登录结果
+(WALoginResult*)getCurrentLoginResult;

//弹出登录界面
+(void)login:(id<WALoginViewDelegate>)delegate cacheEnabled:(BOOL)cacheEnabled;
//移除登录界面
+(void)hide;
//设置当前平台
+(void)setCurrentLoginPlatform:(NSString *)platform;
+(NSString*)getCurrentLoginPlatform;

// 针对wa登录（邮箱和手机登录）
-(void)loginPlatform:(NSString*)platform WithExtInfo:(NSString *)extInfo delegate:(id<WALoginDelegate>)delegate;

@property(nonatomic)BOOL switchWaLogin; //如果是切换wa账号，需要处理UI
@end
