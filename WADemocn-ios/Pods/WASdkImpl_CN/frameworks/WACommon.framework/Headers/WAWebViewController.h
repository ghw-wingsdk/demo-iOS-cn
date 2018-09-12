//
//  WAWebViewController.h
//  WACommon
//
//  Created by hank on 2018/8/23.
//  Copyright © 2018年 GHW-T-01. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WAWebViewController : UIViewController

@property (nonatomic, strong) NSString *url;
@property (nonatomic, copy) void(^handler)(BOOL isClose);

@end
