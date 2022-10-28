//
//  GHWHelper.h
//  GHWSdk
//
//  Created by GHW-T-01 on 15/5/21.
//  Copyright (c) 2015年 Wuyx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface WAHelper : NSObject
+ (NSString *)getMd5_32Bit_String:(NSString *)srcString;
+ (NSString *)file_md5:(NSString*) path;
+ (NSString*)getOts;
+ (id)toArrayOrNSDictionary:(NSString *)jsonString;
+ (void)setClientId:(NSString*)newClientId;
+ (void)deleteClientId;
+ (NSString*)getClientId;
+ (NSString*)getBundleId;
+ (NSString*)getBuild;
+ (NSString*)getAppVersion;
+ (NSString*)getCarrierName;
+ (NSString*)getFingerId;
+ (NSString*)getDeviceId;
+ (void)saveCache:(NSString *const)key withString:(NSString *)value;
+ (NSString *)getCacheWithKey:(NSString *const)key;
+ (id)getCacheByKey:(NSString *const)key;
+ (void)deleteCacheWithKey:(NSString *const)key;
+ (void)saveCacheWithKey:(NSString *const)key andValue:(id)value;
+ (void)archivedDataWithRootObject:(id)obj andKey:(NSString *const)key;
+ (id)unarchiveObjectWithKey:(NSString *const)key;
+ (void)dictionary:(NSMutableDictionary *)dictionary setObject:(id)object forKey:(id<NSCopying>)key;
+(NSString*)toJSONStringFromDictionary:(NSDictionary*)dict;
//keychain 增删改
+(UIImage*)loadImgWithBundleName:(NSString*)bundleName ImgName:(NSString*)imgName andExt:(NSString*)ext;
+(void)saveKeyChainWithObj:(id)obj andKey:(NSString *const)key;
+(id)loadObjFromKeyChainWithKey:(NSString *const)key;
+(void)deleteObjFromKeyChainWithKey:(NSString *const)key;

// group
+(BOOL)saveKeyChainWithObj:(id)obj andKey:(NSString *const)key  group:(NSString*)group;
+(id)loadObjFromKeyChainWithKey:(NSString *const)key group:(NSString*)group;
+(void)deleteObjFromKeyChainWithKey:(NSString *const)key group:(NSString*)group;
+ (NSString *)getUUID;

+(NSString*)getIDFV;
+(NSString*)getIDFA;
+(NSString*)getSimulateIDFA;
+(NSArray*)getSimulateIDFAParams;
+(NSString*)getPreferredLanguage;

// 读取提前写入的group钥匙串是否正确 572fb189425e0cc04087b6703f95da3e = md5(thisistestgroupclientid)
+(NSString*)getGroupTestSdkClientid;
+(NSString*)getGHWTestValidationClientId;
/**
 *  获取本地时间
 */
+(NSDate*)getLocalTime;
+(NSMutableDictionary*)addParam:(id)param andKey:(NSString *const)key forDict:(NSMutableDictionary*)dict;
+(UIViewController *)getCurrentVC;
+(void)addOrientationNotification:(id)observer selector:(SEL)selector object:(id)object;
+(void)removeOrientationNotification:(id)observer object:(id)object;
+(NSString *)getMacAddress;
/** 设备是否越狱 */
+ (BOOL)isJailBreak;
/** 设置sdk类型 0 国外，1 国内 */
+(void)setSDKType:(NSInteger)sdkType;
/** 获取sdk类型 0 国外，1 国内 */
+(NSInteger)getSDKType;

+(NSString*)getMsgWithDict:(NSDictionary*)dict;
@end
