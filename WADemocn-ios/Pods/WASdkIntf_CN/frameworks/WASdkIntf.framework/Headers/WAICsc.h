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

@end
