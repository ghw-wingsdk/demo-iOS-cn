//
//  WADemoCNMainUI.m
//  WADemocn
//
//  Created by hank on 16/9/26.
//  Copyright © 2016年 GHW. All rights reserved.
//  国内demo view

#import "WADemoCNMainUI.h"
#import "WADemoUtil.h"
#import "WADemoButtonSwitch.h"
#import "WADemoMaskLayer.h"
#import "WADemoPayView.h"
#import "WADemoAppTrackingView.h"
#import "WADemoCscViewController.h"
#import <Toast/Toast.h>
#import "WADemoViewController.h"

@interface WADemoCNMainUI() 

@property(nonatomic)BOOL cacheEnabled;
@property(nonatomic)BOOL appWallEnabled;
@property(nonatomic, strong) WADemoPayView* productList;
@property(nonatomic, strong) WADemoAppTrackingView* appTrackView;

@end

@implementation WADemoCNMainUI

static const NSString *kRandomAlphabet = @"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
#define kRandomLength 32


-(instancetype)initWithBtns:(NSMutableArray *)btns btnLayout:(NSMutableArray *)btnLayout{
    self = [super initWithBtns:btns btnLayout:btnLayout];
    if (self) {
        
    }
    return self;
}

-(instancetype)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self) {
	
		_cacheEnabled=YES;

        [self initBtnAndLayout];
    }
    return self;
}

-(void)initBtnAndLayout{
    NSMutableArray *btnTitles = [NSMutableArray array];
    
    // 按钮标题列表
    NSNumber *loginFlowType = [NSNumber numberWithBool:([WAUserProxy getLoginFlowType] == WA_LOGIN_FLOW_TYPE_REBIND)];
    [btnTitles addObject:@[@"登录时不重新绑定设备", @"登录时重新绑定设备", loginFlowType]];
    [btnTitles addObject:@[@"关闭应用墙", @"启用应用墙", [NSNumber numberWithBool:_appWallEnabled]]];
    [btnTitles addObject:@[@"登录"]];
    [btnTitles addObject:@[@"支付"]];
    [btnTitles addObject:@[@"不缓存登录", @"缓存登录", [NSNumber numberWithBool:_cacheEnabled]]];
    [btnTitles addObject:@[@"切换账号"]];
    [btnTitles addObject:@[@"登出"]];
    [btnTitles addObject:@[@"数据收集"]];
    [btnTitles addObject:@[@"闪退测试"]];
    [btnTitles addObject:@[@"进入客服"]];
    [btnTitles addObject:@[@"查询实名认证状态"]];
    [btnTitles addObject:@[@"设置随机clientid"]];
    [btnTitles addObject:@[@"用户中心"]];
    [btnTitles addObject:@[@"单独账号绑定页"]];
    [btnTitles addObject:@[@"单独账号切换页"]];
    [btnTitles addObject:@[@"单独实名认证页"]];



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
    
    NSMutableArray* btnLayout = [NSMutableArray arrayWithArray:@[@1,@2,@2,@2,@2,@2,@1,@1,@2,@1]];
    
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
//    CFShow((__bridge CFTypeRef)(infoDict));
    // app版本
    NSString *appVersion = [infoDict objectForKey:@"CFBundleShortVersionString"];
    
    self.title = [NSString stringWithFormat:@"WADemocn%@", appVersion];
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
	
	NSString * titleStr= button.titleLabel.text;
    NSInteger tag = button.tag;
    if (tag == 1) //修改登录流程
    {
        int flowType = [WAUserProxy getLoginFlowType];
        if (flowType == WA_LOGIN_FLOW_TYPE_REBIND) {
            flowType= WA_LOGIN_FLOW_TYPE_DEFAULT;
        }else{
            flowType = WA_LOGIN_FLOW_TYPE_REBIND;
        }
        NSLog(@"flowType:%d",flowType);
        [WAUserProxy setLoginFlowType:flowType];
        
        NSString *titleNormal = [button titleForState:UIControlStateNormal];
        [button setTitle:[button titleForState:UIControlStateSelected] forState:UIControlStateNormal];
        [button setTitle:titleNormal forState:UIControlStateSelected];
    }
    else if (tag == 2) // 应用墙
    {
        if (button.isSelected)
            [WAApwProxy hideEntryFlowIcon];
            
        else
            [WAApwProxy showEntryFlowIcon];
        
        button.selected = !button.isSelected;
    }
    else if ([titleStr isEqualToString:@"登录"]) // 登录
    {
        [WAUserProxy loginWithPlatform:WA_PLATFORM_WINGA
                               extInfo:[NSString stringWithFormat:@"{\"enableCache\":%d,\"extInfo\":\"\"}", _cacheEnabled]
                              delegate:self];
    }
    else if ([titleStr isEqualToString:@"支付"]) // 支付
    {
        UIViewController* vc = [WADemoUtil getCurrentVC];
        _productList = [[WADemoPayView alloc]initWithFrame:self.bounds];
        _productList.hasBackBtn = YES;
        [vc.view addSubview:_productList];
        [_productList moveIn];
        [_productList pay];
    }
    else if ([titleStr isEqualToString:@"缓存登录"]) //设置是否缓存登录
    {
        _cacheEnabled = !_cacheEnabled;
		
		if(_cacheEnabled){
			[self showToastMessage:@"打开了免密登录"];
		}else{
			[self showToastMessage:@"关闭了免密登录"];

		}
		

		
        NSString *titleNormal = [button titleForState:UIControlStateNormal];
        [button setTitle:[button titleForState:UIControlStateSelected] forState:UIControlStateNormal];
        [button setTitle:titleNormal forState:UIControlStateSelected];
    }
    else if ([titleStr isEqualToString:@"切换账号"]) // 切换账号
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
    else if ([titleStr isEqualToString:@"登出"]) // 登出
    {
        [WAUserProxy logout];
    }
    else if ([titleStr isEqualToString:@"数据收集"]) // 数据收集
    {
        UIViewController* vc = [WADemoUtil getCurrentVC];
        _appTrackView = [[WADemoAppTrackingView alloc]initWithFrame:self.bounds];
        _appTrackView.hasBackBtn = YES;
        [vc.view addSubview:_appTrackView];
        [_appTrackView moveIn];
    }
    else if ([titleStr isEqualToString:@"闪退测试"]) // 闪退测试
    {
        NSArray* array = [NSArray array];
        int i = (int)array[1];
        NSLog(@"%d",i);
    }else if ([titleStr isEqualToString:@"进入客服"]) // 进入客服
    {

		WADemoCscViewController *cscVC = [[WADemoCscViewController alloc] init];
		UIViewController * vc =[WADemoUtil getCurrentVC];
		[vc presentViewController:cscVC animated:YES completion:^{
			
		}];
		
		

    }else if ([titleStr isEqualToString:@"查询实名认证状态"]) //
		{
			
			[WAUserProxy queryUserCertificationInfo:^(WACertificationInfo *certificationInfo, NSError *error) {
				
				if (!error) {
					NSLog(@"d实名认证状态======%ld",certificationInfo.userRealNameStatus);
					NSLog(@"d实名认证状态======%ld",certificationInfo.age);
					
					if (certificationInfo) {
						
						NSString * message= @"";
						if (certificationInfo.userRealNameStatus==-1) {
							message=@"未开启实名认证";
						}else if(certificationInfo.userRealNameStatus==1){
							message=@"未实名";

						}else {
							message=[NSString stringWithFormat:@"已经实名，年龄:=%ld",certificationInfo.age];
							
						}
						[self showToastMessage:message];

					}

					

					

				}else{
					NSLog(@"d实名认证状态======%@",error);
					[self showToastMessage:@"用户未登录"];
					
				}
			}];

			
			
			//用户中心
		}else if([titleStr isEqualToString:@"用户中心"]){
			
			WADemoViewController* vc = (WADemoViewController*)[WADemoUtil getCurrentVC];
			[WAUserProxy openAccountManager:vc];
			
			
			//查询绑定
		}else if([titleStr isEqualToString:@"设置随机clientid"]){

			NSMutableString *randomString = [NSMutableString stringWithCapacity:kRandomLength];
			for (int i = 0; i < kRandomLength; i++) {
				[randomString appendFormat: @"%C", [kRandomAlphabet characterAtIndex:arc4random_uniform((u_int32_t)[kRandomAlphabet length])]];
			}
			
			[WACoreProxy setClientId:randomString];
			[self makeToast:randomString duration:2 position:CSToastPositionCenter];

			
			WALog(@"设置随机吗")
			
		}else if([titleStr isEqualToString:@"单独账号绑定页"]){

			if ([WAUserProxy canOpenAccoutbind]) {
				[WAUserProxy openAccoutbindManager:^(NSError *error, WABindingResult *bindResult) {
						
					if (!error) {
						
						WALog(@"cp回掉绑定成功信息描述platform=%@",bindResult.platform);
						WALog(@"cp回掉绑定成功信息描述userId=%@",bindResult.userId);
						WALog(@"cp回掉绑定成功信息描述accessToken=%@",bindResult.accessToken);

						[self showToastMessage:@"账号绑定成功===="];

					}else{
						
						WALog(@"cp回掉错误信息描述=%@",error.localizedDescription);
						[self showToastMessage:error.localizedDescription];
						
					}
					
					
					
				}];
			}else{
				
				[self showToastMessage:@"没有登录或没有开启绑定账号权限"];

			}
	
			
		}else if([titleStr isEqualToString:@"单独账号切换页"]){
			
			if ([WAUserProxy canOpenAccoutSwitch]) {
				[WAUserProxy openAccoutSwithchManager:^(NSError *error, WALoginResult *loginResult) {
					if (!error) {

						[self showToastMessage:@"cp会调切换账号成功===="];

					}else{

						WALog(@"cp回掉错误信息描述=%@",error.localizedDescription);
						[self showToastMessage:error.localizedDescription];

					}

				}];

			}else{

				[self showToastMessage:@"没有登录或没有开启切换账号权限"];

			}
			
			
		}else if([titleStr isEqualToString:@"单独实名认证页"]){
			
			if ([WAUserProxy canOpenRealNameAuth]) {
				[WAUserProxy openRealNameAuthManager:^(NSError *error, WACertificationInfo *certificationInfo)
				{
					if (!error) {

						[self showToastMessage:@"cp回调 实名认证成功===="];
						WALog(@"实名认证成功=");

					}else{

						WALog(@"cp回调 实名认证 错误信息描述=%@",error.localizedDescription);
						[self showToastMessage:error.localizedDescription];

					}


				}];
			}else{

				[self showToastMessage:@"未登录或者已实名"];


			}
			
			
		}
	

}

- (void)showToastMessage:(NSString *)messag{
	
	[self makeToast:messag duration:2 position:CSToastPositionCenter];

}
- (void)deviceOrientationDidChange
{
    [super deviceOrientationDidChange];
    if (_productList)
        [_productList deviceOrientationDidChange];
    
    if (_appTrackView)
        [_appTrackView deviceOrientationDidChange];
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
	
	[self showToastMessage:@"登录成功回调,通知cp"];

	
	
}

-(void)loginDidFailWithError:(NSError *)error andResult:(WALoginResult *)result
{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"result.pToken:%@",result.pToken);
    NSLog(@"result.pUserId:%@",result.pUserId);
    NSLog(@"loginDidFailWithError:%@",error);
	[self showToastMessage:@"loginDidFailWithError"];

}

-(void)loginDidCancel:(WALoginResult *)result
{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"loginDidCancel--platform:%@",result.platform);
	[self showToastMessage:@"loginDidCancel"];

}

@end
