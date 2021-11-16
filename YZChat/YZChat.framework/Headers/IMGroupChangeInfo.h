//
//  IMGroupChangeInfo.h
//  YChat
//
//  Created by Jinyu Li on 2021/5/2.
//  Copyright © 2021 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGroupChangeInfo : NSObject

@property (nonatomic, strong) NSString * key;
@property (nonatomic, strong) NSString * value;
@property (nonatomic, assign) NSInteger type;

@end

NS_ASSUME_NONNULL_END
