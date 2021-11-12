//
//  WAQQCore.h
//  WAQQImpl
//
//  Created by LPW on 2020/3/9.
//  Copyright © 2020 LPW. All rights reserved.
//

#import <WASdkIntf/WASdkIntf.h>


@class WACoreProxy;
@class WAQQCore;

#define QQLog(fmt,...) {\
if([WACoreProxy isDebugMode]){\
NSLog((@"WASDK LOG [(version %@) %s ]:" fmt), [WAQQCore getVersion],__FUNCTION__, ##__VA_ARGS__);\
[WACoreProxy addLogWithString:[NSString stringWithFormat:(@"(version %@) %s ]:" fmt),[WAQQCore getVersion],__FUNCTION__, ##__VA_ARGS__]];\
}\
}



@interface WAQQCore : WACore


+(NSString*)getVersion;

@end

