//
//  YzCustomMessageView.h
//  YZChat
//
//  Created by 安笑 on 2021/4/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 消息类型
typedef NS_ENUM(NSInteger, YzCustomMessageType){
    YzCustomMessageTypeNone                  = 0,  /// 未知消息
    YzCustomMessageTypeCardLink              = 1,  /// CardLink
    YzCustomMessageTypeOss                   = 2,  /// OSS
    YzCustomMessageTypeBusinessCard          = 3,
    YzCustomMessageTypeImage                 = 4,
    YzCustomMessageTypeVideo                 = 5,
    YzCustomMessageTypeVoice                 = 6,
};

@class TUIMessageCellData;
@protocol IMMessage;

@interface YzCustomMessageData : NSObject

+ (instancetype)messageDataWithData:(NSData *)data;

- (TUIMessageCellData *)createBuildInCellData:(id<IMMessage>)msg;
- (YzCustomMessageType)type;
/**
 * 消息气泡标识符
 *
 * 子类重写
 */
- (NSString *)reuseIdentifier;

/**
 * 一个气泡内容的视图大小
 *
 * 子类重写
 */
- (CGSize)contentSize;

/**
 * 自定义消息二进制数据
 *
 * 子类重写
 */
- (NSData *)data;

- (void)parse:(NSString *)jsonStr;

/**
 * 自定义字段描述，用于搜索历史记录
 *
 * 子类重写
 */
- (nullable NSString *)desc;

/**
 * 是否为系统消息，例如：“您撤回了一条消息”。
 *
 * @default NO
 */
- (BOOL)isSystemMessage;

@end


/**
 * 自定义消息内容控件
 */
@interface YzCustomMessageView : UIView

@property (nonatomic, strong, readonly) YzCustomMessageData *data;

- (void)fillWithData:(YzCustomMessageData *)data;

@end

NS_ASSUME_NONNULL_END
