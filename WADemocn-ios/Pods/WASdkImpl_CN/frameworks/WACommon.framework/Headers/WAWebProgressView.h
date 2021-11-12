//
//  WAWebProgressView.h
//  WAWebPayImplUI
//
//  Created by hank on 16/4/29.
//  Copyright © 2016年 hank. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WAWebProgressView : UIView

/** 进度值 */
@property (nonatomic, assign) CGFloat progress;
/** 背景颜色 */
@property (nonatomic, strong) UIColor *backgroundColor;
/** 进度颜色 */
@property (nonatomic, strong) UIColor *progressColor;

/** 开启网页自动进度效果 */
- (void)startAnimation;

/** 关闭网页自动进度效果 */
- (void)stopAnimation;

@end
