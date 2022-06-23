//
//  WADeleteRequestModel.h
//  WASdkIntf
//
//  Created by lpw on 2022/6/9.
//  Copyright © 2022 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WADeleteRequestModel : NSObject
/*!
 @abstract 删除平台(Facebook,Apple)
 */
@property(copy,nonatomic)NSString *deletePlatform;
/*!
 @abstract 删除平台accessToken
 */
@property(copy,nonatomic)NSString *deleteToken;
@end

NS_ASSUME_NONNULL_END
