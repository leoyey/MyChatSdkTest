//
//  YzIMConversationService.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/25.
//


#import <Foundation/Foundation.h>
#import "YzIMHeader.h"

NS_ASSUME_NONNULL_BEGIN


/////////////////////////////////////////////////////////////////////////////////
//
// YzIMConversationService
//
/////////////////////////////////////////////////////////////////////////////////


@class IMConversation;

@protocol YzIMConversationService <NSObject>

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
                 success:(YzIMConversationListSuccess)success
                 failure:(nullable YzChatFailure)failure;

/**
 * 获取跟某个人的会话（单聊/群聊）
 *
 * @param conversationId 会话id 如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
 */
- (void)getConversation:(NSString *)conversationId
                success:(YzIMConversationSuccess)success
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
- (void)conversationUnRead:(YzIMUnreadCountSuccess)success
                   failure:(nullable YzChatFailure)failure;


@end

NS_ASSUME_NONNULL_END
