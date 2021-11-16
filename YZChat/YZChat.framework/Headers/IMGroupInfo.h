//
//  IMGroupInfo.h
//  YZChat
//
//  Created by Jinyu Li on 2021/9/1.
//

#import <Foundation/Foundation.h>
#import "YzIMHeader.h"
NS_ASSUME_NONNULL_BEGIN


/// 加群选项
typedef NS_ENUM(NSInteger, IMGroupAddOpt) {
    IM_GROUP_ADD_FORBID                 = 0,  ///< 禁止加群
    IM_GROUP_ADD_AUTH                   = 1,  ///< 需要管理员审批
    IM_GROUP_ADD_ANY                    = 2,  ///< 任何人可以加入
};


/// 群成员角色
typedef NS_ENUM(NSInteger, IMGroupMemberRole) {
    IM_GROUP_MEMBER_UNDEFINED           = 0,    ///< 未定义（没有获取该字段）
    IM_GROUP_MEMBER_ROLE_MEMBER         = 200,  ///< 群成员
    IM_GROUP_MEMBER_ROLE_ADMIN          = 300,  ///< 群管理员
    IM_GROUP_MEMBER_ROLE_SUPER          = 400,  ///< 群主
};


@interface IMGroupInfo : NSObject

/// 群组 ID
@property(nonatomic,strong) NSString* groupID;

/// 群类型
@property(nonatomic,strong) NSString* groupType;

/// 群名称
@property(nonatomic,strong) NSString* groupName;

/// 群公告
@property(nonatomic,strong) NSString* notification;

/// 群简介
@property(nonatomic,strong) NSString* introduction;

/// 群头像
@property(nonatomic,strong) NSString* faceURL;

/// 是否全员禁言
@property(nonatomic,assign) BOOL allMuted;

///设置群自定义字段需要两个步骤：
///1.在 [控制台](https://console.cloud.tencent.com/im) (功能配置 -> 群自定义字段) 配置群自定义字段的 key 值，Key 为 String 类型，长度不超过 16 字节。
///2.调用 setGroupInfo 接口设置该字段，value 为 NSData 数据，长度不超过 512 字节。
///@note 该字段主要用于 V1 和 V2 版本的兼容，如果您直接使用的是 V2 版本的 API ，建议使用 initGroupAttributes 接口设置群属性，其设置更灵活（无需控制台配置），支持的存储也更大（最大支持 16K）
@property(nonatomic,strong) NSDictionary<NSString *,NSData *>* customInfo;

/// 群创建人/管理员
@property(nonatomic,strong,readonly) NSString *owner;

/// 群创建时间
@property(nonatomic,assign,readonly) uint32_t createTime;

/// 加群是否需要管理员审批，工作群（Work）不能主动加入，不支持此设置项
@property(nonatomic,assign) IMGroupAddOpt groupAddOpt;

/// 群最近一次群资料修改时间
@property(nonatomic,assign,readonly) uint32_t lastInfoTime;

/// 群最近一次发消息时间
@property(nonatomic,assign,readonly) uint32_t lastMessageTime;

/// 群成员总数量
/// @note 频繁调用该接口会影响程序性能，如果仅需获取群在线人数，推荐使用[V2TIMManager.sharedInstance getGroupOnlineMemberCount:groupId succ:nil fail:nil]接口
@property(nonatomic,assign,readonly) uint32_t memberCount;

/// 在线成员数量
@property(nonatomic,assign,readonly) uint32_t onlineCount;

/// 当前用户在此群组中的角色，切换角色请调用 setGroupMemberRole 接口
@property(nonatomic,assign,readonly) IMGroupMemberRole role;

/// 当前用户在此群组中的消息接收选项,修改群消息接收选项请调用 setGroupReceiveMessageOpt 接口
@property(nonatomic,assign,readonly) IMReceiveMessageOpt recvOpt;

/// 当前用户在此群中的加入时间，不支持设置，系统自动生成
@property(nonatomic,assign,readonly) uint32_t joinTime;

- (BOOL)isNotDisturb;

@end

NS_ASSUME_NONNULL_END
