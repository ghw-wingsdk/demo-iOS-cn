//
//  WAParamConfigObj.h
//  WASDKUI
//
//  Created by wuyx on 15/11/25.
//  Copyright © 2015年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WAParamConfigObj : NSObject<NSCoding,NSCopying>
@property(nonatomic)BOOL enableExtend;
@property(nonatomic)BOOL enableHotPatch;
@property(nonatomic,copy)NSString* afadAppKey;
@property(nonatomic,copy)NSString* fbSecretKey;
@property(nonatomic,copy)NSString* rewardType;
@property(nonatomic)float reorderLimitTime;
@property(nonatomic) NSInteger paymentReportTime;
@property(nonatomic) float heartbeatIntervalTime;
@property(nonatomic)int eventCacheNumberLimit;
@property(nonatomic)int eventCacheTimeLimit;
@property(nonatomic,copy)NSString* eventTypeImmediate;
@property(nonatomic,strong)NSNumber* enableNewAccount;
@property(nonatomic,strong)NSNumber* enableChangeAccount;
@property(nonatomic,strong)NSNumber* isTestDevice;
@property(nonatomic,copy)NSString* userAgreementUrl;
@property(nonatomic,strong)NSNumber* uploadPurchaseLog;
@property(nonatomic) NSInteger adVideoCacheCount;
@property(nonatomic) NSInteger enableBindAccount; // 绑定：  0-关闭， 1-打开
@property(nonatomic) NSInteger enableUnBindAccount; // 解绑：   0-关闭，1-打开
@property(nonatomic,copy)NSString* privacyUrl; // 用户协议url
@property(nonatomic,copy)NSString* privacyUpdateTime; // 用户协议更新时间

@end
