//
//  IMGroupMemberInfo.h
//  YChat
//
//  Created by Jinyu Li on 2021/5/2.
//  Copyright © 2021 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGroupMemberInfo : NSObject

@property (nonatomic, strong) NSString *userId;

/// 用户昵称
@property(nonatomic,strong) NSString* nickname;

/// 用户好友备注
@property(nonatomic,strong) NSString* friendRemark;

/// 群成员名片
@property(nonatomic,strong) NSString* nameCard;

/// 用户头像
@property(nonatomic,strong) NSString* faceURL;

@end

NS_ASSUME_NONNULL_END
