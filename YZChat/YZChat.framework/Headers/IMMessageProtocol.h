//
//  IMMessageProtocol.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/30.
//

#import <Foundation/Foundation.h>
#import "YzIMHeader.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IMMessageElement;

@protocol IMMessage <NSObject>

/// 消息 ID（消息创建的时候为 nil，消息发送的时候会生成）
@property(nonatomic,strong,readonly) NSString *msgID;

/// 消息时间
@property(nonatomic,strong,readonly) NSDate *timestamp;

/// 消息发送者
@property(nonatomic,strong,readonly) NSString *sender;

/// 消息发送者昵称
@property(nonatomic,strong,readonly) NSString *nickname;

/// 消息发送者好友备注
@property(nonatomic,strong,readonly) NSString *friendRemark;

/// 如果是群组消息，nameCard 为发送者的群名片
@property(nonatomic,strong,readonly) NSString *nameCard;

/// 消息发送者头像
/// 在 C2C 场景下，陌生人的头像不会实时更新，如需更新陌生人的头像（如在 UI 上点击陌生人头像以展示陌生人信息时），
/// 请调用 V2TIMManager.h -> getUsersInfo 接口触发信息的拉取。待拉取成功后，SDK 会更新本地头像信息，即 faceURL 字段的内容。
/// @note 请不要在收到每条消息后都去 getUsersInfo，会严重影响程序性能。
@property(nonatomic,strong,readonly) NSString *faceURL;

/// 如果是群组消息，groupID 为会话群组 ID，否则为 nil
@property(nonatomic,strong,readonly) NSString *groupID;

/// 如果是单聊消息，userID 为会话用户 ID，否则为 nil，
/// 假设自己和 userA 聊天，无论是自己发给 userA 的消息还是 userA 发给自己的消息，这里的 userID 均为 userA
@property(nonatomic,strong,readonly) NSString *userID;

/// 群聊中的消息序列号云端生成，在群里是严格递增且唯一的,
/// 单聊中的序列号是本地生成，不能保证严格递增且唯一。
@property(nonatomic,assign,readonly) uint64_t seq;

/// 消息随机码
@property(nonatomic,assign,readonly) uint64_t random;

/// 消息发送状态
@property(nonatomic,assign,readonly) YzIMMessageStatus status;

/// 消息发送者是否是自己
@property(nonatomic,assign,readonly) BOOL isSelf;

/// 消息自己是否已读
@property(nonatomic,assign,readonly) BOOL isRead;

/// 消息对方是否已读（只有 C2C 消息有效）
@property(nonatomic,assign,readonly) BOOL isPeerRead;

/// 群消息中被 @ 的用户 UserID 列表（即该消息都 @ 了哪些人）
@property(nonatomic,strong,readonly) NSArray<NSString *> *groupAtUserList;

/// 消息类型
@property(nonatomic,assign,readonly) YzIMElemType elemType;

@property (nonatomic, strong, readonly) id<IMMessageElement> element;

/// 消息自定义数据（本地保存，不会发送到对端，程序卸载重装后失效）
@property(nonatomic,strong) NSData* localCustomData;

/// 消息自定义数据,可以用来标记语音、视频消息是否已经播放（本地保存，不会发送到对端，程序卸载重装后失效）
@property(nonatomic,assign) int localCustomInt;

/**
 *  根据消息类型，获取需要展示的字符串
 *  比如对于图片消息，返回“[图片]”，对于退群消息，返回“XXX 退出了群聊。”
 */
- (NSString * _Nullable)getDisplayString;

- (NSString * _Nullable)getShowName;

@end

NS_ASSUME_NONNULL_END
