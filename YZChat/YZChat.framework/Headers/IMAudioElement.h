//
//  IMAudioElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//


#import <Foundation/Foundation.h>
#import "IMMessageElement.h"
#import "IMMessageCallback.h"

NS_ASSUME_NONNULL_BEGIN


@protocol IMAudioElement <IMMessageElement>

@property (nonatomic, strong, nullable, readonly) NSString * url;
@property (nonatomic, strong, nullable, readonly) NSString * uuid;
@property (nonatomic, assign, readonly) NSInteger fileSize;
// 对于发送者，path保存了本地路径，如果存在，则不需要下载了
@property (nonatomic, strong, nullable, readonly) NSString * path;

@property (nonatomic, assign, readonly) NSInteger duration;

/// FIXME: delete?
@property (nonatomic, assign) int customInt;

- (NSString *)URLWithSuccess:(IMURLSuccess)success withFailure:(IMGeneralFailure)failure;
- (void)downloadWithPath:(NSString *)path withProgress:(IMDownloadProgress)progress withSuccess:(IMGeneralSuccess)success withFailure:(IMGeneralFailure)failure;

@end

NS_ASSUME_NONNULL_END
