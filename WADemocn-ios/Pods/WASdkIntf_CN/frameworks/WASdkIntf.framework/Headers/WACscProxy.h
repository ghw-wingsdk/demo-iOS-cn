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
 @abstract 设置SDK语言
 @param language 语言名称
 */
+  (void)setLanguage:(nonnull NSString *)language;

/*!
@abstract 检测是否开启aihelp
*/
+ (BOOL) isOpenAiHelp;

/*!
 @abstract 打开aihelp V2版本
 */
+ (void) openAiHelpV2;


/*!
@abstract 判断是否可打开游戏评价-我要吐槽 aiheip入口
*/
+ (BOOL) isOpenGameReviewAiHelp;


/*!
@abstract 打开游戏评价-我要吐槽 进入aiheip入口
*/
+ (void) openGameReviewAiHelp;




@end
