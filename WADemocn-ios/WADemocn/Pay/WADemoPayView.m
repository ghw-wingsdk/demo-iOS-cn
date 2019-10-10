//
//  WADemoPayView.m
//  WADemo
//
//  Created by hank on 16/4/27.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import "WADemoPayView.h"
#import "WADemoMaskLayer.h"
#import "WADemoProductList.h"
#import "WADemoUtil.h"
#import "WADemoAlertView.h"

@interface WADemoPayView ()
{
    WADemoProductList* productList;
}
@end

@implementation WADemoPayView

-(instancetype)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self) {
        [self initBtnAndLayout];
    }
    return self;
}

-(void)initBtnAndLayout{
    NSMutableArray* btns = [NSMutableArray array];
    
    NSMutableArray* btnLayout = [NSMutableArray array];
    self.title = @"支付";
    self.btnLayout = btnLayout;
    self.btns = btns;
}

-(void)pay{
    [WADemoMaskLayer startAnimating];
//    [WAPayProxy queryInventoryWithPlatform:WA_PLATFORM_WINGA delegate:self];
    [WAPayProxy queryInventoryWithDelegate:self];
}

-(void)queryInventoryDidCompleteWithResult:(NSArray<WAIapProduct *> *)Inventory{
    [WADemoMaskLayer stopAnimating];
	
	
	
	[WAPayProxy queryChannelProduct:@"APPLE" callBackBlock:^(NSArray<WAChannelProduct *> *channelProductsArray, NSError *error) {
		if (!error) {
			
			productList = [[WADemoProductList alloc]initWithFrame:self.scrollView.bounds];
			productList.goToType = GoToTypeWA;
			productList.products = Inventory;
			productList.channelProducts=channelProductsArray;
			[self.scrollView addSubview:productList];
			
		}else{
			
			productList = [[WADemoProductList alloc]initWithFrame:self.scrollView.bounds];
				productList.goToType = GoToTypeWA;
				productList.products = Inventory;
				[self.scrollView addSubview:productList];
		}
	}];

	
	
    
//    productList = [[WADemoProductList alloc]initWithFrame:self.scrollView.bounds];
//    productList.goToType = GoToTypeWA;
//    productList.products = Inventory;
//    [self.scrollView addSubview:productList];
}

-(void)queryInventoryDidFailWithError:(NSError*)error{
    [WADemoMaskLayer stopAnimating];
    
    WADemoAlertView* alert = [[WADemoAlertView alloc]initWithTitle:@"tip" message:[NSString stringWithFormat:@"查询支付发方式失败: error:%@", error.description] cancelButtonTitle:@"Sure" otherButtonTitles:nil block:nil];
    [alert show];
}


-(void)removeView{
    [super removeView];
    [WADemoMaskLayer stopAnimating];
}

- (void)deviceOrientationDidChange
{
    [super deviceOrientationDidChange];
    productList.frame = self.scrollView.bounds;
    [productList deviceOrientationDidChange];
}

@end

