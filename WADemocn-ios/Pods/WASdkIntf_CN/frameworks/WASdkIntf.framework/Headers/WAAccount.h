//
//  WASDKAccount.h
//  WASDKUI
//
//  Created by wuyx on 15/11/30.
//  Copyright © 2015年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 @discussion WAAccount 该类为账户类
 - - -
 */
@interface WAAccount : NSObject
/*!
 @abstract 第三方平台openId
 */
@property(nonatomic,copy)NSString* pUserId;//第三方平台openId

/*!
 @abstract 绑定平台标识 FACEBOOK、APPLE、WINGA
 */
@property(nonatomic,copy)NSString* platform;

@property (nonatomic, strong) NSString *mobile;//wa平台才有此字段

@property (nonatomic,strong) NSString * email;//WA平台且已绑定邮箱时返回 20230703  绑定帐号列表 V4(增加邮箱返回)


+(WAAccount*)parserWithDict:(NSDictionary*)dict;
+(NSArray*)parserWithArray:(NSArray*)arr;
@end
