//
//  YzSearchMessageResult.h
//  YZChat
//
//  Created by Jinyu Li on 2021/9/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IMMessage;

@interface YzSearchMessageResult : NSObject

/// 1、全局搜索的时候，如果是 C2C 单聊则为对方的id, 如果是群聊则为群组id 2、指定了会话查询，这个id是该消息体发送人的id
@property (nonatomic, strong) NSString *resultId;

/// 1、全局搜索的时候，如果是 C2C 单聊则为对方的昵称，如果是群聊则为群名称 2、指定搜索则为消息发送人昵称
@property (nonatomic, strong) NSString *title;

/// 该消息体来自哪个会话，如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
@property (nonatomic, strong) NSString *conversationId;

/// 1、全局搜索的时候，如果是 C2C 单聊则为对方的头像，如果是群聊则为群组的头像 2、指定搜索，头像是该消息的发送人
@property (nullable, nonatomic, strong) NSString *avatarUrl;

/// 查询到相关的条数
@property (nonatomic, assign) NSUInteger count;

/// 搜索到的关键词信息描述：1、如果只有一条，会直接显示出来那一条的信息 2、如果count > 1，内容是`count 条聊天记录`
@property (nonatomic, strong) NSString *matchText;

/// 查询到的消息体：1、全局搜索的时候，如果只有一条，该值存在 2、指定会话搜索的时候，每一个对象体都存在
@property (nullable, nonatomic, strong) id<IMMessage> locateMessage;

@end

NS_ASSUME_NONNULL_END
