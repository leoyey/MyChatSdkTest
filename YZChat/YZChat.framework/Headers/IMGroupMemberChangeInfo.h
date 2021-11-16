//
//  IMGroupMemberChangeInfo.h
//  YChat
//
//  Created by Jinyu Li on 2021/5/2.
//  Copyright © 2021 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGroupMemberChangeInfo : NSObject

@property (nonatomic, strong) NSString * userId;
@property (nonatomic, assign) NSInteger muteTime;

@end

NS_ASSUME_NONNULL_END
