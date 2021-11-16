//
//  YzIMKitAgent.h
//  YChat
//
//  Created by magic on 2020/12/7.
//  Copyright © 2020 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SysUser.h"
#import "YzCustomMsg.h"
#import "YzIMHeader.h"

@import ImSDK_Plus.V2TIMManager_Conversation;

NS_ASSUME_NONNULL_BEGIN

// 强制下线通知
extern NSString * const kYZChatNotification_ForceOffline;

@class YzIMConversation;

@protocol YzIMKitAgentListener <NSObject>
@optional

- (void)logout;

/**
 * 收到加群申请
 *
 * @param groupId 群id
 */
- (void)onReceiveJoinApplication:(NSString *)groupId;

@end

@interface YzIMKitAgent : NSObject

/**
 *  获取 YzIMKitAgent 管理实例
 */
+(YzIMKitAgent *)shareInstance;

/**
 * 初始化时候调用 传入appId
 */
- (void)initAppId:(NSString *)appId DEPRECATED_MSG_ATTRIBUTE("请改用 initWithAppId:");
- (void)initWithAppId:(NSString *)appId;
- (void)initWithAppId:(NSString *)appId logLevel:(V2TIMLogLevel)logLevel;
/**
 * 初始化SDK
 *
 * @param appId 由元信提供的一个appId
 * @param logLevel 日志等级
 * @param isDev 开发环境，YES 是开发环境，NO 是正式环境，发布的时候务必改成 NO
 */
- (void)initWithAppId:(NSString *)appId logLevel:(V2TIMLogLevel)logLevel isDev:(BOOL)isDev;

/**
 * 同步数据,最好每次启动的时候可以调用该接口保持数据同步
 */
- (void)registerWithSysUser:(SysUser*)sysUser
               loginSuccess:(YzChatSuccess)success
                loginFailed:(YzChatFailure)fail;

/*
 * 退出IM
 */
- (void)logout;

/**
 * 设置监听器
 */
- (void)addListener:(id<YzIMKitAgentListener>)listener;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                              Conversation
//
/////////////////////////////////////////////////////////////////////////////////

@interface V2TIMConversation (YzChat)

/// 是否开启消息免打扰
@property (nonatomic, assign, readonly) BOOL isNotDisturb;

/// @ 提醒类型，分成 “@我” 、“@所有人” 以及 “@我并@所有人” 三类
@property(nonatomic ,assign, readonly) V2TIMGroupAtType atType;

@end


@interface YzIMKitAgent (Conversation)

/// 获取会话列表成功的回调，next：下一次分页拉取的游标 isFinished：会话列表是否已经拉取完毕
typedef void(^YzChatConversationListSuccess)(NSArray<YzIMConversation *>*list, NSUInteger next, BOOL isFinished);
/// 获取单个会话成功回调
typedef void(^YzChatConversationSuccess)(YzIMConversation *conversation);
/// 获取未读消息成功回调，c2cUnreadCount单聊未读数，groupUnread群聊未读数
typedef void(^YzChatUnreadCountSuccess)(NSUInteger c2cUnreadCount, NSUInteger groupUnread);

/**
 * 设置会话监听器
 */
- (void)addConversationListener:(id<YzConversationListener>)listener;

/**
 * 获取会话列表
 * 
 * @param next 下一次分页拉取的游标
 * @param count 分页拉取的个数
 * @param type 会话列表类型
 */
- (void)loadConversation:(NSUInteger)next
                   count:(NSUInteger)count
                    type:(YzChatType)type
                 success:(YzChatConversationListSuccess)success
                 failure:(nullable YzChatFailure)failure;

/**
 * 获取跟某个人的会话（单聊/群聊）
 *
 * @param conversationId 会话id 如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
 */
- (void)getConversation:(NSString *)conversationId
                success:(YzChatConversationSuccess)success
                failure:(nullable YzChatFailure)failure;

/**
 * 删除会话以及该会话中的历史消息（单聊/群聊）
 *
 * @param conversationId 会话id 如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
 *
 * @note 请注意:
 * - 该会话以及会话中的历史消息，会被 SDK 从本地和服务端一同删除掉，并且不可恢复。
 */
- (void)deleteConversation:(NSString *)conversationId
                   success:(YzChatSuccess)success
                   failure:(nullable YzChatFailure)failure;

/**
 * 获取消息未读数
 */
- (void)conversationUnRead:(YzChatUnreadCountSuccess)success
                   failure:(nullable YzChatFailure)failure;

/**
 * 发送自定义消息
 *
 * @param message 自定义消息
 * @param conversationId 会话id
 */
- (nullable UIViewController *)sendCustomMessage:(YzCustomMessageData *)message
                                  toConversation:(nullable NSString *)conversationId
                                         success:(nullable YzChatSuccess)success
                                         failure:(nullable YzChatFailure)failure;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                              Message
//
/////////////////////////////////////////////////////////////////////////////////

/// 获取会话历史消息成功回调
typedef void(^YzChatHistoryMessageSuccess)(NSArray <V2TIMMessage *>*message);
/// 搜索本地消息成功回调
//typedef void(^YzSearchMessageSuccess)(NSArray <YzSearchMessageResult *>*results);


@interface YzIMKitAgent (Message)

- (void)setMessageDataProviderService:(id<YzMessageDataProviderService>)service;

/**
 * 获取会话历史消息
 *
 * @param conversationId 会话唯一 ID，如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
 * @param count 拉取消息的个数，不宜太多，会影响消息拉取的速度，这里建议一次拉取 20 个
 * @param lastMsg 获取消息的起始消息，如果传 nil，起始消息为会话的最新消息
 *
 * @note 如果 SDK 检测到没有网络，默认会直接返回本地数据
 */
- (void)getHistoryMessage:(NSString *)conversationId
                    count:(int)count
                  lastMsg:(V2TIMMessage *)lastMsg
                  success:(YzChatHistoryMessageSuccess)success
                  failure:(nullable YzChatFailure)failure;

/**
 * 搜索本地消息
 *
 * @param param 消息搜索参数，详见 YzSearchMessageParam 的定义
 *
 */
- (void)searchMessage:(YzSearchMessageParam *)param
              success:(YzSearchMessageSuccess)success
              failure:(YzChatFailure)failure;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                              C2C
//
/////////////////////////////////////////////////////////////////////////////////

/// 获取单聊是否免打扰成功回调
//typedef void(^YzChatC2CMessageOptSuccess)(NSSet <NSString *>*optSet);

@interface YzIMKitAgent (C2C)

/**
 *  设置单聊免打扰
 *  @param userIds 用户id列表（最大允许设置 30 个用户）
 *  @param opt 是否开启单聊消息免打扰
 *
 *  @note 该接口调用频率被限制为1秒内最多调用5次。
 */
- (void)changeC2CReceiveMessageOpt:(NSArray<NSString *> *)userIds
                               opt:(BOOL)opt
                           success:(YzChatSuccess)success
                           failure:(YzChatFailure)failure;

/**
 *  获取单聊是否免打扰
 *  @param userIds 用户id列表
 *
 */
- (void)getC2CReceiveMessageOpt:(NSArray<NSString *> *)userIds
                        success:(YzChatC2CMessageOptSuccess)success
                        failure:(YzChatFailure)failure;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                              Group
//
/////////////////////////////////////////////////////////////////////////////////

@interface V2TIMGroupInfo (YzChat)

/// 是否开启单聊消息免打扰
@property (nonatomic, assign, readonly) BOOL isNotDisturb;

@end

/// 获取加群申请的列表成功回调
typedef void(^YzChatGroupApplicationSuccess)(NSArray <V2TIMGroupApplication *>*applicationList);
/// 获取指定群列表成功回调
typedef void (^YzChatGroupInfoResultSuccess)(NSArray<V2TIMGroupInfoResult *> *groupResultList);

@interface YzIMKitAgent (Group)

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
- (void)getGroupApplicationList:(YzChatGroupApplicationSuccess)success
                        failure:(nullable YzChatFailure)failure;

/**
 *  拉取群资料
 *
 *  @param groupIds 群组id列表
 */
- (void)getGroupsInfo:(NSArray<NSString *> *)groupIds
              success:(YzChatGroupInfoResultSuccess)success
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
 * 消息免打扰
 *
 * @param groupId 群组id
 * @param opt 是否开启群消息免打扰
 */
- (void)changeGroupReceiveMessageOpt:(NSString*)groupId
                                 opt:(BOOL)opt
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


@interface YzIMKitAgent (User)

- (void)updateFriend:(NSString *)friendId withRemark:(NSString *)friendRemark withSuccess:(YzChatSuccess)succes withFailure:(YzChatFailure)failure;

@end
NS_ASSUME_NONNULL_END
