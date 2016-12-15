//
//  WAEventData.m
//  GHWSDKUI
//
//  Created by wuyx on 16/2/22.
//  Copyright © 2016年 GHW-T-01. All rights reserved.
//

#import "WADemoEventData.h"
#import "WADemoEventParam.h"

static NSMutableArray* _waEventDataArray;
@implementation WADemoEventData

-(NSMutableArray *)params{
    if (!_params) {
        _params = [NSMutableArray array];
    }
    return _params;
}


+ (NSString*)getOts{
    NSTimeInterval time = [[NSDate date] timeIntervalSince1970];
    long long int date = (long long int)time;
    
    NSString *ots = [NSString stringWithFormat:@"%lld", date];
    return ots;
}

+(NSMutableArray*)genarateData{
 
    if (_waEventDataArray) {
        return _waEventDataArray;
    }
    
    NSMutableArray* _waEventDataArray = [NSMutableArray array];
    
    //*** event WAEventLogin start ***
    WADemoEventData* data1 = [[WADemoEventData alloc]init];
    data1.eventName = WAEventLogin;
    [_waEventDataArray addObject:data1];
    //*** event 2）	WAEventLogin end ***
    
    
    //*** event WAEventInitiatedPayment start ***
    WADemoEventData* data2 = [[WADemoEventData alloc]init];
    data2.eventName = WAEventInitiatedPayment;
    [_waEventDataArray addObject:data2];
    //*** event WAEventInitiatedPayment end ***
    
    //*** event WAEventPayment start ***
    WADemoEventData* data3 = [[WADemoEventData alloc]init];
    data3.eventName = WAEventPayment;
    
    WADemoEventParam* param3_1 = [[WADemoEventParam alloc]init];
    param3_1.paramName = WAEventParameterNameTransactionId;
    param3_1.paramDesc = @"string";
    param3_1.paramType = GHWParamTypeString;
    [data3.params addObject:param3_1];
    WADemoEventParam* param3_2 = [[WADemoEventParam alloc]init];
    param3_2.paramName = WAEventParameterNameCurrencyType;
    param3_2.paramDesc = @"string";
    param3_2.paramType = GHWParamTypeString;
    param3_2.paramDefValue = @"USD";
    [data3.params addObject:param3_2];
    WADemoEventParam* param3_3 = [[WADemoEventParam alloc]init];
    param3_3.paramName = WAEventParameterNameCurrencyAmount;
    param3_3.paramDesc = @"double";
    param3_3.paramType = GHWParamTypeDouble;
    [data3.params addObject:param3_3];
    WADemoEventParam* param3_4 = [[WADemoEventParam alloc]init];
    param3_4.paramName = WAEventParameterNameVirtualCoinAmount;
    param3_4.paramDesc = @"int";
    param3_4.paramType = GHWParamTypeInt;
    [data3.params addObject:param3_4];
    WADemoEventParam* param3_5 = [[WADemoEventParam alloc]init];
    param3_5.paramName = WAEventParameterNameIAPId;
    param3_5.paramDesc = @"string";
    param3_5.paramType = GHWParamTypeString;
    [data3.params addObject:param3_5];
    WADemoEventParam* param3_6 = [[WADemoEventParam alloc]init];
    param3_6.paramName = WAEventParameterNameIAPName;
    param3_6.paramDesc = @"string";
    param3_6.paramType = GHWParamTypeString;
    [data3.params addObject:param3_6];
    [_waEventDataArray addObject:data3];
    //*** event WAEventPayment end ***
    
    
    //*** event WAEventInitiatedPurchase start ***
    WADemoEventData* data4 = [[WADemoEventData alloc]init];
    data4.eventName = WAEventInitiatedPurchase;
    [_waEventDataArray addObject:data4];
    //*** event WAEventInitiatedPurchase end ***
    
    //*** event WAEventPurchase start ***
    WADemoEventData* data5 = [[WADemoEventData alloc]init];
    data5.eventName = WAEventPurchase;
    
    WADemoEventParam* param5_1 = [[WADemoEventParam alloc]init];
    param5_1.paramName = WAEventParameterNameItemName;
    param5_1.paramDesc = @"string";
    param5_1.paramType = GHWParamTypeString;
    [data5.params addObject:param5_1];
    WADemoEventParam* param5_2 = [[WADemoEventParam alloc]init];
    param5_2.paramName = WAEventParameterNameItemAmount;
    param5_2.paramDesc = @"int";
    param5_2.paramType = GHWParamTypeInt;
    [data5.params addObject:param5_2];
    WADemoEventParam* param5_3 = [[WADemoEventParam alloc]init];
    param5_3.paramName = WAEventParameterNamePrice;
    param5_3.paramDesc = @"double";
    param5_3.paramType = GHWParamTypeDouble;
    [data5.params addObject:param5_3];
    
    [_waEventDataArray addObject:data5];
    //*** event WAEventPurchase end ***
    
    //*** event WAEventLevelAchieved start ***
    WADemoEventData* data6 = [[WADemoEventData alloc]init];
    data6.eventName = WAEventLevelAchieved;
    
    WADemoEventParam* param6_1 = [[WADemoEventParam alloc]init];
    param6_1.paramName = WAEventParameterNameLevel;
    param6_1.paramDesc = @"int";
    param6_1.paramType = GHWParamTypeInt;
    [data6.params addObject:param6_1];
    WADemoEventParam* param6_2 = [[WADemoEventParam alloc]init];
    param6_2.paramName = WAEventParameterNameScore;
    param6_2.paramDesc = @"int";
    param6_2.paramType = GHWParamTypeInt;
    [data6.params addObject:param6_2];
    WADemoEventParam* param6_3 = [[WADemoEventParam alloc]init];
    param6_3.paramName = WAEventParameterNameFighting;
    param6_3.paramDesc = @"int";
    param6_3.paramType = GHWParamTypeInt;
    [data6.params addObject:param6_3];
    WADemoEventParam* param6_4 = [[WADemoEventParam alloc]init];
    param6_4.paramName = WAEventParameterNameLevelInfo;
    param6_4.paramDesc = @"string";
    param6_4.paramType = GHWParamTypeString;
    [data6.params addObject:param6_4];
    WADemoEventParam* param6_5 = [[WADemoEventParam alloc]init];
    param6_5.paramName = WAEventParameterNameLevelType;
    param6_5.paramDesc = @"int(1,2,3,4,5)";
    param6_5.paramType = GHWParamTypeInt;
    param6_5.paramDefValue = @"1";
    [data6.params addObject:param6_5];
    WADemoEventParam* param6_6 = [[WADemoEventParam alloc]init];
    param6_6.paramName = WAEventParameterNameDescription;
    param6_6.paramDesc = @"string";
    param6_6.paramType = GHWParamTypeString;
    [data6.params addObject:param6_6];
    [_waEventDataArray addObject:data6];
    //*** event WAEventLevelAchieved end ***
    
    //*** event WAEventUserCreate start ***
    WADemoEventData* data7 = [[WADemoEventData alloc]init];
    data7.eventName = WAEventUserCreate;
    
    WADemoEventParam* param7_1 = [[WADemoEventParam alloc]init];
    param7_1.paramName = WAEventParameterNameRoleType;
    param7_1.paramDesc = @"string";
    param7_1.paramType = GHWParamTypeString;
    [data7.params addObject:param7_1];
    WADemoEventParam* param7_2 = [[WADemoEventParam alloc]init];
    param7_2.paramName = WAEventParameterNameGender;
    param7_2.paramDesc = @"int(0,1,2)";
    param7_2.paramType = GHWParamTypeInt;
    [data7.params addObject:param7_2];
    WADemoEventParam* param7_3 = [[WADemoEventParam alloc]init];
    param7_3.paramName = WAEventParameterNameNickName;
    param7_3.paramDesc = @"string";
    param7_3.paramType = GHWParamTypeString;
    [data7.params addObject:param7_3];
    WADemoEventParam* param7_4 = [[WADemoEventParam alloc]init];
    param7_4.paramName = WAEventParameterNameRegisterTime;
    param7_4.paramDesc = @"double";
    param7_4.paramType = GHWParamTypeDouble;
    long registerTime = 1000*[[NSDate date]timeIntervalSince1970];
    param7_4.paramDefValue = [NSString stringWithFormat:@"%ld",registerTime];
    [data7.params addObject:param7_4];
    WADemoEventParam* param7_5 = [[WADemoEventParam alloc]init];
    param7_5.paramName = WAEventParameterNameVip;
    param7_5.paramDesc = @"int";
    param7_5.paramType = GHWParamTypeInt;
    [data7.params addObject:param7_5];
    WADemoEventParam* param7_6 = [[WADemoEventParam alloc]init];
    param7_6.paramName = WAEventParameterNameStatus;
    param7_6.paramDesc = @"int(-1,1)";
    param7_6.paramType = GHWParamTypeInt;
    param7_6.paramDefValue = @"-1";
    [data7.params addObject:param7_6];
    WADemoEventParam* param7_7 = [[WADemoEventParam alloc]init];
    param7_7.paramName = WAEventParameterNameBindGameGold;
    param7_7.paramDesc = @"int";
    param7_7.paramType = GHWParamTypeInt;
    [data7.params addObject:param7_7];
    WADemoEventParam* param7_8 = [[WADemoEventParam alloc]init];
    param7_8.paramName = WAEventParameterNameGameGold;
    param7_8.paramDesc = @"int";
    param7_8.paramType = GHWParamTypeInt;
    [data7.params addObject:param7_8];
    WADemoEventParam* param7_9 = [[WADemoEventParam alloc]init];
    param7_9.paramName = WAEventParameterNameLevel;
    param7_9.paramDesc = @"int";
    param7_9.paramType = GHWParamTypeInt;
    [data7.params addObject:param7_9];
    WADemoEventParam* param7_10 = [[WADemoEventParam alloc]init];
    param7_10.paramName = WAEventParameterNameFighting;
    param7_10.paramDesc = @"int";
    param7_10.paramType = GHWParamTypeInt;
    [data7.params addObject:param7_10];
    [_waEventDataArray addObject:data7];
    //*** event WAEventUserCreate end ***
    
    
    //*** event WAEventUserInfoUpdate start ***
    WADemoEventData* data8 = [[WADemoEventData alloc]init];
    data8.eventName = WAEventUserInfoUpdate;

    WADemoEventParam* param8_1 = [[WADemoEventParam alloc]init];
    param8_1.paramName = WAEventParameterNameNickName;
    param8_1.paramDesc = @"string";
    param8_1.paramType = GHWParamTypeString;
    [data8.params addObject:param8_1];
    WADemoEventParam* param8_2 = [[WADemoEventParam alloc]init];
    param8_2.paramName = WAEventParameterNameVip;
    param8_2.paramDesc = @"int";
    param8_2.paramType = GHWParamTypeInt;
    [data8.params addObject:param8_2];
    WADemoEventParam* param8_3 = [[WADemoEventParam alloc]init];
    param8_3.paramName = WAEventParameterNameRoleType;
    param8_3.paramDesc = @"string";
    param8_3.paramType = GHWParamTypeString;
    [data8.params addObject:param8_3];
    [_waEventDataArray addObject:data8];
    //*** event WAEventOpenedFromPushNotification end ***
    
    
    //*** event WAEventGoldUpdate start ***
    WADemoEventData* data9 = [[WADemoEventData alloc]init];
    data9.eventName = WAEventGoldUpdate;

    WADemoEventParam* param9_1 = [[WADemoEventParam alloc]init];
    param9_1.paramName = WAEventParameterNameGoldType;
    param9_1.paramDesc = @"int";
    param9_1.paramType = GHWParamTypeInt;
    param9_1.paramDefValue = @"1";
    [data9.params addObject:param9_1];
    WADemoEventParam* param9_2 = [[WADemoEventParam alloc]init];
    param9_2.paramName = WAEventParameterNameApproach;
    param9_2.paramDesc = @"string";
    param9_2.paramType = GHWParamTypeString;
    [data9.params addObject:param9_2];
    WADemoEventParam* param9_3 = [[WADemoEventParam alloc]init];
    param9_3.paramName = WAEventParameterNameAmount;
    param9_3.paramDesc = @"int";
    param9_3.paramType = GHWParamTypeInt;
    [data9.params addObject:param9_3];
    WADemoEventParam* param9_4 = [[WADemoEventParam alloc]init];
    param9_4.paramName = WAEventParameterNameCurrentAmount;
    param9_4.paramDesc = @"int";
    param9_4.paramType = GHWParamTypeInt;
    [data9.params addObject:param9_4];
    [_waEventDataArray addObject:data9];
    //*** event WAEventGoldUpdate end ***
    
    //*** event WAEventTaskUpdate start ***
    WADemoEventData* data10 = [[WADemoEventData alloc]init];
    data10.eventName = WAEventTaskUpdate;

    WADemoEventParam* param10_1 = [[WADemoEventParam alloc]init];
    param10_1.paramName = WAEventParameterNameTaskId;
    param10_1.paramDesc = @"string";
    param10_1.paramType = GHWParamTypeString;
    [data10.params addObject:param10_1];
    WADemoEventParam* param10_2 = [[WADemoEventParam alloc]init];
    param10_2.paramName = WAEventParameterNameTaskName;
    param10_2.paramDesc = @"string";
    param10_2.paramType = GHWParamTypeString;
    [data10.params addObject:param10_2];
    WADemoEventParam* param10_3 = [[WADemoEventParam alloc]init];
    param10_3.paramName = WAEventParameterNameTaskType;
    param10_3.paramDesc = @"string";
    param10_3.paramType = GHWParamTypeString;
    [data10.params addObject:param10_3];
    WADemoEventParam* param10_4 = [[WADemoEventParam alloc]init];
    param10_4.paramName = WAEventParameterNameTaskStatus;
    param10_4.paramDesc = @"int(1,2,3,4)";
    param10_4.paramType = GHWParamTypeInt;
    param10_4.paramDefValue = @"1";
    [data10.params addObject:param10_4];
    
    [_waEventDataArray addObject:data10];
    //*** event WAEventTaskUpdate end ***
    
    
    //*** event WAEventUserImport start ***
    WADemoEventData* data11 = [[WADemoEventData alloc]init];
    data11.eventName = WAEventUserImport;

    WADemoEventParam* param11_1 = [[WADemoEventParam alloc]init];
    param11_1.paramName = WAEventParameterNameIsFirstEnter;
    param11_1.paramDesc = @"bool";
    param11_1.paramType = GHWParamTypeBool;
    [data11.params addObject:param11_1];
    WADemoEventParam* param11_2 = [[WADemoEventParam alloc]init];
    param11_2.paramName = WAEventParameterNameServerId;
    param11_2.paramDesc = @"string";
    param11_2.paramType = GHWParamTypeString;
    [data11.params addObject:param11_2];
    [_waEventDataArray addObject:data11];
    //*** event WAEventUserImport end ***

    return _waEventDataArray;
}


+(WADemoEventData*)dealWithData:(WADemoEventData*)data{
    data.value = @"0";
    [data.params enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        WADemoEventParam* eventParamObj = obj;
        if (!eventParamObj.paramDefValue) {
            if (eventParamObj.paramType == GHWParamTypeString) {
                eventParamObj.paramDefValue = eventParamObj.paramName;
            }else{
                eventParamObj.paramDefValue = @"0";
            }
        }
    }];
    return data;
}

+(WADemoEventData*)getEventDataWithEventName:(NSString*)eventName{
    
    NSMutableArray* eventDataArray = [self genarateData];
    
    __block WADemoEventData* eventData;
    __block BOOL isCustom = YES;
    [eventDataArray enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        WADemoEventData* eventDataObj = obj;
        if ([eventDataObj.eventName isEqualToString:eventName]) {
            isCustom = NO;
            eventData = eventDataObj;
            [self dealWithData:eventData];
            *stop = YES;
        }
    }];
    
    if (isCustom) {
        eventData = [[WADemoEventData alloc]init];
        eventData.eventName = eventName;
        eventData.on = YES;
        eventData.eventNameOn = YES;
        eventData.paramDictOn = YES;
    }
    
    return eventData;
}
@end
