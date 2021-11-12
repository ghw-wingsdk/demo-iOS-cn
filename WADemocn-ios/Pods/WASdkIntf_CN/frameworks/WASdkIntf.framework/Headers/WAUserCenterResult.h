//
//  WAUserCenterResult.h
//  WASdkIntf
//
//  Created by hank on 2019/5/8.
//  Copyright © 2019年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WAUserCenterResult : NSObject<NSCoding,NSCopying>

/*!
 @abstract 状态码
 */
@property NSInteger code;
/*!
 @abstract 结果描述
 */
@property(copy,nonatomic)NSString *msg;
/*!
 @abstract 用户中心文字内容
 */
@property(copy,nonatomic)NSString *userCenterInfo;
/*!
 @abstract 用户名
 */
@property(copy,nonatomic)NSString *userName;
/*!
 @abstract 初始密码
 */
@property(copy,nonatomic)NSString *password;

/*!
 @abstract 充值中心域名
 */
@property(copy,nonatomic)NSString *rechargeCenterDomain;

/*!
 @abstract 服务器名
 */
@property(copy,nonatomic)NSString *serverName;

/*!
 @abstract 游戏名称
 */
@property(copy,nonatomic)NSString *appName;



@end

NS_ASSUME_NONNULL_END
