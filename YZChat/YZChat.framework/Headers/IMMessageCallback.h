//
//  IMMessageCallback.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 获取URL回调
typedef void (^IMURLSuccess)(NSString * url);

/// 成功通用回调
typedef void (^IMGeneralSuccess)(void);

/// 失败通用回调
typedef void (^IMGeneralFailure)(NSInteger errCode, NSString * errMsg);

typedef void (^IMDownloadProgress)(NSUInteger progress);

NS_ASSUME_NONNULL_END
