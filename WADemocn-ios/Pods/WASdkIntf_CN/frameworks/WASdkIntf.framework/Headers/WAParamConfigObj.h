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
@property(nonatomic) NSInteger enableBindAccount; // 绑定：  0-关闭， 1-打开  2-强制绑定（国内）
@property(nonatomic) NSInteger enableUnBindAccount; // 解绑：   0-关闭，1-打开
@property(nonatomic,copy)NSString* privacyUrl; // 隐私协议url
@property(nonatomic,copy)NSString* privacyUpdateTime; // 用户协议更新时间
@property(nonatomic,copy)NSString* userPolicyUrl; // 用户协议
@property(nonatomic,copy)NSString* childPrivacyUrl; // 儿童隐私协议地址



@property(nonatomic)NSInteger userCenterStatus; // 用户中心状态 0-关闭，1-打开
@property(nonatomic)NSInteger isRechargeCenterPay; // 是否开启充值中心支付：0-关闭，1-打开，2-仅安卓打开，3-仅IOS打开
@property(nonatomic,copy)NSString* rechargeCenterIcon; // 充值中心的支付图片URL
@property(nonatomic)NSInteger isOpenKefu; //  是否开启客服  0  关闭 1 启动机器人客服聊天界面   2 启动人工客服聊天界面   3 启动运营界面  4 展示全部FAQ菜单 5 展示全部FAQ菜单(无机器人客服)
@property (nonatomic, copy) NSDictionary *paymentTip; //付款信息提示  (complete:提示语字段的key)
@property(nonatomic)NSInteger logEventControl; //  事件日志开关  0  关闭 1 全部打开  2 仅android打开   3 仅ios打开  
@property(nonatomic)NSInteger loginRna; 	// 0 - 关闭，登录后不弹实名认证。   1 - 开启并强制   2开启不强制
@property(nonatomic)NSInteger paymentRna;   // 0 - 关闭，下单前不弹出实名认证。  1 - 开启并强制   2开启不强制

@property(nonatomic)NSInteger autoGuestLogin;       // 游客自动登录开关 0 - 开启，  1 - 关闭
@property(nonatomic)NSInteger guestLoginBindAlert;   // 游客登录绑定提醒 0 - 关闭，  1 - 开启


@end
