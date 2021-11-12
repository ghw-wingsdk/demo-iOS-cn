//
//  WACscProxy.h
//  WASdkIntf
//
//  Created by hank on 2018/6/7.
//  Copyright © 2018年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WACscProxy : NSObject

/*!
 @abstract 启动机器人客服界面
 @param showConversationFlag (0或1):是否为vip, 0:标示非VIP；1:表示：VIP此处为1时，将在机器人的聊天界面右上角，提供人工聊天的入口功能
 @param config 可为nil，自定义Dictionary信息可以在此处设置特定的Tag信息
 */
+ (void)showElva:(nonnull NSString *)showConversationFlag config:(nullable NSMutableDictionary *)config;

/*!
 @abstract 启动运营界面
 @param showConversationFlag (0或1):是否为vip, 0:标示非VIP；1:表示：VIP此处为1时，将在机器人的聊天界面右上角，提供人工聊天的入口功能
 @param config 可为nil，自定义Dictionary信息可以在此处设置特定的Tag信息
 */
+ (void)showElvaOP:(nonnull NSString *)showConversationFlag config:(nullable NSMutableDictionary *)config;

/*!
 @abstract 展示全部FAQ菜单
 @param config 可为nil，自定义Dictionary信息可以在此处设置特定的Tag信息
 */
+ (void)showFAQs:(nullable NSMutableDictionary *)config;

/*!
 @abstract 展示FAQ分类
 @param sectionPublishId FAQ Section的PublishID（可以在AIHelp 后台 中，从FAQs菜单下[Section]菜单，查看PublishID）
 @param config 可为nil，自定义Dictionary信息可以在此处设置特定的Tag信息
 */
+ (void)showFAQSection:(nonnull NSString *)sectionPublishId config:(nullable NSMutableDictionary *)config;

/*!
 @abstract 展示单条FAQ
 @param faqId FAQ的编号。打开AIHelp 后台中，在机器人→常见问题页面下找到指定FAQ的FAQ编号，注意：此FAQID不能填写客服后台未存在的FAQ编号
 @param config 可为nil，自定义Dictionary信息可以在此处设置特定的Tag信息
 */
+ (void)showSingleFAQ:(nonnull NSString *)faqId config:(nullable NSMutableDictionary *)config;

/*!
 @abstract 进入人工客服界面
 @param config 可为nil，自定义Dictionary信息可以在此处设置特定的Tag信息
 */
+ (void)showConversation:(nullable NSMutableDictionary *)config;

/*!
 @abstract 设置游戏名称信息
 @param name 设置后将显示在SDK中相关界面导航栏
 */
+ (void)setName:(nonnull NSString *)name;

/*!
 @abstract 设置SDK语言
 @param language 语言名称
 */
+  (void)setLanguage:(nonnull NSString *)language;

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
+  (void)setSDKInterfaceOrientationMask:(NSUInteger)interfaceOrientationMask;


/*!
@abstract 检测是否开启aihelp
*/
+ (BOOL) isOpenAiHelp;

+ (void) openAiHelp:(NSString * _Nonnull )language;

+ (void) openAiHelp:(NSString * _Nonnull )language isVip:(BOOL)vip;


@end
