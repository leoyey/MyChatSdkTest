//
//  IMImage.h
//  YChat
//
//  Created by Jinyu Li on 2021/5/2.
//  Copyright © 2021 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMMessageCallback.h"
#import "YzIMHeader.h"

NS_ASSUME_NONNULL_BEGIN

@class TUIImageItem;

@interface IMImage : NSObject

@property (nonatomic, strong) NSString * uuid;
@property (nonatomic, assign) YzIMImageType type;
@property (nonatomic, strong) NSString * url;
@property (nonatomic, assign) NSInteger size;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

- (void)downloadWithPath:(NSString *)path withProgress:(IMDownloadProgress)progress withSuccess:(IMGeneralSuccess)success withFailure:(IMGeneralFailure)failure;
- (TUIImageItem *)toTUIImageItem;
+ (instancetype) imageWithTUIImage:(TUIImageItem *)tuiImage;

@end

NS_ASSUME_NONNULL_END
