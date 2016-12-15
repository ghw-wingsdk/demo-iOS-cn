//
//  WAAppTracking.m
//  WASDKDemo
//
//  Created by wuyx on 16/2/25.
//  Copyright © 2016年 WA. All rights reserved.
//

#import "WADemoAppTrackingView.h"
#import "WADemoUtil.h"
#import "WADemoButtonMain.h"
#import "WADemoSendEventView.h"
@interface WADemoAppTrackingView ()
{
    NSArray *events;
}
@end

@implementation WADemoAppTrackingView

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
    
    events = @[@{@"title" : @"登录游戏",          @"eventType" : WAEventLogin},
             @{@"title" : @"点击充值",  @"eventType" : WAEventInitiatedPayment},
             @{@"title" : @"充值完成",           @"eventType" : WAEventPayment},
             @{@"title" : @"点击购买", @"eventType" : WAEventInitiatedPurchase},
             @{@"title" : @"充值购买",          @"eventType" : WAEventPurchase},
             @{@"title" : @"玩家等级增长",      @"eventType" : WAEventLevelAchieved},
             @{@"title" : @"创建游戏角色",        @"eventType" : WAEventUserCreate},
             @{@"title" : @"更新用户资料",    @"eventType" : WAEventUserInfoUpdate},
             @{@"title" : @"玩家任务信息",        @"eventType" : WAEventTaskUpdate},
             @{@"title" : @"玩家货币状况变更",        @"eventType" : WAEventGoldUpdate},
             @{@"title" : @"导入用户",        @"eventType" : WAEventUserImport},
             @{@"title" : @"自定义事件",            @"eventType" : @"customEvent"}];
    
    UIButton *button = nil;
    NSMutableArray* btnLayout = [NSMutableArray arrayWithCapacity:events.count];
    NSDictionary *eventDict = nil;
    for (NSInteger i = 0; i < events.count; i++)
    {
        eventDict = events[i];
        
        button = [[WADemoButtonMain alloc] init];
        button.tag = i;
        [button setTitle:eventDict[@"title"] forState:UIControlStateNormal];
        [button addTarget:self action:@selector(buttonEvent:) forControlEvents:UIControlEventTouchUpInside];
        [btns addObject:button];
        
        [btnLayout addObject:@"1"];
    }
    
    self.title = @"数据收集";
    self.btnLayout = btnLayout;
    self.btns = btns;
}

- (void)buttonEvent:(UIButton *)button
{
    NSString *eventType = events[button.tag][@"eventType"];
    
    WADemoSendEventView *sendEventView = [[WADemoSendEventView alloc] initWithEventName:eventType];
    [self addSubview:sendEventView];
}

-(void)dealloc{
    [WADemoUtil removeOrientationNotification:self object:nil];
}

@end
