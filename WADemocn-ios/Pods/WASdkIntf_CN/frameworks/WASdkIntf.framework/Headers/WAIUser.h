//
//  WAIUser.h
//  WASdkIntfUI
//
//  Created by GHW-T-01 on 16/3/1.
//  Copyright © 2016年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WASdkIntf/WAUserProxy.h>
#import <WASdkIntf/WASdkIntf.h>
@interface WAIUser : NSObject
-(void)setLoginFlowType:(int)flowType;
-(int)getLoginFlowType;
-(WAAppUser*)getAccountInfo;
-(void)loginWithExtInfo:(NSString *)extInfo delegate:(id<WALoginDelegate>)delegate;
-(void)logout;
-(void)bindingAccountWithExtInfo:(NSString*)extInfo delegate:(id<WAAccountBindingDelegate>)delegate;
-(void)bindingAccountWithPlatform:(NSString *const)platform bindingResult:(WABindingResult*)bindingResult extInfo:(NSString *)extInfo  delegate:(id<WAAccountBindingDelegate>)delegate;

-(void)queryBoundAccountWithCompleteBlock:(void(^)(NSError* error,NSArray<WAAccount *>* accounts))block;
-(void)unBindAccountWithPlatform:(NSString *const)platform platformUserId:(NSString *)pUserId completeBlock:(void (^)(NSError *))completeBlock;
-(void)switchAccountWithPlatform:(NSString *const)platform completeBlock:(void (^)(NSError *, WALoginResult *))completeBlock;
-(void)createNewAccountWithCompleteBlock:(void(^)(NSError* error,WALoginResult* result))completeBlock;
-(void)login:(id<WALoginViewDelegate>)delegate cacheEnabled:(BOOL)cacheEnabled;
-(void)hide;
-(void)clearLoginCache;
-(void)openAccountManager:(id<WAAcctManagerDelegate>)delegate;

-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

-(void)applicationDidBecomeActive:(UIApplication *)application;

-(void)applicationWillEnterForeground:(UIApplication *)application;

-(void)applicationDidEnterBackground:(UIApplication *)application;

-(BOOL)application:(UIApplication *)application
           openURL:(NSURL *)url
 sourceApplication:(NSString *)sourceApplication
        annotation:(id)annotation;

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url;

-(void)loginWithResult:(WALoginResult*)result delegate:(id<WALoginDelegate>)delegate;
-(void)loginWithResult:(WALoginResult*)result extInfo:(NSString*)extInfo delegate:(id<WALoginDelegate>)delegate;

-(void)setCurrentLoginPlatform:(NSString *const)platform;
-(NSString*)getCurrentLoginPlatform;
-(WALoginResult*)getCurrentLoginResult;

-(void)didUserLogin:(void(^)(NSError* error,BOOL didLogin))block;

- (void)getUserCenterNotice:(id<WAUserCenterNoticeDelegate>)delegate;

- (void)showUserCenterNoticeUI:(id<WAUserCenterNoticeUIDelegate>)delegate;

-(void)queryUserCertificationInfo:(void(^)(WACertificationInfo *certificationInfo,NSError *error))callBackBlock;

//查询是否已绑定第三方账号 (国内)
-(BOOL)isBoundPlatformAccount;

/*!
 @discussion 检测是否可以打开账号绑定、账号切换、实名认证接口
			 如果返回NO，没有登录  canOpenRealNameAuth 已经实名
 */
- (BOOL)canOpenAccoutbind;
- (BOOL)canOpenAccoutSwitch;
- (BOOL)canOpenRealNameAuth;

/*!
@discussion 打开账户绑定界面
*/
- (void)openAccoutbindManager:(void(^)(NSError* error,WABindingResult  * bindResult))block;


/*!
@discussion 打开账户切换界面
*/
- (void)openAccoutSwithchManager:(void(^)(NSError* error,WALoginResult  * loginResult))block;


/*!
@discussion 打开实名认证界面
*/
- (void)openRealNameAuthManager:(void(^)(NSError* error,WACertificationInfo  * certificationInfo))block;



/*!
@discussion 打开as评分弹框
*/
- (void)openReview;


/*!
@discussion 打开idfa弹框授权 status状态与 ATTrackingManagerAuthorizationStatus 一致
 */
- (void)openTTAAuthorizationWithCompletionHandler:(void(^)(NSError* error,NSUInteger status))block;

/*!
@discussion 隐私协议弹框
 */
- (void)openPrivacyAgreementWindow:(void(^)(NSError* error,NSUInteger status))block;





//****************************************账号删除有关接口*********************************************************************
/*!
@discussion 检测是否可调用玩家身份确认接口
 */
- (BOOL) canCheckIdentity;



//玩家身份确认接口
- (void)identityCheck:(NSString*)realName idCard:(NSString*)idCard completeBlock:(void(^)(NSError* error))block;

//删除账号授权,拿到第三方的token信息，如 signinwithapple拿到authorizationCode
-(void)deleteAccounAuthorizationWithPlatform:(NSString*)platform completeBlock:(void(^)(NSError* error,WADeleteRequestModel*deleteResult))block;

/*!
@discussion 账号删除
 */
- (void)requestDeleteAccout:(WADeleteRequestModel*)deleteResult completeBlock:(void(^)(NSError* error,WADeleteResult*result))completeBlock;
// 取消删除
-(void)cancelRequestDeleteAccoutWithUserid:(NSString*)userid callback:(void (^)(NSError *))completeBlock;



- (void)requestDeleteAccoutUI:(void(^)(NSError *error, NSUInteger status))completeBlock;




/*!
@discussion 打开游戏评分功能
 */
- (void)openGameReview:(void(^)(OpenGameReviewState status))block;


@end
