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

@interface WADemoViewController ()
{
    WADemoCNMainUI* maincnUI;
}
@end

@implementation WADemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self initUI];
    
}

-(void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
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
    WADemoAlertView* alert = [[WADemoAlertView alloc]initWithTitle:@"切换账户成功" message:[NSString stringWithFormat:@"platform:%@\npUserId:%@,pToken:%@,userId:%@,token:%@",result.platform,result.pUserId,result.pToken,result.token,result.userId] cancelButtonTitle:@"Sure" otherButtonTitles:nil block:nil];
    [alert show];
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    [maincnUI deviceOrientationDidChange];
}

@end
