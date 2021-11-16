//
//  IMMergerElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/30.
//

#import <Foundation/Foundation.h>
#import "IMMessageElement.h"
#import "IMMessageCallback.h"

NS_ASSUME_NONNULL_BEGIN

@class IMMessage;

typedef void (^IMMergeDownloadSuccess)(NSArray * __nullable msgs);

@protocol IMMergerElement <IMMessageElement>

/// 合并消息 title
@property(nonatomic,strong,readonly) NSString *title;

/// 合并消息摘要列表
@property(nonatomic,strong,readonly) NSArray<NSString *> *abstractList;

/// 下载被合并的消息列表
- (void)downloadMergerMessages:(IMMergeDownloadSuccess)succ withFail:(IMGeneralFailure)fail;

@end

NS_ASSUME_NONNULL_END
