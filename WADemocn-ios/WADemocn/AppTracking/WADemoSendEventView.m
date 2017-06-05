//
//  WADemoSendEventView.m
//  WADemocn
//
//  Created by hank on 2016/12/13.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import "WADemoSendEventView.h"
#import "WADemoEventData.h"
#import "WADemoUtil.h"
#import "WADemoEventParam.h"

@interface WADemoSendEventView ()
{
    NSString *mEventName;
    WADemoEventData* waParam;
    UIButton *btnBack;
    UIButton *btnSend;
    UIScrollView *svContent;
}
@end

@implementation WADemoSendEventView

-(instancetype)initWithFrame:(CGRect)frame eventName:(NSString*)eventName
{
    if (self = [super initWithFrame:frame])
    {
        mEventName = eventName;
        
        [self initViews];
        [self initData];
    }
    
    return self;
}

#pragma mark 初始化UI
- (void)initViews
{
    self.frame = [UIScreen mainScreen].bounds;
    self.backgroundColor = [UIColor whiteColor];
    
    UITapGestureRecognizer *ges = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hiddenKeyboard:)];
    [self addGestureRecognizer:ges];
    
    CGRect rectStatus = [[UIApplication sharedApplication] statusBarFrame];
    CGFloat heightStatus = rectStatus.size.width > rectStatus.size.height ? rectStatus.size.height : rectStatus.size.width;
    
    // titleView
    UIView *titleView = [[UIView alloc] initWithFrame:CGRectMake(0, heightStatus, self.frame.size.width, 44)];
    titleView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    titleView.backgroundColor = [UIColor grayColor];
    [self addSubview:titleView];
    
    UILabel *titleLable = [[UILabel alloc] initWithFrame:titleView.bounds];
    titleLable.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    titleLable.textColor = [UIColor whiteColor];
    titleLable.font = [UIFont fontWithName:@"Arial" size:15];
    titleLable.textAlignment = NSTextAlignmentCenter;
    titleLable.text = @"数据收集";
    [titleView addSubview:titleLable];
    
    btnBack = [UIButton buttonWithType:UIButtonTypeCustom];
    btnBack.frame = CGRectMake(0, 0, titleView.frame.size.height, titleView.frame.size.height);
    [btnBack setTitle:@"<" forState:UIControlStateNormal];
    [btnBack.titleLabel setFont:[UIFont fontWithName:@"Helvetica-Bold" size:25]];
    [btnBack setTintColor:[UIColor whiteColor]];
    btnBack.adjustsImageWhenDisabled = YES;
    [btnBack addTarget:self action:@selector(buttonEvents:) forControlEvents:UIControlEventTouchUpInside];
    [titleView addSubview:btnBack];
    
    btnSend = [UIButton buttonWithType:UIButtonTypeCustom];
    btnSend.frame = CGRectMake(titleView.frame.size.width - titleView.frame.size.height, 0, titleView.frame.size.height, titleView.frame.size.height);
    btnSend.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin;
    btnSend.titleLabel.font = [UIFont fontWithName:@"Arial" size:15];
    [btnSend setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [btnSend setTitle:@"发送" forState:UIControlStateNormal];
    [btnSend addTarget:self action:@selector(buttonEvents:) forControlEvents:UIControlEventTouchUpInside];
    [titleView addSubview:btnSend];
    
    //
    CGRect frame = self.frame;
    frame.origin.y = titleView.frame.origin.y + titleView.frame.size.height;
    frame.size.height = frame.size.height - frame.origin.y - 20;
    
    svContent = [[UIScrollView alloc] initWithFrame:frame];
    svContent.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self addSubview:svContent];
}

#pragma mark 根据事件参数初始化UI
- (void)initData
{
    waParam = [WADemoEventData getEventDataWithEventName:mEventName];
    
    UILabel *labelName = nil;
    UISwitch *sValue = nil;
    UITextField *tfValue = nil;
    UILabel *labelLine = nil;
    NSInteger rowX = 10;
    NSInteger rowY = 3;
    CGFloat height  = 35;
    
    // 事件名称
    labelName = [[UILabel alloc] initWithFrame:CGRectMake(rowX, rowY, svContent.frame.size.width - 2 * rowX, height)];
    labelName.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    labelName.font = [UIFont fontWithName:@"Helvetica" size:12];
    labelName.text = [NSString stringWithFormat:@"事件名称 : %@", mEventName];
    [svContent addSubview:labelName];
    
    rowY += height + 3;
    labelLine = [[UILabel alloc] initWithFrame:CGRectMake(rowX, rowY, svContent.frame.size.width - 2 * rowX, 0.5f)];
    labelLine.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    labelLine.backgroundColor = [UIColor blackColor];
    [svContent addSubview:labelLine];
    
    rowY += 3;
    
    // 参数
    labelName = [[UILabel alloc] initWithFrame:CGRectMake(rowX, rowY, svContent.frame.size.width - 2 * rowX, height)];
    labelName.font = [UIFont fontWithName:@"Helvetica" size:12];
    labelName.text = @"参数 : ";
    [svContent addSubview:labelName];
    
    rowY += height;
    
    WADemoEventParam *param = nil;
    for (NSInteger i = 0; i < waParam.params.count; i++)
    {
        param = waParam.params[i];
        
        labelName = [[UILabel alloc] initWithFrame:CGRectMake(rowX, rowY, 180, height)];
        labelName.font = [UIFont fontWithName:@"Helvetica" size:12];
        labelName.text = [NSString stringWithFormat:@"%@[%@]", param.paramName, param.paramDesc];
        [svContent addSubview:labelName];
        
        if (param.paramType == GHWParamTypeBool)
        {
            sValue = [[UISwitch alloc] initWithFrame:CGRectMake(labelName.frame.origin.x + labelName.frame.size.width, rowY, 100, height)];
            sValue.autoresizingMask = UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth;
            sValue.tag = i;
            [svContent addSubview:sValue];
        }
        else
        {
            tfValue = [[UITextField alloc] initWithFrame:CGRectMake(labelName.frame.origin.x + labelName.frame.size.width, rowY,
                                                                    svContent.frame.size.width - labelName.frame.origin.x - labelName.frame.size.width- rowX, height)];
            tfValue.tag = i;
            tfValue.autoresizingMask = UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth;
            tfValue.layer.borderColor = [UIColor blackColor].CGColor;
            tfValue.layer.borderWidth = 0.5f;
            tfValue.leftView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 5, height)];
            tfValue.leftViewMode = UITextFieldViewModeAlways;
            tfValue.font = [UIFont fontWithName:@"Helvetica" size:12];
            if (param.paramType == GHWParamTypeInt)
                tfValue.keyboardType = UIKeyboardTypeNumberPad;
            else if (param.paramType == GHWParamTypeDouble)
                tfValue.keyboardType = UIKeyboardTypeDecimalPad;
            
            tfValue.text = param.paramDefValue;
            [svContent addSubview:tfValue];
        }
        
        rowY += height + 3;
        labelLine = [[UILabel alloc] initWithFrame:CGRectMake(rowX, rowY, svContent.frame.size.width - 2 * rowX, 0.5f)];
        labelLine.autoresizingMask = UIViewAutoresizingFlexibleWidth;
        labelLine.backgroundColor = [UIColor blackColor];
        [svContent addSubview:labelLine];
        
        rowY += 3;
    }
    
    if (tfValue)
        svContent.contentSize = CGSizeMake(self.frame.size.width, labelLine.frame.origin.y + labelLine.frame.size.height);
}

#pragma mark 隐藏键盘
- (void)hiddenKeyboard:(UITapGestureRecognizer *)ges
{
    for (UIView *view in svContent.subviews)
    {
        if ([view isKindOfClass:[UITextField class]])
        {
            [((UITextField *) view) resignFirstResponder];
        }
    }
}

#pragma mark 按钮点击事件
- (void)buttonEvents:(UIButton *)button
{
    if (button == btnBack)
    {
        [self removeFromSuperview];
    }
    else if (button == btnSend)
    {
        NSMutableDictionary *paramDict = [NSMutableDictionary dictionary];
        WADemoEventParam *param = nil;
        for (UIView *view in svContent.subviews)
        {
            if ([view isKindOfClass:[UITextField class]])
            {
                param = waParam.params[view.tag];
                if (param.paramType == GHWParamTypeString)
                    [paramDict setObject:((UITextField *)view).text forKey:param.paramName];
                if (param.paramType == GHWParamTypeInt)
                    [paramDict setObject:[NSNumber numberWithInteger:[((UITextField *)view).text integerValue]] forKey:param.paramName];
                if (param.paramType == GHWParamTypeDouble)
                    [paramDict setObject:[NSNumber numberWithDouble:[((UITextField *)view).text doubleValue]] forKey:param.paramName];
            }
            else if ([view isKindOfClass:[UISwitch class]])
            {
                param = waParam.params[view.tag];
                [paramDict setObject:[NSNumber numberWithBool:((UISwitch *)view).isOn] forKey:param.paramName];
            }
        }
        
        [WATrackProxy trackWithEventName:mEventName valueToSum:0 params:paramDict];
    }
}

- (void)deviceOrientationDidChange
{
    self.frame = self.superview.bounds;
    
    svContent.contentSize = CGSizeMake(self.frame.size.width, svContent.contentSize.height);

}

@end
