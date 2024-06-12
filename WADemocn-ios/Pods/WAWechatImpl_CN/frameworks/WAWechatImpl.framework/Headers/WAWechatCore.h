//
//  WAWechatCore.h
//  WAWechatImplUI
//
//  Created by hank on 2016/11/23.
//  Copyright © 2016年 hank. All rights reserved.
//

#import <WASdkIntf/WASdkIntf.h>


@class WACoreProxy;
@class WAWechatCore;

#define WechatLog(fmt,...) {\
if([WACoreProxy isDebugMode]){\
NSLog((@"WASDK LOG [(version %@) %s ]:" fmt), [WAWechatCore getVersion],__FUNCTION__, ##__VA_ARGS__);\
[WACoreProxy addLogWithString:[NSString stringWithFormat:(@"(version %@) %s ]:" fmt),[WAWechatCore getVersion],__FUNCTION__, ##__VA_ARGS__]];\
}\
}

@interface WAWechatCore : WACore

+(NSString*)getVersion;

@end
