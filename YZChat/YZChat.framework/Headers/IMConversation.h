//
//  IMConversation.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/26.
//


#import <Foundation/Foundation.h>
#import "YzIMHeader.h"
NS_ASSUME_NONNULL_BEGIN

//@class IMMessage;
@protocol IMMessage;

@import ImSDK_Plus.V2TIMManager_Conversation;


/// 会话类型
typedef NS_ENUM(NSInteger, IMConversationType) {
    IM_C2C                             = 1,  ///< 单聊
    IM_GROUP                           = 2,  ///< 群聊
};

/// @ 类型
typedef NS_ENUM(NSInteger, IMGroupAtType) {
    IM_AT_ME                           = 1,  ///< @ 我
    IM_AT_ALL                          = 2,  ///< @ 群里所有人
    IM_AT_ALL_AT_ME                    = 3,  ///< @ 群里所有人并且单独 @ 我
};


/// @ 信息
@interface IMGroupAtInfo : NSObject
/// @ 消息序列号，即带有 “@我” 或者 “@所有人” 标记的消息的序列号
@property(nonatomic,assign,readonly) uint64_t seq;

/// @ 提醒类型，分成 “@我” 、“@所有人” 以及 “@我并@所有人” 三类
@property(nonatomic,assign,readonly) IMGroupAtType atType;

@end

@interface IMConversation : NSObject

/// 会话类型
@property(nonatomic,assign,readonly) IMConversationType type;

/// 会话唯一 ID，如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
@property(nonatomic,strong,readonly) NSString *conversationID;

/// 如果会话类型为 C2C 单聊，userID 会存储对方的用户ID，否则为 nil
@property(nonatomic,strong,readonly) NSString *userID;

/// 如果会话类型为群聊，groupID 会存储当前群的群 ID，否则为 nil
@property(nonatomic,strong,readonly) NSString *groupID;

/// 如果会话类型为群聊，groupType 为当前群类型，否则为 nil
@property(nonatomic,strong,readonly) NSString *groupType;

/// 会话展示名称（群组：群名称 >> 群 ID；C2C：对方好友备注 >> 对方昵称 >> 对方的 userID）
@property(nonatomic,strong,readonly) NSString *showName;

/// 会话展示头像（群组：群头像；C2C：对方头像）
@property(nonatomic,strong,readonly) NSString *faceUrl;

/// 会话未读消息数量,直播群（AVChatRoom）不支持未读计数，默认为 0
@property(nonatomic,assign,readonly) int unreadCount;

/// 消息接收选项（接收 | 接收但不提醒 | 不接收）
@property(nonatomic,assign,readonly) IMReceiveMessageOpt recvOpt;

/// 会话最后一条消息，可以通过 lastMessage -> timestamp 对会话做排序，timestamp 越大，会话越靠前
@property(nonatomic,strong,readonly) id<IMMessage> lastMessage;

/// 群会话 @ 信息列表，用于展示 “有人@我” 或 “@所有人” 这两种提醒状态
@property(nonatomic,strong,readonly) NSArray<IMGroupAtInfo *> *groupAtInfolist;

/// 草稿信息，设置草稿信息请调用 setConversationDraft() 接口
@property(nonatomic,strong,readonly) NSString *draftText;

/// 草稿编辑时间，草稿设置的时候自动生成
@property(nonatomic,strong,readonly) NSDate *draftTimestamp;

/// 是否置顶
@property(nonatomic,assign,readonly) BOOL isPinned;

/// 是否开启消息免打扰
@property (nonatomic, assign, readonly) BOOL isNotDisturb;

/// @ 提醒类型，分成 “@我” 、“@所有人” 以及 “@我并@所有人” 三类
@property(nonatomic ,assign, readonly) IMGroupAtType atType;


- (instancetype)initWithConversation:(V2TIMConversation *)conv withRemark:(NSString * __nullable)remark;
- (instancetype)initWithConversation:(V2TIMConversation *)conv withRemark:(NSString * __nullable)remark withLastMsg:(id<IMMessage>)lastMsg;

- (NSDate *)lastDisplayDate;

@end

NS_ASSUME_NONNULL_END
