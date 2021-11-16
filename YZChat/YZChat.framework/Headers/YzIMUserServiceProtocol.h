//
//  YzIMUserService.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/25.
//


#import <Foundation/Foundation.h>
#import "YzIMHeader.h"

NS_ASSUME_NONNULL_BEGIN


/////////////////////////////////////////////////////////////////////////////////
//
// YzIMUserService
//
/////////////////////////////////////////////////////////////////////////////////


@protocol YzIMUserService <NSObject>

- (void)updateUser:(NSString *)friendId withRemark:(NSString * _Nullable)friendRemark withSuccess:(YzChatSuccess)succes withFailure:(YzChatFailure)failure;

@end

NS_ASSUME_NONNULL_END
