//
//  WAUserProxy.h
//  WASdkIntfUI
//
//  Created by GHW-T-01 on 16/3/1.
//  Copyright © 2016年 GHW-T-01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WASdkIntf/WALoginResult.h>
#import <WASdkIntf/WABindingResult.h>
#import <WASdkIntf/WAAccount.h>
#import <WASdkIntf/WAUserCenterResult.h>
#import <WASdkIntf/WAAppUser.h>
#import <WASdkIntf/WACertificationInfo.h>
#import <WASdkIntf/WADeleteRequestModel.h>
#import <WASdkIntf/WADeleteResult.h>

typedef NS_ENUM(NSInteger, OpenGameReviewState) {
    OpenGameReviewStateReject=0,           //游戏评价结果：不，谢谢！
    OpenGameReviewStateOpenAiHelp,       //游戏评价结果：我要提意见
    OpenGameReviewStateOpentReview,       //游戏评价结果：提交好评(无法获取用户是否点击评分以及具体的评分分数)
    OpenGameReviewStateError            //打开游戏评价失败,后台没有开启游戏评价开关

};
/*!
 @discussion 登录协议
 - - -
 */
@protocol WALoginDelegate <NSObject>

@required
/*!
 @abstract 登录成功
 @param result 登录结果
 */
-(void)loginDidCompleteWithResults:(WALoginResult*)result;
/*!
 @abstract 登录失败
 @param result 登录的用户信息 注:这不是登录结果,由于登录失败所以userId是空的.但如果第三方平台(Facebook,Apple)授权成功,pUserId,pToken,extends不为空,可用于提示用户.
 @param error 错误
 */
-(void)loginDidFailWithError:(NSError*)error andResult:(WALoginResult*)result;
@optional
/*!
 @abstract 用户取消登录
 @param result 登录的账户信息 (注:返回的result只有platform有值)
 */
-(void)loginDidCancel:(WALoginResult*)result;

@end

/*!
 @discussion 账户绑定协议
 - - -
 */
@protocol WAAccountBindingDelegate <NSObject>

@required
/*!
 @abstract 绑定成功
 @param result 绑定的账户信息
 */
-(void)bindingDidCompleteWithResult:(WABindingResult*)result;
/*!
 @abstract 绑定失败
 @param result 绑定的账户信息
 @param error 错误
 */
-(void)bindingDidFailWithError:(NSError*)error andResult:(WABindingResult*)result;
@optional
/*!
 @abstract 绑定取消
 @param result 绑定的账户信息(注:返回的result只有platform有值)
 */
-(void)bindingDidCancel:(WABindingResult*)result;
@end

/*!
 @discussion 登录界面协议
 - - -
 */
@protocol WALoginViewDelegate <NSObject>

@required
/*!
 @abstract 登录成功
 @param result 登录的用户信息
 */
-(void)loginViewDidCompleteWithResult:(WALoginResult*)result;
/*!
 @abstract 登录失败
 @param result 登录的用户信息 注:这不是登录结果,由于登录失败所以userId是空的.但如果第三方平台(Facebook,Apple)授权成功,pUserId,pToken,extends不为空,可用于提示用户.
 @param error 错误
 */
-(void)loginViewDidFailWithError:(NSError*)error andResult:(WALoginResult*)result;
@optional
/*!
 @abstract 用户取消登录
 @param result 登录的用户信息（只有platform非空）.
 */
-(void)loginViewDidCancel:(WALoginResult*)result;
@end




/*!
 @discussion 账号管理界面协议
 - - -
 */
@protocol WAAcctManagerDelegate <NSObject>

@required
/*!
 @abstract 新建账户回调接口
 @param result 新建账户的账户信息
 */
-(void)newAcctDidCompleteWithResult:(WALoginResult*)result;
/*!
 @abstract 切换账户回调接口
 @param result 切换账户的账户信息
 */
-(void)switchAcctDidCompleteWithResult:(WALoginResult*)result;

/*!
@abstract 绑定账号回调接口
@param bindResult 绑定账号信息
*/
-(void)bindAccountDidCompleteWithResult:(WABindingResult*)bindResult;


/*!
@abstract 实名认证成功回调接口
@param certificationInfo 实名认证信息
*/
-(void)realNameAuthtDidCompleteWithResult:(WACertificationInfo*)certificationInfo;

@end

/*!
 @discussion 用户中心
 - - -
 */
@protocol WAUserCenterNoticeDelegate <NSObject>
/*!
 @abstract 获取用户中心数据回调接口
 @param result 用户中心数据信息
 */
- (void)userCenterNoticeWithResult:(WAUserCenterResult *)result;

@end

/*!
 @discussion 用户中心
 - - -
 */
@protocol WAUserCenterNoticeUIDelegate <NSObject>
/*!
 @abstract 用户中心界面关闭回调接口
 */
- (void)userCenterNoticeClose;
/*!
 @abstract 用户中心界面错误回调接口
 @param error 用户中心错误信息
 */
- (void)userCenterNoticeError:(NSError *)error;

@end


/*!
 @discussion WAUserProxy 是用户模块的代理类。功能包括设置登录流程、登录、登出、绑定、解绑、查询当前用户绑定的第三方平台账户列表、切换账号、创建账号等等。
 - - -
 */

@interface WAUserProxy : NSObject

/*!
 @discussion 设置登录流程
 @param flowType 常量WA_LOGIN_FLOW_TYPE_DEFAULT是默认模式，表示切换新账户的时候不进行设备绑定操作，下次调用匿名登录还是登录之前的账户。常量WA_LOGIN_FLOW_TYPE_REBIND切换新账户的时候将当前设备的clientId绑定到新账户中，下一次匿名登录的时候将会登录到新账户。
 */
+(void)setLoginFlowType:(int)flowType;

/*!
 @discussion 获取登录流程
 */
+(int)getLoginFlowType;

/*!
 @discussion 登录接口
 @param platform 登录平台：目前的登录平台有Facebook，Apple，GUEST,对应的常量分别是WA_PLATFORM_FACEBOOK，WA_PLATFORM_APPLE，WA_PLATFORM_WINGA。
 @param extInfo 扩展信息
 @param delegate 委托
 */
+(void)loginWithPlatform:(NSString *const)platform extInfo:(NSString*)extInfo delegate:(id<WALoginDelegate>)delegate;
/*!
 @discussion 登出接口
 */
+(void)logout;

/*!
 @discussion 绑定账户接口
 @param platform 绑定平台:目前有Facebook,Apple,对应的常量分别为WA_PLATFORM_FACEBOOK,WA_PLATFORM_APPLE
 @param extInfo 扩展信息
 @param delegate 委托
 */
+(void)bindingAccountWithPlatform:(NSString *const)platform extInfo:(NSString*)extInfo delegate:(id<WAAccountBindingDelegate>)delegate;
/*!
 @discussion 查询绑定的第三方平台账户列表
 @param block 回调
 @error 错误
 @accounts 数组accounts存放着WAAccount类型的对象.
 */
+(void)queryBoundAccountWithCompleteBlock:(void(^)(NSError* error,NSArray<WAAccount *>* accounts))block;
/*!
 @discussion 解绑账号接口
 @param platform 解绑平台(WAAccount中的platform)
 @param pUserId 第三方平台用户id(WAAccount中的pUserId)
 */
+(void)unBindAccountWithPlatform:(NSString *const)platform platformUserId:(NSString*)pUserId completeBlock:(void(^)(NSError* error))completeBlock;
/*!
 @discussion 切换账号接口
 @param platform 切换平台
 @param completeBlock 回调结果：包括error(错误)和result(登录结果)
 */
+(void)switchAccountWithPlatform:(NSString *const)platform completeBlock:(void(^)(NSError* error,WALoginResult* result))completeBlock;

/*!
 @discussion 创建账号接口
 @param completeBlock 回调结果：包括error(错误)和result(创建结果)
 */
+(void)createNewAccountWithCompleteBlock:(void(^)(NSError* error,WALoginResult* result))completeBlock;


/*!
 @abstract 调用此方法打开登录界面
 @param delegate 委托
 @param cacheEnabled 是否缓存登录方式 当该参数为YES，默认以上次登录方式登录，不会弹出登录选择框。
 */
+(void)login:(id<WALoginViewDelegate>)delegate cacheEnabled:(BOOL)cacheEnabled;
/*!
 @abstract 调用此方法隐藏登录界面
 */
+(void)hide;
/*!
 @abstract 清除登录方式的缓存 清除缓存之后会再次弹出登录选择框
 */
+(void)clearLoginCache;
/*!
 @abstract 调用此方法打开账户管理界面
 @param delegate 委托
 */
+(void)openAccountManager:(id<WAAcctManagerDelegate>)delegate;


/*!
@abstract 调用此方法打开账户管理界面
@param delegate 委托
*/
+(void)openAccountCenter:(id<WAAcctManagerDelegate>)delegate;




+(BOOL)isBoundPlatformAccount;
/*!
 @abstract 获取账户信息
 @param platform 平台
 */
+(WAAppUser*)getAccountInfoWithPlatform:(NSString *const)platform;

//+(NSString*)transferWithPlatform:(NSString *const)platform;

+ (void)getUserCenterNotice:(id<WAUserCenterNoticeDelegate>)delegate;

+ (void)showUserCenterNoticeUI:(id<WAUserCenterNoticeUIDelegate>)delegate;

/*!
 @discussion 处理UIApplicationDelegate的方法[-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions]传递过来的参数。
 */
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/*!
 @discussion 处理UIApplicationDelegate的方法[- (void)applicationDidBecomeActive:(UIApplication *)application]传递过来的参数。
 */
+(void)applicationDidBecomeActive:(UIApplication *)application;

/*!
 @discussion 处理UIApplicationDelegate的方法[- (void)applicationWillEnterForeground:(UIApplication *)application]传递过来的参数。
 */
+(void)applicationWillEnterForeground:(UIApplication *)application;

/*!
 @discussion 处理UIApplicationDelegate的方法[- (void)applicationDidEnterBackground:(UIApplication *)application]传递过来的参数。
 */
+(void)applicationDidEnterBackground:(UIApplication *)application;

/*!
 @discussion 处理UIApplicationDelegate的方法[-(BOOL)application:(UIApplication *)application
 openURL:(NSURL *)url
 sourceApplication:(NSString *)sourceApplication
 annotation:(id)annotation]传递过来的参数。
 */
+(BOOL)application:(UIApplication *)application
           openURL:(NSURL *)url
 sourceApplication:(NSString *)sourceApplication
        annotation:(id)annotation;



//当一个新的场景被创建时调用，可以在这个方法中配置场景。
- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions API_AVAILABLE(ios(13.0));
// 当场景被销毁时调用。
- (void)sceneDidDisconnect:(UIScene *)scene  API_AVAILABLE(ios(13.0));
//当场景变成活跃状态时调用。
- (void)sceneDidBecomeActive:(UIScene *)scene API_AVAILABLE(ios(13.0));
//当场景将要变成非活跃状态时调用。
- (void)sceneWillResignActive:(UIScene *)scene API_AVAILABLE(ios(13.0));
//当应用程序即将进入前台时调用。
- (void)sceneWillEnterForeground:(UIScene *)scene  API_AVAILABLE(ios(13.0));
//当应用程序进入后台时调用。
- (void)sceneDidEnterBackground:(UIScene *)scene API_AVAILABLE(ios(13.0));
//当别的APP通过URL地址，打开我们的app时调用
- (void)scene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts API_AVAILABLE(ios(13.0));
- (void)scene:(UIScene *)scene continueUserActivity:(NSUserActivity *)userActivity API_AVAILABLE(ios(13.0));




/*!
 @discussion （tip:CP无需关注）此方法为成功登录第三方平台之后调用。根据第三方平台的pUserId，pToken，platform构建一个WALoginResult实例作为参数调用此方法。此方法将会调用WindAnalytics的登录接口。
 @param result 登录结果
 @param delegate 委托
 */
+(void)loginWithResult:(WALoginResult*)result delegate:(id<WALoginDelegate>)delegate;

+(void)loginWithResult:(WALoginResult*)result extInfo:(NSString*)extInfo delegate:(id<WALoginDelegate>)delegate;

/*!
 @discussion （tip:CP无需关注）设置当前的登录平台
 */
+(void)setCurrentLoginPlatform:(NSString *const)platform;
/*!
 @discussion （tip:CP无需关注）获取当前的登录平台
 */
+(NSString*)getCurrentLoginPlatform;
/*!
 @discussion （tip:CP无需关注）获取当前的登录结果
 */
+(WALoginResult*)getCurrentLoginResult;

/*!
 @discussion （tip:CP无需关注）获取用户模块组件
 */
+(NSArray*)getUserComponents;

+(void)queryUserCertificationInfo:(void(^)(WACertificationInfo *certificationInfo,NSError *error))callBackBlock;


/*!
 @discussion 检测是否可以打开账号绑定、账号切换、实名认证接口
 */
+ (BOOL)canOpenAccoutbind;
+ (BOOL)canOpenAccoutSwitch;
+ (BOOL)canOpenRealNameAuth;

/*!
@discussion 打开账户绑定界面
*/
+ (void)openAccoutbindManager:(void(^)(NSError* error,WABindingResult  * bindResult))block;


/*!
@discussion 打开账户切换界面
*/
+ (void)openAccoutSwithchManager:(void(^)(NSError* error,WALoginResult  * loginResult))block;


/*!
@discussion 打开实名认证界面
*/
+ (void)openRealNameAuthManager:(void(^)(NSError* error,WACertificationInfo  * certificationInfo))block;



/*!
@discussion 打开as评分弹框
*/
+ (void)openReview API_AVAILABLE(ios(10.3), macos(10.14));



/*!
@discussion 打开idfa弹框授权
 */
+ (void)openTTAAuthorizationWithCompletionHandler:(void(^)(NSError* error,NSUInteger status))block;

/*!
@discussion 隐私协议弹框
 error 不为空时
    status  -1  弹出了协议框，用户点击了拒绝
            
 error 为空
    status 1 弹出了协议框，用户点击了同意
    status 2 没有弹出协议框，用户之前点击过同意，无需再弹
 */
+ (void)openPrivacyAgreementWindow:(void(^)(NSError* error,NSUInteger status))bloc;



//**************************************删除账号有关start************************************************************

/*!
@discussion 检测是否可调用玩家身份确认接口
 */
+ (BOOL)canCheckIdentity;

/*!
 @discussion 注销账号时，验证当前用户的身份证、id是否匹配，确认是本人操作
 @param realName 姓名
 @param idCard     身份证号码
 */
+ (void)identityCheck:(NSString*)realName idCard:(NSString*)idCard completeBlock:(void(^)(NSError* error))block;


//删除账号授权,拿到第三方的token信息，如 signinwithapple拿到authorizationCode
+ (void)deleteAccounAuthorizationWithPlatform:(NSString*)platform completeBlock:(void(^)(NSError* error,WADeleteRequestModel*deleteResult))block;


/*!
@discussion 账号删除接口
 */
+ (void)requestDeleteAccout:(WADeleteRequestModel*)deleteResult completeBlock:(void(^)(NSError* error,WADeleteResult*result))completeBlock;

/*!
@discussion 取消删除账号接口
 */

+ (void)cancelRequestDeleteAccoutWithUserid:(NSString*)userid callback:(void (^)(NSError *))completeBlock;


// status==1,提交删除账号申请成功
// status==2，用户取消
+ (void)requestDeleteAccoutUI:(void(^)(NSError *error, NSUInteger status))completeBlock;



//**************************************删除账号有关end************************************************************



/*!
@discussion 打开游戏评分功能
 */
+ (void)openGameReview:(void(^)(OpenGameReviewState status))block;


/*!
@discussion 弹出cmp修改同意内容弹框
 */
+ (void)showConsentPreferences;;

@end
