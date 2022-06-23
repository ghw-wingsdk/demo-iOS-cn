//
//  WADeleteResult.h
//  WASdkIntf
//
//  Created by lpw on 2022/6/14.
//  Copyright © 2022 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WADeleteResult : NSObject
@property(copy,nonatomic)NSString *apply_date; //申请时间（游戏时区）
@property(copy,nonatomic)NSString *delete_date; //注销时间（游戏时区）
@end

NS_ASSUME_NONNULL_END
