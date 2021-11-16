//
//  YzIMHeader.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/25.
//

#import <Foundation/Foundation.h>
#import "YzSearchMessageParam.h"
#import "YzSearchMessageResult.h"
NS_ASSUME_NONNULL_BEGIN


#pragma mark - global

// 强制下线通知
extern NSString * const kYZChatNotification_ForceOffline;

/// 成功通用回调
typedef void (^YzChatSuccess)(void);

/// 失败通用回调
typedef void (^YzChatFailure)(NSInteger errCode, NSString * errMsg);


#pragma mark - conversation related

@class IMConversation;

/// 日志级别
typedef NS_ENUM(NSInteger, YzIMLogLevel) {
    YzIM_LOG_NONE                         = 0,  ///< 不输出任何 sdk log
    YzIM_LOG_DEBUG                        = 3,  ///< 输出 DEBUG，INFO，WARNING，ERROR 级别的 log
    YzIM_LOG_INFO                         = 4,  ///< 输出 INFO，WARNING，ERROR 级别的 log
    YzIM_LOG_WARN                         = 5,  ///< 输出 WARNING，ERROR 级别的 log
    YzIM_LOG_ERROR                        = 6,  ///< 输出 ERROR 级别的 log
};

typedef NS_ENUM(NSUInteger, YzChatType) {
    // 单聊
    YzChatTypeC2C = 1 << 0,
    // 群聊
    YzChatTypeGroup  = 1 << 1,
};

/// 获取会话列表成功的回调，next：下一次分页拉取的游标 isFinished：会话列表是否已经拉取完毕
typedef void(^YzIMConversationListSuccess)(NSArray<IMConversation *>*list, NSUInteger next, BOOL isFinished);

/// 获取单个会话成功回调
typedef void(^YzIMConversationSuccess)(IMConversation *conversation);
/// 获取未读消息成功回调，c2cUnreadCount单聊未读数，groupUnreadCount群聊未读数
typedef void(^YzIMUnreadCountSuccess)(NSUInteger c2cUnreadCount, NSUInteger groupUnreadCount);

@protocol YzConversationListener <NSObject>
@optional

/**
 * 消息未读数发生变化回调
 *
 * @param c2cUnreadCount 单聊未读数
 * @param groupUnread 群聊未读数
 */
- (void)updateUnreadCount:(NSUInteger)c2cUnreadCount groupUnread:(NSUInteger)groupUnread;

/**
 * 会话发生变化回调
 *
 * @param conversationList 发生变化的会话列表
 */
- (void)updateConversation:(NSArray<IMConversation *>*)conversationList;

@end


#pragma mark - message related

/// 消息接收选项
typedef NS_ENUM(NSInteger, IMReceiveMessageOpt) {
    IM_RECEIVE_MESSAGE                     = 0,  ///< 在线正常接收消息，离线时会进行 APNs 推送
    IM_NOT_RECEIVE_MESSAGE                 = 1,  ///< 不会接收到消息，离线不会有推送通知
    IM_RECEIVE_NOT_NOTIFY_MESSAGE          = 2,  ///< 在线正常接收消息，离线不会有推送通知
};

/// 消息状态
typedef NS_ENUM(NSInteger, YzIMMessageStatus){
    YzIM_MSG_STATUS_SENDING                  = 1,  ///< 消息发送中
    YzIM_MSG_STATUS_SEND_SUCC                = 2,  ///< 消息发送成功
    YzIM_MSG_STATUS_SEND_FAIL                = 3,  ///< 消息发送失败
    YzIM_MSG_STATUS_HAS_DELETED              = 4,  ///< 消息被删除
    YzIM_MSG_STATUS_LOCAL_IMPORTED           = 5,  ///< 导入到本地的消息
    YzIM_MSG_STATUS_LOCAL_REVOKED            = 6,  ///< 被撤销的消息
};

/// 消息类型
typedef NS_ENUM(NSInteger, YzIMElemType){
    YzIM_ELEM_TYPE_NONE                      = 0,  ///< 未知消息
    YzIM_ELEM_TYPE_TEXT                      = 1,  ///< 文本消息
    YzIM_ELEM_TYPE_CUSTOM                    = 2,  ///< 自定义消息
    YzIM_ELEM_TYPE_IMAGE                     = 3,  ///< 图片消息
    YzIM_ELEM_TYPE_SOUND                     = 4,  ///< 语音消息
    YzIM_ELEM_TYPE_VIDEO                     = 5,  ///< 视频消息
    YzIM_ELEM_TYPE_FILE                      = 6,  ///< 文件消息
    YzIM_ELEM_TYPE_LOCATION                  = 7,  ///< 地理位置消息
    YzIM_ELEM_TYPE_FACE                      = 8,  ///< 表情消息
    YzIM_ELEM_TYPE_GROUP_TIPS                = 9,  ///< 群 Tips 消息
    YzIM_ELEM_TYPE_MERGER                    = 10, ///< 合并消息
};

/// 图片类型
typedef NS_ENUM(NSInteger, YzIMImageType){
    YzIM_IMAGE_TYPE_ORIGIN                   = 1,  ///< 原图
    YzIM_IMAGE_TYPE_LARGE                    = 2,  ///< 大图
    YzIM_IMAGE_TYPE_THUMB                    = 3,  ///< 缩略图
};


@protocol YzMessageDataProviderService <NSObject>

/**
 * 获取自定义消息在会话列表中显示的内容
 *
 * @param message 自定义消息
 * @return 返回用于显示的字符串，返回空则使用 `[不支持的自定义消息]`
 */
- (nullable NSString *)customMessageContent:(NSData *)message;

@end


@protocol IMMessage;
@class YzSearchMessageResult;

/// 获取单聊是否免打扰成功回调
typedef void(^YzChatC2CMessageOptSuccess)(NSSet <NSString *>*optSet);

/// 获取会话历史消息成功回调
typedef void(^YzIMHistoryMessageSuccess)(NSArray <id<IMMessage>>*message);

/// 搜索本地消息成功回调
typedef void(^YzSearchMessageSuccess)(NSArray <YzSearchMessageResult *>*results);


#pragma mark - group related


/// Group类型
extern NSString * const kGroupType_Private;
extern NSString * const kGroupType_Pbulic;

@protocol YzIMGroupListener <NSObject>

/**
 * 收到加群申请
 *
 * @param groupId 群id
 */
- (void)onReceiveJoinApplication:(NSString *)groupId;

@end



NS_ASSUME_NONNULL_END
