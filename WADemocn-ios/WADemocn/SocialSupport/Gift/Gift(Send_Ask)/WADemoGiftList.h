//
//  GHWGiftList.h
//  GHWSDKDemo
//
//  Created by wuyx on 16/2/25.
//  Copyright © 2016年 GHW. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WASdkIntf/WASdkIntf.h>
@interface WADemoGiftList : UITableView<UITableViewDataSource>
@property(nonatomic,strong)NSArray* gifts;
@end
