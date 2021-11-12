//
//  GHWConstants.h
//  GHWSdk
//
//  Created by GHW-T-01 on 15/5/21.
//  Copyright (c) 2015年 Wuyx. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef WA_Constants_h
#define WA_Constants_h


extern NSString *const WA_MODULE_USR;//用户模块
extern NSString *const WA_MODULE_PAY;//支付模块
extern NSString *const WA_MODULE_TRA;//数据收集模块
extern NSString *const WA_MODULE_SOC;//社交模块
extern NSString *const WA_MODULE_APW;//应用墙模块
extern NSString *const WA_MODULE_CORE;//公共模块
extern NSString *const WA_MODULE_HUP;//热更新模块
extern NSString *const WA_MODULE_PUSH;//消息推送模块
extern NSString *const WA_MODULE_AD; //广告模块
extern NSString *const WA_MODULE_CSC;//客服系统

extern NSString *const WA_PLATFORM_FACEBOOK;
extern NSString *const WA_PLATFORM_APPLE;
extern NSString *const WA_PLATFORM_APPSFLYER;
extern NSString *const WA_PLATFORM_CHARTBOOST;
extern NSString *const WA_PLATFORM_WEBPAY;
extern NSString *const WA_PLATFORM_WINGA;
extern NSString *const WA_PLATFORM_BOACOMPRA;
extern NSString *const WA_PLATFORM_VK;
extern NSString *const WA_PLATFORM_WECHAT;
extern NSString *const WA_PLATFORM_QQ;
extern NSString *const WA_PLATFORM_SIGNINWITHAPPLE;
extern NSString *const WA_PLATFORM_FIREBASE;



extern NSString *const WA_PLATFORM_QQ_CN_NAME;
extern NSString *const WA_PLATFORM_SIGNINWITHAPPLE_CN_NAME;
extern NSString *const WA_PLATFORM_WECHAT_CN_NAME;
extern NSString *const WA_PLATFORM_WINGA_CN_NAME;
extern NSString *const WA_CONSTANT_GUEST_CN_NAME;




extern NSString *const WA_PLATFORM_HUP;
extern NSString *const WA_PLATFORM_APW;
extern NSString *const WA_PLATFORM_PUSH;
extern NSString *const WA_PLATFORM_TWITTER;
extern NSString *const WA_PLATFORM_INSTAGRAM;
extern NSString *const WA_PLATFORM_AIHELP;


extern NSString *const WA_CONSTANT_GUEST;



extern NSString *const WA_XML_NODE_CONFIG;
extern NSString *const WA_XML_NODE_VERSION;
extern NSString *const WA_XML_NODE_SUPPORTS;
extern NSString *const WA_XML_NODE_COMP;

extern NSString *const WA_XML_ATTRIBUTE_KEY_VAL;
extern NSString *const WA_XML_ATTRIBUTE_KEY_MODULE;
extern NSString *const WA_XML_ATTRIBUTE_KEY_PLAF;
extern NSString *const WA_XML_ATTRIBUTE_KEY_VALUE;
extern NSString *const WA_XML_ATTRIBUTE_KEY_DESC;

//登录流程
extern const int WA_LOGIN_FLOW_TYPE_DEFAULT;
extern const int WA_LOGIN_FLOW_TYPE_REBIND;

//facebook permission
extern NSString *const WA_FB_PERMISSION_PUBLIC_PROFILE;
extern NSString *const WA_FB_PERMISSION_PUBLISH_ACTIONS;
extern NSString *const WA_FB_PERMISSION_USER_FRIENDS;
extern NSString *const WA_FB_PERMISSION_EMAIL;


//facebook action type
extern NSString *const WA_FB_ACTION_TYPE_NONE;
extern NSString *const WA_FB_ACTION_TYPE_SEND;
extern NSString *const WA_FB_ACTION_TYPE_ASKFOR;
extern NSString *const WA_FB_ACTION_TYPE_INVITE;

extern NSString *const WA_REQUEST_TYPE_SEND;
extern NSString *const WA_REQUEST_TYPE_ASKFOR;
extern NSString *const WA_REQUEST_TYPE_INVITE;
extern NSString *const WA_REQUEST_TYPE_REQUEST;


extern NSString *const WA_APPLE_IAPResultNotification;

//下面四个通知分别是绑定成功、绑定失败、解绑成功、解绑失败。当绑定有结果之后（无论成功失败），将回传一个WABindingResult实例。当解绑有结果（无论成功失败），将回传一个WAAccount实例。
extern NSString *const WABindDidSucceedNotification;//绑定成功
extern NSString *const WABindDidFailNotification;//绑定失败
extern NSString *const WAUnbindDidSucceedNotification;//解绑成功
extern NSString *const WAUnbindDidFailNotification;//解绑失败

// SDK类型
extern const int WA_SDK_TYPE_FR; // 国外
extern const int WA_SDK_TYPE_CN; // 国内


// qq登录通知
extern NSString *const WAQQLoginSuccessedNSNotification;
extern NSString *const WAQQkLoginFailedNSNotificationName;
extern NSString *const WAQQkLoginCancelledNSNotificationName;
extern NSString *const WAQQkGetUnionIDNSNotificationName;
extern NSString *const WAQQkLogoutSuccessedNSNotificationName;



//隐私协议地址
extern NSString *const WAPrivacyAgreementURL_UserAgreement;         //用户协议
extern NSString *const WAPrivacyAgreementURL_PrivacyPolicy;         //隐私地址
extern NSString *const WAPrivacyAgreementURL_ChildrenPrivacyPolicy; //儿童隐私协议



@interface WAConstants : NSObject {
    
}
#endif
@end
