//
//  IMGroupTipsElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//


#import <Foundation/Foundation.h>
#import "IMMessageElement.h"

NS_ASSUME_NONNULL_BEGIN

@class IMGroupMemberInfo;
@class IMGroupChangeInfo;
@class IMGroupMemberChangeInfo;

@protocol IMGroupTipsElement <IMMessageElement>

@property (nonatomic, strong, nullable, readonly) NSString * groupId;
@property (nonatomic, assign, readonly) NSInteger type;
@property (nonatomic, assign, readonly) NSInteger memberCount;
@property (nonatomic, strong, nullable, readonly) IMGroupMemberInfo * opMember;

@property (nonatomic, strong, nullable, readonly) NSArray<IMGroupMemberInfo *> * memberInfoList;
@property (nonatomic, strong, nullable, readonly) NSArray<IMGroupChangeInfo *> * groupChangeInfoList;
@property (nonatomic, strong, nullable, readonly) NSArray<IMGroupMemberChangeInfo *> * groupMemberChangeInfoList;

@end

NS_ASSUME_NONNULL_END
