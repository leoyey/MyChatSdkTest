//
//  YzIMManager+UI.h
//  YZChat
//
//  Created by Jinyu Li on 2021/9/14.
//

#import <Foundation/Foundation.h>
#import "YzIMManager.h"

NS_ASSUME_NONNULL_BEGIN


@interface YzIMManager (UI)

@property(nonatomic, strong, readonly) SysUser *currentUser;

- (BOOL)isLoggedIn;
- (BOOL)isIMLoggedIn;

- (UIViewController *)loginViewController;
- (UIViewController *)mainViewController;

- (void)gotoMainViewWithTab:(NSInteger)tab;
- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;
- (BOOL)openURL:(NSURL *)url options:(NSDictionary *)options;

@end

NS_ASSUME_NONNULL_END
