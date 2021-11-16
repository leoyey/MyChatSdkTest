//
//  YzIMGroupService.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/25.
//


#import <Foundation/Foundation.h>
#import "YzIMHeader.h"

NS_ASSUME_NONNULL_BEGIN


/////////////////////////////////////////////////////////////////////////////////
//
// YzIMGroupService
//
/////////////////////////////////////////////////////////////////////////////////
@class IMGroupApplication;
@class IMGroupInfoResult;

/// 获取加群申请的列表成功回调
typedef void(^YzIMGroupApplicationSuccess)(NSArray <IMGroupApplication *>*applicationList);
/// 获取指定群列表成功回调
typedef void (^YzIMGroupInfoResultSuccess)(NSArray<IMGroupInfoResult *> *groupResultList);


@protocol YzIMGroupService <NSObject>

@property (nonatomic, strong) id<YzIMGroupListener> listener;

- (void)clearCache;

/**
 * 加入群组
 *
 * @param groupId 群组id
 * @param message 申请消息
 */
- (void)joinGroup:(NSString*)groupId
          message:(NSString*)message
          success:(YzChatSuccess)success
          failure:(YzChatFailure)failure;

/**
 * 获取加群的申请列表
 */
- (void)getGroupApplicationList:(YzIMGroupApplicationSuccess)success
                        failure:(nullable YzChatFailure)failure;

/**
 *  拉取群资料
 *
 *  @param groupIds 群组id列表
 */
- (void)getGroupsInfo:(NSArray<NSString *> *)groupIds
              success:(YzIMGroupInfoResultSuccess)success
              failure:(nullable YzChatFailure)failure;

/**
 * 修改群头像
 *
 * @param groupId 群组id
 * @param url 头像地址
 */
- (void)changeGroupFaceURL:(NSString*)groupId
                       url:(NSString*)url
                   success:(YzChatSuccess)success
                   failure:(YzChatFailure)failure;

/**
 * 修改群名称
 *
 * @param groupId 群组id
 * @param name 群名称
 */
- (void)changeGroupName:(NSString*)groupId
                   name:(NSString*)name
                success:(YzChatSuccess)success
                failure:(YzChatFailure)failure;

/**
 * 修改群公告
 *
 * @param groupId 群组id
 * @param notification 群公告
 */
- (void)changeGroupNotification:(NSString*)groupId
                   notification:(NSString*)notification
                        success:(YzChatSuccess)success
                        failure:(YzChatFailure)failure;

/**
 * 修改群简介
 *
 * @param groupId 群组id
 * @param introduction 群简介
 */
- (void)changeGroupIntroduction:(NSString*)groupId
                   introduction:(NSString*)introduction
                        success:(YzChatSuccess)success
                        failure:(YzChatFailure)failure;

/**
 * 全体禁言
 *
 * @param groupId 群组id
 * @param muted 是否全体禁言
 */
- (void)changeGroupMuted:(NSString*)groupId
                   muted:(BOOL)muted
                 success:(YzChatSuccess)success
                 failure:(YzChatFailure)failure;

/**
 * 设置管理员
 *
 * @param groupId 群组id
 * @param userId 成员id
 * @param isAdd 是否设置为管理员
 */
- (void)changeGroupMemberRole:(NSString*)groupId
                       userId:(NSString *)userId
                        isAdd:(BOOL)isAdd
                      success:(YzChatSuccess)success
                      failure:(YzChatFailure)failure;


@end

NS_ASSUME_NONNULL_END
