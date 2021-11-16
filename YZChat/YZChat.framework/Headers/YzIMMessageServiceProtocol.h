//
//  YzIMMessageService.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/25.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YzIMHeader.h"

NS_ASSUME_NONNULL_BEGIN


/////////////////////////////////////////////////////////////////////////////////
//
// YzIMMessageService
//
/////////////////////////////////////////////////////////////////////////////////


@class YzSearchMessageParam;
@class YzSearchMessageResult;
@protocol IMMessage;
@class YzCustomMessageData;


@protocol YzIMMessageService <NSObject>

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
                  lastMsg:(id<IMMessage>)lastMsg
                  success:(YzIMHistoryMessageSuccess)success
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
 *  获取单聊是否免打扰
 *  @param userIds 用户id列表
 *
 */
- (void)getC2CReceiveMessageOpt:(NSArray<NSString *> *)userIds
                        success:(YzChatC2CMessageOptSuccess)success
                        failure:(YzChatFailure)failure;

/**
 * 发送自定义消息
 *
 * @param message 自定义消息
 * @param conversationId 会话id
 */
- (UIViewController * _Nullable)sendCustomMessage:(YzCustomMessageData *)message
           toConversation:(nullable NSString *)conversationId
                  success:(nullable YzChatSuccess)success
                  failure:(nullable YzChatFailure)failure;

@end

NS_ASSUME_NONNULL_END
