//
//  GHWLoginUI.m
//  GHWSDKDemo
//
//  Created by wuyx on 16/2/24.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import "WADemoLoginUI.h"
#import "WADemoButtonMain.h"
#import "WADemoButtonSwitch.h"
#import "WADemoViewController.h"
#import "WADemoUtil.h"
#import "WADemoMaskLayer.h"
@interface WADemoLoginUI()
@property(nonatomic)BOOL cacheEnabled;
@end
@implementation WADemoLoginUI

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
    NSMutableArray* btns = [NSMutableArray array];
    WADemoButtonSwitch* btn1 = [[WADemoButtonSwitch alloc]init];
    
    NSString* btnTitle;
    if ([WAUserProxy getLoginFlowType] == WA_LOGIN_FLOW_TYPE_DEFAULT) {
        btnTitle = @"登录时不重新绑定设备";
    }else{
        btnTitle = @"登录时重新绑定设备";
    }
    
    [btn1 setTitle:btnTitle forState:UIControlStateNormal];
    [btn1 addTarget:self action:@selector(changeLoginFlowType:) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn1];
    WADemoButtonSwitch* btn2 = [[WADemoButtonSwitch alloc]init];
    [btn2 setTitle:@"Facebook登录" forState:UIControlStateNormal];
    [btn2 addTarget:self action:@selector(facebookLogin) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn2];
    WADemoButtonMain* btn3 = [[WADemoButtonMain alloc]init];
    [btn3 setTitle:@"Apple登录" forState:UIControlStateNormal];
    [btn3 addTarget:self action:@selector(appleLogin) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn3];
    WADemoButtonMain* btn8 = [[WADemoButtonMain alloc]init];
    [btn8 setTitle:@"VK登录" forState:UIControlStateNormal];
    [btn8 addTarget:self action:@selector(vkLogin) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn8];
    WADemoButtonMain* btn4 = [[WADemoButtonMain alloc]init];
    [btn4 setTitle:@"访客登录" forState:UIControlStateNormal];
    [btn4 addTarget:self action:@selector(anonymousLogin) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn4];
    WADemoButtonMain* btn9 = [[WADemoButtonMain alloc]init];
    [btn9 setTitle:@"应用内登录" forState:UIControlStateNormal];
    [btn9 addTarget:self action:@selector(appSelfLogin) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn9];
    WADemoButtonMain* btn5 = [[WADemoButtonMain alloc]init];
    [btn5 setTitle:@"登录窗口" forState:UIControlStateNormal];
    [btn5 addTarget:self action:@selector(popLoginUI) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn5];
    WADemoButtonMain* btn6 = [[WADemoButtonMain alloc]init];
    
    NSString* btnTitle6;
    if (_cacheEnabled == NO) {
        btnTitle6 = @"不缓存登录方式";
    }else{
        btnTitle6 = @"缓存登录方式";
    }
    
    [btn6 setTitle:btnTitle6 forState:UIControlStateNormal];
    [btn6 addTarget:self action:@selector(setCache:) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn6];
    WADemoButtonMain* btn7 = [[WADemoButtonMain alloc]init];
    [btn7 setTitle:@"登出" forState:UIControlStateNormal];
    [btn7 addTarget:self action:@selector(logout) forControlEvents:UIControlEventTouchUpInside];
    [btns addObject:btn7];
    
    NSMutableArray* btnLayout = [NSMutableArray arrayWithArray:@[@1,@2,@2,@1,@2,@1]];
//
    self.title = @"登录";
    self.btnLayout = btnLayout;
    self.btns = btns;
}
#pragma btn action
//登录
-(void)facebookLogin{
    NSLog(@"---facebook login ---");
    [WADemoMaskLayer startAnimating];
    [WAUserProxy loginWithPlatform:WA_PLATFORM_FACEBOOK extInfo:nil delegate:self];
    
}

- (void)anonymousLogin{
//    [WADemoMaskLayer startAnimating];
    NSLog(@"---anonymousLogin login ---");
    [WAUserProxy loginWithPlatform:WA_PLATFORM_WINGA extInfo:@"{\"enableCache\":YES,\"extInfo\":\"\"}" delegate:self];
}

-(void)appSelfLogin{
    [WADemoMaskLayer startAnimating];
    NSString* extInfo = @"{\"appUserId\":\"12345\",\"extInfo\":\"extInfo String\",\"appToken\":\"o1akkfjia81FMvFSO8kxC96TgQYlhEEr\",\"appSelfLogin\":true}";
    [WAUserProxy loginWithPlatform:WA_PLATFORM_WINGA extInfo:extInfo delegate:self];
}

-(void)appleLogin{
    [WADemoMaskLayer startAnimating];
    [WAUserProxy loginWithPlatform:WA_PLATFORM_APPLE extInfo:nil delegate:self];
    NSLog(@"---apple login ---");
//    [GHWSDKLoginManager loginWithType:GHWLoginTypeApple delegate:self];

}

-(void)vkLogin{
    [WADemoMaskLayer startAnimating];
    [WAUserProxy loginWithPlatform:WA_PLATFORM_VK extInfo:nil delegate:self];
}

//修改登录流程
- (void)changeLoginFlowType:(WADemoButtonSwitch *)btn {
    
    int flowType = [WAUserProxy getLoginFlowType];
    NSLog(@"flowType:%d",flowType);
    NSString* btnTitle;
    if (flowType == WA_LOGIN_FLOW_TYPE_REBIND) {
        flowType= WA_LOGIN_FLOW_TYPE_DEFAULT;
        btnTitle = @"登录时不重新绑定设备";
    }else{
        flowType = WA_LOGIN_FLOW_TYPE_REBIND;
        btnTitle = @"登录时重新绑定设备";
    }
    [WAUserProxy setLoginFlowType:flowType];
    [btn setTitle:btnTitle forState:UIControlStateNormal];
}

//弹出登录窗口
-(void)popLoginUI{
    WADemoViewController* curentVC = (WADemoViewController*)[WADemoUtil getCurrentVC];
    [WAUserProxy login:curentVC cacheEnabled:_cacheEnabled];
}

//登出
-(void)logout{
    [WAUserProxy logout];
}

//设置是否缓存登录方式
-(void)setCache:(UIButton*)btn{
    NSString* title;
    if (_cacheEnabled == NO) {
        _cacheEnabled = YES;
        title = @"缓存登录方式";
    }else{
        _cacheEnabled = NO;
        title = @"不缓存登录方式";
    }
    [btn setTitle:title forState:UIControlStateNormal];
}

#pragma mark GHWLoginDelegate
-(void)loginDidCompleteWithResults:(WALoginResult *)result{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"result--token:%@",result.token);
    NSLog(@"result--userid:%@",result.userId);
    NSLog(@"result--pToken:%@",result.pToken);
    NSLog(@"result--pUserid:%@",result.pUserId);
    NSLog(@"result--platform:%@",result.platform);
    NSLog(@"result--extends:%@",result.extends);
    if (result.platform == WA_PLATFORM_FACEBOOK||result.platform == WA_PLATFORM_VK) {
        
        [WASocialProxy inviteInstallRewardPlatform:result.platform TokenString:result.pToken handler:^(NSUInteger code, NSString *msg, NSError *error) {
            if (code == 200) {
                
                UIAlertView* alert = [[UIAlertView alloc]initWithTitle:@"tip" message:[NSString stringWithFormat:@"触发Facebook被邀请人安装应用事件接口成功 msg:%@",msg] delegate:nil cancelButtonTitle:@"Sure" otherButtonTitles:nil];
                [alert show];
            }else{
                UIAlertView* alert = [[UIAlertView alloc]initWithTitle:@"tip" message:[NSString stringWithFormat:@"触发Facebook被邀请人安装应用事件接口失败 error:%@",error] delegate:nil cancelButtonTitle:@"Sure" otherButtonTitles:nil];
                [alert show];
            }
        }];
    }
}

//-(void)loginDidCompleteWithResults:(WALoginResult *)result{
//    if (result.platform == WA_PLATFORM_FACEBOOK||result.platform == WA_PLATFORM_VK) {
//        
//        [WASocialProxy inviteInstallRewardPlatform:result.platform TokenString:result.pToken handler:^(NSUInteger code, NSString *msg, NSError *error) {
//            if (code == 200) {
//                //触发被邀请人安装应用事件接口成功
//               
//            }else{
//               //触发被邀请人安装应用事件接口失败
//            }
//        }];
//    }
//}

-(void)loginDidFailWithError:(NSError *)error andResult:(WALoginResult *)result{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"result.pToken:%@",result.pToken);
    NSLog(@"result.pUserId:%@",result.pUserId);
    NSLog(@"loginDidFailWithError:%@",error);
}

-(void)loginDidCancel:(WALoginResult *)result{
    [WADemoMaskLayer stopAnimating];
    NSLog(@"loginDidCancel--platform:%@",result.platform);
}

-(void)dealloc{
    [WADemoUtil removeOrientationNotification:self object:nil];
}

@end
