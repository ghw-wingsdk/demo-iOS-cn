//
//  GHWSDKBindingResult.h
//  GHWSdkUI
//
//  Created by wuyx on 15/9/22.
//  Copyright (c) 2015年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 @discussion WABindingResult 该类为绑定结果
 - - -
 */
@interface WABindingResult : NSObject
/*!
 @abstract 绑定平台userid
 */
@property(copy,nonatomic)NSString *userId;
/*!
 @abstract 绑定平台(Facebook,Apple)
 */
@property(copy,nonatomic)NSString *platform;
/*!
 @abstract 绑定平台accessToken
 */
@property(copy,nonatomic)NSString *accessToken;

/*!
 @abstract 绑定wa时，是邮箱绑定还是email绑定
 */
@property(copy,nonatomic)NSString *email;
@property(copy,nonatomic)NSString *mobile;

@end
