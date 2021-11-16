//
//  YzIMMessage.h
//  YZChat
//
//  Created by Jinyu Li on 2021/7/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@import ImSDK_Plus.V2TIMManager_Message;

@interface YzIMMessage : NSObject

/// 消息 ID（消息创建的时候为 nil，消息发送的时候会生成）
@property(nonatomic,strong,readonly) NSString *msgID;

/// 消息时间
@property(nonatomic,strong,readonly) NSDate *timestamp;

/// 消息发送者
@property(nonatomic,strong,readonly) NSString *sender;

/// 消息发送者昵称
@property(nonatomic,strong,readonly) NSString *nickName;

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

/// 消息发送状态
@property(nonatomic,assign,readonly) V2TIMMessageStatus status;

/// 消息发送者是否是自己
@property(nonatomic,assign,readonly) BOOL isSelf;

/// 消息自己是否已读
@property(nonatomic,assign,readonly) BOOL isRead;

/// 消息对方是否已读（只有 C2C 消息有效）
@property(nonatomic,assign,readonly) BOOL isPeerRead;

/// 群消息中被 @ 的用户 UserID 列表（即该消息都 @ 了哪些人）
@property(nonatomic,strong,readonly) NSMutableArray<NSString *> *groupAtUserList;

/// 消息类型
@property(nonatomic,assign,readonly) V2TIMElemType elemType;

/// 消息类型 为 V2TIM_ELEM_TYPE_TEXT，textElem 会存储文本消息内容
@property(nonatomic,strong,readonly) V2TIMTextElem *textElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_CUSTOM，customElem 会存储自定义消息内容
@property(nonatomic,strong,readonly) V2TIMCustomElem *customElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_IMAGE，imageElem 会存储图片消息内容
@property(nonatomic,strong,readonly) V2TIMImageElem *imageElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_SOUND，soundElem 会存储语音消息内容
@property(nonatomic,strong,readonly) V2TIMSoundElem *soundElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_VIDEO，videoElem 会存储视频消息内容
@property(nonatomic,strong,readonly) V2TIMVideoElem *videoElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_FILE，fileElem 会存储文件消息内容
@property(nonatomic,strong,readonly) V2TIMFileElem *fileElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_LOCATION，locationElem 会存储地理位置消息内容
@property(nonatomic,strong,readonly) V2TIMLocationElem *locationElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_FACE，faceElem 会存储表情消息内容
@property(nonatomic,strong,readonly) V2TIMFaceElem *faceElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_MERGER，mergerElem 会存储转发消息内容
@property(nonatomic,strong,readonly) V2TIMMergerElem *mergerElem;

/// 消息类型 为 V2TIM_ELEM_TYPE_GROUP_TIPS，groupTipsElem 会存储群 tips 消息内容
@property(nonatomic,strong,readonly) V2TIMGroupTipsElem *groupTipsElem;

/// 消息自定义数据（本地保存，不会发送到对端，程序卸载重装后失效）
@property(nonatomic,strong) NSData* localCustomData;


/**
 *  根据消息类型，获取需要展示的字符串
 *  比如对于图片消息，返回“[图片]”，对于退群消息，返回“XXX 退出了群聊。”
 */
- (NSString *)getDisplayString;

@end

NS_ASSUME_NONNULL_END
