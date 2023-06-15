//
//  WAICsc.h
//  WASdkIntf
//
//  Created by hank on 2018/6/7.
//  Copyright © 2018年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WAICsc : NSObject





#pragma mark -- 判断是否加载aihelp模块
- (BOOL) isOpenAiHelp;

#pragma mark -- 打开aihelp V2版本
- (void) openAiHelpV2;


#pragma mark -- 设置SDK语言
- (void)setLanguage:(nonnull NSString *)language;


#pragma mark-- 判断是否可打开游戏评价-我要吐槽 aiheip入口
- (BOOL) isOpenGameReviewAiHelp;

#pragma mark -- 打开游戏评价-我要吐槽 进入aiheip入口
- (void) openGameReviewAiHelp;


@end
