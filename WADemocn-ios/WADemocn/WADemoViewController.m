//
//  ViewController.m
//  GHWSDKDemo
//
//  Created by wuyx on 16/2/23.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import "WADemoViewController.h"
#import "WADemoCNMainUI.h"
#import "WADemoAlertView.h"
#import <Toast/Toast.h>

@interface WADemoViewController ()
{
    WADemoCNMainUI* maincnUI;
}
@end

@implementation WADemoViewController
-(void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self initUI];
	
//	
//	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//		
//		BOOL cacheEnabled=YES;
//		[WAUserProxy loginWithPlatform:WA_PLATFORM_WINGA
//								   extInfo:[NSString stringWithFormat:@"{\"enableCache\":%d,\"extInfo\":\"\"}", cacheEnabled]
//								  delegate:maincnUI];
//	});
    
    
    
    [WAUserProxy openPrivacyAgreementWindow:^(NSError *error, NSUInteger status) {
        if (error) {
            //退出游戏
        }else{
            //继续逻辑
            //建议status为1，也就是第一次弹框同意后再调用TTA
            if(status==1){
                [WAUserProxy openTTAAuthorizationWithCompletionHandler:^(NSError *error, NSUInteger status) {
                    NSLog(@"状态=======%ld",status);
                }];
            }
  
        }
    }];
    
 
                
    

    
}




-(void)initUI{
//    WADemoMainUI* mainUI = [[WADemoMainUI alloc]init];
//    [self.view addSubview:mainUI];
    CGFloat width = self.view.bounds.size.width;
    CGFloat height = self.view.bounds.size.height;
    if (((self.interfaceOrientation == UIInterfaceOrientationPortrait || self.interfaceOrientation == UIInterfaceOrientationPortraitUpsideDown) && width > height)
        || ((self.interfaceOrientation == UIInterfaceOrientationLandscapeLeft || self.interfaceOrientation == UIInterfaceOrientationLandscapeRight) && width < height))
    {
        width = self.view.bounds.size.height;
        height = self.view.bounds.size.width;
    }
    
    maincnUI = [[WADemoCNMainUI alloc]initWithFrame:CGRectMake(0, 0, width, height)];
    [self.view addSubview:maincnUI];
	

	
	
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark delegate  GHWLoginViewControllerDelegate
-(void)loginViewDidCancel:(WALoginResult *)result{
    UIAlertView* alert = [[UIAlertView alloc]initWithTitle:@"取消登录" message:[NSString stringWithFormat:@"用户取消登录 登录平台:%@",result.platform] delegate:nil cancelButtonTitle:@"Sure" otherButtonTitles:nil];
    [alert show];
}

-(void)loginViewDidCompleteWithResult:(WALoginResult *)result{
    WADemoAlertView* alert = [[WADemoAlertView alloc]initWithTitle:@"登录成功" message:[NSString stringWithFormat:@"platform:%@\npUserId:%@,pToken:%@,userId:%@,token:%@",result.platform,result.pUserId,result.pToken,result.userId,result.token] cancelButtonTitle:@"Sure" otherButtonTitles:nil block:nil];
    [alert show];
}

-(void)loginViewDidFailWithError:(NSError *)error andResult:(WALoginResult *)result{
    
    WADemoAlertView* alert = [[WADemoAlertView alloc]initWithTitle:@"登录失败" message:[NSString stringWithFormat:@"error:%@\nplatform:%@\npUserId:%@,pToken:%@,userId:%@,token:%@",error.description,result.platform,result.pUserId,result.pToken,result.token,result.userId] cancelButtonTitle:@"Sure" otherButtonTitles:nil block:nil];
    [alert show];
}

#pragma mark delegate  WAAcctManagerDelegate
-(void)newAcctDidCompleteWithResult:(WALoginResult*)result{
    
    WADemoAlertView* alert = [[WADemoAlertView alloc]initWithTitle:@"新建账户成功" message:[NSString stringWithFormat:@"platform:%@\npUserId:%@,pToken:%@,userId:%@,token:%@",result.platform,result.pUserId,result.pToken,result.token,result.userId] cancelButtonTitle:@"Sure" otherButtonTitles:nil block:nil];
    [alert show];
}

-(void)switchAcctDidCompleteWithResult:(WALoginResult*)result{
    WADemoAlertView* alert = [[WADemoAlertView alloc]initWithTitle:@"切换账户成功" message:[NSString stringWithFormat:@"platform:%@\npUserId:%@,pToken:%@,userId:%@,token:%@",result.platform,result.pUserId,result.pToken,result.userId,result.token] cancelButtonTitle:@"Sure" otherButtonTitles:nil block:nil];
    [alert show];
}

-(void)bindAccountDidCompleteWithResult:(WABindingResult*)bindResult{

	WALog(@"绑定成功了========");
	WADemoAlertView* alert = [[WADemoAlertView alloc]initWithTitle:@"绑定账户成功" message:[NSString stringWithFormat:@"platform:%@\n ,pToken:%@,userId:%@",bindResult.platform,bindResult.accessToken,bindResult.userId] cancelButtonTitle:@"Sure" otherButtonTitles:nil block:nil];
	 [alert show];
	
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    [maincnUI deviceOrientationDidChange];
}

@end


