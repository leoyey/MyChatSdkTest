//
//  YzChatController.h
//  YZChat
//
//  Created by 安笑 on 2021/4/9.
//

#import <UIKit/UIKit.h>

#import "YzIMKitAgent.h"
#import "YzCustomMessageView.h"

@class V2TIMConversation;

NS_ASSUME_NONNULL_BEGIN

@interface YzChatInfo : NSObject

/// 会话唯一 ID，如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
@property (nonatomic, copy) NSString *conversationId;
/// 会话展示名称（群组：群名称 >> 群 ID；C2C：对方好友备注 >> 对方昵称 >> 对方的 userID）
@property (nonatomic, copy) NSString *showName;

- (instancetype)initWithConversationId:(NSString *)conversationId
                              showName:(NSString *)showName;

@end

@interface YzChatControllerConfig : NSObject

/**
 *  是否关闭发送图片功能
 *
 *  @default NO
 */
@property (nonatomic, assign) BOOL disableSendPhotoAction;

/**
 *  是否关闭拍照功能
 *
 *  @default NO
 */
@property (nonatomic, assign) BOOL disableCaptureAction;

/**
 *  是否关闭摄像功能
 *
 *  @default NO
 */
@property (nonatomic, assign) BOOL disableVideoRecordAction;

/**
 *  是否关闭发文件功能
 *  
 *  @default NO
 */
@property (nonatomic, assign) BOOL disableSendFileAction;

/**
 *  是否关闭发送位置
 *
 *  @default NO
 */
@property (nonatomic, assign) BOOL disableSendLocationAction;
/**
 *  是否关闭发送名片
 *
 *  @default NO
 */
@property (nonatomic, assign) BOOL disableSendBusinessCardAction;
/**
 *  是否关闭音频电话
 *
 *  @default YES
 */
@property (nonatomic, assign) BOOL disableAudioCall;

/**
 *  是否关闭视频电话
 *
 *  @default YES
 */
@property (nonatomic, assign) BOOL disableVideoCall;

/**
 *  是否关闭聊天面板，只能看聊天记录
 *
 *  @default NO
 */
@property (nonatomic, assign) BOOL disableChatInput;

@end

@protocol YzChatControllerDelegate <NSObject>
@optional

/**
 * 点击头像
 *
 * 默认点击头像是打开联系人资料页
 *
 * @param userId 头像用户id
 * @return 如果返回YES，则内部不做任何处理
 */
- (BOOL)onUserIconClick:(NSString *)userId;

/**
 * 触发了@功能
 *
 * @return 如果返回YES，则内部不做任何处理
 */
- (BOOL)onAtGroupMember;

/**
 *  更新自定义会话消息内容回调
 *
 *  @param customMessageView 所更新的自定义会话消息视图
 */
- (void)updatedCustomMessageView:(YzCustomMessageView *)customMessageView;

/**
 *  点击自定义会话消息内容回调
 *
 *  @param customMessageView 所点击的自定义会话消息视图
 */
- (void)onSelectedCustomMessageView:(YzCustomMessageView *)customMessageView;

/**
 *  当前 InputBar 高度改变时的回调。
 *  一般由 InputBar 中的高度改变回调进一步调用。
 *  可以通过该回调实现：根据改变的高度调整控制器内各个组件的 UI 布局。
 *
 *  @param height 改变高度的具体数值（偏移量）。
 */
- (void)didInputBarChangeHeight:(CGFloat)height;

@end

@protocol YzChatControllerDataSource <NSObject>

/**
 * 自定义消息二进制数据
 *
 * @param data 自定义消息二进制数据
 * @return 自定义消息
 */
- (YzCustomMessageData * _Nullable)customMessageForData:(NSData *)data;

@end

extern const CGFloat kYZChatInputBar_Height;

@interface YzChatController : UIViewController

@property(nullable, nonatomic, weak) id<YzChatControllerDelegate> delegate;
@property(nullable, nonatomic, weak) id<YzChatControllerDataSource> dataSource;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

/**
 * @param chatInfo 会话信息 详见 YzChatInfo 定义
 * @param config 会话配置 详见 YzChatControllerConfig 定义
 */
- (instancetype)initWithChatInfo:(YzChatInfo *)chatInfo
                          config:(nullable YzChatControllerConfig *)config NS_DESIGNATED_INITIALIZER;
/**
 * @param chatInfo 会话信息 详见 YzChatInfo 定义
 * @param config 会话配置 详见 YzChatControllerConfig 定义
 * @param locateMessage 定位消息，打开消息列表之后会定位到当前消息，适用于消息搜索场景下点击后的跳转
 * @param highlightKeyword 高亮文本，在搜索场景下，匹配该关键字后cell会高亮显示
 */
- (instancetype)initWithChatInfo:(YzChatInfo *)chatInfo
                          config:(nullable YzChatControllerConfig *)config
                   locateMessage:(V2TIMMessage *)locateMessage
                highlightKeyword:(nullable NSString *)highlightKeyword;

/**
 * 触发了@功能并且选择完成员
 *
 * @param names 成员姓名列表
 * @param ids 成员id列表
 */
- (void)updateInputTextByNames:(NSArray <NSString *> *)names
                           ids:(NSArray <NSString *> *)ids;

/**
 * 触发了@功能并且@所有人
 */
- (void)updateInputTextByAtAll;

/**
 * 注册自定义消息视图
 *
 * @param viewClass 自定义消息视图类型，需继承自 YzCustomMessageView
 * @param identifier 复用标识
 */
- (void)registerClass:(nullable Class)viewClass forCustomMessageViewReuseIdentifier:(NSString *)identifier;

/**
 * 发送自定义消息
 *
 * @param message 自定义消息
 */
- (void)sendMessage:(YzCustomMessageData *)message;
- (void)sendMessage:(YzCustomMessageData *)message
            success:(nullable YzChatSuccess)success
            failure:(nullable YzChatFailure)failure;

/**
 * 发送文本消息
 *
 * @param content 发送内容
 */
- (void)sendTextMessage:(NSString *)content
                success:(nullable YzChatSuccess)success
                failure:(nullable YzChatFailure)failure;

/**
 * 发送图片消息
 *
 * @param path 图片沙盒路径
 */
- (void)sendImageMessage:(NSString *)path
                 success:(nullable YzChatSuccess)success
                 failure:(nullable YzChatFailure)failure;

/**
 * 发送视频消息
 *
 * @param path 视频沙盒路径
 */
- (void)sendVideoMessage:(NSString *)path
                 success:(nullable YzChatSuccess)success
                 failure:(nullable YzChatFailure)failure;

/**
 * 发送位置消息
 *
 * @param name 位置地址
 * @param longitude 经度
 * @param latitude 纬度
 */
- (void)sendLocationMessage:(NSString *)name
                  longitude:(double)longitude
                   latitude:(double)latitude
                    success:(nullable YzChatSuccess)success
                    failure:(nullable YzChatFailure)failure;

/**
 * 发送语音消息
 *
 * @param path 语音沙盒路径
 */
- (void)sendAudioMessage:(NSString *)path
                 success:(nullable YzChatSuccess)success
                 failure:(nullable YzChatFailure)failure;

/**
 * 发送文件消息
 *
 * @param path 文件沙盒路径
 */
- (void)sendFileMessage:(NSString *)path
                success:(nullable YzChatSuccess)success
                failure:(nullable YzChatFailure)failure;

@end

NS_ASSUME_NONNULL_END
