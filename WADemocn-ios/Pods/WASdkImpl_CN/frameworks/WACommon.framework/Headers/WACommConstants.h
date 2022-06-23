//
//  GHWConstants.h
//  WASDK
//
//  Created by GHW-T-01 on 15/5/21.
//  Copyright (c) 2015年 Wuyx. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef WASDK_GHWConstants_h
#define WASDK_GHWConstants_h

#define WAWS(weakSelf)  __weak __typeof(self)weakSelf = self;



extern NSString *const WASDK_FLOW_TYPE_DEFAULT;
extern NSString *const WASDK_FLOW_TYPE_REBIND;

extern NSString *const WASDK_PARAM_KEY_SDK_VER;
extern NSString *const WASDK_PARAM_KEY_SDK_TYPE;
extern NSString *const WASDK_PARAM_KEY_RUN_PLATFORM;
extern NSString *const WASDK_PARAM_KEY_GAME_PLATFORM;
extern NSString *const WASDK_PARAM_KEY_REQUEST_FROM;
extern NSString *const WASDK_PARAM_KEY_SDK_ID;
extern NSString *const WASDK_PARAM_KEY_PATCH_ID;
extern NSString *const WASDK_PARAM_KEY_PATCH_VER;
extern NSString *const WASDK_PARAM_KEY_USER_ID;
extern NSString *const WASDK_PARAM_KEY_PUSER_ID;
extern NSString *const WASDK_PARAM_KEY_PUSER_ID_LOWER;
extern NSString *const WASDK_PARAM_KEY_PUSER_IDS;
extern NSString *const WASDK_PARAM_KEY_GAMEUSER_ID;
extern NSString *const WASDK_PARAM_KEY_NICK_NAME;
extern NSString *const WASDK_PARAM_KEY_PUSER_NAME;
extern NSString *const WASDK_PARAM_KEY_USER_FLAG;
extern NSString *const WASDK_PARAM_KEY_SERVER_ID;
extern NSString *const WASDK_PARAM_KEY_OS;
extern NSString *const WASDK_PARAM_KEY_OS_VERSION;
extern NSString *const WASDK_PARAM_KEY_MOBILE_MODEL;
extern NSString *const WASDK_PARAM_KEY_MODEL;
extern NSString *const WASDK_PARAM_KEY_LANGUAGE;
extern NSString *const WASDK_PARAM_KEY_CARRIER;
extern NSString *const WASDK_PARAM_KEY_WIFI;
extern NSString *const WASDK_PARAM_KEY_MAC;
extern NSString *const WASDK_PARAM_KEY_PACKAGE_ID;
extern NSString *const WASDK_PARAM_KEY_PACKAGE_VER_NAME;
extern NSString *const WASDK_PARAM_KEY_PACKAGE_VER_CODE;
extern NSString *const WASDK_PARAM_KEY_CRASH_TIME_STAMP;
extern NSString *const WASDK_PARAM_KEY_EXCEPTION_INFO;
extern NSString *const WASDK_PARAM_KEY_PLATFORM;
extern NSString *const WASDK_PARAM_KEY_ACCESSTOKEN;
extern NSString *const WASDK_PARAM_KEY_WASDK_TOKEN;
extern NSString *const WASDK_PARAM_KEY_OTS;
extern NSString *const WASDK_PARAM_KEY_IDFA;
extern NSString *const WASDK_PARAM_KEY_IDFV;
extern NSString *const WASDK_PARAM_KEY_CLIENT_ID;
extern NSString *const WASDK_PARAM_KEY_APP_ID;
extern NSString *const WASDK_PARAM_KEY_APP_KEY;
extern NSString *const WASDK_PARAM_KEY_APP_VER;
extern NSString *const WASDK_PARAM_KEY_PUBLISH_CHANNEL;
extern NSString *const WASDK_PARAM_KEY_DEVICE_TYPE;
extern NSString *const WASDK_PARAM_KEY_DEVICE_BRAND;
extern NSString *const WASDK_PARAM_KEY_DEVICE_NAME;
extern NSString *const WASDK_PARAM_KEY_PAGE_NO;
extern NSString *const WASDK_PARAM_KEY_PAGE;
extern NSString *const WASDK_PARAM_KEY_PAGE_SIZE;
extern NSString *const WASDK_PARAM_KEY_CHANNEL;
extern NSString *const WASDK_PARAM_KEY_BIND_TYPE;
extern NSString *const WASDK_PARAM_KEY_TRX_ID;
extern NSString *const WASDK_PARAM_KEY_ORDER_ID;
extern NSString *const WASDK_PARAM_KEY_ORDER_IDS;
extern NSString *const WASDK_PARAM_KEY_ORDER_ID_LIST;
extern NSString *const WASDK_PARAM_KEY_ORDER_DICTIONARY;
extern NSString *const WASDK_PARAM_KEY_TRX_TOKEN;
extern NSString *const WASDK_PARAM_KEY_STATUS;
extern NSString *const WASDK_PARAM_KEY_PAY_AMOUNT_MICROS;
extern NSString *const WASDK_PARAM_KEY_OSIGN;
extern NSString *const WASDK_PARAM_KEY_CURRENCY_CODE;
extern NSString *const WASDK_PARAM_KEY_EXT_INFO;
extern NSString *const WASDK_PARAM_KEY_EXTRA;
extern NSString *const WASDK_PARAM_KEY_EXT_VERIFYINFO;
extern NSString *const WASDK_PARAM_KEY_EXTRA_APPLEAUTHORIZATIONCODE;

extern NSString *const WASDK_PARAM_KEY_REALNAME ;
extern NSString *const WASDK_PARAM_KEY_IDCARD   ;

extern NSString *const WASDK_PARAM_KEY_REVOKE_PLATFORM;
extern NSString *const WASDK_PARAM_KEY_REVOKE_TOKEN;


extern NSString *const WASDK_PARAM_KEY_COLLECTION_INFO;
extern NSString *const WASDK_PARAM_KEY_SDKEXTINFO;
extern NSString *const WASDK_PARAM_KEY_ORDER_AMOUNT_MICROS;
extern NSString *const WASDK_PARAM_KEY_PRODUCT_ID;
extern NSString *const WASDK_PARAM_KEY_PRODUCT_NAME;
extern NSString *const WASDK_PARAM_KEY_PRODUCT_DESC;
extern NSString *const WASDK_PARAM_KEY_IAP_URL_PRO_LIST;
extern NSString *const WASDK_PARAM_KEY_IAP_URL_CREATE_ORDER;
extern NSString *const WASDK_PARAM_KEY_IAP_URL_NOTIFY_SERVER;
extern NSString *const WASDK_PARAM_KEY_SEND_SEQ;
extern NSString *const WASDK_PARAM_KEY_APPLE_ABNORMAL;

extern NSString *const WASDK_PARAM_KEY_URL_TYPE;
extern NSString *const WASDK_PARAM_KEY_LONG_URL;

extern NSString *const WASDK_PARAM_KEY_QUERY_TYPE;
extern NSString *const WASDK_PARAM_KEY_IS_REPORTDATA;

extern NSString *const WASDK_PARAM_KEY_REAL_NAME;
extern NSString *const WASDK_PARAM_KEY_ID_CARD;

extern NSString *const WASDK_PARAM_KEY_PRODUCT_LIST;
extern NSString *const WASDK_PARAM_KEY_GAME_CURRENCY_AMOUNT;
extern NSString *const WASDK_PARAM_KEY_PAY_CHANNEL;
extern NSString *const WASDK_PARAM_KEY_CHANNEL_PRODUCT_ID;
extern NSString *const WASDK_PARAM_KEY_ID;
extern NSString *const WASDK_PARAM_KEY_NAME;
extern NSString *const WASDK_PARAM_KEY_METHOD;
extern NSString *const WASDK_PARAM_KEY_LOGO_URL;

//关于Facebook邀请
extern NSString *const WASDK_PARAM_KEY_INVITER;
extern NSString *const WASDK_PARAM_KEY_INVITER_SERVERID;
extern NSString *const WASDK_PARAM_KEY_INVITEE;
extern NSString *const WASDK_PARAM_KEY_INVITEE_SERVERID;
extern NSString *const WASDK_PARAM_KEY_INVITEE_GAMEUSERID;
extern NSString *const WASDK_PARAM_KEY_INVITEE_USERID;
extern NSString *const WASDK_PARAM_KEY_INVITE_IDS;
extern NSString *const WASDK_PARAM_KEY_FB_INVITE_REWARD_EVENTNAME;
extern NSString *const WASDK_PARAM_KEY_FB_INVITE_REQUESTID;
extern NSString *const WASDK_PARAM_KEY_FB_INVITE_INVITEEIDS;

extern NSString *const WASDK_PARAM_KEY_INSTALL_APP_ID;
extern NSString *const WASDK_PARAM_KEY_DEEP_LINK_TYPE;
extern NSString *const WASDK_PARAM_KEY_FB_DEEPLINK;

extern NSString *const WASDK_RESULT_KEY_IAP_PRODUCT_IDS;
extern NSString *const WASDK_RESULT_KEY_IAP_ORDER_ID;
extern NSString *const WASDK_RESULT_KEY_IAP_CODE;
extern NSString *const WASDK_RESULT_KEY_IAP_DEF_AMT_MCR;
extern NSString *const WASDK_RESULT_KEY_IAP_DEF_CCY;
extern NSString *const WASDK_RESULT_KEY_IAP_VCA;
extern NSString *const WASDK_RESULT_KEY_IAP_VCCY;







//热更新
extern NSString *const WASDK_HUP_KEY_PATCH_VERSION;
extern NSString *const WASDK_HUP_KEY_SDK_ID;
extern NSString *const WASDK_HUP_KEY_SDK_VERSION;
extern NSString *const WASDK_HUP_KEY_APP_ID;
extern NSString *const WASDK_HUP_KEY_PUBLIST_APP_ID;
extern NSString *const WASDK_HUP_KEY_PUBLIST_APP_VER;
extern NSString *const WASDK_HUP_KEY_PLATFORM_ID;
extern NSString *const WASDK_HUP_KEY_CLIENT_OS;
extern NSString *const WASDK_HUP_KEY_CLIENT_OS_VERSION;
extern NSString *const WASDK_HUP_KEY_CLIENT_MODEL;
extern NSString *const WASDK_HUP_KEY_DEVICE_ID;
extern NSString *const WASDK_HUP_KEY_CLIENT_ID;
extern NSString *const WASDK_HUP_KEY_OTS;
extern NSString *const WASDK_HUP_KEY_USER_ID;
extern NSString *const WASDK_HUP_KEY_PATCH_ID;
extern NSString *const WASDK_HUP_KEY_PROGRESS;
extern NSString *const WASDK_HUP_KEY_STATUS;



//匿名登录时 从sdk后台获取的token 和 userid
extern NSString *const WASDK_GUEST_LOGIN_TOKEN;
extern NSString *const WASDK_GUEST_LOGIN_USERID;
extern NSString *const WASDK_GUEST_LOGIN_TOKEN_CACHE;
extern NSString *const WASDK_GUEST_LOGIN_USERID_CACHE;

//绑定账号 preUserId prePlatform
extern NSString *const WASDK_ACOUNT_BINDING_PREUSERID;
extern NSString *const WASDK_ACOUNT_BINDING_PREPLATFORM;

//绑定账号 支付订单购买日志
extern NSString *const WASDK_TIME_STAMP;
extern NSString *const WASDK_LOG_INFO;

// 消息推送
extern NSString *const WASDK_ACCESS_TOKEN;
extern NSString *const WASDK_MSG_ID;
extern NSString *const WASDK_ACTION_TYPE;

//extern NSString *const WASDK_IAP_URL_PROLIST;
//Apple商品消耗
extern NSString *const WASDK_IAP_URL_FINISH_TRANSACTION;
extern NSString *const WASDK_IAP_URL_NOTIFY_SERVER;
extern NSString *const WASDK_IAP_URL_CREATE_ORDER;
// 20200229
extern NSString *const WASDK_IAP_URL_APPLE_LAST_ORDER;
extern NSString *const WASDK_IAP_URL_APPLE_ABNORMAL_NOTIFY_SERVER;

extern NSString *const WASDK_REFRESH_TOKEN;
extern NSString *const WASDK_LOGIN_WAY;
extern NSString *const WASDK_ONE_CLICK_SIGIN;
extern NSString *const WASDK_ACCOUNT_BINDING;
extern NSString *const WASDK_ACCOUNT_CREATE;
extern NSString *const WASDK_BINDING_LIST;
extern NSString *const WASDK_BINDING_DISBIND;
extern NSString *const WASDK_PLATFORM_CONFIG;
extern NSString *const WASDK_FB_INVITE_CREATE;
extern NSString *const WASDK_FB_INVITE_REWARD;
extern NSString *const WASDK_FB_INVITE_INSTALL;
//获取补丁更新信息接口
extern NSString *const WASDK_PATCH_UPDATE_CHECK;
//补丁下载接口
extern NSString *const WASDK_PATCH_DOWNLOAD;
//更新补丁回调接口
extern NSString *const WASDK_PATCH_UPDATE_CALLBACK;
extern NSString *const WASDK_APW;

//闪退日志收集接口
extern NSString *const WASDK_CRASH_REPORT;

//数据收集接口
extern NSString *const WASDK_DATA_COLLECTION_URL;

extern NSString *const WASDK_APW_TRACKING;
extern NSString *const WASDK_FIRST_LAUNCH;

extern NSString *const WASDK_USER_LIST;

// 获取客户端未统计上报的订单列表
extern NSString *const WASDK_ORDER_LIST;
// 客户端订单购买日志收集
extern NSString *const WASDK_CLIENT_PURCHASE_LOG;
// 更新订单的客户端统计上报状态
extern NSString *const WASDK_CLT_STATUS_DONE;

// 获取产品及支付方式列表
extern NSString *const WASDK_PAY_URL_PRODUCTS;
// 提交web支付
extern NSString *const WASDK_PAY_URL_DO_PAY;
// web支付成功
extern NSString *const WASDK_PAY_URL_SUCCESS;
// web支付失败
extern NSString *const WASDK_PAY_URL_FAILURE;
// web支付取消
extern NSString *const WASDK_PAY_URL_CANCEL;

// 手机号/帐号登录接口
extern NSString *const WASDK_LOGIN_URL_SIGN_IN;
// 手机号注册接口
extern NSString *const WASDK_LOGIN_URL_SIGN_UP;
// 发送验证码接口
extern NSString *const WASDK_LOGIN_URL_SEND_VALIDATE_CODE;
// 验证验证码接口
extern NSString *const WASDK_LOGIN_URL_VALIDATE_CODE;
// 更新密码接口
extern NSString *const WASDK_LOGIN_URL_UPDATE_PWD;
// 游客/帐号绑定手机
extern NSString *const WASDK_LOGIN_URL_BIND_MOBILE;
// 免密码登录接口
extern NSString *const WASDK_LOGIN_URL_FAST_LOGIN;
// 使用TOKEN实名验证
extern NSString *const WASDK_REAL_NAME_AUTHENTICATION;

// 消息推送
// 更新第三方消息服务的accessToken
extern NSString *const WASDK_LOGIN_URL_MESSAGE_REFRESH_TOKEN;
// 客户端拉取消息
extern NSString *const WASDK_LOGIN_URL_MESSAGE_CLIENT_PULL;
// 消息推送回执
extern NSString *const WASDK_LOGIN_URL_MESSAGE_SEND_RECEIPT;
// 消息打开确认
extern NSString *const WASDK_LOGIN_URL_MESSAGE_OPEN_MESSAGE_CONFIRM;

// 获取视频广告列表
extern NSString *const WASDK_AD_URL_GET_AD_LIST;
// 提交广告展示事件
extern NSString *const WASDK_AD_URL_SUBMIT_SHOW_EVENT;
// 更新展示广告状态
extern NSString *const WASDK_AD_URL_UPDATE_STATUS;
// 充值中心-账号生成
extern NSString *const WASDK_AD_URL_GAME_CREATE_WINGA_ACCOUNT;

//充值中心-短链接申请
extern NSString *const WASDK_PAYCENTER_URL_GET_SHORT_LINK;

// 玩家身份确认接口
extern NSString *const WASDK_ACCOUNT_DELETE_IDENTITY_CHECK;

// 申请注销账号
extern NSString *const WASDK_ACCOUNT_DELETE_DELETE_APPLY;

// 撤销注销账号申请
extern NSString *const WASDK_ACCOUNT_DELETE_DELETE_REVOCATION;

extern NSString *const WASDK_FB_INVITE_FROM_USERID;
extern NSString *const WASDK_FB_INVITE_TO_USERID;
extern NSString *const WASDK_FB_INVITE_SERVERID;
extern NSString *const WASDK_FB_INVITE_ACTIONTYPE;
extern NSString *const WASDK_FB_INVITE_GS_INVITE;
extern NSString *const WASDK_FB_INVITE_APPID;

extern const int WASDK_VALUE_KEY_STATUS_SUCCESS;//回传给客户端的代码值，表示支付成功
extern const int WASDK_VALUE_KEY_STATUS_FAILED;//回传给客户端的代码值，表示支付失败
extern const int WASDK_VALUE_KEY_STATUS_PURCHASE_CANCELED;//回传给客户端的代码值，表示支付取消
extern const int WASDK_VALUE_KEY_STATUS_PURCHASE_SUCCESS_WITHOUT_REPORT;//回传给客户端的代码值 表示支付成功但是没有上报或者上报失败了
extern const int WASDK_VALUE_KEY_STATUS_PURCHASE_UNCONSUME;//商品未消耗
extern const int WASDK_VALUE_KEY_STATUS_CREATE_ORDER_FAILED;//创建订单失败

extern const int WASDK_VALUE_KEY_STATUS_VAILD_FAIL;//后台验证失败表示验证失败
extern NSString *const WASDK_VALUE_KEY_STATUS_NOTIFY_FAIL;


extern NSString *const WASDK_STATUS_UNKNOWN;
extern NSString *const WASDK_STATUS_UNKNOWN_1;

extern NSString *const WASDK_CACHE_KEY_FB_APP_SECRET;

extern NSString *const WASDK_CACHE_KEY_TTA_TAG;






@interface WACommConstants : NSObject {
    
}
#endif
@end
