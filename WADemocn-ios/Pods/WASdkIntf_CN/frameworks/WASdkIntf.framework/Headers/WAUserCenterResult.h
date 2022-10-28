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
 @abstract characterId           （cp使用）
 */
@property(copy,nonatomic)NSString *characterId;

/*!
 @abstract shortUrl                 （cp使用）
 */
@property(copy,nonatomic)NSString *shortUrl;

/*
 uid                    （cp使用）
 */
@property(copy,nonatomic)NSString *uid;
/*!
 @abstract 用户中心文字内容 （cp使用）
 */
@property(copy,nonatomic)NSString *userCenterInfo;

@end

NS_ASSUME_NONNULL_END
