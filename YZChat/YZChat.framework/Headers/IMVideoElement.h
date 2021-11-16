//
//  IMVideoElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//


#import <Foundation/Foundation.h>
#import "IMMessageElement.h"
#import "IMMessageCallback.h"

NS_ASSUME_NONNULL_BEGIN


@protocol IMVideoElement <IMMessageElement>

@property (nonatomic, strong, nullable, readonly) NSString * videoURL;
@property (nonatomic, strong, nullable, readonly) NSString * videoUUID;
@property (nonatomic, strong, nullable, readonly) NSString * videoType;
// 对于发送者，则直接使用local path
@property (nonatomic, strong, nullable, readonly) NSString * videoPath;
@property (nonatomic, assign, readonly) NSInteger videoSize;
@property (nonatomic, strong, nullable, readonly) NSString * snapshotURL;
@property (nonatomic, strong, nullable, readonly) NSString * snapshotUUID;
@property (nonatomic, strong, nullable, readonly) NSString * snapshotPath;
@property (nonatomic, assign, readonly) NSInteger snapshotWidth;
@property (nonatomic, assign, readonly) NSInteger snapshotHeight;
@property (nonatomic, assign, readonly) NSInteger snapshotSize;
@property (nonatomic, assign, readonly) NSInteger duration;

- (void)snapshotURLWithSuccess:(IMURLSuccess)success withFailure:(nullable IMGeneralFailure)failure;
- (void)downloadSnapshotWithPath:(NSString *)path withProgress:(IMDownloadProgress)progress withSuccess:(IMGeneralSuccess)success withFailure:(nullable IMGeneralFailure)failure;


- (void)videoURLWithSuccess:(IMURLSuccess)success withFailure:(IMGeneralFailure)failure;
- (void)downloadVideoWithPath:(NSString *)path withProgress:(IMDownloadProgress)progress withSuccess:(IMGeneralSuccess)success withFailure:(nullable IMGeneralFailure)failure;

@end

NS_ASSUME_NONNULL_END
