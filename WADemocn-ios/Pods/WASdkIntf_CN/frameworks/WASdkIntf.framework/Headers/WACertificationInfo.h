//
//  WACertificationInfo.h
//  WASdkIntf
//
//  Created by LPW on 2019/12/30.
//  Copyright © 2019 GHW-T-01. All rights reserved.
//  查询用户实名信息返回model

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WACertificationInfo : NSObject
/*用户实名认证状态
 * -1  未开启
 * 0   已实名
 * 1   未实名
 * 2   已实名-未成年()
 * 3   认证中(2.3.0增加)

 */
@property NSInteger userRealNameStatus;


/*用户实名认证状态
* -1  未开启实名认证 或者  未实名
*/
@property NSInteger age;


@end

NS_ASSUME_NONNULL_END
