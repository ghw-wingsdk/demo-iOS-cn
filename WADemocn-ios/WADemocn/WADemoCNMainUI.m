//
//  WADemoCNMainUI.m
//  WADemocn
//
//  Created by hank on 16/9/26.
//  Copyright © 2016年 GHW. All rights reserved.
//  国内demo view

#import "WADemoCNMainUI.h"
#import "WADemoUtil.h"
#import "WADemoButtonMain.h"
#import <WASdkIntf/WASdkIntf.h>
#import "WADemoMaskLayer.h"
#import "WADemoPayView.h"
#import "WADemoAppTrackingView.h"

@interface WADemoCNMainUI() <WALoginDelegate>

@property(nonatomic)BOOL cacheEnabled;

@end

@implementation WADemoCNMainUI

-(instancetype)initWithBtns:(NSMutableArray *)btns btnLayout:(NSMutableArray *)btnLayout{
    self = [super initWithBtns:btns btnLayout:btnLayout];
    if (self) {
        
    }
    return self;
}

-(instancetype)init{
    self = [super init];
    if (self) {
        //添加界面旋转通知
        [WADemoUtil addOrientationNotification:self selector:@selector(handleDeviceOrientationDidChange:) object:nil];
        [self initBtnAndLayout];
    }
    return self;
}

-(void)handleDeviceOrientationDidChange:(NSNotification*)noti{
    [self setNeedsLayout];
}

-(void)initBtnAndLayout{
    NSMutableArray *btnTitles = [NSMutableArray array];
    
    // 按钮标题列表
    NSNumber *loginFlowType = [NSNumber numberWithBool:([WAUserProxy getLoginFlowType] == WA_LOGIN_FLOW_TYPE_DEFAULT)];
    [btnTitles addObject:@[@"登录时不重新绑定设备", @"登录时重新绑定设备", loginFlowType]];
    [btnTitles addObject:@[@"登录"]];
    [btnTitles addObject:@[@"支付"]];
    [btnTitles addObject:@[@"不缓存登录", @"缓存登录", [NSNumber numberWithBool:_cacheEnabled]]];
    [btnTitles addObject:@[@"切换账号"]];
    [btnTitles addObject:@[@"登出"]];
    [btnTitles addObject:@[@"数据收集"]];
    
    UIImage *bgNormal = [self imageWithColor:[UIColor grayColor] size:CGSizeMake(1, 1)];
    UIImage *bgHighlighted = [self imageWithColor:[UIColor orangeColor] size:CGSizeMake(1, 1)];
    
    NSMutableArray* btns = [NSMutableArray array];
    UIButton *button = nil;
    NSArray *titles = nil;
    for (NSInteger i = 0; i < btnTitles.count; i++)
    {
        titles = btnTitles[i];
        
        button = [UIButton buttonWithType:UIButtonTypeCustom];
        button.tag = i + 1;
        [button setBackgroundImage:bgNormal forState:UIControlStateNormal];
        [button setBackgroundImage:bgHighlighted forState:UIControlStateHighlighted];
        button.titleLabel.font = [UIFont fontWithName:@"Arial" size:15];//Helvetica-Bold
        button.titleLabel.adjustsFontSizeToFitWidth = YES;
        [button setShowsTouchWhenHighlighted:YES];
        button.layer.cornerRadius = 5;
        button.layer.masksToBounds = YES;
        [button addTarget:self action:@selector(buttonEvents:) forControlEvents:UIControlEventTouchUpInside];
        [btns addObject:button];
        
        if (titles.count == 3)
        {
            if ([titles[2] boolValue])
            {
                [button setTitle:titles[1] forState:UIControlStateNormal];
                [button setTitle:titles[0] forState:UIControlStateSelected];
            }
            else
            {
                [button setTitle:titles[0] forState:UIControlStateNormal];
                [button setTitle:titles[1] forState:UIControlStateSelected];
            }
        }
        else
        {
            [button setTitle:titles[0] forState:UIControlStateNormal];
        }
    }
    
    NSMutableArray* btnLayout = [NSMutableArray arrayWithArray:@[@1,@2,@2,@2]];
    self.title = @"WADemocn1.1.0";
    self.btnLayout = btnLayout;
    self.btns = btns;
}

-(UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size {
    CGRect rect = CGRectMake(0, 0, size.width, size.height);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

#pragma mark 按钮事件
- (void)buttonEvents:(WADemoButtonMain *)button
{
    NSInteger tag = button.tag;
    if (tag == 1) //修改登录流程
    {
        int flowType = [WAUserProxy getLoginFlowType];
        NSLog(@"flowType:%d",flowType);
        if (flowType == WA_LOGIN_FLOW_TYPE_REBIND) {
            flowType= WA_LOGIN_FLOW_TYPE_DEFAULT;
        }else{
            flowType = WA_LOGIN_FLOW_TYPE_REBIND;
        }
        [WAUserProxy setLoginFlowType:flowType];
        
        NSString *titleNormal = [button titleForState:UIControlStateNormal];
        [button setTitle:[button titleForState:UIControlStateSelected] forState:UIControlStateNormal];
        [button setTitle:titleNormal forState:UIControlStateSelected];
    }
    else if (tag == 2) // 登录
    {
        [WAUserProxy loginWithPlatform:WA_PLATFORM_WINGA
                               extInfo:[NSString stringWithFormat:@"{\"enableCache\":%d,\"extInfo\":\"\"}", _cacheEnabled]
                              delegate:self];
    }
    else if (tag == 3) // 支付
    {
        UIViewController* vc = [WADemoUtil getCurrentVC];
        WADemoPayView* productList = [[WADemoPayView alloc]init];
        productList.hasBackBtn = YES;
        [vc.view addSubview:productList];
        [productList moveIn];
        [productList pay];
    }
    else if (tag == 4) //设置是否缓存登录
    {
        _cacheEnabled = !_cacheEnabled;
        NSString *titleNormal = [button titleForState:UIControlStateNormal];
        [button setTitle:[button titleForState:UIControlStateSelected] forState:UIControlStateNormal];
        [button setTitle:titleNormal forState:UIControlStateSelected];
    }
    else if (tag == 5) // 切换账号
    {
        [WAUserProxy switchAccountWithPlatform:WA_PLATFORM_WINGA
                                 completeBlock:^(NSError *error, WALoginResult *loginResult) {
                                     if (error)
                                     {
                                         [self loginDidFailWithError:error andResult:loginResult];
                                         return;
                                     }
                                     
                                     [self loginDidCompleteWithResults:loginResult];
                                 }];
    }
    else if (tag == 6) // 登出
    {
        [WAUserProxy logout];
    }
    else if (tag == 7) // 数据收集
    {
        UIViewController* vc = [WADemoUtil getCurrentVC];
        WADemoAppTrackingView* appTrackView = [[WADemoAppTrackingView alloc]init];
        appTrackView.hasBackBtn = YES;
        [vc.view addSubview:appTrackView];
        [appTrackView moveIn];
    }
}

#pragma mark WALoginDelegate
-(void)loginDidCompleteWithResults:(WALoginResult *)result{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"result--token:%@",result.token);
    NSLog(@"result--userid:%@",result.userId);
    NSLog(@"result--pToken:%@",result.pToken);
    NSLog(@"result--pUserid:%@",result.pUserId);
    NSLog(@"result--platform:%@",result.platform);
    NSLog(@"result--extends:%@",result.extends);
}

-(void)loginDidFailWithError:(NSError *)error andResult:(WALoginResult *)result
{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"result.pToken:%@",result.pToken);
    NSLog(@"result.pUserId:%@",result.pUserId);
    NSLog(@"loginDidFailWithError:%@",error);
}

-(void)loginDidCancel:(WALoginResult *)result
{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"loginDidCancel--platform:%@",result.platform);
}

-(void)dealloc
{
    [WADemoUtil removeOrientationNotification:self object:nil];
}

@end
