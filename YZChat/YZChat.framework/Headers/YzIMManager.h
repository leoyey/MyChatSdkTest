//
//  YzIMManager.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/25.
//

#import <Foundation/Foundation.h>
#import "SysUser.h"
#import "YzIMHeader.h"
#import "YzIMUserServiceProtocol.h"
#import "YzIMGroupServiceProtocol.h"
#import "YzIMMessageServiceProtocol.h"
#import "YzIMConversationServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN


@protocol YzIMUIDelegate <NSObject>

@optional
- (void)didClickMeeting:(UIViewController *)viewController withContext:(NSDictionary *)context;

@end

@protocol YzIMStatusListener <NSObject>
@optional

- (void)logout:(BOOL)forced;

@end

@interface YzIMManager : NSObject

/**
 *  获取 YzIMKitAgent 管理实例
 */
+(instancetype)shareInstance;

@property(nonatomic, strong, readonly) NSString *appId;
@property(nonatomic, assign, readonly, getter=isDev) BOOL dev;
@property(nonatomic, strong, readonly) id<YzIMUserService> userService;
@property(nonatomic, strong, readonly) id<YzIMGroupService> groupService;
@property(nonatomic, strong, readonly) id<YzIMMessageService> messageService;
@property(nonatomic, strong, readonly) id<YzIMConversationService> conversationService;

/**
 * 设置默认的groupType，默认为Public。可以使用kGroupType_Private 或者 kGroupType_Pbulic。
 */
@property(nonatomic, strong) NSString *defaultGroupType;

@property(nonatomic, strong) id<YzIMUIDelegate> uiDelegate;

/**
 * 初始化SDK
 *
 * @param appId 由元信提供的一个appId
 * @param logLevel 日志等级
 * @param isDev 开发环境，YES 是开发环境，NO 是正式环境，发布的时候务必改成 NO
 * @param host 可以为空，为空则使用默认的服务器地址
 */
- (void)initWithAppId:(NSString *)appId logLevel:(YzIMLogLevel)logLevel isDev:(BOOL)isDev host:(NSString *)host;

/**
 * 同步数据,最好每次启动的时候可以调用该接口保持数据同步
 */
- (void)loginOnPlatform:(SysUser*)sysUser withSuccess:(YzChatSuccess)success withFailed:(YzChatFailure)fail;

/*
 * 退出IM
 */
- (void)logout;

/**
 * 设置监听器
 */
- (void)setListener:(id<YzIMStatusListener>)listener;


@end

NS_ASSUME_NONNULL_END
