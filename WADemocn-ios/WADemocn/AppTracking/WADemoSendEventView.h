//
//  WADemoSendEventView.h
//  WADemocn
//
//  Created by hank on 2016/12/13.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WADemoSendEventView : UIView

-(instancetype)initWithFrame:(CGRect)frame eventName:(NSString*)eventName;

- (void)deviceOrientationDidChange;

@end
