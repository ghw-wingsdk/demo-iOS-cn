//
//  GHWMaskLayer.m
//  GHWSDKDemo
//
//  Created by wuyx on 16/2/24.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import "WADemoMaskLayer.h"
#import "WADemoUtil.h"

static WADemoMaskLayer* ghwMaskLayer_;

@interface WADemoMaskLayer()
@property(nonatomic,strong)UIActivityIndicatorView* maskLayerIndicator;
@end

@implementation WADemoMaskLayer

-(instancetype)init{
    self = [super init];
    if (self) {
        //添加界面旋转通知
        [WADemoUtil addOrientationNotification:self selector:@selector(handleDeviceOrientationDidChange:) object:nil];
        self.frame = [UIScreen mainScreen].bounds;
        self.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.4];
        [self initUI];
    }
    return self;
}

-(void)handleDeviceOrientationDidChange:(NSNotification*)noti{
    [self setNeedsLayout];
}

-(void)initUI{
    
    _maskLayerIndicator = [[UIActivityIndicatorView alloc]initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    [self addSubview:_maskLayerIndicator];
}

-(void)layoutSubviews{
    [super layoutSubviews];
    self.frame = [UIScreen mainScreen].bounds;
    _maskLayerIndicator.center = self.center;
}

+(void)startAnimating{
    if (!ghwMaskLayer_) {
        ghwMaskLayer_ = [[WADemoMaskLayer alloc]init];
    }
    
    UIViewController* currentVC = [WADemoUtil getCurrentVC];
    [currentVC.view addSubview:ghwMaskLayer_];
    [ghwMaskLayer_.maskLayerIndicator startAnimating];
}

+(void)stopAnimating{
    [ghwMaskLayer_.maskLayerIndicator stopAnimating];
    [ghwMaskLayer_ removeFromSuperview];
    ghwMaskLayer_ = nil;
}

-(void)dealloc{
    [WADemoUtil removeOrientationNotification:self object:nil];
}

@end
