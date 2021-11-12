//
//  WAICsc.h
//  WASdkIntf
//
//  Created by hank on 2018/6/7.
//  Copyright © 2018年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WAICsc : NSObject

#pragma mark - 启动机器人客服界面
- (void)showElva:(nonnull NSString *)showConversationFlag config:(nullable NSMutableDictionary *)config;

#pragma mark - 启动运营界面
- (void)showElvaOP:(nonnull NSString *)showConversationFlag config:(nullable NSMutableDictionary *)config;

#pragma mark 展示全部FAQ菜单
- (void)showFAQs:(nullable NSMutableDictionary *)config;

#pragma mark 展示FAQ分类
- (void)showFAQSection:(nonnull NSString *)sectionPublishId config:(nullable NSMutableDictionary *)config;

#pragma mark 展示单条FAQ
- (void)showSingleFAQ:(nonnull NSString *)faqId config:(nullable NSMutableDictionary *)config;

#pragma mark - 进入人工客服界面
- (void)showConversation:(nullable NSMutableDictionary *)config;

#pragma mark -- 设置游戏名称信息
- (void)setName:(nonnull NSString *)name;

#pragma mark -- 设置SDK语言
- (void)setLanguage:(nonnull NSString *)language;
#pragma mark -- 设置SDK方向
/*
 
 UIInterfaceOrientationMaskPortrait,         // 设备(屏幕)直立
 UIInterfaceOrientationMaskLandscapeLeft,    // 设备(屏幕)向左横置
 UIInterfaceOrientationMaskLandscapeRight,   // 设备(屏幕)向右橫置
 UIInterfaceOrientationMaskPortraitUpsideDown,// 设备(屏幕)直立，上下顛倒
 UIInterfaceOrientationMaskLandscape,        // 设备(屏幕)横置,包含向左和向右
 UIInterfaceOrientationMaskAll,              // 设备(屏幕)可以支持上下左右四个方向
 UIInterfaceOrientationMaskAllButUpsideDown  //设备(屏幕)可以支持上左右三个个方向，但不支持直立上下颠倒

 */
- (void)setSDKInterfaceOrientationMask:(NSUInteger)interfaceOrientationMask;

#pragma mark -- 判断是否加载aihelp模块
- (BOOL) isOpenAiHelp;

#pragma mark -- 打开aihelp
- (void) openAiHelp:(NSString * _Nonnull )language;


#pragma mark -- 打开aihelp 扩展是否为vip
- (void) openAiHelp:(NSString * _Nonnull )language isVip:(BOOL)vip;


@end
