//
//  WAChannelProduct.h
//  WASdkIntf
//
//  Created by LPW on 2019/9/17.
//  Copyright © 2019 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WAChannelProduct : NSObject
@property(nonatomic, strong) NSString *channel; 		  //渠道名称
@property(nonatomic, strong) NSString *productIdentifier; //平台商品id
@property(nonatomic, strong) NSString *localeCurrencyCode; //当前币种code USD 、CNY
@property(nonatomic, strong) NSString *localFormattedPrice;//格式化价格 $999.99  ¥6,498.00
@property(nonatomic, strong) NSDecimalNumber * price ;    //价格 999.99         6498

@end

NS_ASSUME_NONNULL_END
